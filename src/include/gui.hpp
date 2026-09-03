#pragma once

#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "log.hpp"

bool setupGLFW();

bool setupImGui();

void initGui(GLFWwindow** window);
