#include "Stats.h"

#include <algorithm>
#include <iomanip>

stats::stats() = default;

void stats::show_users_stats(const string & username)
{
	system("cls");
	char choose;

	system("cls");
	cout << "\t\t\033[94m-------------------------------\n";
	cout << "\t\t\033[97m|S|t|a|t|i|s|t|i|c|s| |m|e|n|u|\n";
	cout << "\t\t\033[94m-------------------------------\n";
	cout << "\t\t\033[33m -----------------------------\n";
	cout << "\t\t\033[33m |\033[97m |1| \033[92mShow top in math\033[33m      |\n";
	cout << "\t\t\033[33m -----------------------------\n";
	cout << "\t\t\033[33m |\033[97m |2| \033[94mShow top in physics\033[33m   |\n";
	cout << "\t\t\033[33m -----------------------------\n";
	cout << "\t\t\033[33m |\033[97m |3| \033[96mShow top on mechanics\033[33m |\n";
	cout << "\t\t\033[33m -----------------------------\n";
	cout << "\t\t\033[31m | \033[97m|esc|\033[91m Exit\033[31m\t\t     |\n";
	cout << "\t\t\033[33m -----------------------------\n\t\t";

	do
	{
		choose = _getch();
	} while (choose != '1' && choose != '2' && choose != '3' && choose != '\x1b');

	if (choose == '\x1b') // exit to ch. menu
	{
		return;
	}
	Users_ obj;
	Users_::load_num_users(obj);	
	const int size_vec = obj.num_users_;

	switch (choose)
	{
		
	case '1': {
		vector<Users_> users(size_vec);
		Users_::load_users(users);

		// SORT

		for (int i = 0; i < size(users) - 1; i++) {
			for (int j = 0; j < size(users) - i - 1; j++) {
				if (users[j].points_math < users[j + 1].points_math) {
					// меняем элементы местами
					obj = users[j];
					users[j] = users[j + 1];
					users[j + 1] = obj;
				}
			}
		}

		cout << "\x1B[42m";
		system("cls");

		int set_sp;
		cout << "\033[96m\t\t\tTOP ON MATH\n";
		cout << "\033[97m-----------------------------------------------------------------\n";
		cout << "\033[97m|TOP|\t\t      FULL NAME   \t\t|     SCORE\t|\n";
		cout << "\033[97m-----------------------------------------------------------------\n";
		for (int i = 0; i < size_vec; i++)
		{
			if (username == users[i].login_)
			{
				cout << "\033[97m| " << i + 1; i - 1;
				cout << " | \033[46m" << users[i].user_name_ << " " << users[i].user_family_name_ << " " << users[i].user_patronymic_ << "\033[42m";

				set_sp = strlen(users[i].user_name_) + strlen(users[i].user_family_name_) + strlen(users[i].user_patronymic_);

				cout << setw(41 - set_sp) << "|";

				cout << "      " << users[i].points_math;

				if (users[i].points_math < 10) { cout << "\t|\n"; }
				else if (users[i].points_math > 10 && users[i].points_math < 100) { cout << "\t|\n"; }
				else if (users[i].points_math > 100 && users[i].points_math < 1000) { cout << "\t|\n"; }
				else if (users[i].points_math == 1000) { cout << "\t|\n"; }
			}
			else {
				cout << "\033[97m| " << i + 1; i - 1;
				cout << " | " << users[i].user_name_ << " " << users[i].user_family_name_ << " " << users[i].user_patronymic_;

				set_sp = strlen(users[i].user_name_) + strlen(users[i].user_family_name_) + strlen(users[i].user_patronymic_);

				cout << setw(41 - set_sp) << "|";

				cout << "      " << users[i].points_math;

				if (users[i].points_math < 10) { cout << "\t|\n"; }
				else if (users[i].points_math > 10 && users[i].points_math < 100) { cout << "\t|\n"; }
				else if (users[i].points_math > 100 && users[i].points_math < 1000) { cout << "\t|\n"; }
				else if (users[i].points_math == 1000) { cout << "\t|\n"; }
			}
		}

		cout << "\033[97m-----------------------------------------------------------------\n";
		cout << "\033[97m| Press \033[91mesc\033[97m, to go to the user menu |\n";
		cout << "\033[97m-------------------------------------\n\033[0m";
		char a;
		for (int j = 0;;) // infinite loop
		{
			a = _getch(); // stores char typed in a

			if (a == '\x1b') // exit to ch. menu
			{
				break;
			}
		}
	}break;
	case '2':
	{
		vector<Users_> users(size_vec);
		Users_::load_users(users);

		// SORT

		for (int i = 0; i < size(users) - 1; i++) {
			for (int j = 0; j < size(users) - i - 1; j++) {
				if (users[j].physics_points < users[j + 1].physics_points) {
					// меняем элементы местами
					obj = users[j];
					users[j] = users[j + 1];
					users[j + 1] = obj;
				}
			}
		}

		cout << "\x1B[44m";
		system("cls");

		int set_sp;
		cout << "\033[96m\t\t\tTOP ON PHYSICS\n";
		cout << "\033[97m-----------------------------------------------------------------\n";
		cout << "\033[97m|TOP|\t\t      FULL NAME   \t\t|     SCORE\t|\n";
		cout << "\033[97m-----------------------------------------------------------------\n";
		for (int i = 0; i < size_vec; i++)
		{
			if (username == users[i].login_)
			{
				cout << "\033[97m| " << i + 1; i - 1;
				cout << " | \033[46m" << users[i].user_name_ << " " << users[i].user_family_name_ << " " << users[i].user_patronymic_ << "\033[44m";

				set_sp = strlen(users[i].user_name_) + strlen(users[i].user_family_name_) + strlen(users[i].user_patronymic_);

				cout << setw(41 - set_sp) << "|";

				cout << "      " << users[i].physics_points;

				if (users[i].physics_points < 10) { cout << "\t|\n"; }
				else if (users[i].physics_points > 10 && users[i].physics_points < 100) { cout << "\t|\n"; }
				else if (users[i].physics_points > 100 && users[i].physics_points < 1000) { cout << "\t|\n"; }
				else if (users[i].physics_points == 1000) { cout << "\t|\n"; }

			}
			else {
				cout << "\033[97m| " << i + 1; i - 1;
				cout << " | " << users[i].user_name_ << " " << users[i].user_family_name_ << " " << users[i].user_patronymic_;

				set_sp = strlen(users[i].user_name_) + strlen(users[i].user_family_name_) + strlen(users[i].user_patronymic_);

				cout << setw(41 - set_sp) << "|";

				cout << "      " << users[i].physics_points;

				if (users[i].physics_points < 10) { cout << "\t|\n"; }
				else if (users[i].physics_points > 10 && users[i].physics_points < 100) { cout << "\t|\n"; }
				else if (users[i].physics_points > 100 && users[i].physics_points < 1000) { cout << "\t|\n"; }
				else if (users[i].physics_points == 1000) { cout << "\t|\n"; }

			}
		}

		cout << "\033[97m-----------------------------------------------------------------\n";
		cout << "\033[97m| Press \033[91mesc\033[97m, to go to the user menu |\n";
		cout << "\033[97m-------------------------------------\n\033[0m";
		char a;
		for (int j = 0;;) // infinite loop
		{
			a = _getch(); // stores char typed in a

			if (a == '\x1b') // exit to ch. menu
			{
				break;
			}
		}
	}break;
	case '3':
	{
		vector<Users_> users(size_vec);
		Users_::load_users(users);

		// SORT

		for (int i = 0; i < size(users) - 1; i++) {
			for (int j = 0; j < size(users) - i - 1; j++) {
				if (users[j].points_mechanics < users[j + 1].points_mechanics) {
					// меняем элементы местами
					obj = users[j];
					users[j] = users[j + 1];
					users[j + 1] = obj;
				}
			}
		}

		cout << "\x1B[46m";
		system("cls");

		int set_sp;
		cout << "\033[96m\t\t\tTOP ON MECHANICS\n";
		cout << "\033[97m-----------------------------------------------------------------\n";
		cout << "\033[97m|TOP|\t\t      FULL NAME   \t\t|     SCORE\t|\n";
		cout << "\033[97m-----------------------------------------------------------------\n";
		for (int i = 0; i < size_vec; i++)
		{
			if (username == users[i].login_)
			{
				cout << "\033[97m| " << i + 1; i - 1;
				cout << " | \033[104m" << users[i].user_name_ << " " << users[i].user_family_name_ << " " << users[i].user_patronymic_ << "\033[46m";

				set_sp = strlen(users[i].user_name_) + strlen(users[i].user_family_name_) + strlen(users[i].user_patronymic_);

				cout << setw(41 - set_sp) << "|";

				cout << "      " << users[i].points_mechanics;

				if (users[i].points_mechanics < 10) { cout << "\t|\n"; }
				else if (users[i].points_mechanics > 10 && users[i].points_mechanics < 100) { cout << "\t|\n"; }
				else if (users[i].points_mechanics > 100 && users[i].points_mechanics < 1000) { cout << "\t|\n"; }
				else if (users[i].points_mechanics == 1000) { cout << "\t|\n"; }

			}
			else {
				cout << "\033[97m| " << i + 1; i - 1;
				cout << " | " << users[i].user_name_ << " " << users[i].user_family_name_ << " " << users[i].user_patronymic_;

				set_sp = strlen(users[i].user_name_) + strlen(users[i].user_family_name_) + strlen(users[i].user_patronymic_);

				cout << setw(41 - set_sp) << "|";

				cout << "      " << users[i].points_mechanics;

				if (users[i].points_mechanics < 10) { cout << "\t|\n"; }
				else if (users[i].points_mechanics > 10 && users[i].points_mechanics < 100) { cout << "\t|\n"; }
				else if (users[i].points_mechanics > 100 && users[i].points_mechanics < 1000) { cout << "\t|\n"; }
				else if (users[i].points_mechanics == 1000) { cout << "\t|\n"; }

			}
		}

		cout << "\033[97m-----------------------------------------------------------------\n";
		cout << "\033[97m| Press \033[91mesc\033[97m, to go to the user menu |\n";
		cout << "\033[97m-------------------------------------\n\033[0m";
		char a;
		for (int j = 0;;) // infinite loop
		{
			a = _getch(); // stores char typed in a

			if (a == '\x1b') // exit to ch. menu
			{
				break;
			}
		}
	}break;

	default:;
	}
}

