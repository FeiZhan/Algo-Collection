class Solution {
public:
    /**
     * @param path the original path
     * @return the simplified path
     */
    string simplifyPath(string& path) {
        // Write your code here
		vector<string> path_list;
		std::istringstream ss(path);
		std::string token;
		while(std::getline(ss, token, '/')) {
			path_list.push_back(token);
		}
		for (size_t i = 0; i < path_list.size(); ++ i) {
			if (string("") == path_list[i] || string(" ") == path_list[i] || string(".") == path_list[i]) {
				path_list.erase(path_list.begin() + i);
				-- i;
			}
			else if (string("..") == path_list[i]) {
				if (i > 0) {
					path_list.erase(path_list.begin() + i - 1, path_list.begin() + i);
					i -= 2;
				}
				else {
					path_list.erase(path_list.begin() + i);
					-- i;
				}
			}
		}
		string simplified;
		for (size_t i = 0; i < path_list.size(); ++ i) {
			simplified += string("/") + path_list[i];
		}
		if (0 == simplified.length()) {
			simplified = string("/");
		}
		return simplified;
    }
};
