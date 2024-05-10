#include "glad/glad.h"

GLuint create_buffer(unsigned int size);
void destroy_buffer(GLuint buff);
void write_buffer(GLuint buff, void* data, size_t size);
void bind_buffer(GLuint buff, GLuint slot);