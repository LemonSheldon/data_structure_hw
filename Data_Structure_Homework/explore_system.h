#pragma once
#include "message.h"
#include "data_sys.h"
#include <string>
#include <stack>

namespace explore_action_type
{
	const int AQUIRE_HIT_POINTS = 10;
	const int AQUIRE_MAX_HIT_POINTS = 11;
	const int REMOVE_HIT_POINTS = 12;
	const int REMOVE_MAX_HIT_POINTS = 13;
	const int AQUIRE_STRENGTH = 14;
	const int AQUIRE_DEXRITY = 15;
	const int AQUIRE_VITALITY = 16;
	const int AQUIRE_LUCK = 17;
	const int REMOVE_STRENGTH = 18;
	const int REMOVE_DEXRITY = 19;
	const int REMOVE_VITALITY = 20;
	const int REMOVE_LUCK = 21;

	const int AQUIRE_CARD = 30;//card
	const int REMOVE_CARD = 31;//size_t
	const int UPGRADE_CARD = 32;//size_t
	const int CHANGE_CARD = 33;//size_t
	const int AQUIRE_ARTIFACT = 34;//artifact
	const int REMOVE_ARTIFACT = 35;//size_t
	const int AQUIRE_GOLD = 36;
	const int REMOVE_GOLD = 37;
	const int AQUIRE_FOOD = 38;
	const int REMOVE_FOOD = 39;

	const int START_BATTLE = 98;
	const int NEXT_PHASE = 99;
	const int END_EVENT = 100;
}

struct explore_system_action
{
	explore_system_action(std::size_t, int, artifact, card);
	std::size_t action_id;
	int value;
	artifact atf;
	card c;
};

class explore_system
{
public:
	vector<card> get_random_card(size_t num, bool is_rare);
private:
	std::stack<explore_system_action> process_stack;
	void process();
	data_sys* data;
};

