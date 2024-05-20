#include "buffer.h"
#include "camera.h"
struct renderer 
{
    renderer();
    camera cam;
    buffer cam_buffer;
    void draw_planes(unsigned int planeNum);
    void bind_vertex_buffer(buffer buff);
    void update();
};