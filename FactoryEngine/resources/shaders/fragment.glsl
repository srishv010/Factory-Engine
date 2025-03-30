#version 460 core

in vec2 TexCoords;

uniform sampler2D Texture0;

out vec4 FragColor;

void main() {
   FragColor = texture(Texture0, TexCoords);
}