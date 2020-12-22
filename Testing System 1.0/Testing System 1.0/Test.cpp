#include "Test.h"
#include <iomanip>

test::test()
{
	this->num_tests_ = 0;
	this->num_questions = 0;
	this->topic_test[0] = ' ';/*'U'; this->topic_test[1] = 'n'; this->topic_test[2] = 'k'; this->topic_test[3] = 'o'; this->topic_test[4] = 'w'; this->topic_test[5] = 'n';*/
}

void test::test_admin_menu()
{
	char move = '1';
	char choose = ' ';

	while (choose != '\x0D')
	{
		switch (move)
		{
		case '1':
		{
			system("cls");
			cout << "\n\033[97m  -------------------------"; cout << "   ----------------------\n";
			cout << " \033[93m |A|d|m|i|n| \033[31m|test| \033[93m|menu|"; cout << "   | \033[94mControl - \033[92mUp" << " \033[93m Down\033[93m |\n";
			cout << " \033[97m -------------------------" << "   ----------------------\n";
			cout << "  \033[97m----------------------------\n";
			cout << "  \033[97m| \033[104mCreate test\033[0m              \033[97m|\n";
			cout << "  \033[97m| \033[92mAssign a test to a user  \033[97m|\n";
			cout << "  \033[97m| \033[91mExit		     \033[97m|\n";
			cout << "  \033[97m----------------------------\n";
		}break;
		case '2':
		{
			system("cls");
			cout << "\n\033[97m  -------------------------"; cout << "   ----------------------\n";
			cout << " \033[93m |A|d|m|i|n| \033[31m|test| \033[93m|menu|"; cout << "   | \033[94mControl - \033[92mUp" << " \033[93m Down\033[93m |\n";
			cout << " \033[97m -------------------------" << "   ----------------------\n";
			cout << "  \033[97m----------------------------\n";
			cout << "  \033[97m| \033[92mCreate test              \033[97m|\n";
			cout << "  \033[97m| \033[104mAssign a test to a user\033[0m  \033[97m|\n";
			cout << "  \033[97m| \033[91mExit		     \033[97m|\n";
			cout << "  \033[97m----------------------------\n";
		}break;
		case '3':
		{
			system("cls");
			cout << "\n\033[97m  -------------------------"; cout << "   ----------------------\n";
			cout << " \033[93m |A|d|m|i|n| \033[31m|test| \033[93m|menu|"; cout << "   | \033[94mControl - \033[92mUp" << " \033[93m Down\033[93m |\n";
			cout << " \033[97m -------------------------" << "   ----------------------\n";
			cout << "  \033[97m----------------------------\n";
			cout << "  \033[97m| \033[92mCreate test              \033[97m|\n";
			cout << "  \033[97m| \033[92mAssign a test to a user  \033[97m|\n";
			cout << "  \033[97m| \033[101mExit\033[0m		     \033[97m|\n";
			cout << "  \033[97m----------------------------\n";
		}break;
		default:;
		}
		do {
			choose = _getch();
		} while (static_cast<int>(choose) != 80 && static_cast<int>(choose) != 72 && choose != '\x1b' && choose != '\x0D');

		if (static_cast<int>(choose) == 80 && move == '1')
		{
			move = '2';
		}
		else if (static_cast<int>(choose) == 80 && move == '2')
		{
			move = '3';
		}
		else if (static_cast<int>(choose) == 80 && move == '3')
		{
			move = '3';
		}
		else if (static_cast<int>(choose) == 72 && move == '3')
		{
			move = '2';
		}
		else if (static_cast<int>(choose) == 72 && move == '2')
		{
			move = '1';
		}
		else if (static_cast<int>(choose) == 72 && move == '1')
		{
			move = '1';
		}
	}

	switch (move)
	{
	case '1':
	{
		choose = ' ';
		while (choose != '\x0D')
		{
			switch (move)
			{
			case '1':
			{
				system("cls");
				cout << "\n \033[93m -----------------------------\n";
				cout << " \033[94m |C|r|e|a|t|i|n|g| \033[32m|T|e|s|t|s|\n";
				cout << " \033[93m -----------------------------\n";
				cout << " \033[93m     | \033[94mCREATE TEST:   \033[93m    |\n";
				cout << " \033[93m     ----------------------\n";
				cout << "      | \033[94mControl - \033[92mUp" << " \033[93m Down\033[93m |\n";
				cout << "\033[93m      ----------------------\n";
				cout << " \033[93m     | \033[104mMathematics\033[0m    \033[93m|\n";
				cout << " \033[93m     | \033[92mPhysics        \033[93m|\n";
				cout << " \033[93m     | \033[92mMechanics      \033[93m|\n";
				cout << " \033[93m     ------------------\n";
				cout << " \033[93m     | \033[91mExit           \033[93m|\n";
				cout << " \033[93m     ------------------";
			}break;
			case '2':
			{
				system("cls");
				cout << "\n \033[93m -----------------------------\n";
				cout << " \033[94m |C|r|e|a|t|i|n|g| \033[32m|T|e|s|t|s|\n";
				cout << " \033[93m -----------------------------\n";
				cout << " \033[93m     | \033[94mCREATE TEST:   \033[93m    |\n";
				cout << " \033[93m     ----------------------\n";
				cout << "      | \033[94mControl - \033[92mUp" << " \033[93m Down\033[93m |\n";
				cout << "\033[93m      ----------------------\n";
				cout << " \033[93m     | \033[92mMathematics    \033[93m|\n";
				cout << " \033[93m     | \033[104mPhysics\033[0m        \033[93m|\n";
				cout << " \033[93m     | \033[92mMechanics      \033[93m|\n";
				cout << " \033[93m     ------------------\n";
				cout << " \033[93m     | \033[91mExit           \033[93m|\n";
				cout << " \033[93m     ------------------";
			}break;
			case '3':
			{
				system("cls");
				cout << "\n \033[93m -----------------------------\n";
				cout << " \033[94m |C|r|e|a|t|i|n|g| \033[32m|T|e|s|t|s|\n";
				cout << " \033[93m -----------------------------\n";
				cout << " \033[93m     | \033[94mCREATE TEST:   \033[93m    |\n";
				cout << " \033[93m     ----------------------\n";
				cout << "      | \033[94mControl - \033[92mUp" << " \033[93m Down\033[93m |\n";
				cout << "\033[93m      ----------------------\n";
				cout << " \033[93m     | \033[92mMathematics\033[0m    \033[93m|\n";
				cout << " \033[93m     | \033[92mPhysics        \033[93m|\n";
				cout << " \033[93m     | \033[104mMechanics\033[0m      \033[93m|\n";
				cout << " \033[93m     ------------------\n";
				cout << " \033[93m     | \033[91mExit           \033[93m|\n";
				cout << " \033[93m     ------------------";
			}break;
			case '4':
			{
				system("cls");
				cout << "\n \033[93m -----------------------------\n";
				cout << " \033[94m |C|r|e|a|t|i|n|g| \033[32m|T|e|s|t|s|\n";
				cout << " \033[93m -----------------------------\n";
				cout << " \033[93m     | \033[94mCREATE TEST:   \033[93m    |\n";
				cout << " \033[93m     ----------------------\n";
				cout << "      | \033[94mControl - \033[92mUp" << " \033[93m Down\033[93m |\n";
				cout << "\033[93m      ----------------------\n";
				cout << " \033[93m     | \033[92mMathematics\033[0m    \033[93m|\n";
				cout << " \033[93m     | \033[92mPhysics        \033[93m|\n";
				cout << " \033[93m     | \033[92mMechanics      \033[93m|\n";
				cout << " \033[93m     ------------------\n";
				cout << " \033[93m     | \033[101mExit\033[0m           \033[93m|\n";
				cout << " \033[93m     ------------------";
			}break;
			default:;
			}
			do {
				choose = _getch();
			} while (static_cast<int>(choose) != 80 && static_cast<int>(choose) != 72 && choose != '\x1b' && choose != '\x0D');

			if (static_cast<int>(choose) == 80 && move == '1')
			{
				move = '2';
			}
			else if (static_cast<int>(choose) == 80 && move == '2')
			{
				move = '3';
			}
			else if (static_cast<int>(choose) == 80 && move == '3')
			{
				move = '4';
			}
			else if (static_cast<int>(choose) == 80 && move == '4')
			{
				move = '4';
			}
			else if (static_cast<int>(choose) == 72 && move == '4')
			{
				move = '3';
			}
			else if (static_cast<int>(choose) == 72 && move == '3')
			{
				move = '2';
			}
			else if (static_cast<int>(choose) == 72 && move == '2')
			{
				move = '1';
			}
			else if (static_cast<int>(choose) == 72 && move == '1')
			{
				move = '1';
			}
		}
		switch (move)
		{
		case '1': // Mathematics
		{
			test obj;

			load_test_count(path_num_test_math(), obj);

			vector<test> tests_names(obj.num_tests_);

			if (obj.num_tests_ > 0)
			{
				load_test_names(path_test_names(), tests_names);
			}

		EnterTopicName:
			//  Enter the name of the math test topic ( Вводим название темы теста по математике )

			system("cls");
			cout << "\033[" << YELLOW << "m--------------------------------\n";
			cout << "\033[" << BLUE << "m| Creating | a \033[" << BrightRed << "m| math | \033[" << BLUE << "m| test |\n";
			cout << "\033[" << YELLOW << "m--------------------------------\n";
			cout << "\033[" << YELLOW << "m| \033[" << BrightYellow << "mEnter a topic name:\033[" << WHITE << "m ";
				
			int i;
			char a; // a Temp char

			for (i = 0;;) // infinite loop
			{		
				a = _getch(); // stores char typed in a

				if (a == '\x1b') // exit to ch. menu
				{
					return;
				}

				if (a >= 'a' && a <= 'z' || (a >= 'A' && a <= 'Z') || a >= '0' && a <= '9' || a == ' ')
					//check if a is numeric or alphabet
				{
					obj.topic_test[i] = a; //stores a in pass
					++i;
					cout << a;
				}
				if (a == '\b' && i >= 1) // if user typed backspace
				{
					cout << "\b \b"; // rub the character behind the cursor.
					--i;
				}
				if (a == '\r' && strlen(obj.topic_test)>5) // if enter is pressed
				{
					obj.topic_test[i] = '\0'; // null means end of string.
					break; // break the loop
				}
				if (strlen(obj.topic_test) == 50)
				{
					system("cls");
					cout << "\033["<< WHITE << "m---------------------------------------------------------------------";
					cout << "\n| \033[" << BrightGreen << "mTopic\033[" << WHITE << "m: \033[" << BrightYellow << "m" << obj.topic_test << setw(61-strlen(obj.topic_test)) << " \033[" << WHITE << "m|\n";
					cout << "\033[" << WHITE << "m---------------------------------------------------------------------";
					cout << "\n|\033[" << CYAN << "m You entered the maximum number of characters \033[" << WHITE << "m|";
					cout << "\n------------------------------------------------";
					cout << "\n| 1. \033[" << GREEN << "mConfirm the current topic \033[" << WHITE << "m|";
					cout << "\n--------------------------------";
					cout << "\n| 2. \033[" << YELLOW << "mEnter a different topic   \033[" << WHITE << "m|";
					cout << "\n--------------------------------";
					do { a = _getch(); } while (a != '1' && a != '2');
					if (a == '2')
					{
						int tmp;
						tmp = strlen(obj.topic_test);
						for (int s = 0; s < tmp; s++)
						{
							obj.topic_test[s] = '\0';
						}
						goto EnterTopicName;
					}
					else
					{
						break;
					}
				}
			}
				
			cout << "Enter the number of questions:";


			
			SYSTEMTIME t;
			GetLocalTime(&t);

			obj.num_tests_++;
			obj.day_reg = t.wDay;
			obj.month_reg = t.wMonth;
			obj.year_reg = t.wYear;

			// Save the name, number of tests
			save_test_count(path_num_test_math(), obj);
			save_test_names(path_test_names(), obj);
			//

			save_test(path_test_save(obj), obj);
		}break;
		case '2': // Physics
		{
		}break;
		case'3': // Mechanics
		{
		}break;
		case'4': // Exit
		{
			return;
		}
		default:;
		}
	}break;
	case '2':
	{
	}break;
	case '3':
	{
		return;
	}

	default:;
	}
}

