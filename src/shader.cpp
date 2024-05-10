#include "shader.h"
#include <fstream>
#include <sstream>

bool shader::compile()
{
    return false;
}

bool shader_program::link()
{
    return false;
}

bool shader_program::validate()
{
    return false;
}

void shader_program::add(shader new_shader)
{
    shader_program::shaders.push_back(new_shader);
}

shader create_shader(std::string path, GLenum type)
{
    GLuint val = glCreateShader(type);
    std::ifstream t(path);
    std::stringstream buffer;
    buffer << t.rdbuf();
    bool good = t.good();
    std::string code = buffer.str();
    const char* data = code.data();
    const int size = code.size();
    glShaderSource(val, 1, &data, &size);
    shader new_shader = {val, code, type};
    return new_shader;
}