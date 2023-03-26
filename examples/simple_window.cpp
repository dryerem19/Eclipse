#include <eclipse.h>

int main()
{
    if (!eclipseInit()) {
        return -1;
    }

    bool running = true;
    while (running)
    {
        eclipseBegin();
        {
            ImGui::ShowDemoWindow(&running);
        }
        eclipseEnd();
    }

    eclipseDestroy();
}