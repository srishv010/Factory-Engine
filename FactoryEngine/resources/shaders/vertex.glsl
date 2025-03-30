#version 460 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoords;

uniform mat4 modelMatrix;
uniform mat4 viewProjectionMatrix;

out vec2 TexCoords;

void main() {
   gl_Position = viewProjectionMatrix * modelMatrix * vec4(aPos.x, aPos.y, aPos.z, 1.0);
   TexCoords = aTexCoords;
}