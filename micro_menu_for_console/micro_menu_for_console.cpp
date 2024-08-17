#include <iostream>
#include <Windows.h>
#include "Menu.h"

bool menuproc(Menu* menu);

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

    menu.menu_processor(&menuproc);
}

bool menuproc(Menu* menu) {
    menu->clear_screen();
    std::cout << "какой-то код\nномер выбранного пункта: " << menu->get_cursor_pos() << "\n";
    bool a;
    std::cin >> a;
    system("CLS");
    menu->draw_menu();
    return a;
}