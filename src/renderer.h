#include "glad/glad.h"
struct renderer 
{
    void draw_planes(unsigned int planeNum);
    void bind_vertex_buffer(GLuint buff);
};