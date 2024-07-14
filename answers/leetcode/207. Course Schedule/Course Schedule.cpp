//@type Depth-first Search Breadth-first Search Graph Topological Sort
//@result 34 / 34 test cases passed. Status: Accepted Runtime: 340 ms Submitted: 2 minutes ago You are here! Your runtime beats 18.56% of cpp submissions.

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int> > course_mat(numCourses, vector<int> ());
		for (size_t i = 0; i < prerequisites.size(); ++ i) {
			course_mat[prerequisites[i].first].push_back(prerequisites[i].second);
		}
		vector<int> visit_flag(numCourses, 0);
		for (size_t i = 0; i < numCourses; ++ i) {
			if (! dfs(i, course_mat, visit_flag)) {
				return false;
			}
		}
		return true;
    }
	bool dfs(size_t current, const vector<vector<int> > &course_mat, vector<int> &visit_list) {
		//cout << "test " << current << " " << visit_list[current] << endl;
		if (1 == visit_list[current]) {
			return false;
		}
		visit_list[current] = 1;
		for (size_t i = 0; i < course_mat[current].size(); ++ i) {
			if (! dfs(course_mat[current][i], course_mat, visit_list)) {
				return false;
			}
		}
		visit_list[current] = 2;
		return true;
	}
};