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
//2014-04-11
class Solution {
public:
	vector<vector<int> > permute(vector<int> &num) {
		std::vector<std::vector<int> > ans;
		if (num.size() == 0)
		{
			return ans;
		}
		std::vector<int> temp(num.begin(), num.end() - 1);
		std::vector<std::vector<int> > temp1 = permute(temp);
		if (temp1.size() == 0)
		{
			temp1.push_back(vector<int>());
		}
		for (std::vector<std::vector<int> >::iterator it = temp1.begin(); it != temp1.end(); ++it)
		{
			for (size_t j = 0; j <= it->size(); ++j)
			{
				std::vector<int> temp2(it->begin(), it->end());
				temp2.insert(temp2.begin() + j, num.back());
				ans.push_back(temp2);
			}
		}
		return ans;
	}
};