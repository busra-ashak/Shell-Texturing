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

layout(std430, binding = 2) buffer transformBuffer
{
    mat4 base_transform;
    vec3 spacing;
};

void main()
{
    int plane_id = gl_VertexID / 6;
    vec4 pos = vec4(vertices[gl_VertexID%6], 1.0f)*base_transform;
    pos.xyz += spacing*plane_id;
    gl_Position = projection*view*pos;
}