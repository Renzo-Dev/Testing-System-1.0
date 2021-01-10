#include "Admin.h"
#include <iomanip>
#include "Display.h"
#include <direct.h>
#include <filesystem>
/*****************
  cpp for Admin.h
*****************/

admin::admin()
{
	this->login_[0] = { 'a' };  this->password_[0] = { 'a' }; this->key_recovery_[0] = { 'a' }; this->backup_day_ = 0;
	this->login_[1] = { 'd' };  this->password_[1] = { 'd' }; this->key_recovery_[1] = { 'd' }; this->backup_month_ = 0;
	this->login_[2] = { 'm' };  this->password_[2] = { 'm' }; this->key_recovery_[2] = { 'm' }; this->backup_year_ = 0;
	this->login_[3] = { 'i' };  this->password_[3] = { 'i' }; this->key_recovery_[3] = { 'i' };
	this->login_[4] = { 'n' };  this->password_[4] = { 'n' }; this->key_recovery_[4] = { 'n' };
}

void admin::save_date_admin(const admin& obj)
{
	std::ofstream ofs;
	ofs.open(adm_save_location(), std::ios::binary | ios::trunc);
	ofs.write((char*)(&obj), sizeof obj);
	ofs.close();
}

void admin::load_date_admin(admin& obj)
{
	std::ifstream ifs(adm_save_location(), std::ios::binary);
	if (!ifs.is_open()) {}
	else {
		ifs.read(reinterpret_cast<char*>(&obj), sizeof(obj));
	}
	ifs.close();
}

int admin::join_admin()
{
	admin admin_aud_load; // admin_aud_load to load data from a file (admin_aud_load для загрузки данных с файла)
	admin admin_aud_save; // admin_aud_save to load data into a file (admin_aud_save для загрузки данных в файл)
	char tmp;

start_aud:
	load_date_admin(admin_aud_load); // loading object data into object (загрузка данных объекта в объект)

#pragma region authentication_admin(f_log_= 0)
	if (admin_aud_load.r_admin_ == '0')
	{
		system("cls");
		cout << "\n\t\033[93m-------------------------\n\t\033[93m|\033[92mFirst login under Admin\033[93m|\n\t\033[93m-------------------------";
		Sleep(1000);
		system("cls");
		cout << "\n\n\t\t\033[93m-------------------------\n\t\t\033[93m|\033[92mFirst login under Admin\033[93m|\n\t\t\033[93m-------------------------";
		Sleep(1000);
		system("cls");
		cout << "\n\n\n\t\t\t\033[93m-------------------------\n\t\t\t\033[93m|\033[92mFirst login under Admin\033[93m|\n\t\t\t\033[93m-------------------------";
		Sleep(1000);
		// Reg Login
	EnterLogin:

		system("cls");
		cout << "\x1B[97m----------------------------------------------------------------------------------------------------------\n";
		cout << "\033[97m|\033[31m Press \033[91m( \033[97mEsc \033[91m) \033[31mto exit \n";
		cout << "\x1B[97m|\n|\x1B[34m Come up with a \x1B[96mLogin";
		cout << " \x1B[34mto login under\x1B[31m Admin \033[32m(number of characters from 4 to 15)\033[33m: ";
		char a; // a Temp char
		int j;
		for (j = 0;;) // infinite loop
		{
			a = _getch(); // stores char typed in a

			if (a == '\x1b') // exit to ch. menu
			{
				return 1;
			}

			if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
				//check if a is numeric or alphabet
			{
				admin_aud_save.login_[j] = a; // stores a in pass
				++j;
				cout << a;
			}
			if (a == '\b' && j >= 1) // if user typed backspace
			{
				cout << "\b \b"; // rub the character behind the cursor.
				--j;
			}
			if (a == '\r') // if enter is pressed
			{
				admin_aud_save.login_[j] = '\0'; // null means end of string.
				break; // break the loop
			}
		}
		// Reg password
	EnterPassword:

		cout << "\n\x1B[97m|\n\x1B[97m|\x1B[34m Come up with a \x1B[96mPassword \x1B[34mto login under\x1B[31m Admin \033[32m(number of characters from 4 to 15)\033[33m: ";

#pragma region Checking for prohibited characters (password_)

		for (int j = 0;;) // infinite loop
		{
			a = _getch(); // stores char typed in a

			if (a == '\x1b') // exit to ch. menu
			{
				return 1;
			}

			if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
				//check if a is numeric or alphabet
			{
				admin_aud_save.password_[j] = a; //stores a in pass
				++j;
				cout << '*';
			}
			if (a == '\b' && j >= 1) // if user typed backspace
			{
				cout << "\b \b"; // rub the character behind the cursor.
				--j;
			}
			if (a == '\r') // if enter is pressed
			{
				admin_aud_save.password_[j] = '\0';//null means end of string.
				break;//break the loop
			}
		}
		cout << "\n\x1B[97m|\n----------------------------------------------------------------------------------------------------------\n";
		Sleep(800);
#pragma endregion
#pragma endregion
#pragma region authentication_admin(f_log_= 1)

		admin_aud_save.r_admin_ = '1';

		show_admin_details(admin_aud_save);

		save_date_admin(admin_aud_save);
		system("cls");
		cout << endl;
		cout << "\x1B[32m----------------------------------------------------------------------------------------------------------\n";
		cout << "\x1B[32m| \x1B[93mCongratulations on your registration! Please try again to log in!";
		cout << "\n\x1B[32m| \x1B[91mGo to login menu \x1B[34m(\x1B[32my\x1B[34m / \x1B[31many button\x1B[34m):  \x1B[0m"; tmp = _getch(); if (tmp == 'y') { goto start_aud; }
	}
	else
	{
		admin admin_syn;
	admin_aud_syn:

		system("cls");
		cout << "\x1B[94m -----------------------------------------------\n";
		cout << "\x1B[91m \\L/o\\g/\\i/\\n/ \x1B[97m|t|o| \x1B[94m|a|d|m|i|n| \x1B[94m|a|c|c|o|u|n|t|\n";
		cout << "\x1B[94m -----------------------------------------------";
		cout << "\n\x1B[97m | \033[31m Press \033[91m( \033[97mEsc \033[91m) \033[31mto exit";
		cout << "\n\x1B[97m |\n |\x1B[36m Enter login from admin panel\033[90m: ";
		char a; // a Temp char
		int j;
		for (j = 0;;) // infinite loop
		{
			a = _getch(); // stores char typed in a

			if (a == '\x1b') // exit to ch. menu
			{
				return 0;
			}

			if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
				//check if a is numeric or alphabet
			{
				admin_syn.login_[j] = a; //stores a in pass
				++j;
				cout << a;
			}
			if (a == '\b' && j >= 1) // if user typed backspace
			{
				cout << "\b \b"; // rub the character behind the cursor.
				--j;
			}
			if (a == '\r') // if enter is pressed
			{
				admin_syn.login_[j] = '\0';//null means end of string.
				break;//break the loop
			}
		}
		cout << "\n\x1B[97m |";
		cout << "\n\x1B[97m |\x1B[36m Enter your admin password\033[90m: ";
		for (j = 0;;) // infinite loop
		{
			a = _getch(); // stores char typed in a

			if (a == '\x1b') // exit to ch. menu
			{
				return 0;
			}

			if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
				//check if a is numeric or alphabet
			{
				admin_syn.password_[j] = a; //stores a in pass
				++j;
				cout << '*';
			}
			if (a == '\b' && j >= 1) // if user typed backspace
			{
				cout << "\b \b"; // rub the character behind the cursor.
				--j;
			}
			if (a == '\r') // if enter is pressed
			{
				admin_syn.password_[j] = '\0';//null means end of string.
				break;//break the loop
			}
		}
		cout << "\x1B[97m\n |";
		cout << "\n\x1B[94m -----------------------------------------------\n";

#pragma region Data validation
		bool valid_login;
		bool valid_password;

		valid_password = strcmp(admin_syn.password_, admin_aud_load.password_);
		valid_login = strcmp(admin_syn.login_, admin_aud_load.login_);
		if (valid_login == 0 && valid_password == 0)
		{
			return 1;
		}
		else
		{
			system("cls");
			cout << "\x1B[94m----------------------------------";
			cout << "\n\033[93m| \033[94mPassword or login is incorrect \033[93m|\n";
			cout << "\x1B[93m|\x1B[94m--------------------------------\x1B[93m|\n";
			cout << "\033[93m|1.\033[91m  Try again \033[93m\t\t\t |\n";
			cout << "\x1B[93m|\x1B[93m--------------------------------\x1B[93m|\n";
			cout << "\033[93m|2.\033[91m  Enter the recovery key \033[93m\t |\n";
			cout << "\x1B[93m|\x1B[91m--------------------------------\x1B[93m|\n";
			cout << "\033[93m|\033[93m0.\033[91m  Exit to main menu\033[93m\t\t |\n";
			cout << "\x1B[93m|\x1B[93m--------------------------------\x1B[93m|\n";
			do {
				tmp = _getch();
			} while (tmp != '1' && tmp != '2' && tmp != '0');
			switch (tmp)
			{
			case '1':
			{
				goto admin_aud_syn;
			}break;
			case '2':
			{
				reset_settings();
				return 0;
			}break;
			case '0':
			{
				return 0;
			}break;
			default:;
			}
		}
#pragma endregion
	}
	return 0;
}

void admin::show_admin_details(const admin& obj)
{
	char tm;
	system("cls");
	cout << "\x1B[97m--------------------------------------";
	cout << "\n|\x1B[92m Your data \t\t\t     \x1B[97m|";
	cout << "\n\x1B[97m--------------------------------------\n";
	cout << "|\x1B[93m Admin Login: " << obj.login_ << setw(28 - strlen(obj.login_)) << "\x1B[97m|";
	cout << "\n|\x1B[93m Admin Password: " << obj.password_ << setw(25 - strlen(obj.password_)) << "\x1B[97m|";
	cout << "\n|\x1B[93m Key to reset admin settings: " << obj.key_recovery_ << " \x1B[97m|";
	cout << "\n\x1B[97m--------------------------------------";
	cout << "\n|\x1B[93m Press any button to continue " << setw(12) << "\x1B[97m|";
	cout << "\n\x1B[97m--------------------------------------"; _getch();
}

void admin::change_admin_password(admin& obj)
{
	admin admin_load;
	admin admin_save;
	load_date_admin(admin_load);
	strcpy(admin_save.login_, admin_load.login_);
	strcpy(admin_save.key_recovery_, admin_load.key_recovery_);
	admin_save.r_admin_ = admin_load.r_admin_;

change_admin_password:
	system("cls");
	cout << "\n\033[91m |C|h|a|n|g|e| \033[94m|p|a|s|s|w|o|r|d|\n";
	cout << "\n\033[93m --------------------------------------------------------------------------------";
	cout << "\n\033[93m | \033[92mYour old admin password \033[94mpassword: \033[93m" << admin_load.password_;
	cout << "\n\033[93m | ";
	cout << "\n\033[93m | \033[92mEnter new password from Admin \033[32m(number of characters from 4 to 15)\033[93m: ", cin >> admin_save.password_;

	for (int i = 0; i < strlen(admin_load.password_); i++)
	{
		if (strlen(admin_save.password_) < 4 || strlen(admin_save.password_) > sizeof(admin_save.password_) || admin_save.password_[i] == ' ' || admin_save.password_[i] == '\n' || admin_save.password_[i] == '!' || admin_save.password_[i] == '*' || admin_save.password_[i] == '"' || admin_save.password_[i] == '#' || admin_save.password_[i] == '$' || admin_save.password_[i] == '%' || admin_save.password_[i] == '&' || admin_save.password_[i] == '(' || admin_save.password_[i] == ')' || admin_save.password_[i] == '+' || admin_save.password_[i] == '-' || admin_save.password_[i] == '.' || admin_save.password_[i] == ',' || admin_save.password_[i] == '/' || admin_save.password_[i] == ':' || admin_save.password_[i] == ';' || admin_save.password_[i] == '<' || admin_save.password_[i] == '>' || admin_save.password_[i] == '=' || admin_save.password_[i] == '?' || admin_save.password_[i] == '@' || admin_save.password_[i] == '[' || admin_save.password_[i] == '\\' || admin_save.password_[i] == ']' || admin_save.password_[i] == '^' || admin_save.password_[i] == '_' || admin_save.password_[i] == '`' || admin_save.password_[i] == '{' || admin_save.password_[i] == '|' || admin_save.password_[i] == '}' || admin_save.password_[i] == '~')
		{
			system("cls");
			cout << "\x1B[32------------------------------------------------------------------\n";
			cout << "\x1B[32|\x1B[91m This password is not valid (Forbidden symbols) \x1B[34m[\x1B[97m" << admin_save.password_ << "\x1B[34m] \x1B[91m, please try again !! \x1B[34m(\x1B[32my\x1B[34m / \x1B[31many button(back)\x1B[34m):  \x1B[0m"; char tmp = _getch(); if (tmp == 'y') { system("cls"); goto change_admin_password; }
		}
	}
	save_date_admin(admin_save);
}

void admin::change_admin_login(admin& obj)
{
	admin admin_load;
	admin admin_save;
	load_date_admin(admin_load);
	strcpy(admin_save.password_, admin_load.password_);
	strcpy(admin_save.key_recovery_, admin_load.key_recovery_);
	admin_save.r_admin_ = admin_load.r_admin_;

change_admin_login:
	system("cls");
	cout << "\n\033[91m |C|h|a|n|g|e| \033[94m|l|o|g|i|n|\033[0m\n";
	cout << "\n\033[93m --------------------------------------------------------------------------------";
	cout << "\n\033[93m | \033[92m Your old admin login \033[94mlogin: \033[93m" << admin_load.login_;
	cout << "\n\033[93m | ";
	cout << "\n\033[93m | \033[92m Enter new login from Admin \033[32m(number of characters from 4 to 15)\033[93m: ", cin >> admin_save.login_;

	for (int i = 0; i < strlen(admin_load.login_); i++)
	{
		if (strlen(admin_save.login_) < 4 || strlen(admin_save.login_) > sizeof(admin_save.login_) || admin_save.login_[i] == ' ' || admin_save.login_[i] == '\n' || admin_save.login_[i] == '!' || admin_save.login_[i] == '*' || admin_save.login_[i] == '"' || admin_save.login_[i] == '#' || admin_save.login_[i] == '$' || admin_save.login_[i] == '%' || admin_save.login_[i] == '&' || admin_save.login_[i] == '(' || admin_save.login_[i] == ')' || admin_save.login_[i] == '+' || admin_save.login_[i] == '-' || admin_save.login_[i] == '.' || admin_save.login_[i] == ',' || admin_save.login_[i] == '/' || admin_save.login_[i] == ':' || admin_save.login_[i] == ';' || admin_save.login_[i] == '<' || admin_save.login_[i] == '>' || admin_save.login_[i] == '=' || admin_save.login_[i] == '?' || admin_save.login_[i] == '@' || admin_save.login_[i] == '[' || admin_save.login_[i] == '\\' || admin_save.login_[i] == ']' || admin_save.login_[i] == '^' || admin_save.login_[i] == '_' || admin_save.login_[i] == '`' || admin_save.login_[i] == '{' || admin_save.login_[i] == '|' || admin_save.login_[i] == '}' || admin_save.login_[i] == '~')
		{
			system("cls");
			cout << "\x1B[32------------------------------------------------------------------\n";
			cout << "\x1B[32|\x1B[91m This login is not valid (Forbidden symbols) \x1B[34m[\x1B[97m" << admin_save.login_ << "\x1B[34m] \x1B[91m, please try again !! \x1B[34m(\x1B[32my\x1B[34m / \x1B[31many button(back)\x1B[34m):  \x1B[0m"; char tmp = _getch(); if (tmp == 'y') { system("cls"); goto change_admin_login; }
		}
	}
	save_date_admin(admin_save);
}

