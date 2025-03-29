#version 460 core

layout (location = 0) in vec3 aPos;

uniform mat4 modelMatrix;
uniform mat4 viewProjectionMatrix;

void main() {
   gl_Position = viewProjectionMatrix * modelMatrix * vec4(aPos.x, aPos.y, aPos.z, 1.0);
}