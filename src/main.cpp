#include <cstdio>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

int main()
{

    int err = glfwInit();
    if(err==GLFW_FALSE)
    {
        return -2;
    }

    GLFWwindow* window = glfwCreateWindow(640, 480, "Grass", NULL, NULL);
    while(!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }    
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}