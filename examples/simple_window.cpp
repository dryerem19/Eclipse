#include <eclipse.h>
#include <iostream>

int main()
{
    if (!Eclipse::Init()) {
        return -1;
    }

    bool first = true;
    bool second = true;

    while (first || second)
    {
        Eclipse::Begin();
        {
            if (first)
            {
                ImGui::Begin("Iconify window", &first);
                {
                    if (ImGui::Button("Iconify")) {
                        Eclipse::setIconify();
                    }
                }
                ImGui::End();
            }

            if (second)
            {
                ImGui::ShowDemoWindow(&second);
            }
        }
        Eclipse::End();
    }

    Eclipse::Destroy();
}