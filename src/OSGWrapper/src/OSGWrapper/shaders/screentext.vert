#version 430 core

layout(location = 0) in vec2 ver_attribute_position;

uniform float font_size;
uniform float viewport_width;
uniform float viewport_height;
uniform vec2 origin = vec2(0.0, 0.0);
uniform vec2 offset = vec2(0.0, 0.0);

void main()
{
	float factor = font_size;
	vec2 viewport_rect = 2.0 * (ver_attribute_position + offset) * vec2(factor, factor) / vec2(viewport_width, viewport_height);
	vec2 screen_pos = viewport_rect + vec2(-1.0, -1.0);
    gl_Position = vec4(screen_pos, 0.0, 1.0);
}