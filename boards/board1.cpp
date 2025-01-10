#include <boards/board1.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include <string>

Board1::Board1()
{
    // const char *ch1 = "0123456789";
    input = std::string("012345678901234567890123456789");
};

void Board1::resize(const int &width, const int &height) {
};

void Board1::draw()
{
    char *items[] = {"1",
                     "2",
                     "3"};

    // ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    // ImGui::NewFrame();

    ImGui::BeginGroup();
    ImGui::Text("Some text %d, %f, %b, %s", currentItem, f, show_demo_window, input.c_str());
    ImGui::EndGroup();

    char *label = "label - 1";
    char *label2 = "label - 2";
    ImVec2 size(1000, 100);
    // ImGui::BeginListBox(label);
    ImGui::ListBox(label2, &currentItem, items, sizeof(items) / sizeof(char *));
    // ImGui::EndListBox();

    ImGui::BeginMainMenuBar();

    char *menuItem1 = "menu item 1";
    ImGui::MenuItem(menuItem1);

    char *menuLabel = "menu";
    // ImGui::BeginMenu(menuLabel);
    // ImGui::EndMenu();

    char *menuItem2 = "menu item 2";
    ImGui::MenuItem(menuItem2);

    ImGui::EndMainMenuBar();

    // char input[] = "0123456789";

    if (ImGui::SmallButton(menuLabel))
    {
        inputClicked = !inputClicked;
    }
    if (inputClicked)
    {
        ImGui::InputText("some text", (char *)input.c_str(), IM_ARRAYSIZE(input.c_str()));
        // ImGui::InputTextMultiline("ITEM: InputTextMultiline", input, inputSize);
    }

    ImGui::Checkbox("Demo Window", &show_demo_window);
    ImGui::SliderFloat("float", &f, 0.0f, 1.0f);

    int hovered_delay_none = 1;
    int hovered_delay_stationary = 2;
    int hovered_delay_short = 3;
    int hovered_delay_normal = 4;
    int hovered_delay_tooltip = 5;

    ImGui::BeginTable("split", 3, ImGuiTableFlags_None);
    ImGui::TableHeader("cols");
    ImGui::TableSetupColumn("col 1", ImGuiTableColumnFlags_WidthStretch); // Left side
    ImGui::TableSetupColumn("col 2", ImGuiTableColumnFlags_WidthFixed);   // Buttons
    ImGui::TableSetupColumn("col 3", ImGuiTableColumnFlags_WidthStretch); // Right side
    ImGui::TableHeadersRow();

    ImGui::TableNextRow();

    ImGui::TableSetColumnIndex(0);
    ImGui::Text("%s (%d)", "Available", IM_ARRAYSIZE(items));

    ImGui::TableSetColumnIndex(1);
    ImGui::Text("%s (%d)", "Available", IM_ARRAYSIZE(items));

    ImGui::TableSetColumnIndex(2);
    ImGui::Text("%s (%d)", "Available", IM_ARRAYSIZE(items));

    ImGui::EndTable();

    ImGui::Text("Double %f", d);
    ImGui::InputDouble("double", &d);
};