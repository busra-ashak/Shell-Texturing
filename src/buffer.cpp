#include "buffer.h"
#include <cstring>

buffer create_buffer(unsigned int size, bool dynamic)
{
    buffer buff;
    buff.dynamic = dynamic;
    glCreateBuffers(1, &buff.data);
    if(!dynamic)
    {
        glNamedBufferData(buff.data, size, nullptr, GL_STATIC_DRAW);
    }
    else 
    {
        glNamedBufferStorage(buff.data, size, nullptr, GL_DYNAMIC_STORAGE_BIT | GL_MAP_READ_BIT | GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT);    
    }
    return buff;
}

void destroy_buffer(buffer buff)
{
    glDeleteBuffers(1, &buff.data);
}

void write_buffer(buffer buff, void* data, size_t size)
{
    if(!buff.dynamic)
    {
        void* ptr = glMapNamedBuffer(buff.data, GL_WRITE_ONLY);
        memcpy(ptr, data, size);
        glUnmapNamedBuffer(buff.data);
    }
    else 
    {
        if(buff.dynamic_data == nullptr)
        {
            buff.dynamic_data = glMapNamedBufferRange(buff.data, 0, size, GL_DYNAMIC_STORAGE_BIT | GL_MAP_READ_BIT | GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT);
        }
        memcpy(buff.dynamic_data, data, size);
    }
}

void bind_buffer(buffer buff, GLuint slot)
{
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, slot, buff.data);
}