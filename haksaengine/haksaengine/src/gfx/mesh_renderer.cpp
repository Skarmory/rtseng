#include "gfx/mesh_renderer.h"

MeshRenderer::MeshRenderer(Mesh* mesh, ShaderProgram* program) : _mesh(mesh), _program(program)
{
}

void MeshRenderer::render(void)
{
	_program->use();
	_mesh->bind();
}