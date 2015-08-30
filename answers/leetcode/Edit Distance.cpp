// don't understand

class Solution {
public:
	inline int minInt(int a, int b)
	{
		return a < b ? a : b;
	}
	inline int minInt(int a, int b, int c)
	{
		return minInt( minInt(a, b), c );
	}
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int l1 = word1.length(), l2 = word2.length();
		std::string &w1 = (l1 < l2 ? word1 : word2); // shorter - horizontal
		std::string &w2 = (l1 < l2 ? word2 : word1); // longer - vertical
		int length1 = w1.length(), length2 = w2.length();
		if (0 == length1)
		{
			return length2;
		}
		std::vector<int> dist(length1, 0);
		for (int i = 0; i < length1; ++ i)
		{
			dist[i] = i + 1;
		}
		// vertical starting from row 1 (when 1 == length2)
		for (int i = 0; i < length2; ++ i)
		{
			int distDiag = i, distLeft = i + 1;
			// horizontal
			for (int j = 0; j < length1; ++ j)
			{
				int distUp = dist[j];
				if (w1[j] == w2[j])
				{
					dist[j] = distDiag;
				} else
				{
					dist[j] = minInt(distLeft, distUp, distDiag) + 1;
				}
				distDiag = distUp;
				distLeft = dist[j];
			}
		}
		return dist[length1 - 1];
    }
};

// 2014-12-14
class Solution {
public:
    int minDistance(string word1, string word2) {
		if (0 == word1.length() || 0 == word2.length()) {
			return word1.length() + word2.length();
		}
		// rotation array is better
		std::vector<std::vector<int> > dp(word1.length(), std::vector<int>(word2.length(), INT_MAX));
		for (size_t i = 0; i < word1.length(); ++ i) {
			for (size_t j = 0; j < word2.length(); ++ j) {
				// be careful with size_t minus
				int diff = std::abs(static_cast<int>(i) - static_cast<int>(j));
				if (word1[i] == word2[j]) {
					if (i >= 1 && j >= 1) {
						dp[i][j] = dp[i - 1][j - 1];
					} else {
						dp[i][j] = diff;
					}
				} else {
					if (i >= 1) {
						dp[i][j] = dp[i - 1][j] + 1;
					} else {
						dp[i][j] = diff + 1;
					}
					if (j >= 1) {
						dp[i][j] = std::min(dp[i][j], dp[i][j - 1] + 1);
					} else {
						dp[i][j] = std::min(dp[i][j], diff + 1);
					}
					// don't forget
					if (i >= 1 && j >= 1) {
						dp[i][j] = std::min(dp[i][j], dp[i - 1][j - 1] + 1);
					}
				}
			}
		}
		/*for (size_t i = 0; i < dp.size(); ++ i) {
			for (size_t j = 0; j < dp[i].size(); ++ j) {
				std::cout << i << " " << j << " : " << dp[i][j] << std::endl;
			}
		}*/
		return dp[word1.length() - 1][word2.length() - 1];
    }
};
