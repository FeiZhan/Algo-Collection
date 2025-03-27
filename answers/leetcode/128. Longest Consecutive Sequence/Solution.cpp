// I guess my code is simplest
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		map<int, int> m;
		for (int i = 0; i < num.size(); ++ i)
		{
			m[num[i]] = 1;
		}
		int max = 0;
		for (map<int, int>::iterator it = m.begin(); it != m.end(); ++ it)
		{
			if (m.find(it->first - 1) != m.end())
			{
				m[it->first] = m[it->first - 1] + 1;
			}
			if (it->second > max)
			{
				max = it->second;
			}
		}
		return max;
    }
};