void admin::change_recovery_key(admin& obj)
{
	admin admin_load;
	admin admin_save;
	load_date_admin(admin_load);
	strcpy(admin_save.password_, admin_load.password_);
	strcpy(admin_save.login_, admin_load.login_);
	admin_save.r_admin_ = admin_load.r_admin_;

change_admin_login:
	system("cls");
	cout << "\n\033[91m |C|h|a|n|g|e| \033[94m|l|o|g|i|n|\033[0m\n";
	cout << "\n\033[93m --------------------------------------------------------------------------------";
	cout << "\n\033[93m | \033[92m Your old recovery key \033[94mkey: \033[93m" << admin_load.key_recovery_;
	cout << "\n\033[93m | ";
	cout << "\n\033[93m | \033[92m Enter new recovery key for Admin account \033[32m(number of characters from 4 to 10)\033[93m: ", cin >> admin_save.key_recovery_;

	for (int i = 0; i < strlen(admin_load.key_recovery_); i++)
	{
		if (strlen(admin_save.key_recovery_) < 4 || strlen(admin_save.key_recovery_) > sizeof(admin_save.key_recovery_) || admin_save.key_recovery_[i] == ' ' || admin_save.key_recovery_[i] == '\n' || admin_save.key_recovery_[i] == '!' || admin_save.key_recovery_[i] == '*' || admin_save.key_recovery_[i] == '"' || admin_save.key_recovery_[i] == '#' || admin_save.key_recovery_[i] == '$' || admin_save.key_recovery_[i] == '%' || admin_save.key_recovery_[i] == '&' || admin_save.key_recovery_[i] == '(' || admin_save.key_recovery_[i] == ')' || admin_save.key_recovery_[i] == '+' || admin_save.key_recovery_[i] == '-' || admin_save.key_recovery_[i] == '.' || admin_save.key_recovery_[i] == ',' || admin_save.key_recovery_[i] == '/' || admin_save.key_recovery_[i] == ':' || admin_save.key_recovery_[i] == ';' || admin_save.key_recovery_[i] == '<' || admin_save.key_recovery_[i] == '>' || admin_save.key_recovery_[i] == '=' || admin_save.key_recovery_[i] == '?' || admin_save.key_recovery_[i] == '@' || admin_save.key_recovery_[i] == '[' || admin_save.key_recovery_[i] == '\\' || admin_save.key_recovery_[i] == ']' || admin_save.key_recovery_[i] == '^' || admin_save.key_recovery_[i] == '_' || admin_save.key_recovery_[i] == '`' || admin_save.key_recovery_[i] == '{' || admin_save.key_recovery_[i] == '|' || admin_save.key_recovery_[i] == '}' || admin_save.key_recovery_[i] == '~')
		{
			system("cls");
			cout << "\x1B[32------------------------------------------------------------------\n";
			cout << "\x1B[32|\x1B[91m This recovery key is not valid (Forbidden symbols) \x1B[34m[\x1B[97m" << admin_save.key_recovery_ << "\x1B[34m] \x1B[91m, please try again !! \x1B[34m(\x1B[32my\x1B[34m / \x1B[31many button(back)\x1B[34m):  \x1B[0m"; char tmp = _getch(); if (tmp == 'y') { system("cls"); goto change_admin_login; }
		}
	}
	save_date_admin(admin_save);
}

void admin::reset_settings()
{
	admin Adm;
	load_date_admin(Adm);
	char tmp_key[15];

	system("cls");
	cout << "\n\033[91m |R|e|s|e|t|\033[0m\033[91m|S|e|t|t|i|n|g|s|\033[0m\n";
	cout << "\n\033[94m -----------------------------------------------------------------";
	cout << "\n\033[93m | \033[36mAre you sure you want to reset your settings\x1B[34m (\x1B[32my\x1B[34m / \x1B[31many button\x1B[34m) \033[93m|";
	cout << "\n\033[94m -----------------------------------------------------------------";
	char tmp = _getch();
	if (tmp == 'y')
	{
		system("cls");
	reset_settings:
		cout << "\n\x1B[91m |R|e|s|e|t| \x1B[96m|s|e|t|t|i|n|g|s| ";
		cout << "\n\033[94m ------------------------------------";
		cout << "\x1B[93m\n|\033[94m Enter a keyword for factory reset :\033[93m "; cin >> tmp_key;

		if (strcmp(Adm.key_recovery_, tmp_key) == 0)
		{
			system("cls");
			cout << "\n\t\t\x1B[91m |R|e|s|e|t| \x1B[96m|s|e|t|t|i|n|g|s| ";
			cout << "\n\033[94m---------------------------------------------------------------------------------------------------";
			cout << "\x1B[93m\n| \033[94mSettings have been reset. Please login again to enter new data \033[92m(Press any button, for continue) \033[93m|";
			cout << "\n\033[94m---------------------------------------------------------------------------------------------------";
			_getch();
			ofstream clear;
			clear.open(adm_save_location());
			if (clear.is_open())
			{
				clear.clear();
			}
			clear.close();
			cout << "\n\n\n";
		}
		else
		{
			system("cls");
			cout << "\x1B[32------------------------------------------------------------------\n";
			cout << "\x1B[32|\x1B[91m Keys don't match \x1B[34m[\x1B[97m" << tmp_key << "\x1B[34m] \x1B[91m, please try again !! \x1B[34m (\x1B[32my\x1B[34m / \x1B[31many button(back)\x1B[34m):  \x1B[0m"; char tmp = _getch(); if (tmp == 'y') { system("cls"); goto reset_settings; }
		}
	}
	else
	{
	}
}

void admin::show_users()
{
	Users_ obj;
	load_num_users(obj);
	const int size_vec = obj.num_users_;

	char choose;
	if (size_vec <= 0)
	{
		system("cls");
		cout << "\033[91m-------------------------------------------------";
		cout << "\n\033[93m| There are no registered users in the database |\n";
		cout << "\033[91m-------------------------------------------------";
		cout << "\n\033[93m| Press any button, to continue |\n";
		cout << "\033[91m---------------------------------";
		_getch();
	}
	else {
		vector<Users_> users(size_vec);
		load_users(users);
		system("cls");
		cout << " \033[33m-----------------------------\n";
		cout << " \033[33m| \033[97m|1|\033[94m Show all at once\033[33m      |\n"; // Показать только данные для входа
		cout << " \033[33m| \033[97m|2|\033[94m Show one by one\t\033[33m     |\n"; // Показать все данные
		cout << " \033[91m-----------------------------\n";
		cout << " \033[33m| \033[97m|9|\033[91m Back to admin menu \033[33m   |\n";
		cout << " \033[33m-----------------------------\n";
		do {
			choose = _getch();
		} while (choose != '1' && choose != '2' && choose != '9');
		unsigned short int tmp_size = size_vec;
		switch (choose)
		{
		case '1':
		{
			system("cls");
			cout << " \033[33m-------------------------------\n";
			cout << " \033[33m| \033[97m|1|\033[94m Show only login details\033[33m |\n"; // Показать только данные для входа
			cout << " \033[33m| \033[97m|2|\033[94m Show all data\t\033[33m       |\n"; // Показать все данные
			cout << " \033[91m-------------------------------\n";
			cout << " \033[33m| \033[97m|9|\033[91m Back to admin menu \033[33m     |\n";
			cout << " \033[33m-------------------------------\n";
			do {
				choose = _getch();
			} while (choose != '1' && choose != '2' && choose != '9');

			switch (choose)
			{
			case '1':
			{
				system("cls");
				for (int i = 0; i < tmp_size; i++)
				{
					cout << "\n\x1B[93m-----------------------------------";
					cout << "\n\x1B[92m| \x1B[91mN\x1B[91m" << i + 1 << "\t\t\t\t\x1B[92m  |";
					cout << "\n\x1B[93m-----------------------------------";
					cout << "\n\x1B[92m| \x1B[94mLogin: \x1B[93m" << users[i].login_ << "\033[92m";
					cout << setw(26 - strlen(users[i].login_)) << "|";
					cout << "\n\x1B[92m| \x1B[91mPassword: \x1B[93m" << users[i].password_ << "\033[92m";
					cout << setw(23 - strlen(users[i].password_)) << "|";
					cout << "\n\x1B[93m-----------------------------------";
					i - 1;
				}
				cout << "\n\n\n\x1B[93m-----------------------------------------";
				cout << "\n\x1B[93m|\x1B[31m Press any button (back to admin menu) \033[93m|";
				cout << "\n\x1B[93m-----------------------------------------";
				_getch();
			}break;
			case '2':
			{
				system("cls");
				for (int i = 0; i < tmp_size; i++)
				{
					cout << "\n\x1B[93m-----------------------------------";
					cout << "\n\x1B[92m| \x1B[91mN\x1B[91m" << i + 1 << "\t\t\t\t\x1B[92m  |";
					cout << "\n\x1B[93m-----------------------------------";
					cout << "\n\x1B[92m| \x1B[94mLogin: \x1B[93m" << users[i].login_ << "\033[92m";
					cout << setw(26 - strlen(users[i].login_)) << "|";
					cout << "\n\x1B[92m| \x1B[91mPassword: \x1B[93m" << users[i].password_ << "\033[92m";
					cout << setw(23 - strlen(users[i].password_)) << "|";
					cout << "\n\x1B[93m-----------------------------------";
					cout << "\n\x1B[92m| \x1B[97mName: \x1B[33m" << users[i].user_name_ << "\033[92m";
					cout << setw(27 - strlen(users[i].user_name_)) << "|";
					cout << "\n\x1B[92m| \x1B[97mFamily name: \x1B[33m" << users[i].user_family_name_ << "\033[92m";
					cout << setw(20 - strlen(users[i].user_family_name_)) << "|";
					cout << "\n\x1B[92m| \x1B[97mPatronymic: \x1B[33m" << users[i].user_patronymic_ << "\033[92m";
					cout << setw(21 - strlen(users[i].user_patronymic_)) << "|";
					cout << "\n\x1B[93m-----------------------------------";
					cout << "\n\x1B[92m| \x1B[94mMail: " << users[i].mail_ << "\033[92m";
					cout << setw(27 - strlen(users[i].mail_)) << "|";
					cout << "\n\x1B[92m| \x1B[96mPhone number:" << users[i].phone_number_ << "\033[92m";
					cout << setw(20 - strlen(users[i].phone_number_)) << "|";
					cout << "\n\x1B[93m-----------------------------------";
					cout << "\n\x1B[92m| \x1B[36mCountry of Residence:\033[32m " << users[i].country << "\033[92m";
					cout << setw(11 - strlen(users[i].country)) << "|";
					cout << "\n\x1B[92m| \x1B[36mCity of residence:\033[32m " << users[i].city << "\033[92m";
					cout << setw(14 - strlen(users[i].city)) << "|";
					cout << "\n\x1B[93m-----------------------------------";
					cout << "\n\x1B[92m| \x1B[93mDate of Birth:\033[97m " << users[i].day << "." << users[i].month << "." << users[i].year << "\033[92m";

					if (users[i].day < 10 && users[i].month < 10) { cout << setw(15) << "\033[92m|"; }
					else if (users[i].day == 10 && users[i].month < 10) { cout << setw(14) << "\033[92m|"; }
					else if (users[i].day < 10 && users[i].month == 10) { cout << setw(14) << "\033[92m|"; }
					else if (users[i].day == 10 && users[i].month == 10) { cout << setw(13) << "\033[92m|"; }
					else if (users[i].day > 10 && users[i].month > 10) { cout << setw(13) << "\033[92m|"; }
					else if (users[i].day == 10 && users[i].month > 10) { cout << setw(13) << "\033[92m|"; }
					else if (users[i].day > 10 && users[i].month == 10) { cout << setw(13) << "\033[92m|"; }
					else if (users[i].day > 10 && users[i].month < 10) { cout << setw(14) << "\033[92m|"; }
					else if (users[i].day < 10 && users[i].month > 10) { cout << setw(14) << "\033[92m|"; }

					cout << "\n\x1B[92m| \x1B[93mGender: "; if (users[i].gender == '1') { cout << "\033[94m Man\t\t\t\033[92m  |"; }
					else { cout << "\033[95m Woman\t\t\033[92m  |"; }
					cout << "\n\x1B[93m-----------------------------------";
					cout << "\n\x1B[92m| \x1B[94mMath points:      \x1B[97m" << users[i].points_math;
					if (users[i].points_math < 10) { cout << "\t\t  \x1B[92m|"; }
					else if (users[i].points_math > 10 && users[i].points_math < 100) { cout << "\t\t  \x1B[92m|"; }
					else if (users[i].points_math > 100 && users[i].points_math < 1000) { cout << "\t\t  \x1B[92m|"; }
					else if (users[i].points_math == 1000) { cout << "\t  \x1B[92m|"; }
					cout << "\n\x1B[92m| \x1B[94mPhysics points:   \x1B[97m" << users[i].physics_points;
					if (users[i].physics_points < 10) { cout << "\t\t\x1B[92m  |"; }
					else if (users[i].physics_points > 10 && users[i].physics_points < 100) { cout << "\t\t  \x1B[92m|"; }
					else if (users[i].physics_points > 100 && users[i].physics_points < 1000) { cout << "\t\t  \x1B[92m|"; }
					else if (users[i].physics_points == 1000) { cout << "\t  \x1B[92m|"; }
					cout << "\n\x1B[92m| \x1B[94mMechanics points: \x1B[97m" << users[i].points_mechanics;
					if (users[i].points_mechanics < 10) { cout << "\t\t  \x1B[92m|"; }
					else if (users[i].points_mechanics > 10 && users[i].points_mechanics < 100) { cout << "\t\t  \x1B[92m|"; }
					else if (users[i].points_mechanics > 100 && users[i].points_mechanics < 1000) { cout << "\t\t  \x1B[92m|"; }
					else if (users[i].points_mechanics == 1000) { cout << "\t  \x1B[92m|"; }
					cout << "\n\x1B[93m-----------------------------------";
					//
					cout << "\n\x1B[92m| \x1B[94mRegistration date:\033[97m " << users[i].day_reg << "." << users[i].month_reg << "." << users[i].year_reg << "\033[92m";
					if (users[i].day_reg < 10 && users[i].month_reg < 10) { cout << setw(11) << "\033[92m|"; }
					else if (users[i].day_reg == 10 && users[i].month_reg < 10) { cout << setw(10) << "\033[92m|"; }
					else if (users[i].day_reg < 10 && users[i].month_reg == 10) { cout << setw(10) << "\033[92m|"; }
					else if (users[i].day_reg == 10 && users[i].month_reg == 10) { cout << setw(9) << "\033[92m|"; }
					else if (users[i].day_reg > 10 && users[i].month_reg > 10) { cout << setw(9) << "\033[92m|"; }
					else if (users[i].day_reg == 10 && users[i].month_reg > 10) { cout << setw(9) << "\033[92m|"; }
					else if (users[i].day_reg > 10 && users[i].month_reg == 10) { cout << setw(9) << "\033[92m|"; }
					else if (users[i].day_reg > 10 && users[i].month_reg < 10) { cout << setw(10) << "\033[92m|"; }
					else if (users[i].day_reg < 10 && users[i].month_reg > 10) { cout << setw(10) << "\033[92m|"; }
					cout << "\n\x1B[93m-----------------------------------";
					i - 1;
				}
				cout << "\n\x1B[93m-----------------------------------------";
				cout << "\n\x1B[93m|\x1B[31m Press any button (back to admin menu) \033[93m|";
				cout << "\n\x1B[93m-----------------------------------------";
				_getch();
			}break;
			case '9':
			{
				break;
			}break;
			default:;
			}
		}break;
		case '2':
		{
			char move = ' ';

			system("cls");
			cout << " \033[33m-------------------------------\n";
			cout << " \033[33m| \033[97m|1|\033[94m Show only login details\033[33m |\n"; // Показать только данные для входа
			cout << " \033[33m| \033[97m|2|\033[94m Show all data\t\033[33m       |\n"; // Показать все данные
			cout << " \033[91m-------------------------------\n";
			cout << " \033[33m| \033[97m|9|\033[91m Back to admin menu \033[33m     |\n";
			cout << " \033[33m-------------------------------\n";
			do {
				choose = _getch();
			} while (choose != '1' && choose != '2' && choose != '9');
			switch (choose)
			{
			case '1':
			{
				for (int i = 0; i < tmp_size; i++)
				{
					system("cls");
					cout << "\n \x1B[91mN\x1B[91m" << i + 1 << " of " << tmp_size;
					cout << "\n\x1B[93m-----------------------------------";
					cout << "\n\x1B[92m| \x1B[94mLogin: \x1B[93m" << users[i].login_ << "\033[92m";
					cout << setw(26 - strlen(users[i].login_)) << "|";
					cout << "\n\x1B[92m| \x1B[91mPassword: \x1B[93m" << users[i].password_ << "\033[92m";
					cout << setw(23 - strlen(users[i].password_)) << "|";
					cout << "\n\x1B[93m-----------------------------------";
					i - 1;
					cout << "\n\x1B[93m---------------------------------";
					cout << "\n\x1B[93m|\x1B[92m 1.Next\t\t\t\x1B[93m|\n\x1B[93m| \x1B[91m2.Back\t\t\t\x1B[93m|\n\x1B[93m|\x1B[31m Press 0 (back to admin menu)  \x1B[93m|";
					cout << "\n\x1B[93m---------------------------------";
					do {
						move = _getch();
					} while (move != '1' && move != '2' && move != '0');

					if (move != '0') {
						if (move == '1' && i == (tmp_size - 1))
						{
							i--;
						}
						else
						{
							if (move == '1')
							{
							}
						}
						if (move == '2' && i == 0)
						{
							i--;
						}
						else
						{
							if (move == '2')
							{
								i--; i--;
							}
						}
					}
					else { break; }
				}
			}break;
			case '2':
			{
				for (int i = 0; i < tmp_size; i++)
				{
					system("cls");
					cout << "\n\x1B[91mN\x1B[91m" << i + 1 << " of " << tmp_size;
					cout << "\n\x1B[93m-----------------------------------";
					cout << "\n\x1B[92m| \x1B[94mLogin: \x1B[93m" << users[i].login_ << "\033[92m";
					cout << setw(26 - strlen(users[i].login_)) << "|";
					cout << "\n\x1B[92m| \x1B[91mPassword: \x1B[93m" << users[i].password_ << "\033[92m";
					cout << setw(23 - strlen(users[i].password_)) << "|";
					cout << "\n\x1B[93m-----------------------------------";
					cout << "\n\x1B[92m| \x1B[97mName: \x1B[33m" << users[i].user_name_ << "\033[92m";
					cout << setw(27 - strlen(users[i].user_name_)) << "|";
					cout << "\n\x1B[92m| \x1B[97mFamily name: \x1B[33m" << users[i].user_family_name_ << "\033[92m";
					cout << setw(20 - strlen(users[i].user_family_name_)) << "|";
					cout << "\n\x1B[92m| \x1B[97mPatronymic: \x1B[33m" << users[i].user_patronymic_ << "\033[92m";
					cout << setw(21 - strlen(users[i].user_patronymic_)) << "|";
					cout << "\n\x1B[93m-----------------------------------";
					cout << "\n\x1B[92m| \x1B[94mMail: " << users[i].mail_ << "\033[92m";
					cout << setw(27 - strlen(users[i].mail_)) << "|";
					cout << "\n\x1B[92m| \x1B[96mPhone number:" << users[i].phone_number_ << "\033[92m";
					cout << setw(20 - strlen(users[i].phone_number_)) << "|";
					cout << "\n\x1B[93m-----------------------------------";
					cout << "\n\x1B[92m| \x1B[36mCountry of Residence:\033[32m " << users[i].country << "\033[92m";
					cout << setw(11 - strlen(users[i].country)) << "|";
					cout << "\n\x1B[92m| \x1B[36mCity of residence:\033[32m " << users[i].city << "\033[92m";
					cout << setw(14 - strlen(users[i].city)) << "|";
					cout << "\n\x1B[93m-----------------------------------";
					cout << "\n\x1B[92m| \x1B[93mDate of Birth:\033[97m " << users[i].day << "." << users[i].month << "." << users[i].year << "\033[92m";
					if (users[i].day < 10 && users[i].month < 10) { cout << setw(15) << "\033[92m|"; }
					else if (users[i].day == 10 && users[i].month < 10) { cout << setw(14) << "\033[92m|"; }
					else if (users[i].day < 10 && users[i].month == 10) { cout << setw(14) << "\033[92m|"; }
					else if (users[i].day == 10 && users[i].month == 10) { cout << setw(13) << "\033[92m|"; }
					else if (users[i].day > 10 && users[i].month > 10) { cout << setw(13) << "\033[92m|"; }
					else if (users[i].day == 10 && users[i].month > 10) { cout << setw(13) << "\033[92m|"; }
					else if (users[i].day > 10 && users[i].month == 10) { cout << setw(13) << "\033[92m|"; }
					else if (users[i].day > 10 && users[i].month < 10) { cout << setw(14) << "\033[92m|"; }
					else if (users[i].day < 10 && users[i].month > 10) { cout << setw(14) << "\033[92m|"; }

					cout << "\n\x1B[92m| \x1B[93mGender: "; if (users[i].gender == '1') { cout << "\033[94m Man\t\t\t\033[92m  |"; }
					else { cout << "\033[95m Woman\t\t\033[92m  |"; }
					cout << "\n\x1B[93m-----------------------------------";
					cout << "\n\x1B[92m| \x1B[94mMath points:      \x1B[97m" << users[i].points_math;
					if (users[i].points_math < 10) { cout << "\t\t  \x1B[92m|"; }
					else if (users[i].points_math > 10 && users[i].points_math < 100) { cout << "\t\t  \x1B[92m|"; }
					else if (users[i].points_math > 100 && users[i].points_math < 1000) { cout << "\t\t  \x1B[92m|"; }
					else if (users[i].points_math == 1000) { cout << "\t  \x1B[92m|"; }
					cout << "\n\x1B[92m| \x1B[94mPhysics points:   \x1B[97m" << users[i].physics_points;
					if (users[i].physics_points < 10) { cout << "\t\t\x1B[92m  |"; }
					else if (users[i].physics_points > 10 && users[i].physics_points < 100) { cout << "\t\t  \x1B[92m|"; }
					else if (users[i].physics_points > 100 && users[i].physics_points < 1000) { cout << "\t\t  \x1B[92m|"; }
					else if (users[i].physics_points == 1000) { cout << "\t  \x1B[92m|"; }
					cout << "\n\x1B[92m| \x1B[94mMechanics points: \x1B[97m" << users[i].points_mechanics;
					if (users[i].points_mechanics < 10) { cout << "\t\t  \x1B[92m|"; }
					else if (users[i].points_mechanics > 10 && users[i].points_mechanics < 100) { cout << "\t\t  \x1B[92m|"; }
					else if (users[i].points_mechanics > 100 && users[i].points_mechanics < 1000) { cout << "\t\t  \x1B[92m|"; }
					else if (users[i].points_mechanics == 1000) { cout << "\t  \x1B[92m|"; }
					cout << "\n\x1B[93m-----------------------------------";
					cout << "\n\x1B[92m| \x1B[94mRegistration date:\033[97m " << users[i].day_reg << "." << users[i].month_reg << "." << users[i].year_reg << "\033[92m";
					if (users[i].day_reg < 10 && users[i].month_reg < 10) { cout << setw(11) << "\033[92m|"; }
					else if (users[i].day_reg == 10 && users[i].month_reg < 10) { cout << setw(10) << "\033[92m|"; }
					else if (users[i].day_reg < 10 && users[i].month_reg == 10) { cout << setw(10) << "\033[92m|"; }
					else if (users[i].day_reg == 10 && users[i].month_reg == 10) { cout << setw(9) << "\033[92m|"; }
					else if (users[i].day_reg > 10 && users[i].month_reg > 10) { cout << setw(9) << "\033[92m|"; }
					else if (users[i].day_reg == 10 && users[i].month_reg > 10) { cout << setw(9) << "\033[92m|"; }
					else if (users[i].day_reg > 10 && users[i].month_reg == 10) { cout << setw(9) << "\033[92m|"; }
					else if (users[i].day_reg > 10 && users[i].month_reg < 10) { cout << setw(10) << "\033[92m|"; }
					else if (users[i].day_reg < 10 && users[i].month_reg > 10) { cout << setw(10) << "\033[92m|"; }
					cout << "\n\x1B[93m-----------------------------------";
					i - 1;
					cout << "\n\x1B[93m---------------------------------";
					cout << "\n\x1B[93m|\x1B[92m 1.Next\t\t\t\x1B[93m|\n\x1B[93m| \x1B[91m2.Back\t\t\t\x1B[93m|\n\x1B[93m|\x1B[31m Press 0 (back to admin menu)  \x1B[93m|";
					cout << "\n\x1B[93m---------------------------------";
					do {
						move = _getch();
					} while (move != '1' && move != '2' && move != '0');

					if (move != '0') {
						if (move == '1' && i == (tmp_size - 1))
						{
							i--;
						}
						else
						{
							if (move == '1')
							{
							}
						}
						if (move == '2' && i == 0)
						{
							i--;
						}
						else
						{
							if (move == '2')
							{
								i--; i--;
							}
						}
					}
					else { break; }
				}
			}break;

			default:;
			}
		}break;

		default:;
		}
	}
}

