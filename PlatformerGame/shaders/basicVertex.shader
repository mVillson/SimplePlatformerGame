#version 460 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec4 color;

out vec4 vColor;

void main()
{
	vColor = color;

	gl_Position = vec4(pos.x, pos.y, pos.z, 1.0f);
}