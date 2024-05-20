#include "glm/glm.hpp"

struct camera
{
    glm::vec3 position{0.0,0.0,5.0};
    glm::vec3 rotation{0.0,0.0,0.0}; //euler angles
    float fov;
    float aspect_ratio;
    float near_clip;
    float far_clip;

    glm::mat4 get_view();
    glm::mat4 get_projection();
};