void test::save_test_count(const string path, test& obj)
{
	ofstream save_count(path, ios::trunc);
	if (save_count.is_open())
	{
		save_count << obj.num_tests_;
	}
	save_count.close();
}

void test::save_test_names(const string path, test& obj)
{
	ofstream file_;
	file_.open(path, ios::binary | ios::app);
	file_.clear();
	if (file_.is_open())
	{
		file_ << obj.topic_test << endl;
	}
	file_.close();
}

void test::load_test_count(const string path, test& obj)
{
	ifstream load_num_tests;
	load_num_tests.open(path);
	if (load_num_tests.is_open())
	{
		load_num_tests >> obj.num_tests_;
	}
	load_num_tests.close();
}

void test::load_test_names(const string path, vector<test>& obj)
{
	ifstream file;
	file.open(path);
	if (file.is_open())
	{
		for (int i = 0; i < size(obj); i++)
		{
			file >> obj[i].topic_test;
		}
	}
	file.close();
}

void test::save_test(string path, test& obj)
{
	ofstream s_test;
	s_test.open(path, ios::trunc);
	if (s_test.is_open())
	{
		s_test << obj.topic_test << endl << obj.day_reg << endl << obj.month_reg << endl << obj.year_reg << endl;
	}
	s_test.close();
}

