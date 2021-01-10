#include "Users_.h"
#include <regex>
#include <iomanip>
#include "Stats.h"

/*****************

  cpp for Users.h

*****************/

Users_::Users_()
{
	this->num_users_ = 0;
	this->r_user_ = 0;
	this->country[0] = { '0' };
	this->city[0] = { '0' };
	this->day = 01;
	this->month = 12;
	this->year = 2020;
	this->login_[0] = { '0' };
	this->password_[0] = { '0' };
	this->user_name_[0] = { '0' };
	this->user_family_name_[0] = { '0' };
	this->user_patronymic_[0] = { '0' };
	this->phone_number_[0] = { '0' };
	this->mail_[0] = { '0' };
	this->gender = ' ';
	this->key = 0;
	this->year_reg = 0;
	this->day_reg = 0;
	this->month_reg = 0;
}

void Users_::encryption(vector<Users_>& obj)
{
	for (int d = 0; d < size(obj); d++)
	{
		obj[d].key = rand() % 100;
		for (int i = 0; i < strlen(obj[d].password_); i++)
		{
			obj[d].password_[i] = obj[d].password_[i] + obj[d].key;
		}
	}
}

void Users_::decryption(vector<Users_>& obj)
{
	for (int d = 0; d < size(obj); d++)
	{
		for (int i = 0; i < strlen(obj[d].password_); i++)
		{
			obj[d].password_[i] = obj[d].password_[i] - obj[d].key;
		}
	}
}

void Users_::save_users(vector<Users_>& obj)
{
	ofstream file;
	file.open(save_password_path(), std::ios::binary, ios::trunc);
	file.clear();
	if (file.is_open())
	{
		encryption(obj);
		for (int i = 0; i < size(obj); i++)
		{
			if (obj[i].r_user_ != 0) {
				file << obj[i].password_ << endl << obj[i].key << endl;
			}
			else { break; }
		}
	}
	file.close();

	ofstream file_;
	file_.open(user_date(), std::ios::binary);
	file_.clear();
	if (file_.is_open())
	{
		for (int i = 0; i < size(obj); i++) {
			if (obj[i].r_user_ != 0) {
				file_ << obj[i].r_user_ << endl << obj[i].login_ << endl << obj[i].user_name_ << endl << obj[i].user_family_name_ << endl << obj[i].user_patronymic_ << endl << obj[i].mail_ << endl << obj[i].phone_number_ << endl << obj[i].country << endl << obj[i].city << endl << obj[i].day << endl << obj[i].month << endl << obj[i].year << endl << obj[i].gender << endl << obj[i].points_math << endl << obj[i].physics_points << endl << obj[i].points_mechanics << endl << obj[i].day_reg << endl << obj[i].month_reg << endl << obj[i].year_reg << endl;
			}
			else
			{
				break;
			}
		}
	}
	file_.close();
}

void Users_::load_users(vector<Users_>& obj)
{
	ifstream file;
	file.exceptions(ifstream::badbit | ifstream::failbit);
	try {

		file.open(save_password_path());
		if (file.is_open())
		{
			for (int i = 0; i < size(obj); i++)
			{
				file >> obj[i].password_ >> obj[i].key;
			}
		}
		file.close();
	}
	catch (...)
	{
		system("cls");
		cout << "\n-------------------";
		cout << "\n| \033["<< BrightRed << "mfile open error \033[" << BrightYellow << "m|";
		cout << "\n-------------------";
		cout << "\n| PATH: \033[" << BrightWhite << "m" << save_password_path().c_str() << "\n";
		cout << "\033[" << BrightYellow << "m--------------------\n";
		cout << "\033[" << BrightYellow << "m| \033[" << BrightGreen << "mPress Any button \033[" << BrightYellow << "m|";
		cout << "\n\033[" << BrightYellow << "m--------------------\n";
		_getch();
	}

	try {
		file.open(user_date(), std::ios::binary);
		if (file.is_open())
		{
			for (int i = 0; i < size(obj); i++) {
				file >> obj[i].r_user_ >> obj[i].login_ >> obj[i].user_name_ >> obj[i].user_family_name_ >> obj[i].user_patronymic_ >> obj[i].mail_ >> obj[i].phone_number_ >> obj[i].country >> obj[i].city >> obj[i].day >> obj[i].month >> obj[i].year >> obj[i].gender >> obj[i].points_math >> obj[i].physics_points >> obj[i].points_mechanics >> obj[i].day_reg >> obj[i].month_reg >> obj[i].year_reg;
			}
		}
		file.close();

		decryption(obj);
	}
	catch (...)
	{
		system("cls");
		cout << "\n-------------------";
		cout << "\n| \033[" << BrightRed << "mfile open error \033[" << BrightYellow << "m|";
		cout << "\n-------------------";
		cout << "\n| PATH: \033[" << BrightWhite << "m" << user_date().c_str() << "\n";
		cout << "\033[" << BrightYellow << "m--------------------\n";
		cout << "\033[" << BrightYellow << "m| \033[" << BrightGreen << "mPress Any button \033[" << BrightYellow << "m|";
		cout << "\n\033[" << BrightYellow << "m--------------------\n";
		_getch();
	}
}

void Users_::save_num_users(Users_& obj)
{
	ofstream file;
	file.open(num_users(), std::ios::binary, ios::trunc);
	if (file.is_open())
	{
		file << obj.num_users_;
	}
	else {}
	file.close();
}

void Users_::load_num_users(Users_& obj)
{
	ifstream file;
	file.open(num_users(), std::ios::binary);
	if (file.is_open())
	{
		file >> obj.num_users_;
	}
	else {}
	file.close();
}

