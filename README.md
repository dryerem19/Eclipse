# Eclipse
Eclipse is a small library for creating windowed applications using ImGui and GLFW

### Eclipse 
This example creates an ImGui window that is displayed on top of the desktop and we can work with it as well as with any other window of your OC

![image](https://user-images.githubusercontent.com/73961037/227783523-6862d6e3-75c2-4fd7-a351-c8c98c577689.png)

### API doc

Call this function to initialize glfw, glew and imgui
```cpp
void eclipseInit();
```

Call this function to start a new ImGui frame
```cpp
void eclipseBegin();
```

Call this function to end a ImGui frame
```cpp
void eclipseEnd();
```

Call this function to destroy glfw, glew and imgui
```cpp
void eclipseDestroy();
```

### Install
Clone the repository and build the library, then you can connect it to your project, you can also embed the project in the build chain of your CMake project

## License 
Eclipse is licensed under the MIT License, see [LICENSE](/LICENSE) for more information.
