class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > tri;
        if (0 == numRows)
        {
			return tri;
		}
        vector<int> tmp;
        tmp.push_back(1);
        tri.push_back(tmp);
        for (int i = 1; i < numRows; ++ i)
        {
			tmp.clear();
			tmp.push_back(tri[i - 1][0]);
			for (int j = 1; j < i; ++ j)
			{
				tmp.push_back(tri[i - 1][j - 1] + tri[i - 1][j]);
			}
			tmp.push_back(tri[i - 1][tri[i - 1].size() - 1]);
			tri.push_back(tmp);
		}
		return tri;
    }
};
