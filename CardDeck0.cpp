#include <algorithm>
#include <iostream>
#include <iterator>
#include <cstdlib> 
#include <String>
#include <vector>
#include <random>
#include <ctime> 
#include <list>
#include <map>



class Deck
{
private:
	auto deck()
	{
		std::map <std::string, std::string> cardDeck {{ "Hearts_Ace", "Hearts_King" }, { "Hearts_Queen", "Hearts_Jack" }, { "Hearts_10", "Hearts" }, { "Hearts_9", "Hearts" }, { "Hearts_8", "Hearts" }, { "Hearts_7", "Hearts" }, { "Hearts_6", "Hearts" },
			{ "Clubs_Ace", "Clubs" }, { "Clubs_King", "Clubs" }, { "Clubs_Queen", "Clubs" }, { "Clubs_Jack", "Clubs" }, { "Clubs_10", "Clubs" }, { "Clubs_9", "Clubs" }, { "Clubs_8", "Clubs" }, { "Clubs_7", "Clubs" }, { "Clubs_6", "Clubs" },
			{ "Diamonds_Ace", "Diamonds" }, { "Diamonds_King", "Diamonds" }, { "Diamonds_Queen", "Diamonds" }, { "Diamonds_Jack", "Diamonds" }, { "Diamonds_10", "Diamonds" }, { "Diamonds_9", "Diamonds" }, { "Diamonds_8", "Diamonds" }, { "Diamonds_7", "Diamonds" }, { "Diamonds_6", "Diamonds" },
			{ "Spades_Ace", "Spades" }, { "Spades_King", "Spades" }, { "Spades_Queen", "Spades" }, { "Spades_Jack", "Spades" }, { "Spades_10", "Spades" }, { "Spades_9", "Spades" }, { "Spades_8", "Spades" }, { "Spades_7", "Spades" }, { "Spades_6", "Spades" }}; //Creating card deck

		// Define the suits and ranks
		std::vector <std::string> suits = { "Hearts", "Clubs", "Diamonds", "Spades" };
		std::vector <std::string> ranks = { "Ace", "King", "Queen", "Jack", "10", "9", "8", "7", "6" };

		//Generate the card deck
		/*for (const auto& suit : suits) {
			for (const auto& rank : ranks) {
				std::string card = suit + "_" + rank;
				cardDeck[card] = suit;
			}
		}*/
		return cardDeck;
	}

	void erase(std::map <std::string, std::string>& cardDeck)
	{
		std::map <std::string, std::string> player_cards;
		for (const auto& entry : player_cards) {
			cardDeck.erase(entry.first);
		}

	}

	auto player_rand_cards()
	{
		std::map <std::string, std::string> player_cards;
		std::map <std::string, std::string> cardDeck;
		cardDeck = deck();
		for (int i = 0; i < 6; i++) {
			int randomIndex = rand() % cardDeck.size();
			auto it = std::next(cardDeck.begin(), randomIndex);
			player_cards.insert(*it);
			cardDeck.erase(it);

		}
		std::list <std::map<std::string, std::string>> returnList{player_cards, cardDeck};
		return returnList;
	}

public:
	void output()
	{
		auto it = player_rand_cards().back();
		std::map <std::string, std::string> lol = player_rand_cards().front();

		for (const auto& idx : it) {
			std::cout << idx.first << ": " << idx.second << std::endl;
		}

		std::cout << "-----------------------------------------" << std::endl;

		for (const auto& idx : lol) {
			std::cout << idx.first << ": " << idx.second << std::endl;
		}
	}
};


int main()
{
	Deck _deck;
	_deck.output();
	return 0;
}
