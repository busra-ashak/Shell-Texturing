#include "renderer.h"
#include "glad/glad.h"

void renderer::draw_planes(unsigned int planeNum)
{
    glDrawArrays(GL_TRIANGLES, 0, planeNum*2*3);
}