//
#include <cstdio>
#include <iostream>
using namespace std;

#include <climits>
#include <vector>
#include <deque>

int main (int argc, char *argv[])
{
	int user_num(0);
	int level_max(0);
	while (cin >> user_num >> level_max) {
		vector<vector<int> > follow_mat(user_num, vector<int> ());
		for (int i = 0; i < user_num; ++ i) {
			int follow_num(0);
			cin >> follow_num;
			for (int j = 0; j < follow_num; ++ j) {
				int follow(0);
				cin >> follow;
				//follow_mat[i].push_back(follow - 1);
				follow_mat[follow - 1].push_back(i);
			}
		}
		int query_num(0);
		cin >> query_num;
		for (int i = 0; i < query_num; ++ i) {
			int query(0);
			cin >> query;
			-- query;
			deque<int> user_que;
			vector<int> follow_list(user_num, INT_MAX);
			int count(0);
			follow_list[query] = 0;
			user_que.push_back(query);
			while (! user_que.empty()) {
				int current(user_que.front());
				user_que.pop_front();
				if (follow_list[current] >= level_max) {
					break;
				}
				for (int j = 0; j < follow_mat[current].size(); ++ j) {
					if (INT_MAX == follow_list[follow_mat[current][j]]) {
						++ count;
						follow_list[follow_mat[current][j]] = follow_list[current] + 1;
						user_que.push_back(follow_mat[current][j]);
						//cout << "update " << current << " " << follow_mat[current][j] << " " << follow_list[follow_mat[current][j]] << endl;
					}
				}
			}
			cout << count << endl;
		}
	}

	return 0;
}