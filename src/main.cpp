//header files (should not include any std headers, only ones I made.)
#include "io.hpp"
#include "log.hpp"
#include "gui.hpp"

//global vars for working directory and whatnot.
static std::string inputPath;
static std::string outputPath;

//modifier keys for keycallback
static bool ctrlPressed = false;

struct IOData
{
    std::string input;
    std::string output;
};

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }

    #pragma region "Control Key Modifiers"
    if((key == GLFW_KEY_LEFT_CONTROL || key == GLFW_KEY_RIGHT_CONTROL) && action == GLFW_PRESS)
    {
        ctrlPressed = true;
    }

    if(!(key == GLFW_KEY_LEFT_CONTROL || key == GLFW_KEY_RIGHT_CONTROL) && action != GLFW_PRESS)
    {
        ctrlPressed = false;
    }
    #pragma endregion
}

int main(int argc, char* argv[])
{ 
    IOData data = processCLI(argc, argv);

    inputPath = data.input;
    outputPath = data.output;

    GLFWwindow* window = nullptr;

    initGui(&window);

    glfwSetKeyCallback(window, keyCallback);

    while(!glfwWindowShouldClose(window))
    {
        if(glfwGetWindowAttrib(window, GLFW_ICONIFIED) != 0)
        {
            ImGui_ImplGlfw_Sleep(10);
            continue;
        }

        renderGui(&window, inputPath);

        glfwPollEvents();
    }

    cleanupGui(&window);

    return 0;
}