class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict)
    {
        unordered_set<string> added;
    	queue<string> q;
    	int ret = 0;
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