void stats::show_users_stats_adm()
{
	system("cls");
	char choose;

	system("cls");
	cout << "\t\t\033[94m-------------------------------\n";
	cout << "\t\t\033[97m|S|t|a|t|i|s|t|i|c|s| |m|e|n|u|\n";
	cout << "\t\t\033[94m-------------------------------\n";
	cout << "\t\t\033[33m -----------------------------\n";
	cout << "\t\t\033[33m |\033[97m |1| \033[92mShow top in math\033[33m      |\n";
	cout << "\t\t\033[33m -----------------------------\n";
	cout << "\t\t\033[33m |\033[97m |2| \033[94mShow top in physics\033[33m   |\n";
	cout << "\t\t\033[33m -----------------------------\n";
	cout << "\t\t\033[33m |\033[97m |3| \033[96mShow top on mechanics\033[33m |\n";
	cout << "\t\t\033[33m -----------------------------\n";
	cout << "\t\t\033[31m | \033[97m|esc|\033[91m Exit\033[31m\t\t     |\n";
	cout << "\t\t\033[33m -----------------------------\n\t\t";

	do
	{
		choose = _getch();
	} while (choose != '1' && choose != '2' && choose != '3' && choose != '\x1b');
	
	if (choose == '\x1b') // exit to ch. menu
	{
		return;
	}

	Users_ obj;
	Users_::load_num_users(obj);

	if (obj.num_users_ < 1)
	{
		system("cls");
		cout << "\033[" << BrightYellow << "m\n\n  -----------------------";
		cout << "\033[" << BrightYellow << "m\n  | \033[" << BrightRed << "mNo registered users \033[" << BrightYellow << "m|";
		cout << "\033[" << BrightYellow << "m\n  -----------------------";
		cout << "\033[" << BrightYellow << "m\n  | \033[" << BrightGreen << "mPress any button \033[" << BrightYellow << "m|";
		cout << "\033[" << BrightYellow << "m\n  --------------------";
		_getch();
		return;
	}

	const int size_vec = obj.num_users_;

	switch (choose)
	{
	case '1': {
		vector<Users_> users(size_vec);
		Users_::load_users(users);

		// SORT

		for (int i = 0; i < size(users) - 1; i++) {
			for (int j = 0; j < size(users) - i - 1; j++) {
				if (users[j].points_math < users[j + 1].points_math) {
					// меняем элементы местами
					obj = users[j];
					users[j] = users[j + 1];
					users[j + 1] = obj;
				}
			}
		}

		cout << "\x1B[42m";
		system("cls");

		int set_sp;
		cout << "\033[96m\t\t\tTOP ON MATH\n";
		cout << "\033[97m-----------------------------------------------------------------\n";
		cout << "\033[97m|TOP|\t\t      FULL NAME   \t\t|     SCORE\t|\n";
		cout << "\033[97m-----------------------------------------------------------------\n";
		for (int i = 0; i < size_vec; i++)
		{
			cout << "\033[97m| " << i + 1; i - 1;
			cout << " | " << users[i].user_name_ << " " << users[i].user_family_name_ << " " << users[i].user_patronymic_;

			set_sp = strlen(users[i].user_name_) + strlen(users[i].user_family_name_) + strlen(users[i].user_patronymic_);

			cout << setw(41 - set_sp) << "|";

			cout << "      " << users[i].points_math;

			if (users[i].points_math < 10) { cout << "\t|\n"; }
			else if (users[i].points_math > 10 && users[i].points_math < 100) { cout << "\t|\n"; }
			else if (users[i].points_math > 100 && users[i].points_math < 1000) { cout << "\t|\n"; }
			else if (users[i].points_math == 1000) { cout << "\t|\n"; }
		}




			
		cout << "\033[97m-----------------------------------------------------------------\n";
		cout << "\033[97m| Press \033[91mesc\033[97m, to go to the admin menu |\n";
		cout << "\033[97m--------------------------------------\n\033[0m";
		char a;
		for (int j = 0;;) // infinite loop
		{
			a = _getch(); // stores char typed in a

			if (a == '\x1b') // exit to ch. menu
			{
				break;
			}
		}
	}break;
	case '2':
	{
		vector<Users_> users(size_vec);
		Users_::load_users(users);

		// SORT

		for (int i = 0; i < size(users) - 1; i++) {
			for (int j = 0; j < size(users) - i - 1; j++) {
				if (users[j].physics_points < users[j + 1].physics_points) {
					// меняем элементы местами
					obj = users[j];
					users[j] = users[j + 1];
					users[j + 1] = obj;
				}
			}
		}

		cout << "\x1B[44m";
		system("cls");

		int set_sp;
		cout << "\033[96m\t\t\tTOP ON PHYSICS\n";
		cout << "\033[97m-----------------------------------------------------------------\n";
		cout << "\033[97m|TOP|\t\t      FULL NAME   \t\t|     SCORE\t|\n";
		cout << "\033[97m-----------------------------------------------------------------\n";
		for (int i = 0; i < size_vec; i++)
		{
			cout << "\033[97m| " << i + 1; i - 1;
			cout << " | " << users[i].user_name_ << " " << users[i].user_family_name_ << " " << users[i].user_patronymic_;

			set_sp = strlen(users[i].user_name_) + strlen(users[i].user_family_name_) + strlen(users[i].user_patronymic_);

			cout << setw(41 - set_sp) << "|";

			cout << "      " << users[i].physics_points;

			if (users[i].physics_points < 10) { cout << "\t|\n"; }
			else if (users[i].physics_points > 10 && users[i].physics_points < 100) { cout << "\t|\n"; }
			else if (users[i].physics_points > 100 && users[i].physics_points < 1000) { cout << "\t|\n"; }
			else if (users[i].physics_points == 1000) { cout << "\t|\n"; }
		}

		cout << "\033[97m-----------------------------------------------------------------\n";
		cout << "\033[97m| Press \033[91mesc\033[97m, to go to the admin menu |\n";
		cout << "\033[97m--------------------------------------\n\033[0m";
		char a;
		for (int j = 0;;) // infinite loop
		{
			a = _getch(); // stores char typed in a

			if (a == '\x1b') // exit to ch. menu
			{
				break;
			}
		}
	}break;
	case '3':
	{

		vector<Users_> users(size_vec);
		Users_::load_users(users);

		// SORT

		for (int i = 0; i < size(users) - 1; i++) {
			for (int j = 0; j < size(users) - i - 1; j++) {
				if (users[j].points_mechanics < users[j + 1].points_mechanics) {
					// меняем элементы местами
					obj = users[j];
					users[j] = users[j + 1];
					users[j + 1] = obj;
				}
			}
		}

		cout << "\x1B[46m";
		system("cls");

		int set_sp;
		cout << "\033[96m\t\t\tTOP ON MECHANICS\n";
		cout << "\033[97m-----------------------------------------------------------------\n";
		cout << "\033[97m|TOP|\t\t      FULL NAME   \t\t|     SCORE\t|\n";
		cout << "\033[97m-----------------------------------------------------------------\n";
		for (int i = 0; i < size_vec; i++)
		{
			cout << "\033[97m| " << i + 1; i - 1;
			cout << " | " << users[i].user_name_ << " " << users[i].user_family_name_ << " " << users[i].user_patronymic_;

			set_sp = strlen(users[i].user_name_) + strlen(users[i].user_family_name_) + strlen(users[i].user_patronymic_);

			cout << setw(41 - set_sp) << "|";

			cout << "      " << users[i].points_mechanics;

			if (users[i].points_mechanics < 10) { cout << "\t|\n"; }
			else if (users[i].points_mechanics > 10 && users[i].points_mechanics < 100) { cout << "\t|\n"; }
			else if (users[i].points_mechanics > 100 && users[i].points_mechanics < 1000) { cout << "\t|\n"; }
			else if (users[i].points_mechanics == 1000) { cout << "\t|\n"; }

		}

		cout << "\033[97m-----------------------------------------------------------------\n";
		cout << "\033[97m| Press \033[91mesc\033[97m, to go to the admin menu |\n";
		cout << "\033[97m--------------------------------------\n\033[0m";
		char a;
		for (int j = 0;;) // infinite loop
		{
			a = _getch(); // stores char typed in a

			if (a == '\x1b') // exit to ch. menu
			{
				break;
			}
		}
	}break;

	default:;
	}
}

stats::~stats() = default;