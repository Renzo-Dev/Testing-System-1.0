#pragma once
#include "Users_.h"
#include "usable includes.h"

class stats
{
public:

	stats();

	static void show_users_stats(const string& username);

	static void show_users_stats_adm();

	~stats();
};
