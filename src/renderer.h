#include "buffer.h"
#include "camera.h"
struct renderer 
{
    renderer();
    camera cam;
    buffer cam_buffer;
    buffer vertex_buffer;
    void setup();
    void draw_planes(unsigned int planeNum);
    void update();
};