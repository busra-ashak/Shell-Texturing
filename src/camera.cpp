#include "camera.h"
#include "renderer.h"
#include "GLFW/glfw3.h"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/matrix_transform.hpp"
#include <algorithm>

glm::mat4 camera::get_view()
{
    glm::mat4 translation_matrix = glm::translate(glm::identity<glm::mat4>(), position);
    glm::mat4 rotation_matrix = glm::mat4(1.0f); // Identity matrix
    rotation_matrix = glm::rotate(rotation_matrix, rotation.x, glm::vec3(1, 0, 0)); // Rotate around X axis (Pitch)
    rotation_matrix = glm::rotate(rotation_matrix, rotation.y, glm::vec3(0, 1, 0)); // Rotate around Y axis (Yaw)
    rotation_matrix = glm::rotate(rotation_matrix, rotation.z, glm::vec3(0, 0, 1)); // Rotate around Z axis (Roll)
    return glm::inverse(rotation_matrix*translation_matrix);
}

glm::mat4 camera::get_projection()
{
    return glm::perspective(fov, aspect_ratio, near_clip, far_clip);
}

void camera::handle_input(int key, renderer& rend)
{
    constexpr float speed = 0.1f;
        if(key == GLFW_KEY_W)
        {
            position += glm::vec3(0.0f, 0.0f, -speed);
        }
        else if(key == GLFW_KEY_S)
        {
            position += glm::vec3(0.0f, 0.0f, speed);
        }
        else if(key == GLFW_KEY_A)
        {
            position += glm::vec3(-speed, 0.0f, 0.0f);
        }
        else if(key == GLFW_KEY_D)
        {
            position += glm::vec3(speed, 0.0f, 0.0f);
        }
        else if(key == GLFW_KEY_SPACE)
        {
            position += glm::vec3(0.0f, speed, 0.0f);
        }
        else if(key == GLFW_KEY_LEFT_SHIFT)
        {
            position += glm::vec3(0.0f, -speed, 0.0f);
        }
        else if(key == GLFW_KEY_Z)
        {
            rend.shell_num = std::min((unsigned int) 12, rend.shell_num+1);
        }
        else if(key == GLFW_KEY_X)
        {
            rend.shell_num = std::max((unsigned int) 1, rend.shell_num-1);
        }
        else if(key == GLFW_KEY_C)
        {
            transform current_transform = rend.get_transform();
            current_transform.spacing = glm::vec3(0.0, std::min(0.03f, current_transform.spacing.y + 0.005f), 0.0f);
            rend.set_transform(current_transform);
        }
        else if(key == GLFW_KEY_V)
        {
            transform current_transform = rend.get_transform();
            current_transform.spacing = glm::vec3(0.0, std::max(0.0f, current_transform.spacing.y - 0.005f), 0.0f);
            rend.set_transform(current_transform);
        }
}

void camera::handle_mouse_events(double xpos, double ypos, bool mouse_pressed)
{
    static double old_xpos = xpos, old_ypos = ypos;
    double delta_x = xpos-old_xpos, delta_y = ypos-old_ypos;
    if(mouse_pressed) 
    {
        rotation.y -= delta_x*0.001;        
        rotation.x -= delta_y*0.001;
    }
    old_xpos = xpos;
    old_ypos = ypos;
}