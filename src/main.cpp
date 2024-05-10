#include <cassert>
#include <cstdio>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "buffer.h"
#include "shader.h"

int main()
{

    int err = glfwInit();
    if(err == GLFW_FALSE)
    {
        return -2;
    }

    GLFWwindow* window = glfwCreateWindow(640, 480, "Grass", NULL, NULL);
    glfwMakeContextCurrent(window);

    int errGL = gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));
    if(errGL == 0)
    {
        return errGL;
    }

    shader vertex_shader = create_shader("./src/vertex_shader.glsl", GL_VERTEX_SHADER);
    shader fragment_shader = create_shader("./src/fragment_shader.glsl", GL_FRAGMENT_SHADER);

    bool success = true;

    success &= vertex_shader.compile();
    success &= fragment_shader.compile();

    shader_program program = create_shader_program();
    program.add(vertex_shader);
    program.add(fragment_shader);
    success &= program.link();
    success &= program.validate();
    if(!success) std::printf("fail");

    while(!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}