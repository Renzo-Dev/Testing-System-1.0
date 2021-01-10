#include "Display.h"
#include <chrono>
#include <iomanip>

SYSTEMTIME gt; // for get local time

display::display()
= default;

void display::main_menu(char choose_)
{
	welcome();
StartProgram:
	do {
		choose_ = ' ';
		system("cls");
		print_date();
		print_time();
		cout << "\n\t\t\t\t\033[93m -----------------------------------";
		cout << "\n\t\t\t\t |\t\033[97m|\033[92mM\033[97m|\033[92ma\033[97m|\033[92mi\033[97m|\033[92mn\033[97m| \033[97m|\033[93mM\033[97m\033[97m|\033[93me\033[97m|\033[93mn\033[97m|\033[93mu\033[97m|\t   \033[93m|";
		cout << "\n\t\t\t\t\033[93m -----------------------------------";
		cout << "\n\t\t\t\t\033[93m | \033[97m|1| \033[33mSign in.\033[0m\t\t\t  \033[93m |";
		cout << "\n\t\t\t\t\033[93m -----------------------------------";
		cout << "\n\t\t\t\t\033[93m | \033[97m|2| \033[92mSign up.\t\t\t  \033[93m |";
		cout << "\n\t\t\t\t\033[93m -----------------------------------";
		cout << "\n\t\t\t\t\033[93m | \033[97m|3| \033[94mLogin as Admin.\t\t  \033[93m |";
		cout << "\n\t\t\t\t\033[93m -----------------------------------";
		cout << "\n\t\t\t\t\033[93m | \033[97m|0| \033[31mExit\t\t\t  \033[93m |";
		cout << "\n\t\t\t\t\033[93m -----------------------------------";

		if (_kbhit())
		{
			choose_ = _getch();
		}
		Sleep(300);
	} while (choose_ != '1' && choose_ != '2' && choose_ != '3' && choose_ != '0');

	switch (choose_)
	{
	case '1':
	{
		sign_in();
		goto StartProgram;
	}
	case '2':
	{
		sign_up();
		goto StartProgram;
	}
	case '3':
	{
		admin Admin;
		if (Admin.join_admin() != 1)
		{
			goto StartProgram;
		}
		else
			system("cls");
		cout << "\n\t\033[93m------------------------------------\n\t\033[93m|\033[92mYou are logged in as administrator\033[93m|\n\t\033[93m------------------------------------";
		Sleep(1000);
		system("cls");
		cout << "\n\n\t\t\033[93m------------------------------------\n\t\t\033[93m|\033[92mYou are logged in as administrator\033[93m|\n\t\t\033[93m------------------------------------";
		Sleep(1000);
		system("cls");
		cout << "\n\n\n\t\t\t\033[93m------------------------------------\n\t\t\t\033[93m|\033[92mYou are logged in as administrator\033[93m|\n\t\t\t\033[93m------------------------------------";
		Sleep(1000);

	AdminMenu:
		system("cls");
		cout << "\n\033[93m        |\033[94mA\033[93m|\033[94md\033[93m|\033[94mm\033[94m\033[93m|\033[94mi\033[93m|\033[94mn\033[93m| \033[93m|\033[91mM\033[93m|\033[91me\033[93m|\033[91mn\033[93m|\033[91mu\033[93m|\n";
		cout << "\n\033[94m -----------------------------------";
		cout << "\n\033[93m | \033[97m|1| \033[94mAdmin Profile Settings.\033[0m\t  \033[93m |";
		cout << "\n\033[94m -----------------------------------";
		cout << "\n\033[93m | \033[97m|2| \033[92mUsers profiles.\t\t  \033[93m |";
		cout << "\n\033[94m -----------------------------------";
		cout << "\n\033[93m | \033[97m|3| \033[96mStatistics.\t\t  \033[93m |";
		cout << "\n\033[94m -----------------------------------";
		cout << "\n\033[93m | \033[97m|4| \033[93mTests.\t\t\t  \033[93m |";
		cout << "\n\033[94m -----------------------------------";
		cout << "\n\033[93m | \033[97m|9| \033[91mSign out of account.\t  \033[93m |";
		cout << "\n\033[94m -----------------------------------";
		cout << "\n\033[93m | \033[97m|0| \033[31mExit\t\t\t  \033[93m |";
		cout << "\n\033[94m -----------------------------------";
		do
		{
			choose_ = _getch();
		} while (choose_ != '1' && choose_ != '2' && choose_ != '3' && choose_ != '4' && choose_ != '5' && choose_ != '9' && choose_ != '0');

		switch (choose_)
		{
		case '1':
		{
			switch (choose_)
			{
			case '1':
			{
				system("cls");
				cout << "\n\033[91m |A|d|m|i|n|\033[0m \033[94m|P|r|o|f|i|l|e|\033[0m \033[91m|S|e|t|t|i|n|g|s|\033[0m\n";
				cout << "\n\033[94m -----------------------------------";
				cout << "\n\033[93m | \033[97m|1| \033[36mShow info about Admin.\033[0m\t  \033[93m |";
				cout << "\n\033[94m -----------------------------------";
				cout << "\n\033[93m | \033[97m|2| \033[36mChange login from Admin.\t  \033[93m |";
				cout << "\n\033[94m -----------------------------------";
				cout << "\n\033[93m | \033[97m|3| \033[36mChange admin password.\t  \033[93m |";
				cout << "\n\033[94m -----------------------------------";
				cout << "\n\033[93m | \033[97m|4| \033[36mChange recovery key.\t  \033[93m |";
				cout << "\n\033[94m -----------------------------------";
				cout << "\n\033[93m | \033[97m|5| \033[36mReset settings.\t\t  \033[93m |";
				cout << "\n\033[94m -----------------------------------";
				cout << "\n\033[93m | \033[97m|9| \033[91mBack to Admin menu.\t  \033[93m |";
				cout << "\n\033[94m -----------------------------------";
				do
				{
					choose_ = _getch();
				} while (choose_ != '1' && choose_ != '2' && choose_ != '3' && choose_ != '4' && choose_ != '5' && choose_ != '9');
				switch (choose_)
				{
				case '1':
				{
					load_date_admin(Admin);
					show_admin_details(Admin); goto AdminMenu;
				}break;
				case '2':
				{
					change_admin_login(Admin);
					cout << "\n \033[92m--------------------------\n";
					cout << " | \033[93mLogin has been changed \033[92m|\n";
					cout << " --------------------------\n";
					cout << " \033[92m---------------------------------\n";
					cout << " \033[33m| Press any button, to continue \033[33m|\n";
					cout << " \033[92m---------------------------------";
					_getch();
					goto AdminMenu;
				}
				case '3':
				{
					change_admin_password(Admin);
					cout << "\n \033[92m-----------------------------\n";
					cout << " | \033[93mPassword has been changed \033[92m|\n";
					cout << " -----------------------------\n";
					cout << " \033[92m---------------------------------\n";
					cout << " \033[33m| Press any button, to continue \033[33m|\n";
					cout << " \033[92m---------------------------------";
					_getch();
					goto AdminMenu;
				}
				case'4':
				{
					change_recovery_key(Admin);
					cout << "\n \033[92m---------------------------------\n";
					cout << " | \033[93mRecovery key has been changed \033[92m|\n";
					cout << " ---------------------------------\n";
					cout << " \033[92m---------------------------------\n";
					cout << " \033[33m| Press any button, to continue \033[33m|\n";
					cout << " \033[92m---------------------------------";
					_getch();
					goto AdminMenu;
				}
				case '5':
				{
					Admin.reset_settings();
					system("cls");
					goto AdminMenu;
				}break;
				case '9':
				{
					goto AdminMenu;
				}

				default:system("cls");
					cout << "\x1B[31m Error, please restart program! "; //
				}
			}break;
			default:system("cls");
				cout << "\x1B[31m Error, please restart program! "; //
			}
		}break;
		case '2':
		{
			load_num_users(Admin);
			system("cls");
			cout << "\n\033[91m   |U|s|e|r|s|\033[0m \033[94m|P|r|o|f|i|l|e|s|\033[0m\n";
			cout << "\n\033[93m | \033[95mNumber of users \033[93m[ \033[97m" << Admin.num_users_ << " \033[93m]";
			cout << "\n\033[94m -----------------------------------";
			cout << "\n\033[93m | \033[97m|1| \033[36mAdd user.\033[0m\t\t  \033[93m |";
			cout << "\n\033[94m -----------------------------------";
			cout << "\n\033[93m | \033[97m|2| \033[36mShow all users.\t\t  \033[93m |";
			cout << "\n\033[94m -----------------------------------";
			cout << "\n\033[93m | \033[97m|3| \033[36mFind user.\t\t  \033[93m |";
			cout << "\n\033[94m -----------------------------------";
			cout << "\n\033[93m | \033[97m|4| \033[36mEdit user profile.\t  \033[93m |";
			cout << "\n\033[94m -----------------------------------";
			cout << "\n\033[93m | \033[97m|5| \033[36mRemove user(s).\t\t  \033[93m |";
			cout << "\n\033[94m -----------------------------------";
			cout << "\n\033[93m | \033[97m|6| \033[36mBackup users data.\t  \033[93m |";
			cout << "\n\033[94m -----------------------------------";
			cout << "\n\033[93m | \033[97m|9| \033[91mBack to Admin menu.\t  \033[93m |";
			cout << "\n\033[94m -----------------------------------";
			do
			{
				choose_ = _getch();
			} while (choose_ != '1' && choose_ != '2' && choose_ != '3' && choose_ != '4' && choose_ != '5' && choose_ != '6' && choose_ != '9');

			switch (choose_)
			{
			case '1':
			{
				sign_up();
				goto AdminMenu;
			}
			case '2':
			{
				system("cls");
				show_users();
				goto AdminMenu;
			}
			case '3':
			{
				find_user();
				goto AdminMenu;
			}
			case '4':
			{
				user_prof_change_menu();
				goto AdminMenu;
			}
			case '5':
			{
				system("cls");
				remove_user_s();
				goto AdminMenu;
			}
			case '6':
			{
				system("cls");
				backup_users_date();
				goto AdminMenu;
			}
			case '9':
			{
				goto AdminMenu;
			}
			default:system("cls");
				cout << "\x1B[31m Error, please restart program! "; //
			}
		}break;
		case '3':
		{
			stats::show_users_stats_adm();
			goto AdminMenu;
		}
		case '4':
		{
			system("cls");
			cout << "\n \033[90m-------------------\n";
			cout << "\033[93m |T|E|S|T| \033[92m|M|e|n|u|\n";
			cout << " \033[90m-------------------\n\n";
			cout << " \033[90m-----------------------------------\n";
			cout << " \033[90m| \033[97m|1| \033[93mAssigning tests to the user \033[90m|\n";
			cout << " \033[90m-----------------------------------\n";
			cout << " \033[90m| \033[97m|2| \033[93mSetting up tests\t\t   \033[90m|\n";
			cout << " \033[90m-----------------------------------\n";
			cout << " \033[90m| \033[97m|esc| \033[91mto Admin Menu \033[90m|\n";
			cout << " \033[90m-----------------------\n";

			do
			{
				choose_ = _getch();
			} while (choose_ != '1' && choose_ != '2' && choose_ != '\x1b');

			if (choose_ == '\x1b') // exit to ch. menu
			{
				goto AdminMenu;
			}

			switch (choose_)
			{
			case '1':
			{
				test::test_admin_menu();
				goto AdminMenu;
			}break;
			case '2':
			{
			}break;
			default:;
			}

			goto AdminMenu;
		}
		case '9':
		{
			goto StartProgram;
		}break;
		case'0':
		{
			display_exit();
		}break;
		default:system("cls");
			cout << "\x1B[31m Error, please restart program! "; //
		}
		break; }
	//
	case '0':
	{
		display_exit();
	}
	break;

	default: system("cls");
		cout << "\x1B[31m Error, please restart program! "; //
	}
}

