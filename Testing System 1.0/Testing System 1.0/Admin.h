#pragma once
#include "usable includes.h"
#include "Users_.h"

class admin : protected Users_
{
	char r_admin_ = '0'; // check for registration of Admin account | RU. проверка на регистрацию Админ аккаунта
						 // 1 - Account registered(->login) | RU. 1 -  Аккаунт зарегистрирован (  -> вход )
						 // 0 - Account not registered(->registration) | RU. 0 - Аккаунт не зарегистрирован (-> регистрация)

	char key_recovery_[30] = {};  // Key to reset administrator settings (Ключ для сброса настроек администратора)
// to enter
	char login_[30] = {}; // Admin Login
	char password_[100] = {}; // Admin Password

// backup date
	unsigned short int backup_day_;
	unsigned short int backup_month_;
	unsigned short int backup_year_;

public:

	admin();

	static void save_date_admin(const admin& obj); // Saving Admin Data ( Сохранения данных Админа )

	static void load_date_admin(admin& obj); // Reading Admin data from a file ( Считывание данных Админа с файла )

	static int join_admin(); // Login / Create / Register - Administrator ( Вход / создание / Регистрация - Администратора )

	static void show_admin_details(const admin& obj); // Administrator data (Данные администратора)

	static void change_admin_password(admin& obj); // Admin login changes ( Изменения логина Админа )

	static void change_admin_login(admin& obj); // Admin password changes ( Изменения пароля Админа )

	static void change_recovery_key(admin& obj); // Change the key to reset the settings ( измените ключ, чтобы сбросить настройки )

	static void reset_settings(); // Resetting password and settings, entering new data ( изменения ключа , для сброса настроек )

	static void show_users(); // show  users (показать пользователей)

	static int find_user(); // Find user(s) ( поиск пользователя(ей) )

	static int just_find_user(); // search without display ( поиск без отображения )

	static void remove_user_s(); // Remove user(s) ( удалить пользователя(ей) )

	static void user_prof_change_menu(); // User Profile Change Menu

	static void backup_users_date(); // back up users ( data ) ( резервное копирование пользователей ( данных ) )

	/*static void setting_up_tests();*/ // User Test Settings ( Настройки тестов для пользователя )

	/*Path of Save*////////////////////////////////////

	static string adm_save_location();

	static string backup_users_date_path();

	static string backup_num_users_path();

	static string backup_users_passwords_path();

	static string date_backup();

	///////////////////////////////////////////////////
	friend class display;

	~admin(); // Destroyer ( Деструтор )
};
