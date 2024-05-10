#include "buffer.h"
#include <cstring>

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

void write_buffer(GLuint buff, void* data, size_t size)
{
    void* ptr = glMapNamedBuffer(buff, GL_WRITE_ONLY);
    memcpy(ptr, data, size);
    glUnmapNamedBuffer(buff);
}

void bind_buffer(GLuint buff, GLuint slot)
{
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, slot, buff);
}