int admin::find_user()
{
	Users_ obj;
	load_num_users(obj);
	const int size_vec = obj.num_users_;
	vector<Users_> users(size_vec);
	load_users(users);
	int i;
	char tmp_find[30];
	char choose;
	int found = -1;
find:
	i = 0;

	system("cls");
	cout << "\n\033[91m   |S|e|a|r|c|h|\033[0m \033[94m|U|s|e|r|(s)\033[0m\n";
	cout << "\n\033[94m -----------------------------------";
	cout << "\n\033[93m | \033[97m|1| \033[36mFind by login.\033[0m\t\t  \033[93m |"; //1. Найти по логину
	cout << "\n\033[94m -----------------------------------";
	cout << "\n\033[93m | \033[97m|2| \033[36mFind by phone number.\t  \033[93m |"; //2. Найти по номеру телефона
	cout << "\n\033[94m -----------------------------------";
	cout << "\n\033[93m | \033[97m|3| \033[36mFind a user by email.\t  \033[93m |"; //4. Найти пользователя по email
	cout << "\n\033[94m -----------------------------------";
	cout << "\n\033[93m | \033[97m|4| \033[36mFind User by Family name.  \033[93m |"; //5. Найти пользователя по Фамилии
	cout << "\n\033[94m -----------------------------------";
	cout << "\n\033[93m | \033[97m|0| \033[91mBack to Admin Menu.\t  \033[93m |";
	cout << "\n\033[94m -----------------------------------";
	do {
		choose = _getch();
	} while (choose != '1' && choose != '2' && choose != '3' && choose != '4' && choose != '5' && choose != '0');

	switch (choose)
	{
	case '1':
	{
		system("cls");
		cout << " --------------------------";
		cout << "\n\x1B[92m |S|e|a|r|c|h|\x1B[36m |by|\x1B[92m |login|\n";
		cout << " --------------------------\n";
		cout << "\x1B[92m |\x1B[36m Enter username:\x1B[37m "; cin >> tmp_find;

		for (; i < size_vec; i++)
		{
			found = strcmp(users[i].login_, tmp_find);
			if (found == 0) { break; }
		}
		if (found == 0)
		{
			system("cls");
			cout << "\n\n\x1B[93m\t------------------------";
			cout << "\n\x1B[92m\t| \033[93mSearch, please wait!\x1B[92m |";
			cout << "\n\x1B[93m\t------------------------";
			Sleep(1000);
			system("cls");
			cout << "\n\n\x1B[93m\t------------------------";
			cout << "\n\x1B[92m\t|\033[93m Search, please wait!\x1B[92m |";
			cout << "\n\x1B[92m\t|      \033[93mUser found      \x1B[92m|";
			cout << "\n\x1B[93m\t------------------------";
			Sleep(1000);
			system("cls");
			cout << "\n\x1B[93m-----------------------------------";
			cout << "\n\x1B[92m|\033[93m           Account data";
			cout << "\n\x1B[93m-----------------------------------";
			cout << "\n\x1B[92m| \x1B[93mLogin: " << users[i].login_;
			cout << "\n\x1B[92m| \x1B[93mPassword: " << users[i].password_;
			cout << "\n\x1B[93m-----------------------------------";
			cout << "\n\x1B[92m| \x1B[97mName: " << users[i].user_name_;
			cout << "\n\x1B[92m| \x1B[97mFamily name: " << users[i].user_family_name_;
			cout << "\n\x1B[92m| \x1B[97mPatronymic: " << users[i].user_patronymic_;
			cout << "\n\x1B[93m-----------------------------------";
			cout << "\n\x1B[92m| \x1B[94mMail: " << users[i].mail_;
			cout << "\n\x1B[92m| \x1B[96mPhone number:" << users[i].phone_number_;
			cout << "\n\x1B[93m-----------------------------------";
			cout << "\n\x1B[92m| \x1B[36mCountry of Residence: " << users[i].country;
			cout << "\n\x1B[92m| \x1B[36mCity of residence: " << users[i].city;
			cout << "\n\x1B[93m-----------------------------------";
			cout << "\n\x1B[92m| \x1B[93mDate of Birth: " << users[i].day << "." << users[i].month << "." << users[i].year;
			cout << "\n\x1B[92m| \x1B[93mGender: "; if (users[i].gender == '1') { cout << "\033[94m Man"; }
			else { cout << "\033[95m Woman"; }
			cout << "\n\x1B[93m-----------------------------------";
			cout << "\n\x1B[92m| \x1B[93mMath points: " << users[i].points_math;
			cout << "\n\x1B[92m| \x1B[93mMechanics points: " << users[i].points_mechanics;
			cout << "\n\x1B[92m| \x1B[93mPhysics points: " << users[i].physics_points;
			cout << "\n\x1B[93m-----------------------------------";
			cout << "\n\x1B[92m   Press any button to continue ";
			_getch();
			found = i;
		}
		else
		{
			system("cls");
			cout << "\033[41m";
			cout << "\n\n\033[93m\t--------------------";
			cout << "\n\x1B[92m\t| \033[93m User not found \x1B[92m |";
			cout << "\n\x1B[92m\t| \033[93mTry again? \x1B[37m(y/n)\x1B[92m |";
			cout << "\n\033[93m\t--------------------";
			cout << "\033[0m";
			do {
				choose = _getch();
			} while (choose != 'y' && choose != 'Y' && choose != 'n' && choose != 'N');
			if (choose == 'y')
			{
				goto find;
			}
		}
	}break;
	case '2':
	{
		system("cls");
		cout << " ---------------------------------";
		cout << "\n\x1B[92m |S|e|a|r|c|h|\x1B[36m |by|\x1B[92m |phone number|\n";
		cout << " ---------------------------------\n";
		cout << "\x1B[92m |\x1B[36m Enter phone number:\x1B[37m "; cin >> tmp_find;
		for (; i < size_vec; i++)
		{
			found = strcmp(users[i].phone_number_, tmp_find);
			if (found == 0) { break; }
		}
		if (found == 0)
		{
			system("cls");
			cout << "\n\n\x1B[93m\t------------------------";
			cout << "\n\x1B[92m\t| \033[93mSearch, please wait!\x1B[92m |";
			cout << "\n\x1B[93m\t------------------------";
			Sleep(1000);
			system("cls");
			cout << "\n\n\x1B[93m\t------------------------";
			cout << "\n\x1B[92m\t|\033[93m Search, please wait!\x1B[92m |";
			cout << "\n\x1B[92m\t|      \033[93mUser found      \x1B[92m|";
			cout << "\n\x1B[93m\t------------------------";
			Sleep(1000);
			system("cls");
			cout << "\n\x1B[93m-----------------------------------";
			cout << "\n\x1B[92m|\033[93m           Account data";
			cout << "\n\x1B[93m-----------------------------------";
			cout << "\n\x1B[92m| \x1B[93mLogin: " << users[i].login_;
			cout << "\n\x1B[92m| \x1B[93mPassword: " << users[i].password_;
			cout << "\n\x1B[93m-----------------------------------";
			cout << "\n\x1B[92m| \x1B[97mName: " << users[i].user_name_;
			cout << "\n\x1B[92m| \x1B[97mFamily name: " << users[i].user_family_name_;
			cout << "\n\x1B[92m| \x1B[97mPatronymic: " << users[i].user_patronymic_;
			cout << "\n\x1B[93m-----------------------------------";
			cout << "\n\x1B[92m| \x1B[94mMail: " << users[i].mail_;
			cout << "\n\x1B[92m| \x1B[96mPhone number:" << users[i].phone_number_;
			cout << "\n\x1B[93m-----------------------------------";
			cout << "\n\x1B[92m| \x1B[36mCountry of Residence: " << users[i].country;
			cout << "\n\x1B[92m| \x1B[36mCity of residence: " << users[i].city;
			cout << "\n\x1B[93m-----------------------------------";
			cout << "\n\x1B[92m| \x1B[93mDate of Birth: " << users[i].day << "." << users[i].month << "." << users[i].year;
			cout << "\n\x1B[92m| \x1B[93mGender: "; if (users[i].gender == '1') { cout << "\033[94m Man"; }
			else { cout << "\033[95m Woman"; }
			cout << "\n\x1B[93m-----------------------------------";
			cout << "\n\x1B[92m| \x1B[93mMath points: " << users[i].points_math;
			cout << "\n\x1B[92m| \x1B[93mMechanics points: " << users[i].points_mechanics;
			cout << "\n\x1B[92m| \x1B[93mPhysics points: " << users[i].physics_points;
			cout << "\n\x1B[93m-----------------------------------";
			cout << "\n\x1B[92m   Press any button to continue ";
			_getch();
			found = i;
		}
		else
		{
			system("cls");
			cout << "\033[41m";
			cout << "\n\n\033[93m\t--------------------";
			cout << "\n\x1B[92m\t| \033[93m User not found \x1B[92m |";
			cout << "\n\x1B[92m\t| \033[93mTry again? \x1B[37m(y/n)\x1B[92m |";
			cout << "\n\033[93m\t--------------------";
			cout << "\033[0m";
			do {
				choose = _getch();
			} while (choose != 'y' && choose != 'Y' && choose != 'n' && choose != 'N');
			if (choose == 'y')
			{
				goto find;
			}
		}
	}break;
	case '3':
	{
		system("cls");
		cout << " --------------------------";
		cout << "\n\x1B[92m |S|e|a|r|c|h|\x1B[36m |by|\x1B[92m |email|\n";
		cout << " --------------------------\n";
		cout << "\x1B[92m |\x1B[36m Enter mail:\x1B[37m "; cin >> tmp_find;
		for (; i < size_vec; i++)
		{
			found = strcmp(users[i].mail_, tmp_find);
			if (found == 0) { break; }
		}
		if (found == 0)
		{
			system("cls");
			cout << "\n\n\x1B[93m\t------------------------";
			cout << "\n\x1B[92m\t| \033[93mSearch, please wait!\x1B[92m |";
			cout << "\n\x1B[93m\t------------------------";
			Sleep(1000);
			system("cls");
			cout << "\n\n\x1B[93m\t------------------------";
			cout << "\n\x1B[92m\t|\033[93m Search, please wait!\x1B[92m |";
			cout << "\n\x1B[92m\t|      \033[93mUser found      \x1B[92m|";
			cout << "\n\x1B[93m\t------------------------";
			Sleep(1000);
			system("cls");
			cout << "\n\x1B[93m-----------------------------------";
			cout << "\n\x1B[92m|\033[93m           Account data";
			cout << "\n\x1B[93m-----------------------------------";
			cout << "\n\x1B[92m| \x1B[93mLogin: " << users[i].login_;
			cout << "\n\x1B[92m| \x1B[93mPassword: " << users[i].password_;
			cout << "\n\x1B[93m-----------------------------------";
			cout << "\n\x1B[92m| \x1B[97mName: " << users[i].user_name_;
			cout << "\n\x1B[92m| \x1B[97mFamily name: " << users[i].user_family_name_;
			cout << "\n\x1B[92m| \x1B[97mPatronymic: " << users[i].user_patronymic_;
			cout << "\n\x1B[93m-----------------------------------";
			cout << "\n\x1B[92m| \x1B[94mMail: " << users[i].mail_;
			cout << "\n\x1B[92m| \x1B[96mPhone number:" << users[i].phone_number_;
			cout << "\n\x1B[93m-----------------------------------";
			cout << "\n\x1B[92m| \x1B[36mCountry of Residence: " << users[i].country;
			cout << "\n\x1B[92m| \x1B[36mCity of residence: " << users[i].city;
			cout << "\n\x1B[93m-----------------------------------";
			cout << "\n\x1B[92m| \x1B[93mDate of Birth: " << users[i].day << "." << users[i].month << "." << users[i].year;
			cout << "\n\x1B[92m| \x1B[93mGender: "; if (users[i].gender == '1') { cout << "\033[94m Man"; }
			else { cout << "\033[95m Woman"; }
			cout << "\n\x1B[93m-----------------------------------";
			cout << "\n\x1B[92m| \x1B[93mMath points: " << users[i].points_math;
			cout << "\n\x1B[92m| \x1B[93mMechanics points: " << users[i].points_mechanics;
			cout << "\n\x1B[92m| \x1B[93mPhysics points: " << users[i].physics_points;
			cout << "\n\x1B[93m-----------------------------------";
			cout << "\n\x1B[92m   Press any button to continue ";
			_getch();
			found = i;
		}
		else
		{
			system("cls");
			cout << "\033[41m";
			cout << "\n\n\033[93m\t--------------------";
			cout << "\n\x1B[92m\t| \033[93m User not found \x1B[92m |";
			cout << "\n\x1B[92m\t| \033[93mTry again? \x1B[37m(y/n)\x1B[92m |";
			cout << "\n\033[93m\t--------------------";
			cout << "\033[0m";
			do {
				choose = _getch();
			} while (choose != 'y' && choose != 'Y' && choose != 'n' && choose != 'N');
			if (choose == 'y')
			{
				goto find;
			}
		}
	}break;
	case '4':
	{
		system("cls");
		cout << " --------------------------------";
		cout << "\n\x1B[92m |S|e|a|r|c|h|\x1B[36m |by|\x1B[92m |Family Name|\n";
		cout << " --------------------------------\n";
		cout << "\x1B[92m |\x1B[36m Enter Famyli Name:\x1B[37m "; cin >> tmp_find;
		for (; i < size_vec; i++)
		{
			found = strcmp(users[i].user_family_name_, tmp_find);
			if (found == 0) { break; }
		}
		if (found == 0)
		{
			system("cls");
			cout << "\n\n\x1B[93m\t------------------------";
			cout << "\n\x1B[92m\t| \033[93mSearch, please wait!\x1B[92m |";
			cout << "\n\x1B[93m\t------------------------";
			Sleep(1000);
			system("cls");
			cout << "\n\n\x1B[93m\t------------------------";
			cout << "\n\x1B[92m\t|\033[93m Search, please wait!\x1B[92m |";
			cout << "\n\x1B[92m\t|      \033[93mUser found      \x1B[92m|";
			cout << "\n\x1B[93m\t------------------------";
			Sleep(1000);
			system("cls");
			cout << "\n\x1B[93m-----------------------------------";
			cout << "\n\x1B[92m|\033[93m           Account data";
			cout << "\n\x1B[93m-----------------------------------";
			cout << "\n\x1B[92m| \x1B[93mLogin: " << users[i].login_;
			cout << "\n\x1B[92m| \x1B[93mPassword: " << users[i].password_;
			cout << "\n\x1B[93m-----------------------------------";
			cout << "\n\x1B[92m| \x1B[97mName: " << users[i].user_name_;
			cout << "\n\x1B[92m| \x1B[97mFamily name: " << users[i].user_family_name_;
			cout << "\n\x1B[92m| \x1B[97mPatronymic: " << users[i].user_patronymic_;
			cout << "\n\x1B[93m-----------------------------------";
			cout << "\n\x1B[92m| \x1B[94mMail: " << users[i].mail_;
			cout << "\n\x1B[92m| \x1B[96mPhone number:" << users[i].phone_number_;
			cout << "\n\x1B[93m-----------------------------------";
			cout << "\n\x1B[92m| \x1B[36mCountry of Residence: " << users[i].country;
			cout << "\n\x1B[92m| \x1B[36mCity of residence: " << users[i].city;
			cout << "\n\x1B[93m-----------------------------------";
			cout << "\n\x1B[92m| \x1B[93mDate of Birth: " << users[i].day << "." << users[i].month << "." << users[i].year;
			cout << "\n\x1B[92m| \x1B[93mGender: "; if (users[i].gender == '1') { cout << "\033[94m Man"; }
			else { cout << "\033[95m Woman"; }
			cout << "\n\x1B[93m-----------------------------------";
			cout << "\n\x1B[92m| \x1B[93mMath points: " << users[i].points_math;
			cout << "\n\x1B[92m| \x1B[93mMechanics points: " << users[i].points_mechanics;
			cout << "\n\x1B[92m| \x1B[93mPhysics points: " << users[i].physics_points;
			cout << "\n\x1B[93m-----------------------------------";
			cout << "\n\x1B[92m   Press any button to continue ";
			_getch();
			found = i;
		}
		else
		{
			system("cls");
			cout << "\033[41m";
			cout << "\n\n\033[93m\t--------------------";
			cout << "\n\x1B[92m\t| \033[93m User not found \x1B[92m |";
			cout << "\n\x1B[92m\t| \033[93mTry again? \x1B[37m(y/n)\x1B[92m |";
			cout << "\n\033[93m\t--------------------";
			cout << "\033[0m";
			do {
				choose = _getch();
			} while (choose != 'y' && choose != 'Y' && choose != 'n' && choose != 'N');
			if (choose == 'y')
			{
				goto find;
			}
		}
	}break;
	default:;
	}
	return found;
}

