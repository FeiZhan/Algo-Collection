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
