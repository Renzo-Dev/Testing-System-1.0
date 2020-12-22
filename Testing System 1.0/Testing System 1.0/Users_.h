#pragma once
#include "usable includes.h"
#include "Stats.h"

class Users_
{
protected:
	// Date of Birth ( user )
	unsigned int day;
	unsigned int month;
	unsigned int year;
	//

	int key; // decryption key

	// registration date
	unsigned short int day_reg;
	unsigned short int month_reg;
	unsigned short int year_reg;
	//

	unsigned short physics_points = 0; // physics glasses
	unsigned short points_math = 0; // math glasses
	unsigned short points_mechanics = 0; // mechanics glasses

	//
	unsigned int num_users_; // size vector ( for save and load )
	unsigned int r_user_; // check for emptiness of a vector element ( проверка на пустоту элемента  вектора )

	char country[30] = {}; // Country ( Страна проживания )
	char city[30] = {}; // city ( город проживания )
	char login_[30] = {}; // Login for login to account ( логин для входа в аккаунт )
	char password_[100] = {}; // Password for login to account ( пароль для входа в аккаунт )
	char user_name_[30] = {}; // User Name ( Имя )
	char user_family_name_[30] = {}; // Family Name ( Фамилия )
	char user_patronymic_[30] = {}; // patronymic ( Отчество )
	char phone_number_[30] = {}; // phone number ( Номер телефона )
	char mail_[35] = {}; // mail ( почта )
	char gender = {}; // gender ( пол )

public:
	Users_();
	static void save_users(vector<Users_>& obj); // save user ( Сохранить пользователя )

	static void encryption(vector<Users_>& obj); // Password encryption  ( шифровка пароля )

	static void decryption(vector<Users_>& obj); // Password decryption ( дешифровка пароля )

	static void load_users(vector<Users_>& obj); // load users ( загрузить пользователей )

	static void save_num_users(Users_& obj); // Saving the number of users (vector size ( Сохранение количества пользователей(размер vector))

	static void load_num_users(Users_& obj); // loading the number of users ( загрузка количества пользователей )

	static void sign_up(); // Add user/ registrations  ( Добавить пользователя/ регистрация )

	static void sign_in(); // Login in ( вход )
protected:
	static string user_date(); // user data storage location ( место хранения данных пользователей  )
	static string num_users(); // number of users in the database ( количество пользователей в базе )
	static string save_password_path(); // storage location for encrypted user passwords ( место хранения зашифрованных паролей пользователей )
public:
	friend class admin;
	friend class stats;

	~Users_();
};
