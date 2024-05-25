#include "renderer.h"
#include "glm/ext/matrix_transform.hpp"
#include "glm/fwd.hpp"

renderer::renderer()
{
    cam.fov = 3.14159f/2.0f;
    cam.aspect_ratio = 640.0f/480.0f;
    cam.near_clip = 0.1f;
    cam.far_clip = 1000.0f;
    shell_num = 6;
}

void renderer::setup()
{
    cam_buffer = create_buffer(2*sizeof(glm::mat4), true);

    transform trans;
    trans.base_tranform = glm::rotate(glm::identity<glm::mat4>(), 3.14159f/4.0f, glm::vec3(1.0f, 0.0f, 0.0f));
    trans.spacing = glm::vec3(0,0.01,0);
    transform_buffer = create_buffer(sizeof(trans));
    set_transform(trans);

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

void renderer::draw_planes()
{
    glDrawArrays(GL_TRIANGLES, 0, shell_num*2*3);
}

void renderer::update()
{
    glm::mat4 temp[2];
    temp[0] = cam.get_view();
    temp[1] = cam.get_projection();
    write_buffer(cam_buffer, temp, 2*sizeof(glm::mat4));
}

void renderer::set_transform(transform t)
{
    trans = t;
    write_buffer(transform_buffer, &trans, sizeof(trans));
}

const transform& renderer::get_transform() const
{
    return trans;
}