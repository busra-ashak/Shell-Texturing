#ifndef RENDERER_H
#define RENDERER_H

#include "buffer.h"
#include "camera.h"

struct transform {
    glm::mat4 base_tranform;
    glm::vec3 spacing;
};

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
    void set_transform(transform t);
    const transform& get_transform() const;
private:
    transform trans;
};

#endif