#pragma once

#include <glm/glm.hpp>

// Contains vertex attribute information
struct Vertex
{
	glm::vec3	  position;
	glm::vec3	  normal;
	glm::vec2	  uv;
	unsigned int  bone_ids[4];
	float		  bone_weights[4];
};