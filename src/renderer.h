#ifndef RENDERER_H
#define RENDERER_H

#include "buffer.h"
#include "camera.h"
struct renderer 
{
    renderer();
    camera cam;
    buffer cam_buffer;
    buffer vertex_buffer;
    buffer transform_buffer;
    unsigned int shell_num;
    void setup();
    void draw_planes();
    void update();
};

#endif