//WA
class Solution {
public:
    vector<vector<string> > partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > is_palin;
        for (int i = 0; i < s.length(); ++ i)
        {
			vector<int> tmp;
			for (int j = i; j < s.length(); ++ j)
			{
				tmp.push_back(isPalin(s.substr(i, j - i)));
			}
			is_palin.push_back(tmp);
		}
		return parti(s, is_palin, 0, s.length() - 1);
    }
	bool isPalin(string s)
    {
		for (int i = 0; i < s.length() / 2; ++ i)
		{
			if (s[i] != s[s.length() - i - 1])
			{
				return false;
			}
		}
		return true;
	}
    vector<vector<string> > parti(const string &s, const vector<vector<int> > &is_palin, int begin, int end)
    {
		vector<vector<string> > p;
		if (begin > end)
		{
			return p;
		}
		if (begin == end && is_palin[begin][end])
		{
			vector<string> tmp;
			tmp.push_back(s.substr(begin, end - begin));
			p.push_back(tmp);
			return p;
		}
		vector<vector<string> > first;
		for (int i = begin; i <= end; ++ i)
		{
			vector<string> tmp;
			if (is_palin[begin][i])
			{
				tmp.push_back(s.substr(i, i - begin));
			}
			//vector<vector<string> > first; // = parti(s, is_palin, begin, i);
			first.push_back(tmp);
			/*if (is_palin[i + 1][end])
			{
				tmp.clear();
				tmp.push_back(s.substr(end, end - i - 1));
			}
			vector<vector<string> > second; // = parti(s, is_palin, i + 1, end);
			second.push_back(tmp);
			if (first.size() == 0 || second.size() == 0)
			{
				continue;
			}
			for (int j = 0; j < first.size(); ++ j)
			{
				for (int k = 0; k < second.size(); ++ k)
				{
					vector<string> tmp;
					// preallocate memory
					tmp.reserve( first[j].size() + second[k].size() );
					tmp.insert( tmp.end(), first[j].begin(), first[j].end() );
					tmp.insert( tmp.end(), second[k].begin(), second[k].end() );
					p.push_back(tmp);
				}
			}*/
		}
		//unique(p.begin(), p.end());
		return first; //p;
	}
};
