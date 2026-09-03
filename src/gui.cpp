#include "gui.hpp"

bool setupGLFW(GLFWwindow* window)
{
    if(!glfwInit())
    {
        logFatal("GLFW failed to init.");
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    float mainMonitorScale = ImGui_ImplGlfw_GetContentScaleForMonitor(glfwGetPrimaryMonitor());

    window = glfwCreateWindow((int)(1280 * mainMonitorScale), (int)(800 * mainMonitorScale), "radicent", nullptr, nullptr);

    if(window == nullptr)
    {
        logFatal("GLFW failed to create the window.");
        return false;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    return true;
}

bool setupImGui(GLFWwindow* window)
{
    IMGUI_CHECKVERSION();

    if(!ImGui::CreateContext())
    {
        logFatal("Failed to create the imgui context.");
        return false;
    }

    ImGuiIO& io = ImGui::GetIO(); (void) io;

    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init();

    return true;
}

void initGui(GLFWwindow** window)
{
    if(!setupGLFW(*window))
    {
        logFatal("GLFW failed to set up.");
    }

    if(!setupImGui(*window))
    {
        logFatal("ImGui failed to set up.");
    }
}