#include "gui.hpp"

bool setupGLFW(GLFWwindow** window)
{
    if(!glfwInit())
    {
        logFatal("GLFW failed to init.");
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    float mainMonitorScale = ImGui_ImplGlfw_GetContentScaleForMonitor(glfwGetPrimaryMonitor());

    *window = glfwCreateWindow((int)(1280 * mainMonitorScale), (int)(800 * mainMonitorScale), "radicent", nullptr, nullptr);

    if(*window == nullptr)
    {
        logFatal("GLFW failed to create the window.");
        return false;
    }

    glfwMakeContextCurrent(*window);
    glfwSwapInterval(1);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        logFatal("Failed to initialize glad.");
        return false;
    }

    return true;
}

bool setupImGui(GLFWwindow** window)
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

    ImGui_ImplGlfw_InitForOpenGL(*window, true);
    ImGui_ImplOpenGL3_Init();

    return true;
}

void initGui(GLFWwindow** window)
{
    if(!setupGLFW(window))
    {
        logFatal("GLFW failed to set up.");
    }

    if(!setupImGui(window))
    {
        logFatal("ImGui failed to set up.");
    }
}

bool renderGui(GLFWwindow** window)
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();

    ImGui::NewFrame();

    ImGui::Begin("radicent text editor");

    ImGui::Text("this is the future application site of a text editor written entirely by my own hands.");

    ImGui::End();

    int displayWidth;
    int displayHeight;

    ImGui::Render();

    glfwGetFramebufferSize(*window, &displayWidth, &displayHeight);
    glViewport(0, 0, displayWidth, displayHeight);
    
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(*window);

    return true;
}

void cleanupGui(GLFWwindow** window)
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(*window);
    glfwTerminate();
}