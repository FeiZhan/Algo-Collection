//WA

class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > container;
        for (int i = 0; i < height.size(); ++ i)
        {
			vector<int> tmp;
			for (int j = 0; j < height.size(); ++ j)
			{
				tmp.push_back(( (height[i] <= height[j]) ? height[i] : height[j] ) * ( (i > j) ? (i - j) : (j - i) ));
			}
			container.push_back(tmp);
		}
		for (int i = 2; i < height.size(); ++ i)
		{
			for (int j = 0; i + j < height.size(); ++ j)
			{
				if (height[j + i - 1] > height[j + i])
				{
					container[j][j + i] = (container[j][j + i - 1] > (height[j + i]) * i) ? container[j][j + i - 1] : ((height[j + i]) * i);
				} else
				{
					container[j][j + i] = (container[j][j + i - 1] > (height[j + i - 1]) * i) ? container[j][j + i - 1] : ((height[j + i - 1]) * i);
				}
			}
		}
		return container[0][height.size() - 1];
    }
};
