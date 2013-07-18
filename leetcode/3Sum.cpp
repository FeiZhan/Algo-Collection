//WA

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        multiset<int> num_set;
        for (int i = 0; i < num.size(); ++ i)
        {
			num_set.insert(num[i]);
		}
        vector<vector<int> > ans;
        for (multiset<int>::iterator it = num_set.begin(); it != num_set.end(); ++ it)
        {
			for (multiset<int>::iterator it2 = num_set.begin(); it2 != it; ++ it2)
			{
				multiset<int>::iterator it3 = num_set.find(- *it - *it2);
				if (it3 != num_set.end() && it3 != it && it3 != it2)
				{
					vector<int> tmp;
					tmp.push_back(*it);
					tmp.push_back(*it2);
					tmp.push_back(- *it - *it2);
					sort(tmp.begin(), tmp.end());
					//if (! duplicate(tmp, ans))
					//{
						ans.push_back(tmp);
					//}
				}
			}
		}
		Unique(ans.begin(), ans.end(), ans);
		return ans;
    }
    bool duplicate(const vector<int> &ele, const vector<vector<int> > &array)
    {
		for (int i = 0; i < array.size(); ++ i)
		{
			if (ele.size() != array[i].size())
			{
				continue;
			}
			bool same_flag = true;
			for (int j = 0; j < array[i].size(); ++ j)
			{
				if (ele[j] != array[i][j])
				{
					same_flag = false;
					break;
				}
			}
			if (same_flag)
			{
				return true;
			}
		}
		return false;
	}
	void Unique(vector<vector<int> >::iterator begin, vector<vector<int> >::iterator end, vector<vector<int> > &array)
	{
		for (vector<vector<int> >::iterator i = begin; i != end; ++ i)
		{
			for (vector<vector<int> >::iterator j = i + 1; j != end; ++ j)
			{
				if ((*i).size() != (*j).size())
				{
					continue;
				}
				bool flag = false;
				for (int k = 0; k < (*i).size(); ++ k)
				{
					if ((*i)[k] != (*j)[k])
					{
						flag = true;
						break;
					}
				}
				if (false == flag)
				{
					j = array.erase(j, j + 1);
				}
			}
		}
	}
};