int admin::just_find_user()
{
	Users_ obj;
	load_num_users(obj);
	const int size_vec = obj.num_users_;
	vector<Users_> users(size_vec);
	load_users(users);
	int i;
	char tmp_find[30];
	char choose;
	int found = 0;
find:
	i = 0;

	system("cls");
	cout << "\n\033[91m   |S|e|a|r|c|h|\033[0m \033[94m|U|s|e|r|(s)\033[0m\n";
	cout << "\n\033[94m -----------------------------------";
	cout << "\n\033[93m | \033[97m|1| \033[36mFind by login.\033[0m\t\t  \033[93m |"; //1. Найти по логину
	cout << "\n\033[94m -----------------------------------";
	cout << "\n\033[93m | \033[97m|2| \033[36mFind by phone number.\t  \033[93m |"; //2. Найти по номеру телефона
	cout << "\n\033[94m -----------------------------------";
	cout << "\n\033[93m | \033[97m|3| \033[36mFind a user by email.\t  \033[93m |"; //4. Найти пользователя по email
	cout << "\n\033[94m -----------------------------------";
	cout << "\n\033[93m | \033[97m|4| \033[36mFind User by Family name.  \033[93m |"; //5. Найти пользователя по Фамилии
	cout << "\n\033[94m -----------------------------------";
	cout << "\n\033[93m | \033[97m|0| \033[91mBack to Admin Menu.\t  \033[93m |";
	cout << "\n\033[94m -----------------------------------";
	do {
		choose = _getch();
	} while (choose != '1' && choose != '2' && choose != '3' && choose != '4' && choose != '5' && choose != '0');

	switch (choose)
	{
	case '1':
	{
		system("cls");
		cout << " --------------------------";
		cout << "\n\x1B[92m |S|e|a|r|c|h|\x1B[36m |by|\x1B[92m |login|\n";
		cout << " --------------------------\n";
		cout << "\x1B[92m |\x1B[36m Enter username:\x1B[37m "; cin >> tmp_find;

		for (; i < size_vec; i++)
		{
			found = strcmp(users[i].login_, tmp_find);
			if (found == 0) { break; }
		}
		if (found == 0)
		{
			system("cls");
			cout << "\n\n\x1B[93m\t------------------------";
			cout << "\n\x1B[92m\t| \033[93mSearch, please wait!\x1B[92m |";
			cout << "\n\x1B[93m\t------------------------";
			Sleep(1000);
			system("cls");
			cout << "\n\n\x1B[93m\t------------------------";
			cout << "\n\x1B[92m\t|\033[93m Search, please wait!\x1B[92m |";
			cout << "\n\x1B[92m\t|      \033[93mUser found      \x1B[92m|";
			cout << "\n\x1B[93m\t------------------------";
			Sleep(1000);
			found = i;
			return found;
		}
		else
		{
			system("cls");
			cout << "\033[41m";
			cout << "\n\n\033[93m\t--------------------";
			cout << "\n\x1B[92m\t| \033[93m User not found \x1B[92m |";
			cout << "\n\x1B[92m\t| \033[93mTry again? \x1B[37m(y/n)\x1B[92m |";
			cout << "\n\033[93m\t--------------------";
			cout << "\033[0m";
			do {
				choose = _getch();
			} while (choose != 'y' && choose != 'Y' && choose != 'n' && choose != 'N');
			if (choose == 'y')
			{
				goto find;
			}
			else
			{
				return -1;
			}
		}
	}break;
	case '2':
	{
		system("cls");
		cout << " ---------------------------------";
		cout << "\n\x1B[92m |S|e|a|r|c|h|\x1B[36m |by|\x1B[92m |phone number|\n";
		cout << " ---------------------------------\n";
		cout << "\x1B[92m |\x1B[36m Enter phone number:\x1B[37m "; cin >> tmp_find;
		for (; i < size_vec; i++)
		{
			found = strcmp(users[i].phone_number_, tmp_find);
			if (found == 0) { break; }
		}
		if (found == 0)
		{
			system("cls");
			cout << "\n\n\x1B[93m\t------------------------";
			cout << "\n\x1B[92m\t| \033[93mSearch, please wait!\x1B[92m |";
			cout << "\n\x1B[93m\t------------------------";
			Sleep(1000);
			system("cls");
			cout << "\n\n\x1B[93m\t------------------------";
			cout << "\n\x1B[92m\t|\033[93m Search, please wait!\x1B[92m |";
			cout << "\n\x1B[92m\t|      \033[93mUser found      \x1B[92m|";
			cout << "\n\x1B[93m\t------------------------";
			Sleep(1000);
			found = i;
			return found;
		}
		else
		{
			system("cls");
			cout << "\033[41m";
			cout << "\n\n\033[93m\t--------------------";
			cout << "\n\x1B[92m\t| \033[93m User not found \x1B[92m |";
			cout << "\n\x1B[92m\t| \033[93mTry again? \x1B[37m(y/n)\x1B[92m |";
			cout << "\n\033[93m\t--------------------";
			cout << "\033[0m";
			do {
				choose = _getch();
			} while (choose != 'y' && choose != 'Y' && choose != 'n' && choose != 'N');
			if (choose == 'y')
			{
				goto find;
			}
			else
			{
				return -1;
			}
		}
	}break;
	case '3':
	{
		system("cls");
		cout << " --------------------------";
		cout << "\n\x1B[92m |S|e|a|r|c|h|\x1B[36m |by|\x1B[92m |email|\n";
		cout << " --------------------------\n";
		cout << "\x1B[92m |\x1B[36m Enter mail:\x1B[37m "; cin >> tmp_find;
		for (; i < size_vec; i++)
		{
			found = strcmp(users[i].mail_, tmp_find);
			if (found == 0) { break; }
		}
		if (found == 0)
		{
			system("cls");
			cout << "\n\n\x1B[93m\t------------------------";
			cout << "\n\x1B[92m\t| \033[93mSearch, please wait!\x1B[92m |";
			cout << "\n\x1B[93m\t------------------------";
			Sleep(1000);
			system("cls");
			cout << "\n\n\x1B[93m\t------------------------";
			cout << "\n\x1B[92m\t|\033[93m Search, please wait!\x1B[92m |";
			cout << "\n\x1B[92m\t|      \033[93mUser found      \x1B[92m|";
			cout << "\n\x1B[93m\t------------------------";
			Sleep(1000);
			found = i;
			return found;
		}
		else
		{
			system("cls");
			cout << "\033[41m";
			cout << "\n\n\033[93m\t--------------------";
			cout << "\n\x1B[92m\t| \033[93m User not found \x1B[92m |";
			cout << "\n\x1B[92m\t| \033[93mTry again? \x1B[37m(y/n)\x1B[92m |";
			cout << "\n\033[93m\t--------------------";
			cout << "\033[0m";
			do {
				choose = _getch();
			} while (choose != 'y' && choose != 'Y' && choose != 'n' && choose != 'N');
			if (choose == 'y')
			{
				goto find;
			}
			else
			{
				return -1;
			}
		}
	}break;
	case '4':
	{
		system("cls");
		cout << " --------------------------------";
		cout << "\n\x1B[92m |S|e|a|r|c|h|\x1B[36m |by|\x1B[92m |Family Name|\n";
		cout << " --------------------------------\n";
		cout << "\x1B[92m |\x1B[36m Enter Famyli Name:\x1B[37m "; cin >> tmp_find;
		for (; i < size_vec; i++)
		{
			found = strcmp(users[i].user_family_name_, tmp_find);
			if (found == 0) { break; }
		}
		if (found == 0)
		{
			system("cls");
			cout << "\n\n\x1B[93m\t------------------------";
			cout << "\n\x1B[92m\t| \033[93mSearch, please wait!\x1B[92m |";
			cout << "\n\x1B[93m\t------------------------";
			Sleep(1000);
			system("cls");
			cout << "\n\n\x1B[93m\t------------------------";
			cout << "\n\x1B[92m\t|\033[93m Search, please wait!\x1B[92m |";
			cout << "\n\x1B[92m\t|      \033[93mUser found      \x1B[92m|";
			cout << "\n\x1B[93m\t------------------------";
			Sleep(1000);
			found = i;
			return found;
		}
		else
		{
			system("cls");
			cout << "\033[41m";
			cout << "\n\n\033[93m\t--------------------";
			cout << "\n\x1B[92m\t| \033[93m User not found \x1B[92m |";
			cout << "\n\x1B[92m\t| \033[93mTry again? \x1B[37m(y/n)\x1B[92m |";
			cout << "\n\033[93m\t--------------------";
			cout << "\033[0m";
			do {
				choose = _getch();
			} while (choose != 'y' && choose != 'Y' && choose != 'n' && choose != 'N');
			if (choose == 'y')
			{
				goto find;
			}
			else
			{
				return -1;
			}
		}
	}break;
	default:;
	}
	return -1;
}

