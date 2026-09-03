//header files (should not include any std headers, only ones I made.)
#include "io.hpp"
#include "log.hpp"
#include "gui.hpp"

int main(int argc, char* argv[])
{
    GLFWwindow* window;

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

        ImGui::EndFrame();
    }

    return 0;
}