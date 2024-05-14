#version 450 core

const vec3 triangles[3] = vec3[](
    vec3(-0.5, -0.5, 0.0), vec3(0.5, -0.5, 0.0), vec3(-0.5f, 0.5, 0.0)
 );

void main()
{
    gl_Position = vec4(triangles[gl_VertexID], 1.0f);
}