#pragma once
#pragma region include_alias
#include "usable includes.h"
#include "Admin.h"
#include "Test.h"
#pragma endregion

/* ENG
 * The Display class is intended for data input and output, user interaction with the program.
 *
 * RU
 * Класс Display предназначен для ввода и вывода данных, взаимодействия пользователя с программой.
 */

class display : public admin
{
public:
	display();
	// Methods(Методы)

	static void main_menu(char choose_); // Main Menu of Program(Главное меню программы)

	static void captcha(); // Check for captcha(Проверка на капчу)

	static void print_date(); // Display time in main menu(Вывод времени в гл.меню)

	static void welcome(); // screensaver welcome ( заставка добро пожаловать )

	static void print_time();

	static void display_exit(); // nice exit from the program ( красивый выход из программы )

	~display(); // Destructor(деструктор)
};
