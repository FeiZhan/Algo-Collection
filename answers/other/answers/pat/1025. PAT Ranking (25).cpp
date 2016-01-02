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

#include <vector>
#include <algorithm>
struct Testee
{
	std::string id;
	int loc, score;
	size_t local_rank, rank;
	Testee(std::string i, int l, int s) : id(i), loc(l), score(s), local_rank(-1), rank(-1)
	{}
};
bool comp (const Testee &t1, const Testee &t2)
{
	return t1.score > t2.score || (t1.score == t2.score && t1.id < t2.id);
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

	int loc_num;
	std::cin >> loc_num;
	int testee_num, score;
	std::string id;
	vector<Testee> local_test, test;
	for (int i = 0; i < loc_num; ++ i)
	{
		std::cin >> testee_num;
		local_test.clear();
		for (int j = 0; j < testee_num; ++ j)
		{
			std::cin >> id >> score;
			local_test.push_back( Testee(id, i, score) );
		}
		std::sort(local_test.begin(), local_test.end(), comp);
		for (int j = 0, rank = 0, previous = -1; j < local_test.size(); ++ j)
		{
			if (local_test[j].score != previous)
			{
				previous = local_test[j].score;
				rank = j + 1;
			}
			local_test[j].local_rank = rank;
		}
		test.insert(test.end(), local_test.begin(), local_test.end());
	}
	std::sort(test.begin(), test.end(), comp);
	std::cout << test.size() << std::endl;
	for (int i = 0, rank = 0, previous = -1; i < test.size(); ++ i)
	{
		if (test[i].score != previous)
		{
			previous = test[i].score;
			rank = i + 1;
		}
		test[i].rank = rank;
		// registration_number final_rank location_number local_rank
		std::cout << test[i].id << " " << rank << " " << test[i].loc + 1 << " " << test[i].local_rank << std::endl;
	}
	return 0;
}
