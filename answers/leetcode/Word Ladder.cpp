class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict)
    {
        unordered_set<string> added;
    	queue<string> q;
    	int ret = 0;
    	// size of the old queue and the new queue
    	int lev1 = 1, lev2 = 0;
    	q.push(start);
    	added.insert(start);
    	while (! q.empty())
    	{
    		string s = q.front();
    		q.pop();
    		-- lev1;
    		for (int i = 0; i < s.length(); ++ i)
    		{
    			for (int j = 0; j < 26; ++ j)
    			{
    				string t = s;
    				t[i] = 'a' + j;
    				if (t != s)
    				{
    					if (t == end)
    					{
    						return ret + 2;
    					}
    					if (dict.find(t) != dict.end() && added.find(t) == added.end())
    					{
    						q.push(t);
    						added.insert(t);
    						++ lev2;
    					}
    				}
    			}
    		}
    		if (0 == lev1)
    		{
    			++ ret;
    			lev1 = lev2;
    			lev2 = 0;
    		}
    	}
    	return 0;
    }
};

// 2015-01-07
class Solution {
public:
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		queue<string> Q;
		Q.push(start);
		Q.push("");
		int res = 1;
		while (!Q.empty()) {
			string str = Q.front();
			Q.pop();
			if ("" != str) {
				int str_len = str.length();
				for (size_t i = 0; i < str_len; ++i) {
					char tmp = str[i];
					for (char c = 'a'; c <= 'z'; ++c) {
						if (c == tmp) {
							continue;
						}
						str[i] = c;
						if (str == end) {
							return res + 1;
						}
						if (dict.end() != dict.find(str)) {
							Q.push(str);
							dict.erase(str);
						}
					}
					str[i] = tmp;
				}
			}
			else if (!Q.empty()) {
				++res;
				Q.push("");
			}
		}
		return 0;
	}
};