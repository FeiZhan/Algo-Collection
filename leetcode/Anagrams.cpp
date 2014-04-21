
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
		std::multimap<std::string, std::string> ana_map;
		for (std::vector<std::string>::iterator it = strs.begin(); it != strs.end(); ++ it)
		{
			std::string temp(*it);
			std::sort(temp.begin(), temp.end());
			ana_map.insert(std::make_pair(temp, *it));
		}
		vector<string> ans;
		for (std::multimap<std::string, std::string>::iterator it = ana_map.begin(); it != ana_map.end(); ++ it)
		{
			if (ana_map.count(it->first) > 1)
			{
				ans.push_back(it->second);
			}
		}
		return ans;
    }
};
