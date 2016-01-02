// 相当于倒排表
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
#include <map>
#include <set>

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

	int book_num;
	std::string tmp;
	std::cin >> book_num;
	std::getline(std::cin, tmp);
	size_t pos = 0;
	std::string id, title, author, key_list, key, publisher, year;
	std::multimap<std::string, std::string> book_map;
	for (int i = 0; i < book_num; ++ i)
	{
		//Line #1: the 7-digit ID number;
		std::getline(std::cin, id);
//std::cout << "id " << id << std::endl;
		//Line #2: the book title -- a string of no more than 80 characters;
		std::getline(std::cin, title);
		book_map.insert(std::make_pair(title, id));
		//Line #3: the author -- a string of no more than 80 characters;
		std::getline(std::cin, author);
		book_map.insert(std::make_pair(author, id));
		//Line #4: the key words -- each word is a string of no more than 10 characters without any white space, and the keywords are separated by exactly one space;
		std::getline(std::cin, key_list);
		pos = 0;
		while ((pos = key_list.find(' ')) != std::string::npos)
		{
			key = key_list.substr(0, pos);
//std::cout << "key " << key << " ";
			book_map.insert(std::make_pair(key, id));
			key_list.erase(0, pos + 1);
		}
		if (key_list.size())
		{
			book_map.insert(std::make_pair(key_list, id));
		}
		//Line #5: the publisher -- a string of no more than 80 characters;
		std::getline(std::cin, publisher);
		book_map.insert(std::make_pair(publisher, id));
		//Line #6: the published year -- a 4-digit number which is in the range [1000, 3000].
		std::getline(std::cin, year);
		book_map.insert(std::make_pair(year, id));
//std::cout << std::endl << id << " " << title << " " << author << " " << key_list << " " << publisher << " " << year << std::endl;
	}
	int query_num, type;
	std::cin >> query_num;
	char temp;
	std::string query;
	std::pair< std::multimap<std::string, std::string>::iterator, std::multimap<std::string, std::string>::iterator > range;
	std::multiset<std::string> ans_set;
	for (int i = 0; i < query_num; ++ i)
	{
		//1: a book title
		//2: name of an author
		//3: a key word
		//4: name of a publisher
		//5: a 4-digit number representing the year
		std::cin >> type >> temp;
		std::getline(std::cin, query);
		std::cout << type << ":" << query << std::endl;
		query.erase(0, 1);
		ans_set.clear();
		range = book_map.equal_range(query);
		for (std::multimap<std::string, std::string>::iterator it = range.first; it != range.second; ++ it)
		{
			ans_set.insert(it->second);
		}
		for (std::multiset<std::string>::iterator it =  ans_set.begin(); it != ans_set.end(); ++ it)
		{
			std::cout << *it << std::endl;
		}
		if (0 == ans_set.size())
		{
			std::cout << "Not Found" << std::endl;
		}
	}

	return 0;
}
