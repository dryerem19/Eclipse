#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define IMGUI_IMPL_OPENGL_LOADER_GLEW
#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_glfw.h>
#include <imgui_internal.h>

GLFWwindow* g_pWindow = nullptr;

int eclipseInit()
{
    // Инициализация GLFW
    if (!glfwInit()) {
        return -1;
    }

    // Выбор версии OpenGL и профиля
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Скрыть окно при создании
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

    // Создание окна GLFW
    g_pWindow = glfwCreateWindow(1, 1, "Eclipse", nullptr, nullptr);
    if (!g_pWindow) {
        glfwTerminate();
        return -1;
    }

    // Скрытие окна GLFW
    glfwHideWindow(g_pWindow);

    // Создание контекста OpenGL
    glfwMakeContextCurrent(g_pWindow);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    //Инициализация GLEW
    if (glewInit() != GLEW_OK) {
        glfwTerminate();
        return -1;
    }

    // Инициализируем ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();

    // Включение поддержки multi viewports
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

    // Включение поддержки DPI scaling для viewports
    io.ConfigFlags |= ImGuiConfigFlags_DpiEnableScaleViewports;

    // Включение поддержки докирования
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    // Включение поддержки навигации с помощью клавиатуры
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; 

    if (!ImGui_ImplGlfw_InitForOpenGL(g_pWindow, true)) {
        glfwTerminate();
        return -1;
    }
    
    if (!ImGui_ImplOpenGL3_Init("#version 330 core")) {
        glfwTerminate();
        return -1;
    }
    
    // Настраиваем ImGui style
    ImGui::StyleColorsDark();

    return 1;
}

void eclipseBegin()
{
    // Очищаем буфер кадра
    glClear(GL_COLOR_BUFFER_BIT);

    // Обработка событий окна
    glfwPollEvents();

    // Начало нового кадра ImGui
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void eclipseEnd()
{
    ImGuiIO& io = ImGui::GetIO();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    //Завершение кадра и обновление платформенных окон (если используется поддержка viewports)
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
        GLFWwindow* backup_current_context = glfwGetCurrentContext();
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
        glfwMakeContextCurrent(backup_current_context);
    }

    // Отображение кадра
    glfwSwapBuffers(g_pWindow);
}


void eclipseDestroy()
{
    // Освобождение ресурсов ImGui и GLFW
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwTerminate();
}