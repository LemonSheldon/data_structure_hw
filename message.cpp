#include "message.h"
using namespace std;

info_to_battle_sys::info_to_battle_sys() :info(), action_set()
{
}

info_to_battle_sys::info_to_battle_sys(action ichange)
{
	action_set.push_back(ichange);
}

void info_to_battle_sys::append(info_to_battle_sys t)
{
	for (auto &i : t.action_set)
	{
		action_set.push_back(i);
	}
}

info::info()
{
}

action::action(std::size_t id, game_entity * tcaller, game_entity * tlistener, std::size_t ttype, std::size_t tvalue)
	:action_id(id), caller(tcaller), listener(tlistener), type(ttype)
{
}
