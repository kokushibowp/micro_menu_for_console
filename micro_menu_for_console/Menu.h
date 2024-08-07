#pragma once
#include <list>
#include <Windows.h>

// this class is a reworking of the example from https://www.cyberforum.ru/cpp-beginners/thread223822.html
class Menu {
private:
	std::list<char*> items;
	unsigned int countItems;
	unsigned int latestCursorPos;
	HANDLE gout;
	WORD defaultColor = 0x0F;
	WORD selectedColor = 0x1F;                        
	COORD menuCoords = { 0 };
	bool isDrawed = 0;
public:
	Menu(COORD coords); 
	Menu();
	//Menu(const Menu& other);                              like the rule of five
	//Menu& operator=(const Menu& other);                   
	//Menu(const Menu&& other);                             
	//Menu& operator=(const Menu&& other);                  
	//~Menu();

	void add_item(char* itemName);                   //     add an item to the menu, after all items have been added, call draw_menu()
	void del_item(int numItem);                      //     after each call of del_item() function it is necessary to redraw the menu by consecutive calls of clear_screen() and draw_menu().
	void set_cursor(int numItem);
	void draw_menu();
	void clear_screen();
	void move_up();
	void move_down();
	void set_color(WORD dColor, WORD sColor);
	unsigned int get_cursor_pos();
	void menu_processor(bool (*f)(Menu* menu));
	void set_menu_pos(COORD xy);
	COORD get_menu_pos();
};