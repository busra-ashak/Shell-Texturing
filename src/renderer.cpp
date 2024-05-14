#include "renderer.h"
#include "buffer.h"

void renderer::draw_planes(unsigned int planeNum)
{
    glDrawArrays(GL_TRIANGLES, 0, planeNum*2*3);
}


void renderer::bind_vertex_buffer(GLuint buff)
{
    bind_buffer(buff, 0);
}