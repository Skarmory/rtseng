#pragma once

#include <queue>

#include "ecs/system.h"
#include "event/event.h"
#include "gfx/render_command.h"
#include "gfx/uniforms.h"

// Base class for any system that processes render logic
class RenderLogicSystem : public System
{
public:
	RenderLogicSystem(void);
	virtual ~RenderLogicSystem(void);

	virtual void update(float delta) override = 0;
	virtual void on_event(Event ev) override = 0;

protected:
	
	void bind_mesh(const Mesh& mesh);
	void bind_texture(const Texture& texture);
	void use_shader(const Shader& shader);
	void draw_indexed(PrimitiveType primitive_type, unsigned int index_count, unsigned int offset);

	template<class UniformData>
	void update_uniform(unsigned int location, UniformData data)
	{
		if (!_current_uniform_command)
			_current_uniform_command = new UpdateUniformsCommand;

		_current_uniform_command->add_uniform(new Uniform<UniformData>(location, data));
	}

	void submit_commands(void);

private:
	std::vector<const RenderCommand*> _command_queue;

	UpdateUniformsCommand* _current_uniform_command;
	MakeTextureHandlesResidentCommand* _current_texture_command;
};