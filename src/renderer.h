#include "glad/glad.h"
#include "camera.h"
struct renderer 
{
    renderer();
    camera cam;
    void draw_planes(unsigned int planeNum);
    void bind_vertex_buffer(GLuint buff);
};