void display::captcha()
{
	unsigned int b, c, c1;
	auto a = b = c = c1 = 0;
	char tmp;
	auto chance = 3; // Три попытки
captcha:
	srand(time(NULL));
	a = 2 + rand() % 20;
	b = 2 + rand() % 20;
	c1 = a + b;

	system("cls");
	cout << "\x1B[31m------------------------------\n\n";
	cout << "\x1B[94m_______     Captcha     ______\t\x1B[92m |\x1B[96m Количество попыток \x1B[95m" << chance << "\n\n\n";
	cout << "\x1B[33m Сумма чисел " << a << " + " << b << " = \n\n";
	cout << "\x1B[34m Введите правильный ответ:\033[33m "; cin >> c;
	cout << "\x1B[31m------------------------------\n";
	if (chance != 0)
	{
		if (c1 == c) {}
		else
		{
			chance--;
			cout << "\n\x1B[32m| \x1B[91mCaptcha failed! Repeat one more time!\x1B[34m(\x1B[32my\x1B[34m / \x1B[31many button\x1B[34m):  \x1B[0m"; tmp = _getch(); if (tmp == 'y' || tmp == 'Y') { goto captcha; }
			else { display_exit(); }
		}
	}
	else
	{
		{
			system("cls"); cout << "\n\n\x1B[31m Капча не пройдена! Попыток больше нет! Попробуйте позже!\n\n Нажмите любую кнопку для выхода!\033[0m "; _getch(); display_exit();
		}
	}
}

