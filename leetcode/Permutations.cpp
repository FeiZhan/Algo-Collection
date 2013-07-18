class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > perm;
        if (num.size() == 0)
        {
			return perm;
		} else if (num.size() == 1)
        {
			perm.push_back(num);
			return perm;
		}
		for (int i = 0; i < num.size(); ++ i)
		{
			vector<int> target = num;
			target.erase(target.begin() + i);
			vector<vector<int> > second = permute(target);
			for (int j = 0; j < second.size(); ++ j)
			{
				second[j].insert(second[j].begin(), num[i]);
				perm.push_back(second[j]);
			}
		}
		return perm;
    }
};
