class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		string tmp;
		vector<string> first, second, ret;
		// avoid time exceed for big number
		if (s.length() > 12)
		{
			return ret;
		}
		set<string> unique;
		for (int i = 1; i < s.length(); ++ i)
		{
			first = restore1(s.substr(0, i));
			second = restore3(s.substr(i));
			if (first.size() == 0 || second.size() == 0)
			{
				continue;
			}
			for (int j = 0; j < first.size(); ++ j)
			{
				for (int k = 0; k < second.size(); ++ k)
				{
					unique.insert(first[j] + "." + second[k]);
				}
			}
			first = restore2(s.substr(0, i));
			second = restore2(s.substr(i));
			if (first.size() == 0 || second.size() == 0)
			{
				continue;
			}
			for (int j = 0; j < first.size(); ++ j)
			{
				for (int k = 0; k < second.size(); ++ k)
				{
					unique.insert(first[j] + "." + second[k]);
				}
			}
			first = restore3(s.substr(0, i));
			second = restore1(s.substr(i));
			if (first.size() == 0 || second.size() == 0)
			{
				continue;
			}
			for (int j = 0; j < first.size(); ++ j)
			{
				for (int k = 0; k < second.size(); ++ k)
				{
					unique.insert(first[j] + "." + second[k]);
				}
			}
		}
		for (set<string>::iterator it = unique.begin(); it != unique.end(); ++ it)
		{
			ret.push_back(*it);
		}
		return ret;
    }
    vector<string> restore3(string s)
    {
		string tmp;
		vector<string> first, second, ret;
		if (s.length() > 9)
		{
			return ret;
		}
		for (int i = 1; i < s.length(); ++ i)
		{
			first = restore1(s.substr(0, i));
			second = restore2(s.substr(i));
			if (first.size() == 0 || second.size() == 0)
			{
				continue;
			}
			for (int j = 0; j < first.size(); ++ j)
			{
				for (int k = 0; k < second.size(); ++ k)
				{
					ret.push_back(first[j] + "." + second[k]);
				}
			}
			first = restore2(s.substr(0, i));
			second = restore1(s.substr(i));
			if (first.size() == 0 || second.size() == 0)
			{
				continue;
			}
			for (int j = 0; j < first.size(); ++ j)
			{
				for (int k = 0; k < second.size(); ++ k)
				{
					ret.push_back(first[j] + "." + second[k]);
				}
			}
		}
		return ret;
	}
    vector<string> restore2(string s)
    {
		string tmp;
		vector<string> first, second, ret;
		if (s.length() > 6)
		{
			return ret;
		}
		for (int i = 1; i < s.length(); ++ i)
		{
			first = restore1(s.substr(0, i));
			second = restore1(s.substr(i));
			if (first.size() == 0 || second.size() == 0)
			{
				continue;
			}
			for (int j = 0; j < first.size(); ++ j)
			{
				for (int k = 0; k < second.size(); ++ k)
				{
					ret.push_back(first[j] + "." + second[k]);
				}
			}
		}
		return ret;
	}
    vector<string> restore1(string s)
    {
		vector<string> ret;
		// if only zero, can pass
		if (s.length() <= 0 || (s.length() > 1 && '0' == s[0]) || s.length() > 3)
		{
			return ret;
		}
		int value = atoi(s.c_str());
		if (value >= 0 && value <= 255)
		{
			ret.push_back(s);
		}
		return ret;
	}
};
