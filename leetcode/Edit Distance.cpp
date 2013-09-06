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
