#include "buffer.h"
#include "camera.h"
struct renderer 
{
    renderer();
    camera cam;
    void draw_planes(unsigned int planeNum);
    void bind_vertex_buffer(buffer buff);
};