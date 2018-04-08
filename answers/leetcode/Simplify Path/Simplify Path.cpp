//@result 252 / 252 test cases passed. Status: Accepted Runtime: 8 ms Submitted: 0 minutes ago You are here! Your runtime beats 43.27% of cpp submissions.

class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // should use deque to push, pop, and iterate
        deque<string> spath;
        int begin = 1;
		for (int i = 1; i <= path.length(); ++ i)
		{
			// add for the last one
			if ('/' == path[i] || i == path.length())
			{
				string dir = path.substr(begin, i - begin);
				begin = i + 1;
				// if //, skip it
				if ("." == dir || "" == dir)
				{
					continue;
				} else if (".." == dir)
				{
					if (! spath.empty())
					{
						spath.pop_back();
					}
				} else
				{
					spath.push_back(dir);
				}
			}
		}
		string output("");
		for (deque<string>::iterator it = spath.begin(); it != spath.end(); ++ it)
		{
			if ("" != *it)
			{
				output += "/" + *it;
			}
		}
		if ("" == output)
		{
			output += "/";
		}
		return output;
    }
};
