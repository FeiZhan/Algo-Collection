// copied from leetcode

class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		std::string ans;
		int slen = S.length(), tlen = T.length(), min_len = INT_MAX, count = 0;
		int needtofind[256] = {0}, hasfound[256] = {0};
		for (int i = 0; i < tlen; ++ i)
		{
			++ needtofind[T[i]];
		}
		for (int begin = 0, end = 0; end < slen; ++ end)
		{
			// skip chars not in T
			if (0 == needtofind[S[end]])
			{
				continue;
			}
			++ hasfound[S[end]];
			if (hasfound[S[end]] <= needtofind[S[end]])
			{
				++ count;
			}
			if (count == tlen)
			{
				while (0 == needtofind[S[begin]] || hasfound[S[begin]] > needtofind[S[begin]])
				{
					if (hasfound[S[begin]] > needtofind[S[begin]])
					{
						-- hasfound[S[begin]];
					}
					++ begin;
				}
				int window_len = end - begin + 1;
				if (window_len < min_len)
				{
					min_len = window_len;
					ans = S.substr(begin, end - begin + 1);
				}
			}
		}
		return ans;
    }
};
