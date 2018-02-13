#pragma once
#include "message.h"
#include "player_stats.h"
#include "managers.h"
#include <string>
#include <stack>

namespace explore_action_type
{
	const int AQUIRE_HIT_POINTS = 10;
	const int AQUIRE_MAX_HIT_POINTS = 11;
	const int REMOVE_HIT_POINTS = 12;
	const int REMOVE_MAX_HIT_POINTS = 13;

	const int AQUIRE_CARD = 20;
	const int AQUIRE_RANDOM_CARD = 21;
	const int REMOVE_CARD = 30;
	const int REMOVE_RANDOM_CARD = 31;
	const int UPGRADE_CARD = 40;
	const int UPGRADE_RANDOM_CARD = 41;
	const int CHANGE_CARD = 50;
	const int CHANGE_RANDOM_CARD = 51;

	const int AQUIRE_ARTIFACT = 60;
	const int AQUIRE_RANDOM_ARTIFACT = 61;
	const int REMOVE_ARTIFACT = 70;
	const int REMOVE_RANDOM_ARTIFACT = 71;

	const int AQUIRE_GOLD = 80;
	const int REMOVE_GOLD = 81;

	const int GET_RANDOM_EVENT_CARDS = 100;
	const int GET_RANDOM_BATTLE_CARDS = 110;
	const int GET_RANDOM_ARTIFACTS = 120;
	const int GET_RANDOM_GOLD_BALANCE = 130;
}

struct explore_system_action
{
	explore_system_action(size_t id, string act_name, int val)
		:action_name(act_name), action_id(id), value(val) {};
	std::string action_name;
	size_t action_id;
	int value;
};

class explore_system : public message_manager
{
public:
	bool send_message(info_to_explore_system);
protected:
	info* create_message();
	bool interpret_message(info_to_explore_system);
private:
	std::stack<explore_system_action> process_stack;
	void process();
	player_stats player_class;
};