class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		std::vector<int> ans;
		if (L.size() == 0)
		{
			return ans;
		}
		int size = L[0].size();
		std::map<int, int> match;
		for (int i = 0; i < S.length(); ++ i)
		{
			for (int j = 0; j < L.size(); ++ j)
			{
				if (S[i] == L[j][0] && S.substr(i, size) == L[j])
				{
					match.insert(std::make_pair(i, j));
				}
			}
		}
		for (std::map<int, int>::iterator it = match.begin(); it != match.end(); ++ it)
		{
			
		}
    }
};
