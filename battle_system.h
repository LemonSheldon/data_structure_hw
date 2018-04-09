#pragma once
#include <ctime>
#include "game_entity.h"
#include "message.h"
#include <stack>
#include <string>
class data_sys;
class battle_system
{
public:
	battle_system(data_sys& d);
	void update();
	void send_message(info_to_battle_sys);
private:
	bool interpret_message(info_to_battle_sys);
	data_sys & data;
	std::stack<action> process_stack;
	void process();
	bool battle_finishes();
};



//��ʱʹ��:
class my_random_engine
{
public:
	static std::vector<card> xipai(std::vector<card>);
};
