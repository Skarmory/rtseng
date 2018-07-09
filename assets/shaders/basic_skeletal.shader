
#ifdef VERTEX

#define BONES_MAX 40

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform mat4 bones[BONES_MAX];

layout (location = 0) in vec3 in_position;
layout (location = 1) in vec3 in_normal;
layout (location = 2) in vec2 in_uv;
layout (location = 3) in ivec4 boneids;
layout (location = 4) in vec4 boneweights;

layout (location = 0) out vec3 out_position;
layout (location = 1) out vec3 out_normal;
layout (location = 2) out vec2 out_uv;

void main()
{
	mat4 bone_transform = (bones[boneids[0]] * boneweights[0]);
	bone_transform += (bones[boneids[1]] * boneweights[1]);
	bone_transform += (bones[boneids[2]] * boneweights[2]);
	bone_transform += (bones[boneids[3]] * boneweights[3]);

	vec4 pos = bone_transform * vec4(in_position, 1.0);

	out_normal = in_normal;
	out_uv = in_uv;
	
	gl_Position = projection * view * model * vec4(pos.xyz, 1.0);
}

#endif

#ifdef FRAGMENT

layout (binding = 0) uniform sampler2D albedo;

uniform float alpha;

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 uv;

layout (location = 0) out vec4 colour;

void main()
{
	vec4 t = texture(albedo, uv);
	float a = t.a * alpha;
	colour =  vec4(t.rgb, a);
}

#endif