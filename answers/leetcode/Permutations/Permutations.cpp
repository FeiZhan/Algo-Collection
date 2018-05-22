//2014-04-11
//@result 25 / 25 test cases passed. Status: Accepted Runtime: 16 ms Submitted: 0 minutes ago You are here! Your runtime beats 26.69% of cpp submissions.

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