void admin::remove_user_s()
{
	Users_ obj;
	load_num_users(obj);
	const int size_vec = obj.num_users_;
	vector<Users_> users(size_vec);
	load_users(users);

	int account_delete = 0;
	char choose;

	system("cls");
	cout << "\n\033[91m\t   |D|e|l|e|t|e|\033[0m |of| \033[94m|d|e|l|e|t|e|\033[0m\n";
	cout << "\n\033[94m ----------------------------------------------------";
	cout << "\n\033[93m | \033[97m|1| \033[36mDelete all accounts (clean up the database).\033[0m\033[93m |";
	cout << "\n\033[94m ----------------------------------------------------";
	cout << "\n\033[93m | \033[97m|2| \033[36mDelete account.\t\t\t\t  \033[93m  |";
	cout << "\n\033[94m ----------------------------------------------------";
	cout << "\n\033[93m | \033[97m|0| \033[91mBack to admin menu.\t\t\t  \033[93m  |";
	cout << "\n\033[94m ----------------------------------------------------";
	do {
		choose = _getch();
	} while (choose != '1' && choose != '2' && choose != '0');

	switch (choose)
	{
	case '1':
	{
		char choose_del;

		system("cls");
		cout << "\n\033[94m -----------------------------------------";
		cout << "\n\033[93m | \033[36mYou confirm the removal of all users?\033[0m\033[93m |";
		cout << "\n\033[93m | \033[92m\t     Y - Yes \033[93m| \033[91mN - No \033[0m\033[93m\t\t |";
		cout << "\n\033[94m -----------------------------------------";
		do {
			choose_del = _getch();
		} while (choose_del != 'y' && choose_del != 'Y' && choose_del != 'n' && choose_del != 'N');
		if (choose_del == 'n' || choose_del == 'N')
		{
			break;
		}
		system("cls");
		cout << "\n\033[94m ----------------------------------------------";
		cout << "\n\033[93m | \033[36mAre you sure you want to delete all users?\033[93m |";
		cout << "\n\033[93m | \033[92m\t        Y - Yes \033[93m| \033[91mN - No \033[0m\033[93m\t      |";
		cout << "\n\033[94m ----------------------------------------------";
		do {
			choose_del = _getch();
		} while (choose_del != 'y' && choose_del != 'Y' && choose_del != 'n' && choose_del != 'N');
		if (choose_del != 'y' && choose_del != 'Y')
		{
		}
		else {
			ofstream File(user_date());
			File.clear();
			File.close();
			File.open(num_users());
			File.clear();
			File.close();
			File.open(save_password_path());
			File.clear();
			File.close();
			system("cls");
			cout << "\n\033[94m  ---------------------";
			cout << "\n\033[93m  | \033[36mAll users deleted\033[0m\033[93m |";
			cout << "\n\033[94m  ---------------------";
			Sleep(2000);
		}
	}break;
	case '2':
	{
		char tmp;
		account_delete = just_find_user();

		if (account_delete == -1)
		{
			break;
		}
		system("cls");
		cout << "\n\033[94m ------------------------------------------";
		cout << "\n\033[93m |\033[36m Are you sure you want to delete user ? \033[93m|";
		cout << "\033[93m\n |\033[92m User\033[97m: " << users[account_delete].login_; cout << setw(39 - strlen(users[account_delete].login_)) << "\033[93m|";
		cout << "\n\033[94m ------------------------------------------";
		cout << "\n\033[93m |\033[92m Y - Yes \033[93m| \033[91mN - No \033[93m|";
		cout << "\n\033[94m --------------------";
		do {
			tmp = _getch();
		} while (tmp != 'y' && tmp != 'Y' && tmp != 'n' && tmp != 'N');
		if (tmp == 'y' || tmp == 'Y')
		{
			system("cls");
			cout << "\n\033[94m -----------------------------------------";
			cout << "\n\033[93m |\033[36m User";
			cout << "\033[93m\n |\033[37m " << users[account_delete].login_;
			users.erase(users.begin() + account_delete);
			obj.num_users_--;
			save_num_users(obj);
			save_users(users);
			cout << "\n\033[93m |\033[92m Deletion completed";
			cout << "\n\033[94m -----------------------------------------";
			cout << "\n |\x1B[93m Press any button to continue"; _getch();
		}
		else
		{
		}
	}break;
	default:;
	}
}

