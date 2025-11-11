#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));
    int width = 800;
    int height = 600;


    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(width, height, "GLFW Window", nullptr, nullptr);
    if(!window){
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
     }
    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glViewport(0, 0, width, height);

    float vertices[] = {
        // positions         // colors
         0.5f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // top right
         0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,  // bottom left
        -0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 0.0f   // top left 
    };

    unsigned  int VAO, VBO;

    while(!glfwWindowShouldClose(window)){
        processInput(window);

        
        glClearColor(0.0f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();


    return 0;
}