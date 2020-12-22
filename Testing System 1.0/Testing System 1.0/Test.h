#pragma once
#include "usable includes.h"

class test
{
public:

	unsigned int num_tests_; // size vector ( for save and load )

	// creation date of the test
	unsigned short int day_reg = 1;
	unsigned short int month_reg = 1;
	unsigned short int year_reg = 2000;
	//

	unsigned short int num_questions;
	// questions
	struct questions
	{
		char question[256]; // Question ( Вопрос )
		char answer[100]; // Answer ( Ответ )
	};

	char topic_test[51] = { };

	// Test registration date

	test();

	static void test_admin_menu();

	static void save_test_count(string path, test& obj); // Saving the number of tests ( Сохранение количества тестов )

	static void save_test_names(string path, test& obj); // Saving test topics ( Сохранение тем тестов )

	static void load_test_count(string path, test& obj); // Loading the number of tests ( Загрузка количества тестов )

	static void load_test_names(string path, vector<test>& obj); // Loading test themes ( Загрузка тем тестов )

	static void save_test(string path, test& obj);

	static string path_test_save(test& obj); // path to main test save
	static string path_num_test_math(); // Way to keep the number of tests in math ( Путь сохранение количества тестов по математике )
	static string path_test_names(); // The way to save the name of the math tests ( Путь сохранение название тестов по математике )

	~test();
};
