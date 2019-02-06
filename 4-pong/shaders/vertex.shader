#version 140

in vec3 aPos;
in vec2 aTexCoord;
uniform mat4 transform;

void main()
{
    gl_Position = transform * vec4(aPos.x, aPos.y, aPos.z, 1.0);
}