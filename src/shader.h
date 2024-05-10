#include "glad/glad.h"
#include <string>
#include <vector>

struct shader
{
    GLuint val;
    std::string code;
    GLenum type;

    bool compile();
};

struct shader_program
{
    GLuint val;
    std::vector<shader> shaders;

    bool link();
    bool validate();
    void add(shader new_shader);
};

shader create_shader(std::string path, GLenum type);
shader_program create_shader_program();