void admin::user_prof_change_menu()
{
	Users_ obj;
	load_num_users(obj);
	const int size_vec = obj.num_users_;
	vector<Users_> users(size_vec);
	load_users(users);
	char choose_;
	auto found = 0;

	system("cls");
	cout << "\n\033[91m |E|d|i|t|i|n|g|\033[0m |user| \033[94m|P|r|o|f|i|l|e|s|\033[0m\n";
	cout << "\n\033[94m  ----------------------------------";
	cout << "\n\033[93m  | \033[97m|1| \033[36mChange login.\033[0m\t\t  \033[93m |";
	cout << "\n\033[94m  ----------------------------------";
	cout << "\n\033[93m  | \033[97m|2| \033[36mChange Password.\t  \033[93m |";
	cout << "\n\033[94m  ----------------------------------";
	cout << "\n\033[93m  | \033[97m|3| \033[36mChange Full name.\t  \033[93m |";
	cout << "\n\033[94m  ----------------------------------";
	cout << "\n\033[93m  | \033[97m|4| \033[36mChange phone number.\t  \033[93m |";
	cout << "\n\033[94m  ----------------------------------";
	cout << "\n\033[93m  | \033[97m|5| \033[36mChange email.\t\t  \033[93m |";
	cout << "\n\033[94m  ----------------------------------";
	cout << "\n\033[93m  | \033[97m|6| \033[36mChange country.\t\t  \033[93m |";
	cout << "\n\033[94m  ----------------------------------";
	cout << "\n\033[93m  | \033[97m|7| \033[36mChange city.\t\t  \033[93m |";
	cout << "\n\033[94m  ----------------------------------";
	cout << "\n\033[93m  | \033[97m|8| \033[36mChange points.\t\t  \033[93m |";
	cout << "\n\033[94m  ----------------------------------";
	cout << "\n\033[93m  | \033[97m|9| \033[36mDate of Birth.\t\t  \033[93m |";
	cout << "\n\033[91m  ----------------------------------";
	cout << "\n\033[93m  | \033[97m|0| \033[91mBack to Admin menu.\t  \033[93m |";
	cout << "\n\033[94m  ----------------------------------";
	do {
		choose_ = _getch();
	} while (choose_ != '1' && choose_ != '2' && choose_ != '3' && choose_ != '4' && choose_ != '5' && choose_ != '6' && choose_ != '7' && choose_ != '8' && choose_ != '9' && choose_ != '0');
	switch (choose_)
	{
	case '1': // Change login
	{
		found = just_find_user();
		if (found == -1)
		{
			break;
		}
	ChangeLogin:
		system("cls");
		cout << "\n\033[91m |E|d|i|t|i|n|g|\033[0m |user| \033[94m|P|r|o|f|i|l|e|s|\033[0m\n";
		cout << "\n\033[94m  ----------------------------------";
		cout << "\n\033[93m  | \033[36mOld username: " << users[found].login_;
		cout << "\n\033[94m  ----------------------------------";
		cout << "\n\033[93m  | \033[36mEnter new username\033[93m: "; cin >> obj.login_;
		for (int i = 0; i < strlen(obj.login_); i++)
		{
			if (strlen(obj.login_) < 4 || strlen(obj.login_) > sizeof(obj.login_) || obj.login_[i] == ' ' || obj.login_[i] == '\n' || obj.login_[i] == '!' || obj.login_[i] == '*' || obj.login_[i] == '"' || obj.login_[i] == '#' || obj.login_[i] == '$' || obj.login_[i] == '%' || obj.login_[i] == '&' || obj.login_[i] == '(' || obj.login_[i] == ')' || obj.login_[i] == '+' || obj.login_[i] == '-' || obj.login_[i] == '.' || obj.login_[i] == ',' || obj.login_[i] == '/' || obj.login_[i] == ':' || obj.login_[i] == ';' || obj.login_[i] == '<' || obj.login_[i] == '>' || obj.login_[i] == '=' || obj.login_[i] == '?' || obj.login_[i] == '@' || obj.login_[i] == '[' || obj.login_[i] == '\\' || obj.login_[i] == ']' || obj.login_[i] == '^' || obj.login_[i] == '_' || obj.login_[i] == '`' || obj.login_[i] == '{' || obj.login_[i] == '|' || obj.login_[i] == '}' || obj.login_[i] == '~')
			{
				system("cls");
				cout << "\x1B[93m--------------------------------------------------------------------------------------------------\n";
				cout << "\x1B[93m|\x1B[91mThis login is not valid (Forbidden symbols) \x1B[34m[\x1B[97m" << obj.login_ << "\x1B[34m] \x1B[91m, please try again !! \x1B[34m(\x1B[32my\x1B[34m / \x1B[31many button\x1B[34m):  \x1B[0m"; char tmp = _getch(); if (tmp == 'y') { goto ChangeLogin; }
				else
				{
					return;
				}
			}
		}
		cout << "\033[94m  ----------------------------------";
		cout << "\n\033[93m  | Login has been changed ";
		cout << "\n\033[94m  ----------------------------------";
		cout << "\n\033[94m  | \033[91mPress any button to continue";
		cout << "\n\033[94m  ----------------------------------";
		_getch();
		strcpy(users[found].login_, obj.login_);
	}break;
	case '2': // Change password (user)
	{
		found = just_find_user();
		if (found == -1)
		{
			break;
		}
	ChangePassword:
		system("cls");
		cout << "\n\033[91m |E|d|i|t|i|n|g|\033[0m |user| \033[94m|P|r|o|f|i|l|e|s|\033[0m\n";
		cout << "\n\033[94m  ----------------------------------------";
		cout << "\n\033[93m  | \033[36mOld user password: " << users[found].password_;
		cout << "\n\033[94m  ----------------------------------------";
		cout << "\n\033[93m  | \033[36mEnter new user password\033[93m: "; cin >> obj.password_;
		for (int i = 0; i < strlen(obj.password_); i++)
		{
			if (strlen(obj.password_) < 4 || strlen(obj.password_) > sizeof(obj.password_) || obj.password_[i] == ' ' || obj.password_[i] == '\n' || obj.password_[i] == '!' || obj.password_[i] == '*' || obj.password_[i] == '"' || obj.password_[i] == '#' || obj.password_[i] == '$' || obj.password_[i] == '%' || obj.password_[i] == '&' || obj.password_[i] == '(' || obj.password_[i] == ')' || obj.password_[i] == '+' || obj.password_[i] == '-' || obj.password_[i] == '.' || obj.password_[i] == ',' || obj.password_[i] == '/' || obj.password_[i] == ':' || obj.password_[i] == ';' || obj.password_[i] == '<' || obj.password_[i] == '>' || obj.password_[i] == '=' || obj.password_[i] == '?' || obj.password_[i] == '@' || obj.password_[i] == '[' || obj.password_[i] == '\\' || obj.password_[i] == ']' || obj.password_[i] == '^' || obj.password_[i] == '_' || obj.password_[i] == '`' || obj.password_[i] == '{' || obj.password_[i] == '|' || obj.password_[i] == '}' || obj.password_[i] == '~')
			{
				system("cls");
				cout << "\x1B[93m--------------------------------------------------------------------------------------------------\n";
				cout << "\x1B[93m|\x1B[91mThis password is not valid (Forbidden symbols) \x1B[34m[\x1B[97m" << obj.password_ << "\x1B[34m] \x1B[91m, please try again !! \x1B[34m(\x1B[32my\x1B[34m / \x1B[31many button\x1B[34m):  \x1B[0m"; char tmp = _getch(); if (tmp == 'y') {
					goto ChangePassword;
				}
				else
				{
					return;
				}
			}
		}
		cout << "\033[94m  ----------------------------------------";
		cout << "\n\033[93m  | Password has been changed ";
		cout << "\n\033[94m  ----------------------------------------";
		cout << "\n\033[94m  | \033[91mPress any button to continue";
		cout << "\n\033[94m  ----------------------------------------";
		_getch();
		strcpy(users[found].password_, obj.password_);
	}break;
	case '3': // change full name
	{
		found = just_find_user();
		if (found == -1)
		{
			break;
		}

		system("cls");
		cout << "\n\033[91m |E|d|i|t|i|n|g|\033[0m |user| \033[94m|P|r|o|f|i|l|e|s|\033[0m\n";
		cout << "\n\033[94m  ----------------------------------";
		cout << "\n\033[93m  | \033[97m|1| \033[36mChange Name.\t\t  \033[93m |";
		cout << "\n\033[94m  ----------------------------------";
		cout << "\n\033[93m  | \033[97m|2| \033[36mChange Family name.\t  \033[93m |";
		cout << "\n\033[94m  ----------------------------------";
		cout << "\n\033[93m  | \033[97m|3| \033[36mChange Patronymic.\t  \033[93m |";
		cout << "\n\033[94m  ----------------------------------";
		cout << "\n\033[93m  | \033[97m|0| \033[91mBack to Admin menu.\t  \033[93m |";
		cout << "\n\033[94m  ----------------------------------";
		do {
			choose_ = _getch();
		} while (choose_ != '1' && choose_ != '2' && choose_ != '3' && choose_ != '0');
		switch (choose_)
		{
		case '1':
		{
		ChangeName:
			system("cls");
			cout << "\n\033[91m |E|d|i|t|i|n|g|\033[0m |user| \033[94m|P|r|o|f|i|l|e|s|\033[0m\n";
			cout << "\n\033[93m  | \033[36mOld name: " << users[found].user_name_;
			cout << "\n\033[94m  ----------------------------------";
			cout << "\n\033[93m  | \033[36mEnter new name\033[93m: "; cin >> obj.user_name_;
			for (int i = 0; i < strlen(obj.user_name_); i++)
			{
				if (strlen(obj.user_name_) < 1 || strlen(obj.user_name_) > sizeof(obj.user_name_) || obj.user_name_[i] == ' ' || obj.user_name_[i] == '\n' || obj.user_name_[i] == '!' || obj.user_name_[i] == '*' || obj.user_name_[i] == '"' || obj.user_name_[i] == '#' || obj.user_name_[i] == '$' || obj.user_name_[i] == '%' || obj.user_name_[i] == '&' || obj.user_name_[i] == '(' || obj.user_name_[i] == ')' || obj.user_name_[i] == '+' || obj.user_name_[i] == '-' || obj.user_name_[i] == '.' || obj.user_name_[i] == ',' || obj.user_name_[i] == '/' || obj.user_name_[i] == ':' || obj.user_name_[i] == ';' || obj.user_name_[i] == '<' || obj.user_name_[i] == '>' || obj.user_name_[i] == '=' || obj.user_name_[i] == '?' || obj.user_name_[i] == '@' || obj.user_name_[i] == '[' || obj.user_name_[i] == '\\' || obj.user_name_[i] == ']' || obj.user_name_[i] == '^' || obj.user_name_[i] == '_' || obj.user_name_[i] == '`' || obj.user_name_[i] == '{' || obj.user_name_[i] == '|' || obj.user_name_[i] == '}' || obj.user_name_[i] == '~' || obj.user_name_[i] >= '0' && obj.user_name_[i] <= '9')
				{
					system("cls");
					cout << "\x1B[93m--------------------------------------------------------------------------------------------------\n";
					cout << "\x1B[93m|\x1B[91mIncorrectly entered name\x1B[34m[\x1B[97m" << obj.user_name_ << "\x1B[34m] \x1B[91m, please try again !! \x1B[34m(\x1B[32my\x1B[34m / \x1B[31many button\x1B[34m):  \x1B[0m"; char tmp = _getch(); if (tmp == 'y') {
						goto ChangeName;
					}
					else
					{
						return;
					}
				}
			}
			cout << "\033[94m  ----------------------------------";
			cout << "\n\033[93m  | Password has been changed ";
			cout << "\n\033[94m  ----------------------------------";
			cout << "\n\033[94m  | \033[91mPress any button to continue";
			cout << "\n\033[94m  ----------------------------------";
			_getch();
			strcpy(users[found].user_name_, obj.user_name_);
		}break;
		case '2':
		{
		ChangeFamilyName:
			system("cls");
			cout << "\n\033[91m |E|d|i|t|i|n|g|\033[0m |user| \033[94m|P|r|o|f|i|l|e|s|\033[0m\n";
			cout << "\n\033[93m  | \033[36mOld Family name: " << users[found].user_family_name_;
			cout << "\n\033[94m  ----------------------------------";
			cout << "\n\033[93m  | \033[36mEnter new Family name\033[93m: "; cin >> obj.user_family_name_;
			for (int i = 0; i < strlen(obj.user_family_name_); i++)
			{
				if (strlen(obj.user_family_name_) < 1 || strlen(obj.user_family_name_) > sizeof(obj.user_family_name_) || obj.user_family_name_[i] == ' ' || obj.user_family_name_[i] == '\n' || obj.user_family_name_[i] == '!' || obj.user_family_name_[i] == '*' || obj.user_family_name_[i] == '"' || obj.user_family_name_[i] == '#' || obj.user_family_name_[i] == '$' || obj.user_family_name_[i] == '%' || obj.user_family_name_[i] == '&' || obj.user_family_name_[i] == '(' || obj.user_family_name_[i] == ')' || obj.user_family_name_[i] == '+' || obj.user_family_name_[i] == '-' || obj.user_family_name_[i] == '.' || obj.user_family_name_[i] == ',' || obj.user_family_name_[i] == '/' || obj.user_family_name_[i] == ':' || obj.user_family_name_[i] == ';' || obj.user_family_name_[i] == '<' || obj.user_family_name_[i] == '>' || obj.user_family_name_[i] == '=' || obj.user_family_name_[i] == '?' || obj.user_family_name_[i] == '@' || obj.user_family_name_[i] == '[' || obj.user_family_name_[i] == '\\' || obj.user_family_name_[i] == ']' || obj.user_family_name_[i] == '^' || obj.user_family_name_[i] == '_' || obj.user_family_name_[i] == '`' || obj.user_family_name_[i] == '{' || obj.user_family_name_[i] == '|' || obj.user_family_name_[i] == '}' || obj.user_family_name_[i] == '~' || obj.user_family_name_[i] >= '0' && obj.user_family_name_[i] <= '9')
				{
					system("cls");
					cout << "\x1B[93m--------------------------------------------------------------------------------------------------\n";
					cout << "\x1B[93m|\x1B[91mIncorrectly entered Family name\x1B[34m[\x1B[97m" << obj.user_family_name_ << "\x1B[34m] \x1B[91m, please try again !! \x1B[34m(\x1B[32my\x1B[34m / \x1B[31many button\x1B[34m):  \x1B[0m"; char tmp = _getch(); if (tmp == 'y') {
						goto ChangeFamilyName;
					}
					else
					{
						return;
					}
				}
			}
			cout << "\033[94m  ----------------------------------";
			cout << "\n\033[93m  | Password has been changed ";
			cout << "\n\033[94m  ----------------------------------";
			cout << "\n\033[94m  | \033[91mPress any button to continue";
			cout << "\n\033[94m  ----------------------------------";
			_getch();
			strcpy(users[found].user_family_name_, obj.user_family_name_);
		}break;
		case '3':
		{
		ChangePatronymic:
			system("cls");
			cout << "\n\033[91m |E|d|i|t|i|n|g|\033[0m |user| \033[94m|P|r|o|f|i|l|e|s|\033[0m\n";
			cout << "\n\033[93m  | \033[36mOld Patronymic: " << users[found].user_patronymic_;
			cout << "\n\033[94m  ----------------------------------";
			cout << "\n\033[93m  | \033[36mEnter new Patronymic\033[93m: "; cin >> obj.user_patronymic_;
			for (int i = 0; i < strlen(obj.user_patronymic_); i++)
			{
				if (strlen(obj.user_patronymic_) < 1 || strlen(obj.user_patronymic_) > sizeof(obj.user_patronymic_) || obj.user_patronymic_[i] == ' ' || obj.user_patronymic_[i] == '\n' || obj.user_patronymic_[i] == '!' || obj.user_patronymic_[i] == '*' || obj.user_patronymic_[i] == '"' || obj.user_patronymic_[i] == '#' || obj.user_patronymic_[i] == '$' || obj.user_patronymic_[i] == '%' || obj.user_patronymic_[i] == '&' || obj.user_patronymic_[i] == '(' || obj.user_patronymic_[i] == ')' || obj.user_patronymic_[i] == '+' || obj.user_patronymic_[i] == '-' || obj.user_patronymic_[i] == '.' || obj.user_patronymic_[i] == ',' || obj.user_patronymic_[i] == '/' || obj.user_patronymic_[i] == ':' || obj.user_patronymic_[i] == ';' || obj.user_patronymic_[i] == '<' || obj.user_patronymic_[i] == '>' || obj.user_patronymic_[i] == '=' || obj.user_patronymic_[i] == '?' || obj.user_patronymic_[i] == '@' || obj.user_patronymic_[i] == '[' || obj.user_patronymic_[i] == '\\' || obj.user_patronymic_[i] == ']' || obj.user_patronymic_[i] == '^' || obj.user_patronymic_[i] == '_' || obj.user_patronymic_[i] == '`' || obj.user_patronymic_[i] == '{' || obj.user_patronymic_[i] == '|' || obj.user_patronymic_[i] == '}' || obj.user_patronymic_[i] == '~' || obj.user_patronymic_[i] >= '0' && obj.user_patronymic_[i] <= '9')
				{
					system("cls");
					cout << "\x1B[93m--------------------------------------------------------------------------------------------------\n";
					cout << "\x1B[93m|\x1B[91mIncorrectly entered patronymic name\x1B[34m[\x1B[97m" << obj.user_patronymic_ << "\x1B[34m] \x1B[91m, please try again !! \x1B[34m(\x1B[32my\x1B[34m / \x1B[31many button\x1B[34m):  \x1B[0m"; char tmp = _getch(); if (tmp == 'y') {
						goto ChangePatronymic;
					}
					else
					{
						return;
					}
				}
			}
			cout << "\033[94m  ----------------------------------";
			cout << "\n\033[93m  | Password has been changed ";
			cout << "\n\033[94m  ----------------------------------";
			cout << "\n\033[94m  | \033[91mPress any button to continue";
			cout << "\n\033[94m  ----------------------------------";
			_getch();
			strcpy(users[found].user_patronymic_, obj.user_patronymic_);
		}break;
		default:;
		}
	}break;
	case '4': // Change Phone Number
	{
		found = just_find_user();
		if (found == -1)
		{
			break;
		}
	ChangePhoneNumber:
		system("cls");
		cout << "\n\033[91m |E|d|i|t|i|n|g|\033[0m |user| \033[94m|P|r|o|f|i|l|e|s|\033[0m\n";
		cout << "\n\033[93m  | \033[36mOld phone number: " << users[found].phone_number_;
		cout << "\n\033[94m  ----------------------------------";
		cout << "\n\033[93m  | \033[36mEnter new phone number\033[93m: "; cin >> obj.phone_number_;
		for (int i = 0; i < strlen(obj.phone_number_); i++)
		{
			if (strlen(obj.phone_number_) < 10 || strlen(obj.phone_number_) > sizeof(obj.phone_number_) || obj.phone_number_[i] == ' ' || obj.phone_number_[i] == '\n' || obj.phone_number_[i] == '!' || obj.phone_number_[i] == '*' || obj.phone_number_[i] == '"' || obj.phone_number_[i] == '#' || obj.phone_number_[i] == '$' || obj.phone_number_[i] == '%' || obj.phone_number_[i] > '9' || obj.phone_number_[i] == '&' || obj.phone_number_[i] == '(' || obj.phone_number_[i] == ')' || obj.phone_number_[i] == '-' || obj.phone_number_[i] == '.' || obj.phone_number_[i] == ',' || obj.phone_number_[i] == '/' || obj.phone_number_[i] == ':' || obj.phone_number_[i] == ';' || obj.phone_number_[i] == '<' || obj.phone_number_[i] == '>' || obj.phone_number_[i] == '=' || obj.phone_number_[i] == '?' || obj.phone_number_[i] == '@' || obj.phone_number_[i] == '[' || obj.phone_number_[i] == '\\' || obj.phone_number_[i] == ']' || obj.phone_number_[i] == '^' || obj.phone_number_[i] == '_' || obj.phone_number_[i] == '`' || obj.phone_number_[i] == '{' || obj.phone_number_[i] == '|' || obj.phone_number_[i] == '}' || obj.phone_number_[i] == '~')
			{
				system("cls");
				cout << "\x1B[93m--------------------------------------------------------------------------------------------------\n";
				cout << "\x1B[93m|\x1B[91mIncorrectly phone number\x1B[34m[\x1B[97m" << obj.phone_number_ << "\x1B[34m] \x1B[91m, please try again !! \x1B[34m(\x1B[32my\x1B[34m / \x1B[31many button\x1B[34m):  \x1B[0m"; char tmp = _getch(); if (tmp == 'y') {
					goto ChangePhoneNumber;
				}
				else
				{
					return;
				}
			}
		}
		cout << "\033[94m  ----------------------------------";
		cout << "\n\033[93m  | Phone number has been changed ";
		cout << "\n\033[94m  ----------------------------------";
		cout << "\n\033[94m  | \033[91mPress any button to continue";
		cout << "\n\033[94m  ----------------------------------";
		_getch();
		strcpy(users[found].phone_number_, obj.phone_number_);
	}break;
	case '5': // Change email
	{
		found = just_find_user();
		if (found == -1)
		{
			break;
		}
	ChangeMail:
		system("cls");
		cout << "\n\033[91m |E|d|i|t|i|n|g|\033[0m |user| \033[94m|P|r|o|f|i|l|e|s|\033[0m\n";
		cout << "\n\033[93m  | \033[36mOld mail: " << users[found].mail_;
		cout << "\n\033[94m  ----------------------------------";
		cout << "\n\033[93m  | \033[36mEnter new mail\033[93m: "; cin >> obj.mail_;
		for (int i = 0; i < strlen(obj.mail_); i++)
		{
			if (strlen(obj.mail_) < 3 || strlen(obj.mail_) > sizeof(obj.mail_) || obj.mail_[i] == '  ' || obj.mail_[i] == '\n' || obj.mail_[i] == '!' || obj.mail_[i] == '*' || obj.mail_[i] == '"' || obj.mail_[i] == '#' || obj.mail_[i] == '$' || obj.mail_[i] == '%' || obj.mail_[i] == '&' || obj.mail_[i] == '(' || obj.mail_[i] == ')' || obj.mail_[i] == '+' || obj.mail_[i] == '-' || obj.mail_[i] == ',' || obj.mail_[i] == '/' || obj.mail_[i] == ':' || obj.mail_[i] == ';' || obj.mail_[i] == '<' || obj.mail_[i] == '>' || obj.mail_[i] == '=' || obj.mail_[i] == '?' || obj.mail_[i] == '[' || obj.mail_[i] == '\\' || obj.mail_[i] == ']' || obj.mail_[i] == '^' || obj.mail_[i] == '`' || obj.mail_[i] == '{' || obj.mail_[i] == '|' || obj.mail_[i] == '}' || obj.mail_[i] == '~')
			{
				system("cls");
				cout << "\x1B[93m--------------------------------------------------------------------------------------------------\n";
				cout << "\x1B[93m|\x1B[91mIncorrectly mail \x1B[34m[\x1B[97m" << obj.mail_ << "\x1B[34m] \x1B[91m, please try again !! \x1B[34m(\x1B[32my\x1B[34m / \x1B[31many button\x1B[34m):  \x1B[0m"; char tmp = _getch(); if (tmp == 'y') {
					goto ChangeMail;
				}
				else
				{
					return;
				}
			}
		}
		cout << "\033[94m  ----------------------------------";
		cout << "\n\033[93m  | Mail has been changed ";
		cout << "\n\033[94m  ----------------------------------";
		cout << "\n\033[94m  | \033[91mPress any button to continue";
		cout << "\n\033[94m  ----------------------------------";
		_getch();
		strcpy(users[found].mail_, obj.mail_);
	}break;
	case '6': // Change country
	{
		found = just_find_user();
		if (found == -1)
		{
			break;
		}
	ChangeCountry:
		system("cls");
		cout << "\n\033[91m |E|d|i|t|i|n|g|\033[0m |user| \033[94m|P|r|o|f|i|l|e|s|\033[0m\n";
		cout << "\n\033[93m  | \033[36mOld Country: " << users[found].country;
		cout << "\n\033[94m  ----------------------------------";
		cout << "\n\033[93m  | \033[36mEnter new Country\033[93m: "; cin >> obj.country;
		for (int i = 0; i < strlen(obj.country); i++)
		{
			if (strlen(obj.country) < 3 || strlen(obj.country) > sizeof(obj.country) || obj.country[i] == ' ' || obj.country[i] == '@' || obj.country[i] == '\n' || obj.country[i] == '!' || obj.country[i] == '*' || obj.country[i] == '"' || obj.country[i] == '#' || obj.country[i] == '$' || obj.country[i] == '%' || obj.country[i] == '&' || obj.country[i] == '(' || obj.country[i] == ')' || obj.country[i] == '+' || obj.country[i] == '-' || obj.country[i] == ',' || obj.country[i] == '/' || obj.country[i] == ':' || obj.country[i] == ';' || obj.country[i] == '<' || obj.country[i] == '>' || obj.country[i] == '=' || obj.country[i] == '?' || obj.country[i] == '[' || obj.country[i] == '\\' || obj.country[i] == ']' || obj.country[i] == '^' || obj.country[i] == '_' || obj.country[i] == '`' || obj.country[i] == '{' || obj.country[i] == '|' || obj.country[i] == '}' || obj.country[i] == '~' || obj.country[i] >= '0' && obj.country[i] <= '9')
			{
				system("cls");
				cout << "\x1B[93m--------------------------------------------------------------------------------------------------\n";
				cout << "\x1B[93m|\x1B[91mIncorrect country entered \x1B[34m[\x1B[97m" << obj.country << "\x1B[34m] \x1B[91m, please try again !! \x1B[34m(\x1B[32my\x1B[34m / \x1B[31many button\x1B[34m):  \x1B[0m"; char tmp = _getch(); if (tmp == 'y') {
					goto ChangeCountry;
				}
				else
				{
					return;
				}
			}
		}
		cout << "\033[94m  ----------------------------------";
		cout << "\n\033[93m  | Country has been changed ";
		cout << "\n\033[94m  ----------------------------------";
		cout << "\n\033[94m  | \033[91mPress any button to continue";
		cout << "\n\033[94m  ----------------------------------";
		_getch();
		strcpy(users[found].country, obj.country);
	}break;
	case '7': // Change city
	{
		found = just_find_user();
		if (found == -1)
		{
			break;
		}
	ChangeCity:
		system("cls");
		cout << "\n\033[91m |E|d|i|t|i|n|g|\033[0m |user| \033[94m|P|r|o|f|i|l|e|s|\033[0m\n";
		cout << "\n\033[93m  | \033[36mOld City: " << users[found].city;
		cout << "\n\033[94m  ----------------------------------";
		cout << "\n\033[93m  | \033[36mEnter new City\033[93m: "; cin >> obj.city;
		for (int i = 0; i < strlen(obj.city); i++)
		{
			if (strlen(obj.city) < 3 || strlen(obj.city) > sizeof(obj.city) || obj.city[i] == ' ' || obj.city[i] == '@' || obj.city[i] == '\n' || obj.city[i] == '!' || obj.city[i] == '*' || obj.city[i] == '"' || obj.city[i] == '#' || obj.city[i] == '$' || obj.city[i] == '%' || obj.city[i] == '&' || obj.city[i] == '(' || obj.city[i] == ')' || obj.city[i] == '+' || obj.city[i] == '-' || obj.city[i] == ',' || obj.city[i] == '/' || obj.city[i] == ':' || obj.city[i] == ';' || obj.city[i] == '<' || obj.city[i] == '>' || obj.city[i] == '=' || obj.city[i] == '?' || obj.city[i] == '[' || obj.city[i] == '\\' || obj.city[i] == ']' || obj.city[i] == '^' || obj.city[i] == '_' || obj.city[i] == '`' || obj.city[i] == '{' || obj.city[i] == '|' || obj.city[i] == '}' || obj.city[i] == '~')
			{
				system("cls");
				cout << "\x1B[93m--------------------------------------------------------------------------------------------------\n";
				cout << "\x1B[93m|\x1B[91mIncorrect city entered \x1B[34m[\x1B[97m" << obj.city << "\x1B[34m] \x1B[91m, please try again !! \x1B[34m(\x1B[32my\x1B[34m / \x1B[31many button\x1B[34m):  \x1B[0m"; char tmp = _getch(); if (tmp == 'y') {
					goto 	ChangeCity;
				}
				else
				{
					return;
				}
			}
		}
		cout << "\033[94m  ----------------------------------";
		cout << "\n\033[93m  | City has been changed ";
		cout << "\n\033[94m  ----------------------------------";
		cout << "\n\033[94m  | \033[91mPress any button to continue";
		cout << "\n\033[94m  ----------------------------------";
		_getch();
		strcpy(users[found].city, obj.city);
	}break;
	case '8': // Change points
	{
		found = just_find_user();
		if (found == -1)
		{
			break;
		}

		system("cls");
		cout << "\n\033[91m |E|d|i|t|i|n|g|\033[0m |user| \033[94m|P|r|o|f|i|l|e|s|\033[0m\n";
		cout << "\n\033[94m  ----------------------------------";
		cout << "\n\033[93m  | \033[97m|1| \033[36mChange math points.\033[0m\t  \033[93m |";
		cout << "\n\033[94m  ----------------------------------";
		cout << "\n\033[93m  | \033[97m|2| \033[36mChange Physics Points.\t  \033[93m |";
		cout << "\n\033[94m  ----------------------------------";
		cout << "\n\033[93m  | \033[97m|3| \033[36mChange Mechanics Points.  \033[93m |";
		cout << "\n\033[94m  ----------------------------------";
		cout << "\n\033[93m  | \033[97m|0| \033[91mBack to Admin menu.\t  \033[93m |";
		cout << "\n\033[94m  ----------------------------------";
		do
		{
			choose_ = _getch();
		} while (choose_ != '1' && choose_ != '2' && choose_ != '3' && choose_ != '0');
		switch (choose_)
		{
		case '1':
		{  // Change math points
		ChangeMathPoint:
			system("cls");
			cout << "\n\033[91m |E|d|i|t|i|n|g|\033[0m |user| \033[94m|P|r|o|f|i|l|e|s|\033[0m\n";
			cout << "\n\033[93m  | \033[36mMath points: " << users[found].points_math;
			cout << "\n\033[94m  ----------------------------------";
			cout << "\n\033[93m  | \033[36mNew number of points (0 - 1000)\033[93m: "; cin >> obj.points_math;
			for (int i = 0; i < 1; i++)
			{
				if (obj.points_math > 1000 || obj.points_math < 0)
				{
					system("cls");
					cout << "\x1B[93m--------------------------------------------------------------------------------------------------\n";
					cout << "\x1B[93m|\x1B[91mToo small or large value \x1B[34m[\x1B[97m" << obj.points_math << "\x1B[34m] \x1B[91m, please try again !! \x1B[34m(\x1B[32my\x1B[34m / \x1B[31many button\x1B[34m):  \x1B[0m"; char tmp = _getch(); if (tmp == 'y') {
						goto ChangeMathPoint;
					}
					else
					{
						return;
					}
				}
			}
			cout << "\033[94m  ----------------------------------";
			cout << "\n\033[93m  | Math points has been changed   |";
			cout << "\n\033[94m  ----------------------------------";
			cout << "\n\033[94m  | \033[91mPress any button to continue\033[94m   |";
			cout << "\n\033[94m  ----------------------------------";
			_getch();
			users[found].points_math = obj.points_math;
		}break;
		case '2': // Change physics points
		{
		ChangePhysicsPoint:
			system("cls");
			cout << "\n\033[91m |E|d|i|t|i|n|g|\033[0m |user| \033[94m|P|r|o|f|i|l|e|s|\033[0m\n";
			cout << "\n\033[93m  | \033[36mPhysics points: " << users[found].physics_points;
			cout << "\n\033[94m  ----------------------------------";
			cout << "\n\033[93m  | \033[36mNew number of points (0 - 1000)\033[93m: "; cin >> obj.physics_points;
			for (int i = 0; i < 1; i++)
			{
				if (obj.physics_points > 1000 || obj.physics_points < 0)
				{
					system("cls");
					cout << "\x1B[93m--------------------------------------------------------------------------------------------------\n";
					cout << "\x1B[93m|\x1B[91mToo small or large value \x1B[34m[\x1B[97m" << obj.physics_points << "\x1B[34m] \x1B[91m, please try again !! \x1B[34m(\x1B[32my\x1B[34m / \x1B[31many button\x1B[34m):  \x1B[0m"; char tmp = _getch(); if (tmp == 'y') {
						goto ChangePhysicsPoint;
					}
					else
					{
						return;
					}
				}
			}
			cout << "\033[94m  -----------------------------------";
			cout << "\n\033[93m  | Physics points has been changed |";
			cout << "\n\033[94m  -----------------------------------";
			cout << "\n\033[94m  | \033[91mPress any button to continue \033[94m|";
			cout << "\n\033[94m  --------------------------------";
			_getch();
			users[found].physics_points = obj.physics_points;
		}break;
		case '3': // Change mechanics points
		{
		ChangeMechanicsPoint:
			system("cls");
			cout << "\n\033[91m |E|d|i|t|i|n|g|\033[0m |user| \033[94m|P|r|o|f|i|l|e|s|\033[0m\n";
			cout << "\n\033[93m  | \033[36mMath points: " << users[found].points_mechanics;
			cout << "\n\033[94m  ----------------------------------";
			cout << "\n\033[93m  | \033[36mNew number of points (0 - 1000)\033[93m: "; cin >> obj.points_mechanics;
			for (int i = 0; i < 1; i++)
			{
				if (obj.points_mechanics > 1000 || obj.points_mechanics < 0)
				{
					system("cls");
					cout << "\x1B[93m--------------------------------------------------------------------------------------------------\n";
					cout << "\x1B[93m|\x1B[91mToo small or large value \x1B[34m[\x1B[97m" << obj.points_mechanics << "\x1B[34m] \x1B[91m, please try again !! \x1B[34m(\x1B[32my\x1B[34m / \x1B[31many button\x1B[34m):  \x1B[0m"; char tmp = _getch(); if (tmp == 'y') {
						goto ChangeMechanicsPoint;
					}
					else
					{
						return;
					}
				}
			}
			cout << "\033[94m  -------------------------------------";
			cout << "\n\033[93m  | Mechanics points has been changed |";
			cout << "\n\033[94m  -------------------------------------";
			cout << "\n\033[94m  | \033[91mPress any button to continue \033[94m|";
			cout << "\n\033[94m  --------------------------------";
			_getch();
			users[found].points_mechanics = obj.points_mechanics;
		}break;
		default:;
		}
	}break;
	case '9': // Date of Birth
	{
		found = just_find_user();
		if (found == -1)
		{
			break;
		}
	ChangeDateofBirth:
		system("cls");
		cout << "\n\033[91m |E|d|i|t|i|n|g|\033[0m |user| \033[94m|P|r|o|f|i|l|e|s|\033[0m\n";
		cout << "\n\033[93m | \033[36mDate of Birth:\033[97m " << users[found].day << "." << users[found].month << "." << users[found].year;
		cout << "\n\033[94m -------------------------------------------";
		cout << "\n\033[93m | \033[94mEnter new Date of Birth (day.month.year): \033[93m";
		cin >> setw(2) >> obj.day;
		cin.ignore();
		cin >> setw(2) >> obj.month;
		cin.ignore();
		cin >> setw(4) >> obj.year;
		for (int i = 0; i < 1; i++)
		{
			if (obj.day > 31 || obj.day < 1 || obj.month > 12 || obj.month < 1 || obj.year > 2050 || obj.year < 1930)
			{
				system("cls");
				cout << "\x1B[93m--------------------------------------------------------------------------------------------------\n";
				cout << "\x1B[93m|\x1B[91mDate entered incorrectly \x1B[34m[\x1B[97m" << obj.day << "." << obj.month << "." << obj.year << "\x1B[34m] \x1B[91m, please try again !! \x1B[34m(\x1B[32my\x1B[34m / \x1B[31many button\x1B[34m):  \x1B[0m"; char tmp = _getch(); if (tmp == 'y') {
					goto ChangeDateofBirth;
				}
				else
				{
					return;
				}
			}
		}
		cout << "\033[94m -------------------------------------------";
		cout << "\n\033[93m | Date of Birth  has been changed ";
		cout << "\n\033[94m -------------------------------------------";
		cout << "\n\033[94m | \033[91mPress any button to continue";
		cout << "\n\033[94m -------------------------------------------";
		_getch();
		users[found].day = obj.day;

		users[found].month = obj.month;

		users[found].year = obj.year;
	}break;
	default:;
	}
	save_users(users);
}

