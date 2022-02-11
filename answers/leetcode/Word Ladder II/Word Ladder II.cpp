//Time Limit Exceeded

class Solution {
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		std::vector<std::vector<std::string> > ans;
		std::multimap<std::string, std::string> word_map;
		if (0 == dict.size())
		{
			return ans;
		}
		int len = dict.begin()->length();
		for (std::unordered_set<std::string>::iterator it = dict.begin(); it != dict.end(); ++ it)
		{
			if (start == *it)
			{
				word_map.insert(std::make_pair(start, *it));
			}
			if (end == *it)
			{
				word_map.insert(std::make_pair(*it, end));
			}
			for (std::unordered_set<std::string>::iterator it2 = it; it2 != dict.end(); ++ it2)
			{
				if (it->length() != it2->length())
				{
					continue;
				}
				int diff_count = 0;
				for (int i = 0; i < len; ++ i)
				{
					if ((*it)[i] != (*it2)[i])
					{
						++ diff_count;
					}
					if (diff_count > 1)
					{
						break;
					}
				}
				if (diff_count == 1)
				{
					word_map.insert(std::make_pair(*it, *it2));
					word_map.insert(std::make_pair(*it2, *it));
				}
			}
		}
		std::vector<std::string> path;
		path.push_back(start);
		search(start, end, path, word_map, ans, INT_MAX);
		int min_size = INT_MAX;
		for (int i = 0; i < ans.size(); ++ i)
		{
			if (ans[i].size() < min_size)
			{
				min_size = ans[i].size();
			}
		}
		for (std::vector<std::vector<std::string> >::iterator it = ans.begin(); it != ans.end(); ++ it)
		{
			if (it->size() > min_size)
			{
				ans.erase(it);
				-- it;
			}
		}
		return ans;
    }
    void search(const std::string &now, const std::string &end, const std::vector<std::string> &path, const std::multimap<std::string, std::string> &word_map, std::vector<std::vector<std::string> > &ans, int min_size)
    {
		if (now == end)
		{
			ans.push_back(path);
			if (path.size() < min_size)
			{
				min_size = path.size();
			}
			return;
		}
		if (path.size() > min_size)
		{
			return;
		}
		std::multimap<std::string, std::string>::const_iterator low = word_map.lower_bound(now);
		std::multimap<std::string, std::string>::const_iterator up = word_map.upper_bound(now);
		for (std::multimap<std::string, std::string>::const_iterator it = low; it != up; ++ it)
		{
			if (std::find(path.begin(), path.end(), it->second) == path.end())
			{
				std::vector<std::string> mypath = path;
				mypath.push_back(it->second);
				search(it->second, end, mypath, word_map, ans, min_size);
			}
		}
	}
};

//2014-12-17
//TLE
class Solution {
public:
	vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
		dict_list = vector<string>(dict.begin(), dict.end());
		std::vector<string>::iterator find_it = std::find(dict_list.begin(), dict_list.end(), start);
		if (dict_list.end() != find_it) {
			*find_it = dict_list[0];
			dict_list[0] = start;
		} else {
			dict_list.insert(dict_list.begin(), start);
		}
		find_it = std::find(dict_list.begin(), dict_list.end(), end);
		if (dict_list.end() != find_it) {
			*find_it = dict_list[dict_list.size() - 1];
			dict_list[dict_list.size() - 1] = end;
		} else {
			dict_list.push_back(end);
		}

		ladder_map[0] = 0;
		for (size_t i = 1; i < dict_list.size(); ++ i) {
			ladder_map[i] = INT_MAX;
		}
		queue<size_t> ladder_queue;
		set<size_t> ladder_list;
		ladder_queue.push(0);
		ladder_list.insert(0);
		while (ladder_queue.size()) {
			size_t current = ladder_queue.front();
			ladder_queue.pop();
			ladder_list.erase(current);
			if (ladder_map[current] >= ladder_map[dict_list.size() - 1]) {
				continue;
			}
			for (size_t i = 0; i < dict_list.size(); ++ i) {
				if (dict_map[current].end() == dict_map[current].find(i)) {
					int count = 0;
					for (size_t j = 0; j < dict_list[current].size() && j < dict_list[i].size(); ++ j) {
						if (dict_list[current][j] != dict_list[i][j]) {
							++ count;
						}
						if (count > 1) {
							break;
						}
					}
					if (1 != count) {
						continue;
					}
				}
				if (ladder_list.end() != ladder_list.find(i)) {
					continue;
				}
				if (ladder_map[i] < INT_MAX) {
					continue;
				}
				if (ladder_map[current] + 1 < ladder_map[i]) {
					dict_map[current].insert(i);
					dict_map[i].insert(current);
					ladder_map[i] = ladder_map[current] + 1;
					if (dict_list.size() - 1 == i) {
						break;
					}
					ladder_queue.push(i);
					ladder_list.insert(i);
				}
			}
		}
		vector<vector<size_t> > ans = dfs(0);
		vector<vector<string> > ans1;
		for (size_t i = 0; i < ans.size(); ++ i) {
			vector<string> temp;
			for (size_t j = 0; j < ans[i].size(); ++ j) {
				temp.push_back(dict_list[ans[i][j]]);
			}
			ans1.push_back(temp);
		}
		return ans1;
	}
	vector<vector<size_t> > dfs(size_t root) {
		vector<vector<size_t> > ans;
		if (dict_list.size() - 1 == root) {
			vector<size_t> temp;
			temp.push_back(root);
			ans.push_back(temp);
		} else {
			for (size_t j = 0; j < dict_list.size(); ++ j) {
				if (ladder_map[root] + 1 == ladder_map[j]) {
					vector<vector<size_t> > temp = dfs(j);
					for (size_t i = 0; i < temp.size(); ++ i) {
						temp[i].insert(temp[i].begin(), root);
						ans.push_back(temp[i]);
					}
				}
			}
		}
		return ans;
	}
	vector<string> dict_list;
	map<size_t, set<size_t> > dict_map;
	map<size_t, int> ladder_map;
};
