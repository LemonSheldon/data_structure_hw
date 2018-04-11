#pragma once
#include <array>
#include <vector> 
#include <map>
#include <functional>
#include "game_entity.h"


class data_sys
{
public:
	data_sys();
	info_to_battle_sys card_effect(std::size_t card_id);
	info_to_explore_sys event_effect(std::size_t event_id);
	std::vector<card> cards_pool;
	std::vector<artifact> artifacts;
	std::map<std::size_t, std::size_t> card_upgrade_id;
	std::map<std::size_t, std::string> card_name;
	player player_data;
	std::vector<enemy> enemies_data;
	enemy all_enemies, random_enemy, select_one_enemy;
	std::pair<std::string, std::size_t> get_buff(std::size_t);

	std::size_t gold;
	std::size_t food;
	std::size_t strength;
	std::size_t dexterity;
	std::size_t vitality;
	std::size_t luck;
	std::vector<card> cards_deck;
	std::vector<card> cards_grave;
	std::vector<card> cards_in_hand;
	std::vector<card> cards_removed;
	std::vector<card> cards_equiped;
	std::array<bool, 8>draw_select_card;
	std::array<char, 10> reserve_cards;//ò��û��
	info_to_battle_sys i_to_b_pipe;
	info_battle_to_interacting b_to_i_pipe;
	std::vector<std::pair<std::size_t, std::size_t>>b_to_d;
	info_to_explore_sys i_to_e_pipe;
	info_explore_to_interacting e_to_i_pipe;
	std::size_t explore_map[6][6];
	int map_marks[6][6];
	std::pair<int, int> player_location;
	std::vector<explore_selection> choice_list;
	//to determine explore context
	std::size_t current_select_page;//indicates the position of the first selection in choice_list.  
	bool is_vaccant;
	event_e current_event;
};

class random_engine
{
public:
	size_t get_num(int lb, int ub);
};