void Users_::sign_up()
{
	Users_ obj;

	load_num_users(obj);
	if (obj.num_users_ == 0)
	{
		obj.num_users_++;
	}

	const int size_vec = obj.num_users_;

	vector<Users_> users(size_vec);

	load_users(users);

	// Reg Login
EnterLogin:

	system("cls");
	cout << "\x1B[93m-----------------------------------------------------------------------------------------\n";
	cout << "\033[93m|\x1B[33m\t\t\t\t|R|e|g|i|s|t|r|a|t|i|o|n|\033[93m\t\t\t\t|\n";
	cout << "\033[93m|\033[31mPress \033[91m( \033[97mEsc \033[91m) \033[31mto exit " << setw(72) << "\033[93m|\n";
	cout << "\033[93m-----------------------------------------------------------------------------------------\n";
	cout << "\x1B[93m|\n|\x1B[93m Come up with a \x1B[96mLogin";
	cout << " \x1B[93mto login\033[90m: ";

	int i;
	char a; // a Temp char

	for (i = 0;;) // infinite loop
	{
		a = _getch(); // stores char typed in a

		if (a == '\x1b') // exit to ch. menu
		{
			return;
		}

		if (a >= 'a' && a <= 'z' || (a >= 'A' && a <= 'Z') || a >= '0' && a <= '9')
			//check if a is numeric or alphabet
		{
			obj.login_[i] = a; //stores a in pass
			++i;
			cout << a;
		}
		if (a == '\b' && i >= 1) // if user typed backspace
		{
			cout << "\b \b"; // rub the character behind the cursor.
			--i;
		}
		if (a == '\r') // if enter is pressed
		{
			obj.login_[i] = '\0'; // null means end of string.
			break; // break the loop
		}
	}
	if (strlen(obj.login_) < 4)
	{
		system("cls");
		cout << "\n\n\x1B[93m--------------------------------------------\n";
		cout << "\x1B[93m| \x1B[92mLogin is too small, come up with another \x1B[93m|\n";
		cout << "\x1B[93m--------------------------------------------"; Sleep(2300);
		goto EnterLogin;
	}

	for (auto i = 0; i < size_vec; i++)
	{
		if (strcmp(obj.login_, users[i].login_) == 1 || strcmp(obj.login_, users[i].login_) == -1)
		{
		}
		else
		{
			system("cls");
			cout << "\x1B[93m--------------------------------------------------------------------------------------------------\n";
			cout << "\x1B[93m|\x1B[91m This login is not unique \x1B[34m[\x1B[97m " << obj.login_ << " \x1B[34m] \x1B[91m, please try again !! \x1B[34m(\x1B[32my\x1B[34m / \x1B[31many button\x1B[34m):  \x1B[0m"; char tmp = _getch(); if (tmp == 'y') { goto EnterLogin; }
			else { return; }
		}
	}

	// Reg password
EnterPassword:

	cout << "\x1B[93m\n|\n|\x1B[93m Come up with a \x1B[96mPassword \x1B[93mto login\033[90m: ";

	// a Temp char
	for (i = 0;;) // infinite loop
	{
		a = _getch(); // stores char typed in a

		if (a == '\x1b') // exit to ch. menu
		{
			return;
		}

		if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
			//check if a is numeric or alphabet
		{
			obj.password_[i] = a; //stores a in pass
			++i;
			cout << "*";
		}
		if (a == '\b' && i >= 1) // if user typed backspace
		{
			cout << "\b \b"; // rub the character behind the cursor.
			--i;
		}
		if (a == '\r') // if enter is pressed
		{
			obj.password_[i] = '\0';//null means end of string.
			break;//break the loop
		}
	}

	if (strlen(obj.password_) < 7)
	{
		system("cls");
		cout << "\n\n\x1B[93m-----------------------------------------------\n";
		cout << "\x1B[93m| \x1B[92mPassword is too small, come up with another \x1B[93m|\n";
		cout << "\x1B[93m-----------------------------------------------"; Sleep(2300);

		system("cls");
		cout << "\x1B[93m-----------------------------------------------------------------------------------------\n";
		cout << "\033[93m|\x1B[33m\t\t\t\t|R|e|g|i|s|t|r|a|t|i|o|n|\033[93m\t\t\t\t|\n";
		cout << "\033[93m|\033[31mPress \033[91m( \033[97mEsc \033[91m) \033[31mto exit " << setw(72) << "\033[93m|\n";
		cout << "\033[93m-----------------------------------------------------------------------------------------\n";
		cout << "\x1B[93m|\n|\x1B[93m Come up with a \x1B[96mLogin";
		cout << " \x1B[93mto login\033[90m: " << obj.login_;
		goto EnterPassword;
	}

EnterName:

	system("cls");
	cout << "\x1B[93m-----------------------------------------------------------------------------------------\n";
	cout << "\033[93m|\x1B[33m\t\t\t     |C|o|n|t|a|c|t| |d|e|t|a|i|l|s|\033[93m\t\t\t\t|\n";
	cout << "\033[93m|\033[31mPress \033[91m( \033[97mEsc \033[91m) \033[31mto exit " << setw(72) << "\033[93m|\n";
	cout << "\033[93m-----------------------------------------------------------------------------------------\n";
	cout << "\033[93m| Enter your Name: \x1B[92m ";

	for (i = 0;;) // infinite loop
	{
		a = _getch(); // stores char typed in a

		if (a == '\x1b') // exit to ch. menu
		{
			return;
		}

		if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
			//check if a is numeric or alphabet
		{
			obj.user_name_[i] = a; //stores a in pass
			++i;
			cout << a;
		}
		if (a == '\b' && i >= 1) // if user typed backspace
		{
			cout << "\b \b"; // rub the character behind the cursor.
			--i;
		}
		if (a == '\r') // if enter is pressed
		{
			obj.user_name_[i] = '\0';//null means end of string.
			break;//break the loop
		}
	}

EnterSurname:

	cout << "\n\033[93m| Enter your Family name: \x1B[92m ";
	for (i = 0;;) // infinite loop
	{
		a = _getch(); // stores char typed in a

		if (a == '\x1b') // exit to ch. menu
		{
			return;
		}

		if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
			//check if a is numeric or alphabet
		{
			obj.user_family_name_[i] = a; //stores a in pass
			++i;
			cout << a;
		}
		if (a == '\b' && i >= 1) // if user typed backspace
		{
			cout << "\b \b"; // rub the character behind the cursor.
			--i;
		}
		if (a == '\r') // if enter is pressed
		{
			obj.user_family_name_[i] = '\0';//null means end of string.
			break;//break the loop
		}
	}

EnterMiddlename:

	cout << "\n\033[93m| Enter your Patronymic: \x1B[92m ";

	for (i = 0;;) // infinite loop
	{
		a = _getch(); // stores char typed in a

		if (a == '\x1b') // exit to ch. menu
		{
			return;
		}

		if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
			//check if a is numeric or alphabet
		{
			obj.user_patronymic_[i] = a; //stores a in pass
			++i;
			cout << a;
		}
		if (a == '\b' && i >= 1) // if user typed backspace
		{
			cout << "\b \b"; // rub the character behind the cursor.
			--i;
		}
		if (a == '\r') // if enter is pressed
		{
			obj.user_patronymic_[i] = '\0';//null means end of string.
			break;//break the loop
		}
	}
EnterPhonenumber_:

	cout << "\n\033[93m| Enter your phone number \033[91m(with country code):\x1B[92m ";

	for (i = 0;;) // infinite loop
	{
		a = _getch(); // stores char typed in a

		if (a == '\x1b') // exit to ch. menu
		{
			return;
		}

		if (a >= '0' && a <= '9')
			//check if a is numeric or alphabet
		{
			obj.phone_number_[i] = a; //stores a in pass
			++i;
			cout << a;
		}
		if (a == '\b' && i >= 1) // if user typed backspace
		{
			cout << "\b \b"; // rub the character behind the cursor.
			--i;
		}
		if (a == '\r') // if enter is pressed
		{
			obj.phone_number_[i] = '\0';//null means end of string.
			break;//break the loop
		}
	}

	if (strlen(obj.phone_number_) < 10)
	{
		system("cls");
		cout << "\n\n\x1B[93m---------------------------------------------------\n";
		cout << "\x1B[93m| \x1B[92mPhone number is too small, please enter another \x1B[93m|\n";
		cout << "\x1B[93m---------------------------------------------------"; Sleep(2300);
		system("cls");
		cout << "\x1B[93m-----------------------------------------------------------------------------------------\n";
		cout << "\033[93m|\x1B[33m\t\t\t     |C|o|n|t|a|c|t| |d|e|t|a|i|l|s|\033[93m\t\t\t\t|\n";
		cout << "\033[93m|\033[31mPress \033[91m( \033[97mEsc \033[91m) \033[31mto exit " << setw(72) << "\033[93m|\n";
		cout << "\033[93m-----------------------------------------------------------------------------------------\n";
		cout << "\033[93m| Enter your Name: \x1B[92m " << obj.user_name_ << endl;
		cout << "\033[93m| Enter your Family name: \x1B[92m " << obj.user_family_name_ << endl;
		cout << "\033[93m| Enter your Patronymic: \x1B[92m " << obj.user_patronymic_;
		goto EnterPhonenumber_;
	}

	for (auto i = 0; i < size_vec; i++)
	{
		if (strcmp(obj.phone_number_, users[i].phone_number_) == 1 || strcmp(obj.phone_number_, users[i].phone_number_) == -1)
		{
		}
		else
		{
			system("cls");
			cout << "\x1B[93m--------------------------------------------------------------------------------------------------\n";
			cout << "\x1B[93m|\x1B[91mThis phone number is already in use \x1B[34m[\x1B[97m" << obj.phone_number_ << "\x1B[34m] \x1B[91m, please enter another !! \x1B[34m(\x1B[32my\x1B[34m / \x1B[31many button\x1B[34m):  \x1B[0m"; char tmp = _getch(); if (tmp == 'y') {
				system("cls");
				cout << "\x1B[93m-----------------------------------------------------------------------------------------\n";
				cout << "\033[93m|\x1B[33m\t\t\t     |C|o|n|t|a|c|t| |d|e|t|a|i|l|s|\033[93m\t\t\t\t|\n";
				cout << "\033[93m|\033[31mPress \033[91m( \033[97mEsc \033[91m) \033[31mto exit " << setw(72) << "\033[93m|\n";
				cout << "\033[93m-----------------------------------------------------------------------------------------\n";
				cout << "\033[93m| Enter your Name: \x1B[92m " << obj.user_name_ << endl;
				cout << "\033[93m| Enter your Family name: \x1B[92m " << obj.user_family_name_ << endl;
				cout << "\033[93m| Enter your Patronymic: \x1B[92m " << obj.user_patronymic_;
				goto EnterPhonenumber_;
			}
			else { return; }
		}
	}

EnterMail:
	cout << "\n\033[93m| Enter your email \033[91m:\x1B[92m ";
	for (i = 0;;) // infinite loop
	{
		a = _getch(); // stores char typed in a

		if (a == '\x1b') // exit to ch. menu
		{
			return;
		}

		if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9') || (a == '@') || (a == '.') || (a == '_'))
			//check if a is numeric or alphabet
		{
			obj.mail_[i] = a; //stores a in pass
			++i;
			cout << a;
		}
		if (a == '\b' && i >= 1) // if user typed backspace
		{
			cout << "\b \b"; // rub the character behind the cursor.
			--i;
		}
		if (a == '\r') // if enter is pressed
		{
			obj.mail_[i] = '\0';//null means end of string.
			break;//break the loop
		}
	}

	for (auto i = 0; i < size_vec; i++)
	{
		if (strcmp(obj.mail_, users[i].mail_) == 1 || strcmp(obj.mail_, users[i].mail_) == -1)
		{
		}
		else
		{
			system("cls");
			cout << "\x1B[93m--------------------------------------------------------------------------------------------------\n";
			cout << "\x1B[93m|\x1B[91mThis email is already in use \x1B[34m[\x1B[97m" << obj.mail_ << "\x1B[34m] \x1B[91m, please enter another !! \x1B[34m(\x1B[32my\x1B[34m / \x1B[31many button\x1B[34m):  \x1B[0m"; char tmp = _getch(); if (tmp == 'y') {
				system("cls");
				cout << "\x1B[93m-----------------------------------------------------------------------------------------\n";
				cout << "\033[93m|\x1B[33m\t\t\t     |C|o|n|t|a|c|t| |d|e|t|a|i|l|s|\033[93m\t\t\t\t|\n";
				cout << "\033[93m|\033[31mPress \033[91m( \033[97mEsc \033[91m) \033[31mto exit " << setw(72) << "\033[93m|\n";
				cout << "\033[93m-----------------------------------------------------------------------------------------\n";
				cout << "\033[93m| Enter your Name: \x1B[92m " << obj.user_name_ << endl;
				cout << "\033[93m| Enter your Family name: \x1B[92m " << obj.user_family_name_ << endl;
				cout << "\033[93m| Enter your Patronymic: \x1B[92m " << obj.user_patronymic_ << endl;
				cout << "\033[93m| Enter your phone number \033[91m(with country code):\x1B[92m " << obj.phone_number_;
				goto EnterMail;
			}
			else { return; }
		}
	}
	if (regex_match(obj.mail_, regex("([\\w-\\.]+)@((?:\\w+\\.)+)([a-zA-Z]{2,4})")) != 1)
	{
		system("cls");
		cout << "\x1B[93m--------------------------------------------------------------------------------------------------\n";
		cout << "\x1B[93m|\x1B[91mIncorrectly mail \x1B[34m[\x1B[97m" << obj.mail_ << "\x1B[34m] \x1B[91m, please try again !! \x1B[34m(\x1B[32my\x1B[34m / \x1B[31many button\x1B[34m):  \x1B[0m"; char tmp = _getch(); if (tmp == 'y') {
			system("cls");
			cout << "\x1B[93m-----------------------------------------------------------------------------------------\n";
			cout << "\033[93m|\x1B[33m\t\t\t     |C|o|n|t|a|c|t| |d|e|t|a|i|l|s|\033[93m\t\t\t\t|\n";
			cout << "\033[93m|\033[31mPress \033[91m( \033[97mEsc \033[91m) \033[31mto exit " << setw(72) << "\033[93m|\n";
			cout << "\033[93m-----------------------------------------------------------------------------------------\n";
			cout << "\033[93m| Enter your Name: \x1B[92m " << obj.user_name_ << endl;
			cout << "\033[93m| Enter your Family name: \x1B[92m " << obj.user_family_name_ << endl;
			cout << "\033[93m| Enter your Patronymic: \x1B[92m " << obj.user_patronymic_ << endl;
			cout << "\033[93m| Enter your phone number \033[91m(with country code):\x1B[92m " << obj.phone_number_;
			goto EnterMail;
		}
		else { return; }
	}

EnterCountry:

	cout << "\n\033[93m| Enter your country of residence \033[91m:\x1B[92m ";
	for (i = 0;;) // infinite loop
	{
		a = _getch(); // stores char typed in a

		if (a == '\x1b') // exit to ch. menu
		{
			return;
		}

		if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
			//check if a is numeric or alphabet
		{
			obj.country[i] = a; //stores a in pass
			++i;
			cout << a;
		}
		if (a == '\b' && i >= 1) // if user typed backspace
		{
			cout << "\b \b"; // rub the character behind the cursor.
			--i;
		}
		if (a == '\r') // if enter is pressed
		{
			obj.country[i] = '\0';//null means end of string.
			break;//break the loop
		}
	}

Entercity:
	cout << "\n\033[93m| Enter the city of residence \033[91m:\x1B[92m ";
	for (i = 0;;) // infinite loop
	{
		a = _getch(); // stores char typed in a

		if (a == '\x1b') // exit to ch. menu
		{
			return;
		}

		if (a == '\x1b') // exit to ch. menu
		{
			return;
		}

		if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
			//check if a is numeric or alphabet
		{
			obj.city[i] = a; //stores a in pass
			++i;
			cout << a;
		}
		if (a == '\b' && i >= 1) // if user typed backspace
		{
			cout << "\b \b"; // rub the character behind the cursor.
			--i;
		}
		if (a == '\r') // if enter is pressed
		{
			obj.city[i] = '\0';//null means end of string.
			break;//break the loop
		}
	}

EnterDateofBirth:
	cout << "\n\033[93m| Enter Date of Birth \033[94m(day.month.year)\033[97m: ";

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
				system("cls");
				cout << "\x1B[93m-----------------------------------------------------------------------------------------\n";
				cout << "\033[93m|\x1B[33m\t\t\t     |C|o|n|t|a|c|t| |d|e|t|a|i|l|s|\033[93m\t\t\t\t|\n";
				cout << "\033[93m|\033[31mPress \033[91m( \033[97mEsc \033[91m) \033[31mto exit " << setw(72) << "\033[93m|\n";
				cout << "\033[93m-----------------------------------------------------------------------------------------\n";
				cout << "\033[93m| Enter your Name: \x1B[92m " << obj.user_name_ << endl;
				cout << "\033[93m| Enter your Family name: \x1B[92m " << obj.user_family_name_ << endl;
				cout << "\033[93m| Enter your Patronymic: \x1B[92m " << obj.user_patronymic_ << endl;
				cout << "\033[93m| Enter your phone number \033[91m(with country code):\x1B[92m " << obj.phone_number_ << endl;
				cout << "\033[93m| Enter your email \033[91m:\x1B[92m " << obj.mail_ << endl;
				cout << "\033[93m| Enter your country of residence \033[91m:\x1B[92m " << obj.country << endl;
				cout << "\033[93m| Enter the city of residence \033[91m:\x1B[92m " << obj.city;
				goto EnterDateofBirth;
			}
			else { return; }
		}
	}

