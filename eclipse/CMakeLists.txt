cmake_minimum_required(VERSION 3.20)
project(Eclipse)

file(GLOB_RECURSE IMGUI_HEADERS 
	"${CMAKE_CURRENT_SOURCE_DIR}/external/imgui/*.h")
file(GLOB_RECURSE IMGUI_SOURCE "source/*.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/external/imgui/*.cpp")
set(IMGUI_FILES ${IMGUI_HEADERS} ${IMGUI_SOURCE})

# Создаем статическую библиотеку
add_library(${PROJECT_NAME} STATIC eclipse.h eclipse.cpp ${IMGUI_FILES})

# Добавляем директории с заголовочными файлами в проект
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Подключаем GLFW к проекту
find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw)

# Подключаем GLEW к проекту
find_package(GLEW REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC GLEW::GLEW)

# Подключаем Dear ImGui к проекту
#find_package(imgui CONFIG REQUIRED)
#target_link_libraries(${PROJECT_NAME} PUBLIC imgui::imgui)