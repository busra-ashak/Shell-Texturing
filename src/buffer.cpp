#include "buffer.h"

GLuint create_buffer(unsigned int size)
{
    GLuint buff;
    glCreateBuffers(1, &buff);
    glNamedBufferData(buff, size, nullptr, GL_STATIC_DRAW);
    return buff;
}

void destroy_buffer(GLuint buff)
{
    glDeleteBuffers(1, &buff);
}
