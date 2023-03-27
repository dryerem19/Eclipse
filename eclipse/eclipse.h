#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define IMGUI_IMPL_OPENGL_LOADER_GLEW
#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_glfw.h>
#include <imgui_internal.h>

/**
 * @brief Инициализация Eclipse
 * 
 * @return int 
 */
int eclipseInit();

/**
 * @brief Начать новый кадр ImGui
 * 
 */
void eclipseBegin();

/**
 * @brief Закончить кадр ImGui
 * 
 */
void eclipseEnd();

/**
 * @brief Уничтожить все ресурсы Eclipse (GLFW, ImGui)
 * 
 */
void eclipseDestroy();