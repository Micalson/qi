#version 430 core

layout(location = 0) in vec2 ver_attribute_position;
layout(location = 1) in vec2 ver_attribute_texcoord;
layout(location = 2) in vec4 ver_attribute_color;

uniform float viewport_width;
uniform float viewport_height;
uniform vec2 origin;
uniform float width;
uniform float height;

out vec2 texcoord;
out vec4 color;
void main()
{
	vec2 screen_pos = origin + ver_attribute_position * vec2(width, height);
	vec2 normalize_pos = 2.0 * (screen_pos) / vec2(viewport_width, viewport_height) + vec2(-1.0, -1.0);
    gl_Position = vec4(normalize_pos, 0.0, 1.0);
	texcoord = ver_attribute_texcoord;
	color = ver_attribute_color;
}