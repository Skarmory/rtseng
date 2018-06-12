#pragma once

#include <unordered_map>
#include <typeindex>
#include <functional>

#include <ecs/component.h>

class ComponentManager
{
public:

	// Registers a component by name
	template<class ComponentType>
	void register_component(const std::string& component_id)
	{
		std::function<ComponentType*(void)> constructor = [](void) { return new ComponentType; };
		_component_type_map[component_id] = constructor;
	}

	// Create and return a component
	BaseComponent* create_component(const char* name)
	{
		return _component_type_map.at(name)();
	}

	// Query if component type is registered
	bool is_registered(const char* name)
	{
		return _component_type_map.find(name) != _component_type_map.end();
	}

private:
	std::unordered_map<std::string, std::function<BaseComponent*(void)>> _component_type_map;
};
