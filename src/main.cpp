#include <cstdio>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "shader.h"
#include "renderer.h"
#include "glm/glm.hpp"

renderer rend;
bool mouse_pressed = false;

void key_callback(GLFWwindow* wnd, int key, int scancode, int action, int mods)
{
    rend.cam.handle_input(key, rend);
}
void mouse_callback(GLFWwindow* wnd, double xpos, double ypos)
{
    rend.cam.handle_mouse_events(xpos, ypos, mouse_pressed);
}
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) mouse_pressed = true;
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) mouse_pressed = false;    
}

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
    glViewport(0,0,640,480);
    rend.setup();

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

    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);

    while(!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0,0.8,1,1);
        rend.update();
        rend.draw_planes();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}