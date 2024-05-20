#include <cstdio>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "shader.h"
#include "renderer.h"
#include "glm/glm.hpp"

int main()
{

    int err = glfwInit();
    if(err == GLFW_FALSE)
    {
        return -2;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(640, 480, "Grass", NULL, NULL);
    glfwMakeContextCurrent(window);

    int errGL = gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));
    if(errGL == 0)
    {
        return errGL;
    }

    shader vertex_shader = create_shader("./src/vertex_shader.glsl", GL_VERTEX_SHADER);
    shader fragment_shader = create_shader("./src/fragment_shader.glsl", GL_FRAGMENT_SHADER);
    shader_program program = create_shader_program();

    bool success = true;

    success &= vertex_shader.compile();
    success &= fragment_shader.compile();
    program.add(vertex_shader);
    program.add(fragment_shader);
    success &= program.link();
    success &= program.validate();

    if(!success) std::printf("failed");

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glUseProgram(program.val);
    renderer rend;
    std::vector<glm::vec4> triangles({
        glm::vec4(-0.5, -0.5, 0.0, 0), glm::vec4(0.5, -0.5, 0.0, 0), glm::vec4(-0.5f, 0.5, 0.0, 0),
        glm::vec4(-0.5f, 0.5, 0.0, 0), glm::vec4(0.5, -0.5, 0.0, 0), glm::vec4(0.5, 0.5, 0.0, 0)
    });
    
    size_t size = sizeof(glm::vec4)*triangles.size();
    buffer buff = create_buffer(sizeof(glm::vec4)*triangles.size());
    write_buffer(buff, triangles.data(), size);
    rend.bind_vertex_buffer(buff);

    while(!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        rend.update();
        rend.draw_planes(4);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}