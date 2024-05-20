#include "camera.h"
#include "GLFW/glfw3.h"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/matrix_transform.hpp"

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

void camera::handle_input(int key)
{
    constexpr float speed = 0.2f;
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
}