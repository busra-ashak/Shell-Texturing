#version 450 core

layout(std430, binding = 0) buffer vertexBuffer
{
    vec3 vertices[];
};

layout(std430, binding = 1) buffer cameraBuffer
{
    mat4 view;
    mat4 projection;
};

void main()
{
    vec4 pos = vec4(vertices[gl_VertexID%6], 1.0f);
    pos.y += gl_VertexID/6;
    gl_Position = projection*view*pos;
}