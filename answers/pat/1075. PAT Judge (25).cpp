#include <iostream>
using namespace std;

#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>

struct User {
	int id;
	int rank;
	int total;
	int solved;
	int passed;
	vector<int> score_list;
	User(int problem_num) : id(0), rank(0), total(0), solved(0), passed(0), score_list(problem_num, -2) {}
	//User(int i = 0, int r = 0, int t = 0, int s = 0) : id(i), rank(r), total(t), solved(s) {}
	bool operator <(const User &rhs) const {
		if (total != rhs.total) {
			return total > rhs.total;
		}
		else if (solved != rhs.solved) {
			return solved > rhs.solved;
		}
		else if (id != rhs.id) {
			return id < rhs.id;
		}
		return rank > rhs.rank;
	}
};
std::ostream& operator <<(std::ostream& out, const User &user) {
	out << user.rank << " " << std::setw(5) << std::setfill('0') << user.id << " " << user.total;
	for (size_t j = 0; j < user.score_list.size(); ++ j) {
		cout << " ";
		if (user.score_list[j] < -1) {
			cout << "-";
		}
		else if (-1 == user.score_list[j]) {
			cout << "0";
		}
		else {
			cout << user.score_list[j];
		}
	}
    return out;
 }
int main() {
	int user_num(0);
	int problem_num(0);
	int submission_num(0);
	while (cin >> user_num >> problem_num >> submission_num) {
		vector<int> problem_score_list;
		for (int i = 0; i < problem_num; ++ i) {
			int score(0);
			cin >> score;
			problem_score_list.push_back(score);
		}
		vector<User> user_list(user_num, User(problem_num));
		for (int i = 0; i < submission_num; ++ i) {
			int user(0);
			int problem(0);
			int score(0);
			cin >> user >> problem >> score;
			user_list[user - 1].score_list[problem - 1] = score > user_list[user - 1].score_list[problem - 1] ? score : user_list[user - 1].score_list[problem - 1];
		}
		for (size_t i = 0; i < user_list.size(); ++ i) {
			user_list[i].id = i + 1;
			for (size_t j = 0; j < user_list[i].score_list.size(); ++ j) {
				if (user_list[i].score_list[j] >= 0) {
					user_list[i].total += user_list[i].score_list[j];
					if (user_list[i].score_list[j] == problem_score_list[j]) {
						++ user_list[i].solved;
					}
					++ user_list[i].passed;
				}
			}
		}
		sort(user_list.begin(), user_list.end());
		int rank(0);
		int prev_rank(0);
		for (size_t i = 0; i < user_list.size(); ++ i) {
			if (user_list[i].passed <= 0) {
				continue;
			}
			++ rank;
			if (0 == i || user_list[i].total != user_list[i - 1].total) {
				prev_rank = rank;
			}
			user_list[i].rank = prev_rank;
			cout << user_list[i] << endl;
		}
	}
	return 0;
}