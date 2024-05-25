#ifndef BUFFER_H
#define BUFFER_H
#include "glad/glad.h"

struct buffer {
    GLuint data;
    bool dynamic;
    void* dynamic_data = nullptr;
};

buffer create_buffer(unsigned int size, bool dynamic=false);
void destroy_buffer(buffer buff);
void write_buffer(buffer& buff, void* data, size_t size);
void bind_buffer(buffer buff, GLuint slot);

#endif