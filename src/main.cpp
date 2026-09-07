//header files (should not include any std headers, only ones I made.)
#include "io.hpp"
#include "log.hpp"
#include "gui.hpp"

//global vars for working directory and whatnot.
static std::string workingDirectory;

//modifier keys for keycallback
static bool ctrlPressed = false;

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        cleanupGui(&window);
    }

    #pragma region "Control Modifiers"
    if((key == GLFW_KEY_LEFT_CONTROL || key == GLFW_KEY_RIGHT_CONTROL) && action == GLFW_PRESS)
    {
        ctrlPressed = true;
    }

    if(key == GLFW_KEY_S && action == GLFW_PRESS && ctrlPressed)
    {
        logVerbose("saved file");
        writeToFile("placeholder", workingDirectory);
    }

    if(!(key == GLFW_KEY_LEFT_CONTROL || key == GLFW_KEY_RIGHT_CONTROL) && action != GLFW_PRESS)
    {
        ctrlPressed = false;
    }
}

int main(int argc, char* argv[])
{
    GLFWwindow* window = nullptr;

    initGui(&window);

    glfwSetKeyCallback(window, keyCallback);

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        if(glfwGetWindowAttrib(window, GLFW_ICONIFIED) != 0)
        {
            ImGui_ImplGlfw_Sleep(10);
            continue;
        }

        renderGui(&window);
    }

    cleanupGui(&window);

    return 0;
}