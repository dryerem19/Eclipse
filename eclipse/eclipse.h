#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define IMGUI_IMPL_OPENGL_LOADER_GLEW
#include <external/imgui/imgui.h>
#include <external/imgui/imgui_impl_opengl3.h>
#include <external/imgui/imgui_impl_glfw.h>
#include <external/imgui/imgui_internal.h>

namespace Eclipse {

	/**
	 * @brief Инициализация Eclipse
	 *
	 * @return int
	 */
	int Init();

	/**
	 * @brief Начать новый кадр ImGui
	 *
	 */
	void Begin();

	/**
	 * @brief Закончить кадр ImGui
	 *
	 */
	void End();

	GLFWwindow* GetGLFWindow();

	/**
	 * @brief Windows can be iconified (i.e. minimized)
	 */
	void setIconify();

	/**
	 * @brief Windows can be maximized
	 */
	void setMaximized();

	/*
	* @brief Iconified windows can be restored 
	*/
	void restoreIconify();

	/*
	* @brief You can also get the current iconification state
	*/
	bool isIconified();

	/*
	* @brief You can also get the current maximized state
	*/
	bool isMaximized();

	/**
	 * @brief Уничтожить все ресурсы Eclipse (GLFW, ImGui)
	 *
	 */
	void Destroy();
}