string test::path_test_save(test& obj)
{
	char buffer[256]; // buffer for GetUserName
	DWORD size_buf; // size username
	size_buf = sizeof(buffer); // size buffer
	GetUserName(buffer, &size_buf);
	char path[256] = { "C:\\Users\\" };
	strcat(path, buffer);
	strcat(path, R"(\Documents\Testing System\Tests\Tests Math\)");
	strcat(path, obj.topic_test);
	strcat(path, ".txt");
	return path;
}

string test::path_num_test_math()
{
	char buffer[256]; // buffer for GetUserName
	DWORD size_buf; // size username
	size_buf = sizeof(buffer); // size buffer
	GetUserName(buffer, &size_buf);
	char path[100] = { "C:\\Users\\" };
	strcat(path, buffer);
	strcat(path, R"(\Documents\Testing System\Tests\Tests Math\number of tests_mathematics.txt)");
	return path;
}

string test::path_test_names()
{
	char buffer[256]; // buffer for GetUserName
	DWORD size_buf; // size username
	size_buf = sizeof(buffer); // size buffer
	GetUserName(buffer, &size_buf);
	char path[100] = { "C:\\Users\\" };
	strcat(path, buffer);
	strcat(path, R"(\Documents\Testing System\Tests\Tests Math\test names.txt)");
	return path;
}

test::~test()
{
}