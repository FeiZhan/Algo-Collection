//
#define _FILE_DEBUG_
//#define _C_LAN_
//#define _DEBUG_OUTPUT_
#ifdef _FILE_DEBUG_
#include <fstream>
#endif
#include <iostream>
#include <stdio.h>
using namespace std;

#include <string>
#include <vector>
void Shuffle(const std::vector<int> &shuffle, const std::vector<std::string> &deck, std::vector<std::string> &new_deck)
{
	for (size_t i = 0; i < shuffle.size(); ++ i)
	{
		new_deck[shuffle[i]] = deck[i];
	}
}
int main(int argc, char *argv[])
{
#ifdef _FILE_DEBUG_
	ifstream fin;
	fin.open("../input.txt");
	cin.rdbuf(fin.rdbuf());
#ifdef _C_LAN_
	freopen("../input.txt", "r", stdin);
#endif
#endif
#ifdef _FILE_DEBUG_
	ofstream fout;
	fout.open("../output.txt");
	cout.rdbuf(fout.rdbuf());
#ifdef _C_LAN_
	freopen("../output.txt", "w", stdout);
#endif
#endif

	const std::string CARD_TYPE("SHCD");
	std::string card;
	std::vector<std::string> deck;
	//S1, S2, ..., S13, H1, H2, ..., H13, C1, C2, ..., C13, D1, D2, ..., D13, J1, J2
	for (int i = 0; i < 4; ++ i)
	{
		for (int j = 0; j < 13; ++ j)
		{
			card.clear();
			card += CARD_TYPE[i];
			if (j < 9)
			{
				card += static_cast<char>(j + '1');
			} else
			{
				card += '1';
				card += static_cast<char>(j - 10 + '1');
			}
			deck.push_back(card);
		}
	}
	deck.push_back(std::string("J1"));
	deck.push_back(std::string("J2"));
	int times;
	std::cin >> times;
	int number;
	std::vector<int> shuffle;
	for (int i = 0; i < 54; ++ i)
	{
		std::cin >> number;
		shuffle.push_back(number - 1);
	}
	std::string empty("a");
	std::vector<std::string> new_deck(54, empty);
	for (int i = 0; i < times; ++ i)
	{
		Shuffle(shuffle, deck, new_deck);
		deck = new_deck;
	}
	for (int i = 0; i < 54; ++ i)
	{
		if (0 != i)
		{
			std::cout << " ";
		}
		std::cout << new_deck[i];
	}
	std::cout << std::endl;

	return 0;
}