void admin::backup_users_date()
{
	char choose;
	admin Admin;
	SYSTEMTIME getlctime;

	char buffer[256]; // buffer for GetUserName
	DWORD size; // size username
	size = sizeof(buffer); // size buffer
	GetUserName(buffer, &size);
	char dir_backup[100] = { "C:\\Users\\" };
	strcat(dir_backup, buffer);
	strcat(dir_backup, R"(\Documents\Testing System\AdminDate\BackUp)");

	system("cls");
	cout << "\n\033[32m      |M|e|n|u|\033[0m \033[33m|B|a|c|k|u|p|\033[0m\n";
	cout << "\n\033[94m -----------------------------------";
	cout << "\n\033[93m | \033[97m|1| \033[36mMake a backup.\033[0m\t\t  \033[93m |";
	cout << "\n\033[94m -----------------------------------";
	cout << "\n\033[93m | \033[97m|2| \033[36mUpload backup.\t\t  \033[93m |";
	cout << "\n\033[94m -----------------------------------";
	cout << "\n\033[93m | \033[97m|3| \033[36mDelete backup.\t\t  \033[93m |";
	cout << "\n\033[94m -----------------------------------";
	cout << "\n\033[93m | \033[97m|9| \033[91mBack to Admin menu.\t  \033[93m |";
	cout << "\n\033[94m -----------------------------------";
	do {
		choose = _getch();
	} while (choose != '1' && choose != '2' && choose != '3' && choose != '9');
	switch (choose)
	{
	case '1':
	{
		Users_ obj;
		load_num_users(obj);
		const int size_vec = obj.num_users_;
		if (size_vec != 0)
		{
			vector<Users_> users(size_vec);
			load_users(users);
			ifstream file_c;
			file_c.open(date_backup());
			if (file_c.is_open())
			{
				file_c >> Admin.backup_day_ >> Admin.backup_month_ >> Admin.backup_year_;
			}
			file_c.close();
			if (Admin.backup_day_ == 0 && Admin.backup_month_ == 0 && Admin.backup_year_ == 0)
			{
				system("cls");
				cout << "\033[92m----------------------\n";//
				cout << "\033[93m|     \033[33mNo backup \033[93m     |\n";
				cout << "\033[93m| \033[33m Create a backup? \033[93m |\n";
				cout << "----------------------\n";
				cout << "|\033[92m   Y - Yes \033[91mN - No \033[93m  |\n";
				cout << "----------------------\n";
				do {
					choose = _getch();
				} while (choose != 'y' && choose != 'Y' && choose != 'n' && choose != 'N');
				if (choose == 'Y' || choose == 'y')
				{
				}
				else
				{
					break;
				}
			}
			else
			{
				system("cls");
				cout << "\033[92m-----------------------------\n";
				cout << "\033[93m| \033[33mThere is already a backup \033[93m|\n";
				cout << "\033[93m| \033[33mCopy date:  \033[97m " << Admin.backup_day_ << "." << Admin.backup_month_ << "." << Admin.backup_year_;/*if*/ if (Admin.backup_day_ < 10 || Admin.backup_month_ < 10) { cout << "    |"; }
				else { cout << "   \033[93m|"; }
				cout << "\n\033[92m-----------------------------\n\n";
				cout << "----------------------------------------\n";
				cout << "\033[93m|\033[94m Do you want to overwrite the backup? \033[93m|\n\033[93m|\033[92m\t     Y - Yes \033[91mN - No \033[93m\t       |\n";
				cout << "----------------------------------------";
				do {
					choose = _getch();
				} while (choose != 'y' && choose != 'Y' && choose != 'n' && choose != 'N');
				if (choose == 'N' || choose == 'n')
				{
					break;
				}
			}
			CreateDirectory(dir_backup, nullptr); // Creating a directory for backup

			system("cls");
			cout << "\033[92m---------------------------------------------------------------\n";
			cout << "\033[91m| ->_-> Backup in progress, please don't closed program ->_-> |\n";
			cout << "\033[92m---------------------------------------------------------------";
			Sleep(1000);
			// save number users
			ofstream file;
			file.open(backup_num_users_path(), std::ios::binary, ios::trunc);
			if (file.is_open())
			{
				file << obj.num_users_;
			}
			else {}
			file.close();
			system("cls");
			cout << "\n\t\033[92m---------------------------------------------------------------\n";
			cout << "\t\033[97m| ->_-> Backup in progress, please don't closed program ->_-> |\n";
			cout << "\t\033[92m---------------------------------------------------------------";
			Sleep(1000);
			// save users passwords
			file.open(backup_users_passwords_path(), std::ios::binary, ios::trunc);
			file.clear();
			if (file.is_open())
			{
				encryption(users);
				for (int i = 0; i < size_vec; i++)
				{
					if (users[i].r_user_ != 0) {
						file << users[i].password_ << endl << users[i].key << endl;
					}
					else { break; }
				}
			}
			file.close();
			system("cls");
			cout << "\n\n\t\t\033[92m---------------------------------------------------------------\n";
			cout << "\t\t\033[95m| ->_-> Backup in progress, please don't closed program ->_-> |\n";
			cout << "\t\t\033[92m---------------------------------------------------------------";
			Sleep(1000);
			// save users data
			file.open(backup_users_date_path());
			file.clear();
			if (file.is_open())
			{
				for (int i = 0; i < size_vec; i++) {
					if (users[i].r_user_ != 0) {
						file << users[i].r_user_ << endl << users[i].login_ << endl << users[i].user_name_ << endl << users[i].user_family_name_ << endl << users[i].user_patronymic_ << endl << users[i].mail_ << endl << users[i].phone_number_ << endl << users[i].country << endl << users[i].city << endl << users[i].day << endl << users[i].month << endl << users[i].year << endl << users[i].gender << endl << users[i].points_math << endl << users[i].physics_points << endl << users[i].points_mechanics << endl << users[i].day_reg << endl << users[i].month_reg << endl << users[i].year_reg << endl;
					}
					else
					{
						break;
					}
				}
			}
			file.close();
			system("cls");
			cout << "\n\n\n\t\t\t\033[92m---------------------------------------------------------------\n";
			cout << "\t\t\t\033[93m| ->_-> Backup in progress, please don't closed program ->_-> |\n";
			cout << "\t\t\t\033[92m---------------------------------------------------------------";
			Sleep(1000);
			// save backup date
			file.open(date_backup());
			file.clear();
			if (file.is_open())
			{
				GetLocalTime(&getlctime);
				Admin.backup_day_ = getlctime.wDay;
				Admin.backup_month_ = getlctime.wMonth;
				Admin.backup_year_ = getlctime.wYear;
				file << Admin.backup_day_ << endl << Admin.backup_month_ << endl << Admin.backup_year_;///
			}
			file.close();
			system("cls");
			cout << "\033[93m\n\n\t---------------------------------\n";
			cout << "\t\033[92m| \033[94mBackup save done successfully \033[92m|";
			cout << "\033[93m\n\t---------------------------------\n";
			Sleep(2000);
		}
		else
		{
			system("cls");
			cout << "\n\n\033[92m--------------------------------------\n\033[93m| \033[33mUnable to make a backup\t    \033[93m |\n| \033[33mThere are no users in the database\033[93m |\n\033[92m--------------------------------------\n\033[94m\n---------------------------------\n| \033[36mPress any button, to continua \033[94m|\n---------------------------------";
			_getch();
		}
	}break;
	case '2':
	{
		ifstream up_file;
		up_file.open(date_backup());
		if (up_file.is_open())
		{
			up_file >> Admin.backup_day_ >> Admin.backup_month_ >> Admin.backup_year_;
		}
		up_file.close();
		if (Admin.backup_day_ == 0 && Admin.backup_month_ == 0 && Admin.backup_year_ == 0)
		{
			system("cls");
			cout << "\033[92m----------------------------\n";//
			cout << "\033[93m|     \033[33mNot have backup \033[93m     |\n";
			cout << "\033[92m----------------------------\n";
			cout << "\033[92m---------------------------------\n\033[93m|\033[36m Press any button, to continua \033[93m| \n\033[92m---------------------------------";
			_getch();
		}
		else
		{
			system("cls");
			cout << "\033[93m-----------------------------------\n";
			cout << "\033[33m| \033[93mThe backup was made: \033[97m" << Admin.backup_day_ << "." << Admin.backup_month_ << "." << Admin.backup_year_;/*if*/ if (Admin.backup_day_ < 10 || Admin.backup_month_ < 10) { cout << "  \033[33m|"; }
			else { cout << " \033[33m|"; }
			cout << "\033[93m\n-----------------------------------\n";
			cout << "\n\033[93m---------------------------";
			cout << "\n\033[93m| \033[33mLoad data from backup:  \033[93m|";
			cout << "\n---------------------------";
			cout << "\n\033[93m|\033[32m Y - Yes \033[91mN - No \033[93m |\n";
			cout << "-------------------";
			do {
				choose = _getch();
			} while (choose != 'y' && choose != 'Y' && choose != 'n' && choose != 'N');
		}
		if (choose == 'Y' || choose == 'y')
		{
			system("cls");
			cout << "\033[33m-----------------------------------------------------------------\n";
			cout << "\033[33m| \033[92mIf you load data from a backup, the current data will be lost \033[33m|";
			cout << "\n\033[33m-----------------------------------------------------------------\n";
			cout << "\033[33m| \033[37m1 - \033[93mAccept \033[97m| 2 - \033[31mCancel \033[33m|";
			cout << "\n\033[33m---------------------------";
			do {
				choose = _getch();
			} while (choose != '1' && choose != '2');
			if (choose == '1')
			{
				Users_ obj;

				system("cls");
				cout << "--------------------------------------------------\n";
				cout << "\033[93m| \033[92m<-_<- Downloading a backup. Wait, please <-_<- \033[93m|\n";
				cout << "--------------------------------------------------";
				Sleep(1000);

				// loading data on the number of users
				ifstream up_backup;
				up_backup.open(backup_num_users_path());
				if (up_backup.is_open())
				{
					ifstream file;
					file.open(backup_num_users_path(), std::ios::binary);
					if (file.is_open())
					{
						file >> obj.num_users_;
					}
				}
				up_backup.close();
				const int size_vec = obj.num_users_;
				vector<Users_> users(size_vec);

				system("cls");
				cout << "\n\t--------------------------------------------------\n";
				cout << "\t\033[93m| \033[91m<-_<- Downloading a backup. Wait, please <-_<- \033[93m|\n";
				cout << "\t--------------------------------------------------";
				Sleep(1000);

				// loading user passwords
				up_backup.open(backup_users_passwords_path());
				if (up_backup.is_open())
				{
					for (int i = 0; i < size_vec; i++)
					{
						up_backup >> users[i].password_ >> users[i].key;
					}
					decryption(users);
				}
				up_backup.close();

				system("cls");
				cout << "\n\n\t\t--------------------------------------------------\n";
				cout << "\t\t\033[93m| \033[94m<-_<- Downloading a backup. Wait, please <-_<- \033[93m|\n";
				cout << "\t\t--------------------------------------------------";
				Sleep(1000);

				// loading user data
				up_backup.open(backup_users_date_path(), std::ios::binary);
				if (up_backup.is_open())
				{
					for (int i = 0; i < size_vec; i++) {
						up_backup >> users[i].r_user_ >> users[i].login_ >> users[i].user_name_ >> users[i].user_family_name_ >> users[i].user_patronymic_ >> users[i].mail_ >> users[i].phone_number_ >> users[i].country >> users[i].city >> users[i].day >> users[i].month >> users[i].year >> users[i].gender >> users[i].points_math >> users[i].physics_points >> users[i].points_mechanics >> users[i].day_reg >> users[i].month_reg >> users[i].year_reg;
					}
				}
				up_backup.close();
				save_num_users(obj);
				save_users(users);

				system("cls");
				cout << "\n\n\n\t\t\t--------------------------------------------------\n";
				cout << "\t\t\t\033[93m| \033[95m<-_<- Downloading a backup. Wait, please <-_<- \033[93m|\n";
				cout << "\t\t\t--------------------------------------------------";
				Sleep(1000);

				system("cls");
				cout << "\033[93m-----------------------------------\n";
				cout << "\033[92m| \033[94mBackup data loaded successfully \033[92m|\n";
				cout << "\033[93m-----------------------------------\n";

				Sleep(2000);
			}
			else
			{
				break;
			}
		}
		else
		{
			break;
		}
	}break;
	case '3':
	{
		ifstream up_file;
		up_file.open(date_backup());
		if (up_file.is_open())
		{
			up_file >> Admin.backup_day_ >> Admin.backup_month_ >> Admin.backup_year_;
		}
		up_file.close();
		if (Admin.backup_day_ == 0 && Admin.backup_month_ == 0 && Admin.backup_year_ == 0)
		{
			system("cls");
			cout << "\033[92m-------------------------------------\n";//
			cout << "\033[93m|  \033[33mBackup not found or not created \033[93m |\n";
			cout << "\033[92m-------------------------------------\n";
			cout << "\033[92m---------------------------------\n\033[93m|\033[36m Press any button, to continua \033[93m| \n\033[92m---------------------------------";
			_getch();
		}
		else
		{
			system("cls");
			cout << "\n\033[93m-----------------------------------\n";
			cout << "\033[33m| \033[92mThe backup was made: \033[97m" << Admin.backup_day_ << "." << Admin.backup_month_ << "." << Admin.backup_year_;/*if*/ if (Admin.backup_day_ < 10 || Admin.backup_month_ < 10) { cout << "  \033[33m|"; }
			else { cout << " \033[33m|"; }
			cout << "\033[93m\n-----------------------------------\n";
			cout << "\033[93m| \033[97m|1| \033[92mDelete this backup \033[93m|";
			cout << "\n\033[93m--------------------------";
			cout << "\n| \033[97m|2| \033[91mBack to Admin Menu \033[93m|";
			cout << "\n\033[93m--------------------------";
			do
			{
				choose = _getch();
			} while (choose != '1' && choose != '2');
			if (choose == '1')
			{
				system("cls");
				cout << "\n\033[93m----------------------------------------------\n";
				cout << "\033[33m| \033[92mAre you sure you want to delete this copy? \033[33m|\n";
				cout << "\033[93m----------------------------------------------\n";
				cout << "\033[93m[ \033[92mY \033[93m/ \033[91mN \033[93m]\n";
				cout << "\033[93m---------";
				do
				{
					choose = _getch();
				} while (choose != 'Y' && choose != 'y' && choose != 'N' && choose != 'n');
				if (choose == 'Y' || choose == 'y')
				{
					system("cls");

					cout << "\033[93m---------------------\n";
					cout << "\033[92m| \033[91mDeleting a backup \033[92m|\n";
					cout << "\033[93m---------------------";

					// Deleting backup date

					DeleteFile(backup_users_date_path().c_str()); // Deleting a backup copy of user data

					DeleteFile(backup_users_passwords_path().c_str()); // Deleting a backup copy of user passwords

					DeleteFile(backup_num_users_path().c_str()); // Deleting a backup copy of the number of users

					DeleteFile(date_backup().c_str());

					RemoveDirectory(dir_backup);

					;					Sleep(2000);
				}
			}
			else
			{
				break;
			}
		}
	}break;
	case'9':
	{
		break;
	}
	default:;
	}
}