EnterGender:

	cout << "\033[93m| Indicate your gender \033[93m( \033[94m1-man \033[93m| \033[95m2 woman \033[93m) \033[91m\x1B[92m ";
	do {
		obj.gender = _getch();
		if (obj.gender == '\x1b') // exit to ch. menu
		{
			return;
		}
	} while (obj.gender != '1' && obj.gender != '2');

	// Transfer data to a vector for saving  ( Перенос данных в вектор для сохранения )
	bool free = false;

	for (int i1 = 0; i1 < size_vec; i1++) // If all the elements are occupied, add another one ( Если все элементы заняты, добавляем еще один )
	{
		if (users[i1].r_user_ == 0)
		{
			free = false;
		}
		else
		{
			free = true;
		}
	}
	if (free == true)
	{
		obj.num_users_++; // add a new element  ( добавить новый элемент )
		users.resize(obj.num_users_);
	}

	for (int i = 0; i < obj.num_users_; i++)
	{
		if (users[i].r_user_ == 0)
		{
			strcpy(users[i].login_, obj.login_);

			strcpy(users[i].password_, obj.password_);

			strcpy(users[i].user_name_, obj.user_name_);

			strcpy(users[i].user_family_name_, obj.user_family_name_);

			strcpy(users[i].user_patronymic_, obj.user_patronymic_);

			strcpy(users[i].mail_, obj.mail_);

			strcpy(users[i].phone_number_, obj.phone_number_);

			strcpy(users[i].country, obj.country);

			strcpy(users[i].city, obj.city);

			users[i].day = obj.day;

			users[i].month = obj.month;

			users[i].year = obj.year;

			users[i].gender = obj.gender;

			SYSTEMTIME st;
			GetLocalTime(&st);
			users[i].day_reg = st.wDay;
			users[i].month_reg = st.wMonth;
			users[i].year_reg = st.wYear;
			users[i].r_user_ = 1;

			save_users(users);

			save_num_users(obj);
		}
		else {}
	}
	cout << "\n\x1B[93m-----------------------------------------------------------------------------------------\n";

	cout << "\033[93m----------------------\n";
	cout << "\033[93m| \033[92mAccount registered \033[93m|\n";
	cout << "\033[93m----------------------\n\n";
	cout << "\033[93m\n---------------------------------\n| \033[92mPress any button, to continue \033[93m|\n---------------------------------\n";

	_getch();
}

