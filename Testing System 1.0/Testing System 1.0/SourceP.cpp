#include "Display.h"
#include "usable includes.h"
#pragma warning ( disable : 6031)

int main()
{
	try
	{
		
#pragma region Setting program
	setlocale(LC_ALL, "RUS"); // Setting the program language

	// Removes blinking caret (cursor)
	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo); // get cursor information for handle and structCursorInfo
	structCursorInfo.bVisible = FALSE; // Set visibility to false
	SetConsoleCursorInfo(handle, &structCursorInfo);

#pragma endregion
#pragma region directory(s)
	char buffer[256]; // buffer for GetUserName
	DWORD size; // size username
	size = sizeof(buffer); // size buffer

	GetUserName(buffer, &size);
	char dir_pr_save[100] = { "C:\\Users\\" };
	strcat(dir_pr_save, buffer);
	strcat(dir_pr_save, "\\Documents\\Testing System"); // Directory of all saves ( Директория всех сохранений )
	CreateDirectory(dir_pr_save, nullptr);

	char dir_admin_save[100] = { "C:\\Users\\" };
	strcat(dir_admin_save, buffer);
	strcat(dir_admin_save, R"(\Documents\Testing System\AdminDate)"); // Admin data ( Данные Администратора )
	CreateDirectory(dir_admin_save, nullptr);

	char dir_tests_save[100] = { "C:\\Users\\" };
	strcat(dir_tests_save, buffer);
	strcat(dir_tests_save, R"(\Documents\Testing System\Tests)"); // the location of all saved tests ( расположение всех сохраненных тестов )
	CreateDirectory(dir_tests_save, nullptr);

	char dir_tests_save_math[100] = { "C:\\Users\\" };
	strcat(dir_tests_save_math, buffer);
	strcat(dir_tests_save_math, R"(\Documents\Testing System\Tests\Tests Math)"); // location of all math tests ( расположение всех тестов по математике )
	CreateDirectory(dir_tests_save_math, nullptr);

	char dir_tests_save_physics[100] = { "C:\\Users\\" };
	strcat(dir_tests_save_physics, buffer);
	strcat(dir_tests_save_physics, R"(\Documents\Testing System\Tests\Test Physics)"); // location of all physics tests ( расположение всех тестов по физике )
	CreateDirectory(dir_tests_save_physics, nullptr);

	char dir_tests_save_mechanics[100] = { "C:\\Users\\" };
	strcat(dir_tests_save_mechanics, buffer);
	strcat(dir_tests_save_mechanics, R"(\Documents\Testing System\Tests\Test Mechanics)"); // location of all tests on mechanics ( расположение всех тестов по механике )
	CreateDirectory(dir_tests_save_mechanics, nullptr);

	char dir_user_save[100] = { "C:\\Users\\" };
	strcat(dir_user_save, buffer);
	strcat(dir_user_save, R"(\Documents\Testing System\UserDate)"); // User data ( Данные пользователей )
	CreateDirectory(dir_user_save, nullptr);

#pragma endregion
	char choose = ' '; // for choose in program menu
	display::main_menu(choose);
	}
	catch (...)
	{
		return 0;
	}
	return 0;
}