#include "renderer.h"

renderer::renderer()
{
    cam.fov = 3.14159f/2.0f;
    cam.aspect_ratio = 1920.0f/1080.0f;
    cam.near_clip = 0.1f;
    cam.far_clip = 1000.0f;
}

void renderer::setup()
{
    cam_buffer = create_buffer(2*sizeof(glm::mat4), true);
}

void renderer::draw_planes(unsigned int planeNum)
{
    bind_buffer(cam_buffer, 1);
    glDrawArrays(GL_TRIANGLES, 0, planeNum*2*3);
}

void renderer::bind_vertex_buffer(buffer buff)
{
    bind_buffer(buff, 0);
}

void renderer::update()
{
    glm::mat4 temp[2];
    temp[0] = cam.get_view();
    temp[1] = cam.get_projection();
    write_buffer(cam_buffer, temp, 2*sizeof(glm::mat4));
}