void display::print_date()
{
	GetLocalTime(&gt);

	if (gt.wDay <= 10 && gt.wMonth <= 10)
	{
		cout << "\t\t\t\t  \033[97m--------------\033[93mDATE\033[97m---------------\n";
		cout << "\t\t\t\t  \033[97m|\x1B[92m  Day: \033[97m" << gt.wDay << "\x1B[92m Month: \033[97m" << gt.wMonth << "\x1B[92m Year: \033[97m" << gt.wYear << "\033[97m  |";
		cout << "\n\t\t\t\t  \033[97m---------------------------------";
	}
	else if (gt.wDay >= 10 && gt.wMonth >= 10)
	{
		cout << "\t\t\t\t  \033[97m--------------\033[93mDATE\033[97m----------------\n";
		cout << "\t\t\t\t  \033[97m|\x1B[92m  Day: \033[97m" << gt.wDay << "\x1B[92m Month: \033[97m" << gt.wMonth << "\x1B[92m Year: \033[97m" << gt.wYear << "\033[97m  |";
		cout << "\n\t\t\t\t  \033[97m----------------------------------";
	}
	else if (gt.wDay >= 10 && gt.wMonth <= 10)
	{
		cout << "\t\t\t\t  \033[97m--------------\033[93mDATE\033[97m---------------\n";
		cout << "\t\t\t\t  \033[97m|\x1B[92m  Day: \033[97m" << gt.wDay << "\x1B[92m Month: \033[97m" << gt.wMonth << "\x1B[92m Year: \033[97m" << gt.wYear << "\033[97m  |";
		cout << "\n\t\t\t\t  \033[97m---------------------------------";
	}
	else if (gt.wDay <= 10 && gt.wMonth >= 10)
	{
		cout << "\t\t\t\t  \033[97m--------------\033[93mDATE\033[97m---------------\n";
		cout << "\t\t\t\t  \033[97m|\x1B[92m  Day: \033[97m" << gt.wDay << "\x1B[92m Month: \033[97m" << gt.wMonth << "\x1B[92m Year: \033[97m" << gt.wYear << "\033[97m  |";
		cout << "\n\t\t\t\t  \033[97m---------------------------------";
	}
}

