//WA
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
#include <map>

class compare { // simple comparison function
public:
	bool operator()(const int x,const int y)
	{
		return (x-y)>0; 
	} // returns x>y
};
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

	int loc_num, testee_num, score;
	std::string tmp1;
	std::map<std::string, int> loc;
	std::multimap<int, std::string> rank, rank_tmp;
	std::vector<std::multimap<int, std::string> > local_rank;
	cin >> loc_num;
	for (int i = 0; i < loc_num; ++ i)
	{
		cin >> testee_num;
		rank_tmp.clear();
		for (int j = 0; j < testee_num; ++ j)
		{
			cin >> tmp1 >> score;
			loc.insert(std::make_pair(tmp1, i));
			rank.insert(std::make_pair(score, tmp1));
			rank_tmp.insert(std::make_pair(score, tmp1));
		}
		local_rank.push_back(rank_tmp);
	}
	std::cout << rank.size() << std::endl;
	int count = 0, count2 = 0, erase_count = 0;
	for (std::multimap<int, std::string>::reverse_iterator it = rank.rbegin(); it != rank.rend();)
	{
		std::multimap<int, std::string>::reverse_iterator it2;
		for (it2 = it; it2 != rank.rend() && it2->first != it->first; ++ it2)
		{}
		std::multimap<int, std::string>::reverse_iterator min_it = it;
		for (std::multimap<int, std::string>::reverse_iterator it3 = it; it3 != it2 && it3 != rank.rend(); ++ it3)
		{
			if (it3->second < min_it->second)
			{
				min_it = it3;
			}
		}
		count2 = 0;
		for (std::multimap<int, std::string>::reverse_iterator it4 = local_rank[loc[min_it->second]].rbegin(); it4->second != min_it->second && it4 != local_rank[loc[min_it->second]].rend(); ++ it4)
		{
			++ count2;
		}
		// registration_number final_rank location_number local_rank
		std::cout << min_it->second << " " << 1 + count << " " << loc[min_it->second] + 1 << " " << count2 + 1 << std::endl;
		if (min_it == it)
		{
			count += erase_count + 1;
			erase_count = 0;
			++ it;
		} else
		{
			++ erase_count;
			rank.erase( --min_it.base());
		}
	}

	return 0;
}
