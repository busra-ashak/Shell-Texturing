#ifndef CAMERA_H
#define CAMERA_H
#include "glm/glm.hpp"
struct renderer;
struct camera
{
    glm::vec3 position{0.0,0.0,0.75};
    glm::vec3 rotation{0.0,0.0,0.0}; //euler angles
    float fov;
    float aspect_ratio;
    float near_clip;
    float far_clip;

    glm::mat4 get_view();
    glm::mat4 get_projection();
    void handle_input(int key, renderer& rend);
    void handle_mouse_events(double xpos, double ypos, bool mouse_pressed);
};

#endif