void display::welcome()
{
	system("cls");

	cout << "\t\t\t\t\x1B[31m+-+-+-+-+-+-+-++-+-++-+-+-+-+-+-+-++-+-+-+-+-+-+-+\033[0m\n\t\t\t\t\x1B[31m|\033[0m\t\t\t\t\t\t \x1B[31m|\033[0m\n";
	cout << "\t\t\t\t\x1B[31m|\033[0m\t  \x1B[33m| W | e | l | c | o | m | e |\033[31m\t\t \x1B[31m|\033[0m\n\t\t\t\t\x1B[31m|\033[0m \t\t      \x1B[33m| t o |\033[31m\t\t\t \x1B[31m|\033[0m";
	cout << "\n\t\t\t\t\x1B[31m|\033[0m\t \x1B[33m| T e s t i n g  P r o g r a m |\033[31m\t \x1B[31m|\033[0m";
	cout << "\n\t\t\t\t\x1B[31m|\033[0m\t\t\t\t\t\t \x1B[31m|";
	cout << "\n\t\t\t\t\x1B[31m+-+-+-+-+-+-+-++-+-++-+-+-+-+-+-+-++-+-+-+-+-+-+-+\n\n\n";
	cout << "\t\t\t\t\t\t\033[94m  Developer: \033[97mRenzo\033[0m\n\n";
	Sleep(2500);
}

void display::print_time()
{
	cout << "\n\t\t\t\t    " << setw(14) << "TIME: " << gt.wHour << ":" << gt.wMinute << ":" << gt.wSecond;
}

void display::display_exit()
{
	system("cls");
	cout << "\x1B[31m Exit program !!\n\n";
	cout << "\t\x1B[31m Выход из программы !!\n\n";
	cout << "\t\t\x1B[31m Exit program !!\n\n";
	cout << "\t\t\t\x1B[31m Выход из программы !!\n\n";
	Sleep(1500);
	cout << "\x1B[0m";
	exit(0);
}

display::~display() {}