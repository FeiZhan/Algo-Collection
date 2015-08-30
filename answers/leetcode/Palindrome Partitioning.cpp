#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<vector<string> > ans;
		std::vector<std::vector<bool> > palin;
		for (int i = 0; i < s.length(); ++ i)
		{
			palin.push_back(std::vector<bool>(s.length()));
		}
		for (int i = 0; i < s.length(); ++ i)
		{
			// odd
			palin[i][i] = true;
			for (int j = 1; i - j >= 0 && i + j < s.length(); ++ j)
			{
				palin[i - j][i + j] = palin[i - j + 1][i + j - 1] && s[i - j] == s[i + j];
			}
			// even
			for (int j = 0; i - j >= 0 && i + j + 1 < s.length(); ++ j)
			{
				palin[i - j][i + j + 1] = (0 == j || palin[i - j + 1][i + j]) && s[i - j] == s[i + j + 1];
			}
		}
		getPalin(s, 0, vector<string>(), ans, palin);
		return ans;
    }
	void getPalin(const std::string &s, const int begin, const std::vector<std::string> &past, std::vector<std::vector<std::string> > &ans, const std::vector<std::vector<bool> > &palin)
	{
		if (begin == s.length())
		{
			ans.push_back(past);
			return;
		}
		if (begin > s.length())
		{
			return;
		}
		for (int i = begin; i < s.length(); ++ i)
		{
			if (palin[begin][i])
			{
				std::vector<std::string> now = past;
				now.push_back(s.substr(begin, i - begin + 1));
				getPalin(s, i + 1, now, ans, palin);
			}
		}
	}
};
int main()
{
	Solution s;
	vector<vector<string> > ans;
	ans = s.partition("cdd");
	for (int i = 0; i < ans.size(); ++ i)
	{
		for (int j = 0; j < ans[i].size(); ++ j)
		{
			std::cout << ans[i][j] << "+";
		}
		std::cout << ", ";
	}
	std::cout << std::endl;
	return 0;
}

// 2014-12-19
class Solution {
public:
	vector<vector<string> > partition(string s) {
		ans.clear();
		part_map.clear();
		for (size_t i = 0; i < s.length(); ++ i) {
			for (size_t j = 0; j < s.length(); ++ j) {
				if (s[j] == s[j + i] && (i <= 1 || part_map[j + 1].end() != part_map[j + 1].find(j + i - 1))) {
					part_map[j].insert(i + j);
				}
			}
		}
		vector<size_t> path;
		search(0, path);
		vector<vector<string> > str_ans;
		for (size_t i = 0; i < ans.size(); ++ i) {
			vector<string> temp;
			temp.push_back(s.substr(0, ans[i][0] + 1));
			for (size_t j = 1; j < ans[i].size(); ++ j) {
				string temp1(s.substr(ans[i][j - 1] + 1, ans[i][j] - ans[i][j - 1]));
				if (temp1.length()) {
					temp.push_back(temp1);
				}
			}
			str_ans.push_back(temp);
		}
		return str_ans;
	}
	void search(size_t pos, vector<size_t> &path) {
		if (part_map.end() == part_map.find(pos)) {
			if (path.size()) {
				ans.push_back(path);
			}
			return;
		}
		for (std::set<size_t>::iterator it = part_map[pos].begin(); it != part_map[pos].end(); ++ it) {
			path.push_back(*it);
			search((*it) + 1, path);
			path.pop_back();
		}
	}
	vector<vector<size_t> > ans;
	std::map<size_t, std::set<size_t> > part_map;
	void printPartMap(void) {
		cout << "partmap ";
		for (std::map<size_t, std::set<size_t> >::iterator it = part_map.begin(); it != part_map.end(); ++ it) {
			cout << it->first << ": ";
			for (std::set<size_t>::iterator it1 = it->second.begin(); it1 != it->second.end(); ++ it1) {
				cout << *it1 << " ";
			}
			cout << endl;
		}
	}
};