void Users_::sign_in()
{
	Users_ obj;
	load_num_users(obj);
	const int size_vec = obj.num_users_;
	vector<Users_> users(size_vec);
	if (size_vec >= 1)
	{
		load_users(users);
	}
	auto login_found = 0; // login is in the database ( логин есть в базе )
	string username = " ";

	int i = 0;
	char choose;
EnterLogin:
	system("cls");
	cout << "\x1B[93m --------------------------------\n";
	cout << "\x1B[93m |\x1B[92mL\x1B[93m|\x1B[91mo\x1B[93m|\x1B[94mg\x1B[93m|\x1B[95mi\x1B[93m|\x1B[96mn\x1B[93m| \x1B[33m|to| \x1B[92m|\x1B[97ma\x1B[92m|\x1B[96mc\x1B[92m|\x1B[93mc\x1B[92m|\x1B[94mo\x1B[92m|\x1B[95mu\x1B[92m|\x1B[36mn\x1B[92m|\x1B[33mt\x1B[92m|";
	cout << "\n\x1B[93m --------------------------------";
	cout << "\n\033[93m | \033[31mPress \033[91m( \033[97mEsc \033[91m) \033[31mto exit\033[93m\n |";
	cout << "\n\x1B[93m | \033[33mEnter login\x1B[97m: ";
	char a; // a Temp char
	int j;
	for (j = 0;;) // infinite loop
	{
		a = _getch(); // stores char typed in a

		if (a == '\x1b') // exit to ch. menu
		{
			return;
		}

		if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
			//check if a is numeric or alphabet
		{
			obj.login_[j] = a; //stores a in pass
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
			obj.login_[j] = '\0';//null means end of string.
			break;//break the loop
		}
	}

	for (i = 0; i < size_vec; i++)
	{
		login_found = strcmp(users[i].login_, obj.login_);
		if (login_found == 0)
		{
			username = obj.login_;
			break;
		}
	}
	if (login_found == 0)
	{
	EnterPassword:
		cout << "\n\x1B[93m |\n | \033[33mEnter \033[91mpassword\033[97m: ";
		char a; // a Temp char

		for (int j = 0;;) // infinite loop
		{
			a = _getch(); // stores char typed in a

			if (a == '\x1b') // exit to ch. menu
			{
				return;
			}

			if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
				//check if a is numeric or alphabet
			{
				obj.password_[j] = a; //stores a in pass
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
				obj.password_[j] = '\0';//null means end of string.
				break;//break the loop
			}
		}

		if (strcmp(users[i].password_, obj.password_) == 0) // Password check
		{
			//  { User->EnterData-> Load }
			int sp = 10;
			for (int i = 0; i < 10; i++)
			{
				system("cls");
				cout << "\n\n\n\033[97m -----------------\n";
				cout << " | \033[93mLoading \033[92m" << sp << " %"; if (sp != 100) cout << "  \033[97m|"; else { cout << " \033[97m|"; }

				cout << endl << " | ";
				for (int d = 0; d < i; d++)
				{
					cout << "$";
				}
				cout << setw(15 - i) << " |";
				cout << "\n\033[97m -----------------\n";
				sp += 10;
				Sleep(100);
			}
		UserMenu:

			system("cls");
			cout << "\n  --------------------------\n";
			cout << "\033[93m  /\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\";
			cout << "\n /  |U|s||e|r|   \033[93m|M|e|n|u|  \\\n";
			cout << "\n\033[93m ----------------------------";
			cout << "\n\033[93m |\033[92m User: \033[97m" << users[i].login_ << "\033[93m";
			cout << setw(20 - strlen(users[i].login_)) << "|";
			cout << "\n\033[93m ----------------------------";
			cout << "\n\033[93m |\033[97m1| \033[92m Test \033[94m\033[0m\t\t  \033[93m  |";
			cout << "\n\033[93m ----------------------------";
			cout << "\n\033[93m |\033[97m2| \033[92m Stats \033[92m\t\t  \033[93m  |";
			cout << "\n\033[93m ----------------------------";
			cout << "\n\033[93m |\033[97m3| \033[96m Profile \033[90m\t\t  \033[93m  |";
			cout << "\n\033[93m ----------------------------";
			cout << "\n\033[93m |\033[97m9| \033[91m Sign out of account\033[31m\033[93m   |";
			cout << "\n\033[93m ----------------------------";
			cout << "\n\033[93m |\033[97m0| \033[31m Exit the program \t\033[31m\033[93m    |";
			cout << "\n\033[93m ----------------------------";
			do {
				choose = _getch();
			} while (choose != '1' && choose != '2' && choose != '3' && choose != '9' && choose != '0');
			switch (choose)
			{
			case '1':
			{
			}break;
			case '2':
			{
				stats::show_users_stats(username);
				goto UserMenu;
			}break;
			case '3': // personal profile editor ( редактор личного профиля )
			{
				system("cls");
				cout << "\n   |P|R|O|F|I|L|E|\033[92m|M|E|N|U|";
				cout << "\n\033[93m ----------------------------";
				cout << "\n\033[93m |\033[97m1| \033[33m View profile details\033[94m\033[0m\033[93m  |";
				cout << "\n\033[93m ----------------------------";
				cout << "\n\033[93m |\033[97m2| \033[92m Edit your profile \033[94m\033[0m  \033[93m  |";
				cout << "\n\033[93m ----------------------------";
				cout << "\n\033[93m |\033[97m9| \033[91m Back to User Menu \033[94m\033[0m \033[93m   |";
				cout << "\n\033[93m ----------------------------";
				do {
					choose = _getch();
				} while (choose != '1' && choose != '2' && choose != '9');
				switch (choose)
				{
				case '1':
				{
					system("cls");
					cout << "-----------------------------------------------------------------------------\n";
					cout << "|\t\t\t\t  \033[91mYOUR DATE \033[93m\t\t\t\t    |\n";
					cout << "-----------------------------------------------------------------------------\n";
					cout << "\033[94m------------------------------------"; cout << "\t\033[32m ------------------------------------";
					cout << "\n\033[94m| \033[92mLogin: \x1B[36m" << users[i].login_ << "\033[94m"; cout << setw(27 - strlen(users[i].login_)) << "|"; cout << "\t\033[32m | \033[33mName: \033[93m" << users[i].user_name_ << "\033[32m"; cout << setw(28 - strlen(users[i].user_name_)) << "|";
					cout << "\n\033[94m------------------------------------"; cout << "\t\033[32m ------------------------------------";
					cout << "\n\033[94m| \033[92mPassword: \x1B[36m" << users[i].password_ << "\033[94m"; cout << setw(24 - strlen(users[i].password_)) << "|"; cout << "\t\033[32m | \033[33mFamily name: \033[93m" << users[i].user_family_name_ << "\033[32m"; cout << setw(21 - strlen(users[i].user_family_name_)) << "|";
					cout << "\n\033[94m------------------------------------"; cout << "\t\033[32m ------------------------------------";
					cout << "\n\033[94m| \033[95mMail: \x1B[37m" << users[i].mail_ << "\033[94m"; cout << setw(28 - strlen(users[i].mail_)) << "|"; cout << "\t\033[32m | \033[33mPatronymic: \033[93m" << users[i].user_patronymic_ << "\033[32m"; cout << setw(22 - strlen(users[i].user_patronymic_)) << "|";
					cout << "\n\033[94m------------------------------------"; cout << "\t\033[32m ------------------------------------";
					cout << "\n\033[94m| \033[96mPhone number: \x1B[37m" << users[i].phone_number_ << "\033[94m"; cout << setw(20 - strlen(users[i].phone_number_)) << "|"; cout << "\t\033[32m | \033[33mDate of Birth:    \033[94m" << users[i].day << "\033[97m.\033[94m" << users[i].month << "\033[97m.\033[94m" << users[i].year << "\033[32m \t    |";
					cout << "\n\033[94m------------------------------------"; cout << "\t\033[32m ------------------------------------";
					cout << "\n\033[94m| \033[92mCountry: \033[94m" << users[i].country << "\033[94m"; cout << setw(25 - strlen(users[i].country)) << "|"; cout << "\t\033[32m | \033[33mGender: "; if (users[i].gender == '1') { cout << " \033[94mMan\033[32m \t\t    |"; }
					else { cout << "\033[95mWoman\033[32m \t\t    |"; }
					cout << "\n\033[94m------------------------------------"; cout << "\t\033[32m ------------------------------------";
					cout << "\n\033[94m| \033[92mCity: \033[93m" << users[i].city << "\033[94m"; cout << setw(28 - strlen(users[i].city)) << "|";

					int d, m, y;
					d = 5; m = 12; y = 2020;

					if (d < 10 && m < 10)
					{
						cout << "\t\033[32m | \033[33mRegistration date:  \033[94m" << d << "\033[97m.\033[94m" << m << "\033[97m.\033[94m" << y << "\033[32m     |";
					}
					else if (d > 10 && m < 10)
					{
						cout << "\t\033[32m | \033[33mRegistration date:  \033[94m" << d << "\033[97m.\033[94m" << m << "\033[97m.\033[94m" << y << "\033[32m    |";
					}
					else if (d > 10 && m > 10)
					{
						cout << "\t\033[32m | \033[33mRegistration date:  \033[94m" << d << "\033[97m.\033[94m" << m << "\033[97m.\033[94m" << y << "\033[32m   |";
					}
					else if (d < 10 && m > 10)
					{
						cout << "\t\033[32m | \033[33mRegistration date:  \033[94m" << d << "\033[97m.\033[94m" << m << "\033[97m.\033[94m" << y << "\033[32m    |";
					}

					cout << "\n\033[94m------------------------------------"; cout << "\t\033[32m ------------------------------------";
					cout << "\n\n\t\t\033[94m     -----------------------------------";
					cout << "\n\t\t\033[94m     |  \033[93mPress any button, to continue  \033[94m|";
					cout << "\n\t\t\033[94m     -----------------------------------";
					_getch();
					goto UserMenu;
				}break;
				case '2':
				{
					system("Cls");
					cout << "\033[94m  -------------------------";
					cout << "\n\033[93m  |E|d|i|t|\033[0m \033[92m|P|r|o|f|i|l|e|\033[0m\n";
					cout << "\033[94m  -------------------------";
					cout << "\n\n\033[94m ---------------------------";
					cout << "\n\033[93m | \033[97m|1| \033[92mLogin details.\033[0m\t  \033[93m |";
					cout << "\n\033[94m ---------------------------";
					cout << "\n\033[93m | \033[97m|2| \033[92mPersonal data.\t  \033[93m |";
					cout << "\n\033[94m ---------------------------";
					cout << "\n\033[93m | \033[97m|9| \033[91mBack to user menu.  \033[93m|";
					cout << "\n\033[94m ---------------------------";
					do {
						choose = _getch();
					} while (choose != '1' && choose != '2' && choose != '9');
					switch (choose)
					{
					case '1':
					{
						system("cls");
						cout << "\033[94m -------------------------------------";
						cout << "\n\033[93m |E|d|i|t|\033[0m \033[92m|L|o|g|i|n| \033[93m|d|e|t|a|i|l|s|\033[0m\n";
						cout << "\033[94m -------------------------------------";
						cout << "\n\n\033[94m ---------------------------";
						cout << "\n\033[93m | \033[97m|1| \033[92mChange login.\033[0m\t  \033[93m |";
						cout << "\n\033[94m ---------------------------";
						cout << "\n\033[93m | \033[97m|2| \033[92mChange password.  \033[93m  |";
						cout << "\n\033[94m ---------------------------";
						cout << "\n\033[93m | \033[97m|9| \033[91mBack to user menu.  \033[93m|";
						cout << "\n\033[94m ---------------------------";
						do {
							choose = _getch();
						} while (choose != '1' && choose != '2' && choose != '9');
						switch (choose)
						{
						case '1': // Change login ( user )
						{
						changelogin:
							system("cls");
							cout << "\033[92m ---------------------";
							cout << "\n\033[93m |E|d|i|t|\033[0m \033[92m|L|o|g|i|n|\033[0m\n";
							cout << "\033[92m ---------------------";
							cout << "\n\033[94m ------------------------------";
							cout << "\n\033[94m | \033[32mYour old login \033[94m[\033[97m" << users[i].login_ << "\033[94m]";
							cout << "\n\033[94m |\n\033[94m | \033[92mEnter your new username:\033[97m "; cin >> obj.login_;

							for (auto i = 0; i < size_vec; i++)
							{
								if (strcmp(obj.login_, users[i].login_) == 1 || strcmp(obj.login_, users[i].login_) == -1)
								{
								}
								else
								{
									system("cls");
									cout << "\x1B[93m--------------------------------------------------------------------------------------------------\n";
									cout << "\x1B[93m|\x1B[91m This login is not unique \x1B[34m[\x1B[97m " << obj.login_ << " \x1B[34m] \x1B[91m, please try again !! \x1B[34m(\x1B[32my\x1B[34m / \x1B[31many button\x1B[34m):  \x1B[0m"; char tmp = _getch(); if (tmp == 'y') { goto changelogin; }
									else { goto UserMenu; }
								}
							}

							for (auto i = 0; i < strlen(obj.login_); i++)
							{
								if (strlen(obj.login_) < 3 || strlen(obj.login_) > sizeof(obj.login_) || obj.login_[i] == ' ' || obj.login_[i] == '!' || obj.login_[i] == '*' || obj.login_[i] == '"' || obj.login_[i] == '#' || obj.login_[i] == '$' || obj.login_[i] == '%' || obj.login_[i] == '&' || obj.login_[i] == '(' || obj.login_[i] == ')' || obj.login_[i] == '+' || obj.login_[i] == '-' || obj.login_[i] == '.' || obj.login_[i] == ',' || obj.login_[i] == '/' || obj.login_[i] == ':' || obj.login_[i] == ';' || obj.login_[i] == '<' || obj.login_[i] == '>' || obj.login_[i] == '=' || obj.login_[i] == '?' || obj.login_[i] == '@' || obj.login_[i] == '[' || obj.login_[i] == '\\' || obj.login_[i] == ']' || obj.login_[i] == '^' || obj.login_[i] == '_' || obj.login_[i] == '`' || obj.login_[i] == '{' || obj.login_[i] == '|' || obj.login_[i] == '}' || obj.login_[i] == '~')
								{
									system("cls");
									cout << "\x1B[93m--------------------------------------------------------------------------------------------------\n";
									cout << "\x1B[93m|\x1B[91m This login is not valid \x1B[34m[\x1B[97m" << obj.login_ << "\x1B[34m] \x1B[91m, please try again !! \x1B[34m(\x1B[32my\x1B[34m / \x1B[31many button\x1B[34m):  \x1B[0m"; char tmp = _getch(); if (tmp == 'y') { goto changelogin; }
									else { goto UserMenu;; }
								}
							}

							strcpy(users[i].login_, obj.login_);
							save_users(users);
							load_users(users);
							cout << "\n\033[93m ------------------------------";
							cout << "\n\033[93m | \033[92mLogin successfully changed\033[93m |";
							cout << "\n\033[93m ------------------------------";
							cout << "\n\n\033[93m ---------------------------------";
							cout << "\n\033[93m | \033[94mPress any button, to continue\033[93m |";
							cout << "\n\033[93m ---------------------------------";
							_getch();
							goto UserMenu;
						}break;
						case '2': // Change password ( user )
						{
						ChangePassword:
							system("cls");
							cout << "\033[92m ---------------------------";
							cout << "\n\033[93m |E|d|i|t|\033[0m \033[92m|P|a|s|s|w|o|r|d|\033[0m\n";
							cout << "\033[92m ---------------------------";
							cout << "\n\033[94m ------------------------------";
							cout << "\n\033[94m | \033[32mYour old password \033[94m[\033[97m" << users[i].password_ << "\033[94m]";
							cout << "\n\033[94m |\n\033[94m | \033[92mEnter your new password: \033[97m "; cin >> obj.password_;

							for (int i = 0; i < strlen(obj.password_); i++)
							{
								if (strlen(obj.password_) < 4 || strlen(obj.password_) > sizeof(obj.password_) || obj.password_[i] == ' ' || obj.password_[i] == '\n' || obj.password_[i] == '!' || obj.password_[i] == '*' || obj.password_[i] == '"' || obj.password_[i] == '#' || obj.password_[i] == '$' || obj.password_[i] == '%' || obj.password_[i] == '&' || obj.password_[i] == '(' || obj.password_[i] == ')' || obj.password_[i] == '+' || obj.password_[i] == '-' || obj.password_[i] == '.' || obj.password_[i] == ',' || obj.password_[i] == '/' || obj.password_[i] == ':' || obj.password_[i] == ';' || obj.password_[i] == '<' || obj.password_[i] == '>' || obj.password_[i] == '=' || obj.password_[i] == '?' || obj.password_[i] == '@' || obj.password_[i] == '[' || obj.password_[i] == '\\' || obj.password_[i] == ']' || obj.password_[i] == '^' || obj.password_[i] == '_' || obj.password_[i] == '`' || obj.password_[i] == '{' || obj.password_[i] == '|' || obj.password_[i] == '}' || obj.password_[i] == '~')
								{
									system("cls");
									cout << "\x1B[93m--------------------------------------------------------------------------------------------------\n";
									cout << "\x1B[93m|\x1B[91m This password is not valid \x1B[34m[\x1B[97m" << obj.password_ << "\x1B[34m] \x1B[91m, please try again !! \x1B[34m(\x1B[32my\x1B[34m / \x1B[31many button\x1B[34m):  \x1B[0m"; char tmp = _getch(); if (tmp == 'y') {
										goto ChangePassword;
									}
									else { goto UserMenu; }
								}
							}

							strcpy(users[i].password_, obj.password_);
							save_users(users);
							load_users(users);
							cout << "\n\033[93m ---------------------------------";
							cout << "\n\033[93m | \033[92mPassword successfully changed\033[93m |";
							cout << "\n\033[93m ---------------------------------";
							cout << "\n\n\033[93m ---------------------------------";
							cout << "\n\033[93m | \033[94mPress any button, to continue\033[93m |";
							cout << "\n\033[93m ---------------------------------";
							_getch();
							goto UserMenu;
						}break;
						case '9':
						{
							goto UserMenu;
						}
						default:;
						}
					}break;
					case '2':
					{
						system("cls");
						cout << "\033[94m -------------------------------------";
						cout << "\n\033[93m |E|d|i|t|\033[0m \033[92m|P|e|r|s|o|n|a|l| \033[93m|d|a|t|a|\033[0m\n";
						cout << "\033[94m -------------------------------------";
						cout << "\n\n\033[94m -------------------------------------";
						cout << "\n\033[93m | \033[97m|1| \033[92mChange \033[94mMail.\033[0m\t\t  \033[93m   |";
						cout << "\n\033[94m -------------------------------------";
						cout << "\n\033[93m | \033[97m|2| \033[92mChange \033[94mphone number.\033[0m\t  \033[93m   |";
						cout << "\n\033[94m -------------------------------------";
						cout << "\n\033[93m | \033[97m|3| \033[92mChange \033[33mcountry of residence.\033[0m  \033[93m|";
						cout << "\n\033[94m -------------------------------------";
						cout << "\n\033[93m | \033[97m|4| \033[92mChange \033[33mcity of residence.\033[0m  \033[93m   |";
						cout << "\n\033[94m -------------------------------------";
						cout << "\n\033[93m | \033[97m|5| \033[92mChange \033[36mName.\033[0m\t\t  \033[93m   |";
						cout << "\n\033[94m -------------------------------------";
						cout << "\n\033[93m | \033[97m|6| \033[92mChange \033[36mFamily Name.\033[0m\t  \033[93m   |";
						cout << "\n\033[94m -------------------------------------";
						cout << "\n\033[93m | \033[97m|7| \033[92mChange \033[36mPatronymic.\033[0m\t  \033[93m   |";
						cout << "\n\033[94m -------------------------------------";
						cout << "\n\033[93m | \033[97m|8| \033[92mChange \033[34mdate of birth.\033[0m\t  \033[93m   |";
						cout << "\n\033[94m -------------------------------------";
						cout << "\n\033[93m | \033[97m|9| \033[92mChange \033[95mGender.\033[0m\t\t  \033[93m   |";
						cout << "\n\033[94m -------------------------------------";
						cout << "\n\033[93m | \033[97m|0| \033[91mBack to user menu.\t    \033[93m |";
						cout << "\n\033[94m -------------------------------------";
						do {
							choose = _getch();
						} while (choose != '1' && choose != '2' && choose != '3' && choose != '4' && choose != '5' && choose != '6' && choose != '7' && choose != '8' && choose != '9' && choose != '0');
						switch (choose)
						{
						case '1': // Change  mail
						{
						ChangeMail:
							system("cls");
							cout << "\033[92m -------------------";
							cout << "\n\033[93m |E|d|i|t|\033[0m \033[92m|M|a|i|l|\033[0m\n";
							cout << "\033[92m -------------------";
							cout << "\n\033[94m ------------------------------";
							cout << "\n\033[94m | \033[32mYour old mail \033[94m[\033[97m" << users[i].mail_ << "\033[94m]";
							cout << "\n\033[94m |\n\033[94m | \033[92mEnter your new mail: \033[97m "; cin >> obj.mail_;

							for (auto i = 0; i < size_vec; i++)
							{
								if (strcmp(obj.mail_, users[i].mail_) == 1 || strcmp(obj.mail_, users[i].mail_) == -1)
								{
								}
								else
								{
									system("cls");
									cout << "\x1B[93m--------------------------------------------------------------------------------------------------\n";
									cout << "\x1B[93m|\x1B[91mThis email is already in use \x1B[34m[\x1B[97m" << obj.mail_ << "\x1B[34m] \x1B[91m, please enter another !! \x1B[34m(\x1B[32my\x1B[34m / \x1B[31many button\x1B[34m):  \x1B[0m"; char tmp = _getch(); if (tmp == 'y') {
										goto ChangeMail;
									}
									else { goto UserMenu; }
								}
							}
							if (regex_match(obj.mail_, regex("([\\w-\\.]+)@((?:\\w+\\.)+)([a-zA-Z]{2,4})")) != 1)
							{
								system("cls");
								cout << "\x1B[93m--------------------------------------------------------------------------------------------------\n";
								cout << "\x1B[93m|\x1B[91mIncorrectly mail \x1B[34m[\x1B[97m" << obj.mail_ << "\x1B[34m] \x1B[91m, please try again !! \x1B[34m(\x1B[32my\x1B[34m / \x1B[31many button\x1B[34m):  \x1B[0m"; char tmp = _getch(); if (tmp == 'y') {
									goto ChangeMail;
								}
								else { goto UserMenu; }
							}
							strcpy(users[i].mail_, obj.mail_);
							save_users(users);
							load_users(users);
							cout << "\n\033[93m -----------------------------";
							cout << "\n\033[93m | \033[92mMail successfully changed\033[93m |";
							cout << "\n\033[93m -----------------------------";
							cout << "\n\n\033[93m ---------------------------------";
							cout << "\n\033[93m | \033[94mPress any button, to continue\033[93m |";
							cout << "\n\033[93m ---------------------------------";
							_getch();
							goto UserMenu;
						}break;
						case '2': // Change  phone number
						{
						ChangePhoneNumber:
							system("cls");
							cout << "\033[92m --------------------------------------------";
							cout << "\n\033[93m |E|d|i|t|\033[0m \033[92m|p|h|o|n|e| \033[93m|n|u|m|b|e|r|\033[0m\n";
							cout << "\033[92m -----------------------------------";
							cout << "\n\033[94m ------------------------------";
							cout << "\n\033[94m | \033[32mYour old phone number \033[94m[\033[97m" << users[i].phone_number_ << "\033[94m]";
							cout << "\n\033[94m |\n\033[94m | \033[92mEnter your new phone number: \033[97m "; cin >> obj.phone_number_;

							for (auto i = 0; i < size_vec; i++)
							{
								if (strcmp(obj.phone_number_, users[i].phone_number_) == 1 || strcmp(obj.phone_number_, users[i].phone_number_) == -1)
								{
								}
								else
								{
									system("cls");
									cout << "\x1B[93m--------------------------------------------------------------------------------------------------\n";
									cout << "\x1B[93m|\x1B[91mThis phone number is already in use \x1B[34m[\x1B[97m" << obj.phone_number_ << "\x1B[34m] \x1B[91m, please enter another !! \x1B[34m(\x1B[32my\x1B[34m / \x1B[31many button\x1B[34m):  \x1B[0m"; char tmp = _getch(); if (tmp == 'y') {
										goto ChangePhoneNumber;
									}
									else { goto UserMenu; }
								}
							}

							for (int i = 0; i < strlen(obj.phone_number_); i++)
							{
								if (strlen(obj.phone_number_) < 10 || strlen(obj.phone_number_) > sizeof(obj.phone_number_) || obj.phone_number_[i] == ' ' || obj.phone_number_[i] == '\n' || obj.phone_number_[i] == '!' || obj.phone_number_[i] == '*' || obj.phone_number_[i] == '"' || obj.phone_number_[i] == '#' || obj.phone_number_[i] == '$' || obj.phone_number_[i] == '%' || obj.phone_number_[i] > '9' || obj.phone_number_[i] == '&' || obj.phone_number_[i] == '(' || obj.phone_number_[i] == ')' || obj.phone_number_[i] == '-' || obj.phone_number_[i] == '.' || obj.phone_number_[i] == ',' || obj.phone_number_[i] == '/' || obj.phone_number_[i] == ':' || obj.phone_number_[i] == ';' || obj.phone_number_[i] == '<' || obj.phone_number_[i] == '>' || obj.phone_number_[i] == '=' || obj.phone_number_[i] == '?' || obj.phone_number_[i] == '@' || obj.phone_number_[i] == '[' || obj.phone_number_[i] == '\\' || obj.phone_number_[i] == ']' || obj.phone_number_[i] == '^' || obj.phone_number_[i] == '_' || obj.phone_number_[i] == '`' || obj.phone_number_[i] == '{' || obj.phone_number_[i] == '|' || obj.phone_number_[i] == '}' || obj.phone_number_[i] == '~')
								{
									system("cls");
									cout << "\x1B[93m--------------------------------------------------------------------------------------------------\n";
									cout << "\x1B[93m|\x1B[91mIncorrectly phone number\x1B[34m[\x1B[97m" << obj.phone_number_ << "\x1B[34m] \x1B[91m, please try again !! \x1B[34m(\x1B[32my\x1B[34m / \x1B[31many button\x1B[34m):  \x1B[0m"; char tmp = _getch(); if (tmp == 'y')
									{
										goto ChangePhoneNumber;
									}
									else { goto UserMenu; }
								}
							}
							strcpy(users[i].phone_number_, obj.phone_number_);
							save_users(users);
							load_users(users);
							cout << "\n\033[93m -------------------------------------";
							cout << "\n\033[93m | \033[92mPhone number successfully changed\033[93m |";
							cout << "\n\033[93m -------------------------------------";
							cout << "\n\n\033[93m ---------------------------------";
							cout << "\n\033[93m | \033[94mPress any button, to continue\033[93m |";
							cout << "\n\033[93m ---------------------------------";
							_getch();
							goto UserMenu;
						}break;
						case '3': // Change country of residence
						{
						ChangeCountry:
							system("cls");
							cout << "\033[92m -----------------------------------";
							cout << "\n\033[93m |E|d|i|t|\033[0m \033[92m|C|o|u|n|t|r|y|\033[0m\n";
							cout << "\033[92m -----------------------------------";
							cout << "\n\033[94m ------------------------------";
							cout << "\n\033[94m | \033[32mYour old country of residence \033[94m[\033[97m" << users[i].country << "\033[94m]";
							cout << "\n\033[94m |\n\033[94m | \033[92mEnter your new country of residence: \033[97m "; cin >> obj.country;

							for (int i = 0; i < strlen(obj.country); i++)
							{
								if (strlen(obj.country) < 3 || strlen(obj.country) > sizeof(obj.country) || obj.country[i] == ' ' || obj.country[i] == '\n' || obj.country[i] == '!' || obj.country[i] == '*' || obj.country[i] == '"' || obj.country[i] == '#' || obj.country[i] == '$' || obj.country[i] == '%' || obj.country[i] == '&' || obj.country[i] == '(' || obj.country[i] == ')' || obj.country[i] == '@' || obj.country[i] == '+' || obj.country[i] == '-' || obj.country[i] == ',' || obj.country[i] == '/' || obj.country[i] == ':' || obj.country[i] == ';' || obj.country[i] == '<' || obj.country[i] == '>' || obj.country[i] == '=' || obj.country[i] == '?' || obj.country[i] == '[' || obj.country[i] == '\\' || obj.country[i] == ']' || obj.country[i] == '^' || obj.country[i] == '_' || obj.country[i] == '`' || obj.country[i] == '{' || obj.country[i] == '|' || obj.country[i] == '}' || obj.country[i] == '~' || obj.country[i] >= '0' && obj.country[i] <= '9')
								{
									system("cls");
									cout << "\x1B[93m--------------------------------------------------------------------------------------------------\n";
									cout << "\x1B[93m|\x1B[91mIncorrect country entered \x1B[34m[\x1B[97m" << obj.country << "\x1B[34m] \x1B[91m, please try again !! \x1B[34m(\x1B[32my\x1B[34m / \x1B[31many button\x1B[34m):  \x1B[0m"; char tmp = _getch(); if (tmp == 'y') {
										goto ChangeCountry;
									}
									else { goto UserMenu; }
								}
							}
							strcpy(users[i].country, obj.country);

							save_users(users);
							load_users(users);
							cout << "\n\033[93m ---------------------------------------------";
							cout << "\n\033[93m | \033[92mCountry of residence successfully changed\033[93m |";
							cout << "\n\033[93m ---------------------------------------------";
							cout << "\n\n\033[93m ---------------------------------";
							cout << "\n\033[93m | \033[94mPress any button, to continue\033[93m |";
							cout << "\n\033[93m ---------------------------------";
							_getch();
							goto UserMenu;
						}break;
						case '4': // Change city of residence
						{
						ChangeCity:
							system("cls");
							cout << "\033[92m -------------------";
							cout << "\n\033[93m |E|d|i|t|\033[0m \033[92m|C|i|t|y|\033[0m\n";
							cout << "\033[92m -------------------";
							cout << "\n\033[94m ------------------------------------------";
							cout << "\n\033[94m | \033[32mYour old city of residence \033[94m[\033[97m" << users[i].city << "\033[94m]";
							cout << "\n\033[94m |\n\033[94m | \033[92mEnter your new city of residence: \033[97m "; cin >> obj.city;

							for (int i = 0; i < strlen(obj.city); i++)
							{
								if (strlen(obj.city) < 3 || strlen(obj.city) > sizeof(obj.city) || obj.city[i] == '@' || obj.city[i] == ' ' || obj.city[i] == '\n' || obj.city[i] == '!' || obj.city[i] == '*' || obj.city[i] == '"' || obj.city[i] == '#' || obj.city[i] == '$' || obj.city[i] == '%' || obj.city[i] == '&' || obj.city[i] == '(' || obj.city[i] == ')' || obj.city[i] == '+' || obj.city[i] == '-' || obj.city[i] == ',' || obj.city[i] == '/' || obj.city[i] == ':' || obj.city[i] == ';' || obj.city[i] == '<' || obj.city[i] == '>' || obj.city[i] == '=' || obj.city[i] == '?' || obj.city[i] == '[' || obj.city[i] == '\\' || obj.city[i] == ']' || obj.city[i] == '^' || obj.city[i] == '_' || obj.city[i] == '`' || obj.city[i] == '{' || obj.city[i] == '|' || obj.city[i] == '}' || obj.city[i] == '~')
								{
									system("cls");
									cout << "\x1B[93m--------------------------------------------------------------------------------------------------\n";
									cout << "\x1B[93m|\x1B[91mIncorrect city entered \x1B[34m[\x1B[97m" << obj.city << "\x1B[34m] \x1B[91m, please try again !! \x1B[34m(\x1B[32my\x1B[34m / \x1B[31many button\x1B[34m):  \x1B[0m"; char tmp = _getch(); if (tmp == 'y') {
										goto 	ChangeCity;
									}
									else { goto UserMenu; }
								}
							}
							strcpy(users[i].city, obj.city);

							save_users(users);
							load_users(users);
							cout << "\n\033[93m ------------------------------------------";
							cout << "\n\033[93m | \033[92mCity of residence successfully changed\033[93m |";
							cout << "\n\033[93m ------------------------------------------";
							cout << "\n\n\033[93m ---------------------------------";
							cout << "\n\033[93m | \033[94mPress any button, to continue\033[93m |";
							cout << "\n\033[93m ---------------------------------";
							_getch();
							goto UserMenu;
						}break;
						case '5': // Change Name
						{
						ChangeName:
							system("cls");
							cout << "\033[92m -------------------";
							cout << "\n\033[93m |E|d|i|t|\033[0m \033[92m|N|a|m|e|\033[0m\n";
							cout << "\033[92m -------------------";
							cout << "\n\033[94m -----------------------------------";
							cout << "\n\033[94m | \033[32mYour old name \033[94m[\033[97m" << users[i].user_name_ << "\033[94m]";
							cout << "\n\033[94m |\n\033[94m | \033[92mEnter your new name of residence: \033[97m "; cin >> obj.user_name_;

							for (int i = 0; i < strlen(obj.user_name_); i++)
							{
								if (strlen(obj.user_name_) < 1 || strlen(obj.user_name_) > sizeof(obj.user_name_) || obj.user_name_[i] == ' ' || obj.user_name_[i] == '\n' || obj.user_name_[i] == '!' || obj.user_name_[i] == '*' || obj.user_name_[i] == '"' || obj.user_name_[i] == '#' || obj.user_name_[i] == '$' || obj.user_name_[i] == '%' || obj.user_name_[i] == '&' || obj.user_name_[i] == '(' || obj.user_name_[i] == ')' || obj.user_name_[i] == '+' || obj.user_name_[i] == '-' || obj.user_name_[i] == '.' || obj.user_name_[i] == ',' || obj.user_name_[i] == '/' || obj.user_name_[i] == ':' || obj.user_name_[i] == ';' || obj.user_name_[i] == '<' || obj.user_name_[i] == '>' || obj.user_name_[i] == '=' || obj.user_name_[i] == '?' || obj.user_name_[i] == '@' || obj.user_name_[i] == '[' || obj.user_name_[i] == '\\' || obj.user_name_[i] == ']' || obj.user_name_[i] == '^' || obj.user_name_[i] == '_' || obj.user_name_[i] == '`' || obj.user_name_[i] == '{' || obj.user_name_[i] == '|' || obj.user_name_[i] == '}' || obj.user_name_[i] == '~' || obj.user_name_[i] >= '0' && obj.user_name_[i] <= '9')
								{
									system("cls");
									cout << "\x1B[93m--------------------------------------------------------------------------------------------------\n";
									cout << "\x1B[93m|\x1B[91mIncorrectly entered name\x1B[34m[\x1B[97m" << obj.user_name_ << "\x1B[34m] \x1B[91m, please try again !! \x1B[34m(\x1B[32my\x1B[34m / \x1B[31many button\x1B[34m):  \x1B[0m"; char tmp = _getch(); if (tmp == 'y') {
										goto ChangeName;
									}
									else { goto UserMenu; }
								}
							}

							strcpy(users[i].user_name_, obj.user_name_);

							save_users(users);
							load_users(users);
							cout << "\n\033[93m -----------------------------";
							cout << "\n\033[93m | \033[92mName successfully changed\033[93m |";
							cout << "\n\033[93m -----------------------------";
							cout << "\n\n\033[93m ---------------------------------";
							cout << "\n\033[93m | \033[94mPress any button, to continue\033[93m |";
							cout << "\n\033[93m ---------------------------------";
							_getch();
							goto UserMenu;
						}break;
						case '6': // Change Family name
						{
						ChangeFamilyName:
							system("cls");
							cout << "\033[92m ---------------------------------";
							cout << "\n\033[93m |E|d|i|t|\033[0m \033[92m|F|a|m|i|l|y|\033[93m |N|a|m|e|\033[0m\n";
							cout << "\033[92m ---------------------------------";
							cout << "\n\033[94m -----------------------------------";
							cout << "\n\033[94m | \033[32mYour old Family Name \033[94m[\033[97m" << users[i].user_family_name_ << "\033[94m]";
							cout << "\n\033[94m |\n\033[94m | \033[92mEnter your new Family Name: \033[97m "; cin >> obj.user_family_name_;

							for (int i = 0; i < strlen(obj.user_family_name_); i++)
							{
								if (strlen(obj.user_family_name_) < 1 || strlen(obj.user_family_name_) > sizeof(obj.user_family_name_) || obj.user_family_name_[i] == ' ' || obj.user_family_name_[i] == '\n' || obj.user_family_name_[i] == '!' || obj.user_family_name_[i] == '*' || obj.user_family_name_[i] == '"' || obj.user_family_name_[i] == '#' || obj.user_family_name_[i] == '$' || obj.user_family_name_[i] == '%' || obj.user_family_name_[i] == '&' || obj.user_family_name_[i] == '(' || obj.user_family_name_[i] == ')' || obj.user_family_name_[i] == '+' || obj.user_family_name_[i] == '-' || obj.user_family_name_[i] == '.' || obj.user_family_name_[i] == ',' || obj.user_family_name_[i] == '/' || obj.user_family_name_[i] == ':' || obj.user_family_name_[i] == ';' || obj.user_family_name_[i] == '<' || obj.user_family_name_[i] == '>' || obj.user_family_name_[i] == '=' || obj.user_family_name_[i] == '?' || obj.user_family_name_[i] == '@' || obj.user_family_name_[i] == '[' || obj.user_family_name_[i] == '\\' || obj.user_family_name_[i] == ']' || obj.user_family_name_[i] == '^' || obj.user_family_name_[i] == '_' || obj.user_family_name_[i] == '`' || obj.user_family_name_[i] == '{' || obj.user_family_name_[i] == '|' || obj.user_family_name_[i] == '}' || obj.user_family_name_[i] == '~' || obj.user_family_name_[i] >= '0' && obj.user_family_name_[i] <= '9')
								{
									system("cls");
									cout << "\x1B[93m--------------------------------------------------------------------------------------------------\n";
									cout << "\x1B[93m|\x1B[91mIncorrectly entered Family name\x1B[34m[\x1B[97m" << obj.user_family_name_ << "\x1B[34m] \x1B[91m, please try again !! \x1B[34m(\x1B[32my\x1B[34m / \x1B[31many button\x1B[34m):  \x1B[0m"; char tmp = _getch(); if (tmp == 'y') {
										goto ChangeFamilyName;
									}
									else { goto UserMenu; }
								}
							}

							strcpy(users[i].user_family_name_, obj.user_family_name_);

							save_users(users);
							load_users(users);
							cout << "\n\033[93m ------------------------------------";
							cout << "\n\033[93m | \033[92mFamily Name successfully changed\033[93m |";
							cout << "\n\033[93m ------------------------------------";
							cout << "\n\n\033[93m ---------------------------------";
							cout << "\n\033[93m | \033[94mPress any button, to continue\033[93m |";
							cout << "\n\033[93m ---------------------------------";
							_getch();
							goto UserMenu;
						}break;
						case '7': // Name Change Patronymic
						{
						ChangePatronymic:
							system("cls");
							cout << "\033[92m -------------------------------";
							cout << "\n\033[93m |E|d|i|t|\033[0m \033[92m|P|a|t|r|o|n|y|m|i|c|\033[0m\n";
							cout << "\033[92m -------------------------------";
							cout << "\n\033[94m -----------------------------------";
							cout << "\n\033[94m | \033[32mYour old Patronymic \033[94m[\033[97m" << users[i].user_patronymic_ << "\033[94m]";
							cout << "\n\033[94m |\n\033[94m | \033[92mEnter your new Family Name: \033[97m "; cin >> obj.user_patronymic_;

							for (int i = 0; i < strlen(obj.user_patronymic_); i++)
							{
								if (strlen(obj.user_patronymic_) < 1 || strlen(obj.user_patronymic_) > sizeof(obj.user_patronymic_) || obj.user_patronymic_[i] == ' ' || obj.user_patronymic_[i] == '\n' || obj.user_patronymic_[i] == '!' || obj.user_patronymic_[i] == '*' || obj.user_patronymic_[i] == '"' || obj.user_patronymic_[i] == '#' || obj.user_patronymic_[i] == '$' || obj.user_patronymic_[i] == '%' || obj.user_patronymic_[i] == '&' || obj.user_patronymic_[i] == '(' || obj.user_patronymic_[i] == ')' || obj.user_patronymic_[i] == '+' || obj.user_patronymic_[i] == '-' || obj.user_patronymic_[i] == '.' || obj.user_patronymic_[i] == ',' || obj.user_patronymic_[i] == '/' || obj.user_patronymic_[i] == ':' || obj.user_patronymic_[i] == ';' || obj.user_patronymic_[i] == '<' || obj.user_patronymic_[i] == '>' || obj.user_patronymic_[i] == '=' || obj.user_patronymic_[i] == '?' || obj.user_patronymic_[i] == '@' || obj.user_patronymic_[i] == '[' || obj.user_patronymic_[i] == '\\' || obj.user_patronymic_[i] == ']' || obj.user_patronymic_[i] == '^' || obj.user_patronymic_[i] == '_' || obj.user_patronymic_[i] == '`' || obj.user_patronymic_[i] == '{' || obj.user_patronymic_[i] == '|' || obj.user_patronymic_[i] == '}' || obj.user_patronymic_[i] == '~' || obj.user_patronymic_[i] >= '0' && obj.user_patronymic_[i] <= '9')
								{
									system("cls");
									cout << "\x1B[93m--------------------------------------------------------------------------------------------------\n";
									cout << "\x1B[93m|\x1B[91mIncorrectly entered Patronymic\x1B[34m[\x1B[97m" << obj.user_patronymic_ << "\x1B[34m] \x1B[91m, please try again !! \x1B[34m(\x1B[32my\x1B[34m / \x1B[31many button\x1B[34m):  \x1B[0m"; char tmp = _getch(); if (tmp == 'y') {
										goto ChangePatronymic;
									}
									else { goto UserMenu; }
								}
							}

							strcpy(users[i].user_patronymic_, obj.user_patronymic_);

							save_users(users);
							load_users(users);
							cout << "\n\033[93m -----------------------------------";
							cout << "\n\033[93m | \033[92mPatronymic successfully changed\033[93m |";
							cout << "\n\033[93m -----------------------------------";
							cout << "\n\n\033[93m ---------------------------------";
							cout << "\n\033[93m | \033[94mPress any button, to continue\033[93m |";
							cout << "\n\033[93m ---------------------------------";
							_getch();
							goto UserMenu;
						}break;
						case '8': // Change date of birth
						{
						ChangeDateOfBirth:
							system("cls");
							cout << "\033[92m -----------------------------";
							cout << "\n\033[93m |E|d|i|t|\033[0m \033[92m|Date| \033[97m|of| \033[93m|Birth|\033[0m\n";
							cout << "\033[92m -----------------------------";
							cout << "\n\033[94m ------------------------------------";
							cout << "\n\033[94m | \033[32mYour old Date of Birth \033[94m[\033[97m" << users[i].day << "." << users[i].month << "." << users[i].year << "\033[94m]";
							cout << "\n\033[94m |\n\033[94m | \033[92mEnter your new Date of Birth \033[94m(day.month.year)\033[97m:  ";
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
										goto ChangeDateOfBirth;
									}
									else { goto UserMenu; }
								}
							}
							users[i].day = obj.day;

							users[i].month = obj.month;

							users[i].year = obj.year;

							save_users(users);
							load_users(users);
							cout << "\n\033[93m --------------------------------------";
							cout << "\n\033[93m | \033[92mDate of birth successfully changed\033[93m |";
							cout << "\n\033[93m --------------------------------------";
							cout << "\n\n\033[93m ---------------------------------";
							cout << "\n\033[93m | \033[94mPress any button, to continue\033[93m |";
							cout << "\n\033[93m ---------------------------------";
							_getch();
							goto UserMenu;
						}break;
						case '9': // Change Gender
						{
						ChangeGender:
							system("cls");
							cout << "\033[92m -----------------------";
							cout << "\n\033[93m |E|d|i|t|\033[0m \033[92m|G|e|n|d|e|r|\033[0m\n";
							cout << "\033[92m -----------------------";
							cout << "\n\033[94m -------------------------------------------";
							cout << "\n\033[94m | \033[32mYour Gender: "; if (users[i].gender == '1') { cout << "\033[94m Man"; }
							else { cout << "\033[95m Woman"; }
							cout << "\n\033[94m |\n\033[94m | \033[92mEnter your new Gender \033[93m( \033[94m1-man \033[93m| \033[95m2 woman \033[93m) \033[91m\x1B[92m "; obj.gender = _getch();

							if (obj.gender == '1' || obj.gender == '2')
							{
							}
							else
							{
								system("cls");
								cout << "\x1B[93m--------------------------------------------------------------------------------------------------\n";
								cout << "\x1B[93m|\x1B[91mIncorrect gender \x1B[34m[\x1B[97m" << obj.gender << "\x1B[34m] \x1B[91m, please try again !! \x1B[34m(\x1B[32my\x1B[34m / \x1B[31many button\x1B[34m):  \x1B[0m"; char tmp = _getch(); if (tmp == 'y') {
									goto 	ChangeGender;
								}
								else { goto UserMenu; }
							}

							users[i].gender = obj.gender;
							save_users(users);
							load_users(users);
							cout << "\n\n\033[93m -------------------------------";
							cout << "\n\033[93m | \033[92mGender successfully changed\033[93m |";
							cout << "\n\033[93m -------------------------------";
							cout << "\n\n\033[93m ---------------------------------";
							cout << "\n\033[93m | \033[94mPress any button, to continue\033[93m |";
							cout << "\n\033[93m ---------------------------------";
							_getch();
							goto UserMenu;
						}break;
						case '0': // Back to user menu
						{
							goto UserMenu;
						}
						default:;
						}
					}break;
					case '9':
					{
						goto UserMenu;
					}break;
					default:;
					}
				}break;
				case '9':
				{
					goto UserMenu;
				}break;
				default:;
				}
			}break;
			case '9':
			{
			}break;
			case '0':
			{
				system("cls");
				cout << "\x1B[31m Exit program !!\n\n";
				cout << "\t\x1B[31m Выход из программы !!\n\n";
				cout << "\t\t\x1B[31m Exit program !!\n\n";
				cout << "\t\t\t\x1B[31m Выход из программы !!\n\n";
				Sleep(1500);
				cout << "\x1B[0m";
				exit(0);
			}break;
			default:;
			}
		}
		else
		{
			system("cls");
			cout << "\x1B[93m--------------------------------------------------------------------------------------------------\n";
			cout << "\x1B[93m|\x1B[91m This password is not valid \x1B[34m[\x1B[97m" << obj.password_ << "\x1B[34m] \x1B[91m, please try again !! \x1B[34m(\x1B[32my\x1B[34m / \x1B[31many button\x1B[34m):  \x1B[0m"; char tmp = _getch(); if (tmp == 'y') {
				system("cls");
				cout << "\x1B[93m --------------------------------\n";
				cout << "\x1B[93m |\x1B[92mL\x1B[93m|\x1B[91mo\x1B[93m|\x1B[94mg\x1B[93m|\x1B[95mi\x1B[93m|\x1B[96mn\x1B[93m| \x1B[33m|to| \x1B[92m|\x1B[97ma\x1B[92m|\x1B[96mc\x1B[92m|\x1B[93mc\x1B[92m|\x1B[94mo\x1B[92m|\x1B[95mu\x1B[92m|\x1B[36mn\x1B[92m|\x1B[33mt\x1B[92m|";
				cout << "\n\x1B[93m --------------------------------";
				cout << "\n\033[93m | \033[31mPress \033[91m( \033[97mEsc \033[91m) \033[31mto exit\033[93m\n |";
				cout << "\n\x1B[93m | \033[33mEnter login\x1B[97m: " << obj.login_; goto EnterPassword;
			}
			else { return; }
		}
	}
	else
	{
		system("cls");
		cout << "\x1B[93m--------------------------------------------------------------------------------------------------\n";
		cout << "\x1B[93m|\x1B[91m No user with this username found \x1B[34m[\x1B[97m" << obj.login_ << "\x1B[34m] \x1B[91m, please try again !! \x1B[34m(\x1B[32my\x1B[34m / \x1B[31many button\x1B[34m):  \x1B[0m"; char tmp = _getch(); if (tmp == 'y') { goto EnterLogin; }
		else { return; }
	}
}