string admin::adm_save_location()
{
	char buffer[256]; // buffer for GetUserName
	DWORD size_buf; // size username
	size_buf = sizeof(buffer); // size buffer
	GetUserName(buffer, &size_buf);
	char admin_data[100] = { "C:\\Users\\" };
	strcat(admin_data, buffer);
	strcat(admin_data, R"(\Documents\Testing System\AdminDate\AdminDate.txt)");
	return admin_data;
}

string admin::backup_users_date_path()
{
	char buffer[256]; // buffer for GetUserName
	DWORD size_buf; // size username
	size_buf = sizeof(buffer); // size buffer
	GetUserName(buffer, &size_buf);
	// path backup user date
	char backup_users_date[100] = { "C:\\Users\\" };
	strcat(backup_users_date, buffer);
	strcat(backup_users_date, R"(\Documents\Testing System\AdminDate\BackUp\backup users date.txt)");
	return backup_users_date;
}

string admin::backup_num_users_path()
{
	char buffer[256]; // buffer for GetUserName
	DWORD size_buf; // size username
	size_buf = sizeof(buffer); // size buffer
	GetUserName(buffer, &size_buf);
	// path num users
	char backup_num_users[100] = { "C:\\Users\\" };
	strcat(backup_num_users, buffer);
	strcat(backup_num_users, R"(\Documents\Testing System\AdminDate\BackUp\backup num users.txt)");
	return backup_num_users;
}

string admin::backup_users_passwords_path()
{
	char buffer[256]; // buffer for GetUserName
	DWORD size_buf; // size username
	size_buf = sizeof(buffer); // size buffer
	GetUserName(buffer, &size_buf);
	// path users passwords
	char backup_users_passwords[100] = { "C:\\Users\\" };
	strcat(backup_users_passwords, buffer);
	strcat(backup_users_passwords, R"(\Documents\Testing System\AdminDate\BackUp\backup users passwords.txt)");
	return backup_users_passwords;
}

string admin::date_backup()
{
	char buffer[256]; // buffer for GetUserName
	DWORD size_buf; // size username
	size_buf = sizeof(buffer); // size buffer
	GetUserName(buffer, &size_buf);
	// path users passwords
	char date_backup[100] = { "C:\\Users\\" };
	strcat(date_backup, buffer);
	strcat(date_backup, R"(\Documents\Testing System\AdminDate\BackUp\date backup.txt)");
	return date_backup;
}

admin::~admin() {}