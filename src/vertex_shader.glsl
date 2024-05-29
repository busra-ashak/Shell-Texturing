#version 450 core
layout(location = 0) out uint plane_id;
layout(location = 1) out vec3 position;
layout(location = 2) out vec4 pos_camera_space;
layout(location = 3) out vec4 normal;

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
    plane_id = gl_VertexID / 6;

    // reuse same vertex data for all the planes
    position = vertices[gl_VertexID%6];
    vec4 pos = vec4(vertices[gl_VertexID%6], 1.0f);
    pos.xyz += spacing.xzy*plane_id;

    // model space -> world space
    pos = pos * base_transform;

    // pass these to the fragment shader
    pos_camera_space = view*pos;
    gl_Position = projection*pos_camera_space;
    normal = vec4(0,1,0,0)*base_transform;
}