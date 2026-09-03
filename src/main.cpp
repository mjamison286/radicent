//header files (should not include any std headers, only ones I made.)
#include "io.hpp"
#include "log.hpp"
#include "gui.hpp"

int main(int argc, char* argv[])
{
    GLFWwindow* window = nullptr;

    initGui(&window);

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        if(glfwGetWindowAttrib(window, GLFW_ICONIFIED) != 0)
        {
            ImGui_ImplGlfw_Sleep(10);
            continue;
        }

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();

        ImGui::NewFrame();

        ImGui::Begin("radicent text editor");

        ImGui::Text("this is the future application site of a text editor written entirely by my own hands.");

        ImGui::End();

        renderGui(&window);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}