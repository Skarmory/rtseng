#pragma once

#include "gfx/mesh.h"
#include "gfx/shader_program.h"

class MeshRenderer
{
public:
	MeshRenderer(Mesh* mesh, ShaderProgram* program);

	void render(void);

private:
	Mesh* _mesh;
	ShaderProgram* _program;
};