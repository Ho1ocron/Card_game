#include <algorithm>
#include <iostream>
#include <iterator>
#include <String>
#include <random>
#include <list>
#include <map>


class Deck
{
private:
	auto deck()
	{
		std::map <std::string, std::string> suit_list {{"Diamonds", "lightning"}, { "", "blood" }, { "Clubs", "draining" }, { "Spades", "physics" }}; // The list of card suits with their damage effects
		std::map <std::string, std::string> senior_cards{{"Ace", ""}, { "King", "" }, { "Queen", "heal" }, { "Jack", "" }}; //senior cards
		std::list <std::string> deck_values {"10", "9", "8", "7", "6"}; //junior cards

		//random card choice
		std::random_device suit_list_rd;
		std::mt19937 mt(suit_list_rd());
		std::uniform_int_distribution <int> suit_list_dist(0, suit_list.size() - 1);
		int randomIndex = suit_list_dist(mt);
		auto suit_list_idx = suit_list.begin();
		std::advance(suit_list_idx, randomIndex);
		std::string suit_list_rand_key = suit_list_idx->first;

		std::list <std::string> val_list{suit_list_rand_key}; //random suit list
		std::map <std::string, std::string> deck{}; //creating new deck
		std::map <std::string, std::string> deck1{}; // creating deck to fill it with cards's suit

		//adder keys from one map to another one
		std::transform(senior_cards.begin(), senior_cards.end(), std::inserter(deck1, deck1.end()), [](const std::pair<const std::string, std::string>& pair) {return std::make_pair(pair.first, ""); });

		return deck;
	}
		
	void cards_on_hand()
	{

	}

public:
	void output()
	{
		for (const auto& pair : deck()) {
			std::cout << pair.first << pair.second << std::endl;
		}
	}
};


void exmp()
{
	// Create the initial maps
	std::map<int, std::string> map1 = { {1, "one"}, {2, "two"}, {3, "three"} };
	std::map<int, std::string> map2 = { {4, "four"}, {5, "five"} };

	// Retrieve the keys from map2 and insert them into map1
	std::transform(map2.begin(), map2.end(), std::inserter(map1, map1.end()),
		[](const std::pair<const int, std::string>& pair) {
			return std::make_pair(pair.first, "");
		});

	// Print the keys in map1
	for (const auto& pair : map1) {
		std::cout << pair.first << std::endl;
	}
}

int main() 
{
	//exmp();
	Deck _deck;
	_deck.output();
	return 0;
}