string Users_::user_date()
{
	char buffer[256]; // buffer for GetUserName
	DWORD size_buf; // size username
	size_buf = sizeof(buffer); // size buffer
	GetUserName(buffer, &size_buf);
	char user_data[100] = { "C:\\Users\\" };
	strcat(user_data, buffer);
	strcat(user_data, R"(\Documents\Testing System\UserDate\Users Date.txt)");
	return user_data;
}

string Users_::num_users()
{
	char buffer[256]; // buffer for GetUserName
	DWORD size_buf; // size username
	size_buf = sizeof(buffer); // size buffer
	GetUserName(buffer, &size_buf);
	char num_users[100] = { "C:\\Users\\" };
	strcat(num_users, buffer);
	strcat(num_users, R"(\Documents\Testing System\UserDate\num users.txt)");
	return num_users;
}

string Users_::save_password_path()
{
	char buffer[256]; // buffer for GetUserName
	DWORD size_buf; // size username
	size_buf = sizeof(buffer); // size buffer
	GetUserName(buffer, &size_buf);
	char save_password_path[100] = { "C:\\Users\\" };
	strcat(save_password_path, buffer);
	strcat(save_password_path, R"(\Documents\Testing System\UserDate\users passwords.txt)");
	return save_password_path;
}

Users_::~Users_()
{
}