#include <iostream>
#include <Windows.h>
#include "Menu.h"

int main()
{
    system("chcp 1251 > 0");
    COORD menuPos = { 2, 1 };
    Menu menu(menuPos);
    menu.add_item((char*)"Один");
    menu.add_item((char*)"Два");
    menu.add_item((char*)"Три Четыре Пять Шесть");
    menu.add_item((char*)"Семь Восемь");
    menu.set_color(0x0F, 0x0E);
    menu.draw_menu();
    while (1) {
        if ((GetKeyState(VK_UP) == -127) || (GetKeyState(VK_UP) == -128)) {
            menu.move_up();
            Sleep(150);
        }
        else if ((GetKeyState(VK_DOWN) == -127) || (GetKeyState(VK_DOWN) == -128)) {
            menu.move_down();
            Sleep(150);
        }
        else if ((GetKeyState(VK_RETURN) == -127) || (GetKeyState(VK_RETURN) == -128)) {
            menu.clear_screen();
            std::cout << "какой-то код\nномер выбранного пункта: " << menu.get_cursor_pos() << "\n";
            system("PAUSE");
            system("CLS");
            menu.draw_menu();
            menu.set_cursor(menu.get_cursor_pos());
            Sleep(150);
        }
    }
}