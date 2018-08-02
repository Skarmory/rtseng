#include "scene/terrain_gen.h"

#include <glm/glm.hpp>

#include "services.h"

Terrain* TerrainGenerator::generate(unsigned int width, unsigned int height)
{
	Terrain* terrain = new Terrain;
	terrain->_width = width;
	terrain->_height = height;

	std::vector<TerrainVertex> vertices;
	std::vector<unsigned int> indices;
	vertices.reserve(width * height);
	indices.reserve(width * height * 6);

	TerrainVertex vertex;

	// UV coordinates tile in x and y, and thus tessellate together nicely
	// This allows us to use an index buffer and not split any vertices

	// Quick lookup array for texture coordinates based on map x,y
	glm::vec2 uvs[2][2] = {
		{ glm::vec2(1.0f, 0.0f), glm::vec2(1.0f, 1.0f) },
		{ glm::vec2(0.0f, 0.0f), glm::vec2(0.0f, 1.0f) }
	};

	// Create mesh data
	for (unsigned int y = 0; y <= height; y++)
	for (unsigned int x = 0; x <= width; x++)
	{
		// Create vertex
		vertex.position = terrain->_index_to_world(x, y) * 32.0f;
		vertex.normal = glm::vec3(0.0f, 1.0f, 0.0f);
		vertex.uv = uvs[y % 2][x % 2];
		vertex.texture_index = 0;

		vertices.push_back(vertex);

		// Construct triangles
		if (x != width && y != height)
		{
			// Upper
			indices.push_back(terrain->_flatten_coord(x, y));
			indices.push_back(terrain->_flatten_coord(x, y + 1));
			indices.push_back(terrain->_flatten_coord(x + 1, y));
			

			// Lower
			indices.push_back(terrain->_flatten_coord(x + 1, y));
			indices.push_back(terrain->_flatten_coord(x, y + 1));
			indices.push_back(terrain->_flatten_coord(x + 1, y + 1));
			
		}
	}

	terrain->_mesh.set_data(std::move(vertices), std::move(indices));
	terrain->_mesh.initialise();
	terrain->_shader = &Services::get().get_asset_manager()->load_and_get_asset<Shader>("terrain.shader");

	return terrain;
}