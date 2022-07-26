//
// Created by William Aey on 7/24/2022.
//

#pragma once


//Glad must be included before glfw
#include <glad/glad.h>
struct GLFWwindow;
#include <string>

class glfwWindow {
public:
    virtual ~glfwWindow();
    void InitGlfwAndGlad();
    GLFWwindow *GetWindow();
    void processInput();
    [[nodiscard]] static glfwWindow *CreateWindow(const char *title, int width, int height);

private:
    explicit glfwWindow(const char *title, int width, int height);
    struct windowAtrributes {
        std::string title;
        int width;
        int height;
    };

    windowAtrributes m_windowProps;
    GLFWwindow *m_window;

private:
    static void framebuffer_size_callback(GLFWwindow *window, int width, int height);
    static glfwWindow *s_instance;
};
