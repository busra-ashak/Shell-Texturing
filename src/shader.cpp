#include "shader.h"
#include <cstdio>
#include <fstream>
#include <sstream>

bool shader::compile()
{
    glCompileShader(val);
    GLint success ;
    glGetShaderiv(val, GL_COMPILE_STATUS, &success);
    if(success!=GL_TRUE)
    {
        std::string log;
        log.resize(1024);
        GLsizei size = log.size();
        glGetShaderInfoLog(val,size,&size,log.data());
        std::printf(log.data());
    }
    return success;
}

bool shader_program::link()
{
    glLinkProgram(val);
    GLint success ;
    glGetProgramiv(val, GL_LINK_STATUS, &success);
    if(success!=GL_TRUE)
    {
        std::string log;
        log.resize(1024);
        GLsizei size = log.size();
        glGetProgramInfoLog(val,size,&size,log.data());
        std::printf(log.data());
    }
    return success;
}

bool shader_program::validate()
{
    glValidateProgram(val);
    GLint success ;
    glGetProgramiv(val, GL_VALIDATE_STATUS, &success);
    if(success!=GL_TRUE)
    {
        std::string log;
        log.resize(1024);
        GLsizei size = log.size();
        glGetProgramInfoLog(val,size,&size,log.data());
        std::printf(log.data());
    }
    return success;
}

void shader_program::add(shader new_shader)
{
    glAttachShader(val, new_shader.val);
    shaders.push_back(new_shader);
}

shader create_shader(std::string path, GLenum type)
{
    GLuint val = glCreateShader(type);
    std::ifstream t(path);
    std::stringstream buffer;
    buffer << t.rdbuf();
    std::string code = buffer.str();
    const char* data = code.data();
    const int size = code.size();
    glShaderSource(val, 1, &data, &size);
    shader new_shader = {val,code,type};
    return new_shader;
}

shader_program create_shader_program()
{
    GLuint program = glCreateProgram();
    std::vector<shader> shaders;
    shader_program new_shader_program = {program,shaders};
    return new_shader_program;
}