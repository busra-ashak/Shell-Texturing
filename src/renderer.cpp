#include "renderer.h"
#include "glm/ext/matrix_transform.hpp"
#include "glm/fwd.hpp"

renderer::renderer()
{
    cam.fov = 3.14159f/2.0f;
    cam.aspect_ratio = 640.0f/480.0f;
    cam.near_clip = 0.1f;
    cam.far_clip = 1000.0f;
}

struct transform {
    glm::mat4 base_tranform;
    glm::vec3 spacing;
};

void renderer::setup()
{
    cam_buffer = create_buffer(2*sizeof(glm::mat4), true);

    transform trans;
    trans.base_tranform = glm::rotate(glm::identity<glm::mat4>(), 3.14159f/4.0f, glm::vec3(1.0f, 0.0f, 0.0f));
    trans.spacing = glm::vec3(0,0.1,0);
    transform_buffer = create_buffer(sizeof(trans));
    write_buffer(transform_buffer, &trans, sizeof(trans));

    std::vector<glm::vec4> triangles({
        glm::vec4(-0.5, -0.5, 0.0, 0), glm::vec4(0.5, -0.5, 0.0, 0), glm::vec4(-0.5f, 0.5, 0.0, 0),
        glm::vec4(-0.5f, 0.5, 0.0, 0), glm::vec4(0.5, -0.5, 0.0, 0), glm::vec4(0.5, 0.5, 0.0, 0)
    });    
    size_t size_vertex = sizeof(glm::vec4)*triangles.size();
    vertex_buffer = create_buffer(sizeof(glm::vec4)*triangles.size());
    write_buffer(vertex_buffer, triangles.data(), size_vertex);

    bind_buffer(vertex_buffer, 0);
    bind_buffer(cam_buffer, 1);
    bind_buffer(transform_buffer, 2);
}

void renderer::draw_planes(unsigned int planeNum)
{
    glDrawArrays(GL_TRIANGLES, 0, planeNum*2*3);
}

void renderer::update()
{
    glm::mat4 temp[2];
    temp[0] = cam.get_view();
    temp[1] = cam.get_projection();
    write_buffer(cam_buffer, temp, 2*sizeof(glm::mat4));
}