#include <cstdio>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "buffer.h"

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