#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void displayPathtoPrincess(int n, vector <string> grid){
    //your logic here
    queue<pair<size_t, size_t> > pos_que;
    for (size_t i = 0; i < grid.size(); ++ i) {
        for (size_t j = 0; j < grid[i].size(); ++ j) {
            if ('m' == grid[i][j]) {
                pos_que.push(make_pair(i, j));
            }
        }
    }
    pair<size_t, size_t> final;
    const int MOVE_LIST[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool final_flag = false;
    while (! pos_que.empty()) {
        pair<size_t, size_t> current = pos_que.front();
        pos_que.pop();
        if (current.first >= grid.size() || current.second >= grid[current.first].size()) {
            continue;
        }
        for (int i = 0; i < 4; ++ i) {
            if (current.first + MOVE_LIST[i][0] < grid.size() && current.second + MOVE_LIST[i][1] < grid[current.first].size()) {
                if ('p' == grid[current.first + MOVE_LIST[i][0]][current.second + MOVE_LIST[i][1]]) {
                    grid[current.first + MOVE_LIST[i][0]][current.second + MOVE_LIST[i][1]] = i;
                    final = make_pair(current.first + MOVE_LIST[i][0], current.second + MOVE_LIST[i][1]);
                    final_flag = true;
                    break;
                }
                if ('-' == grid[current.first + MOVE_LIST[i][0]][current.second + MOVE_LIST[i][1]]) {
                    grid[current.first + MOVE_LIST[i][0]][current.second + MOVE_LIST[i][1]] = i;
                }
                pos_que.push(make_pair(current.first + MOVE_LIST[i][0], current.second + MOVE_LIST[i][1]));
            }
        }
        if (final_flag) {
            break;
        }
    }
    vector<string> move_list;
    while ('m' != grid[final.first][final.second]) {
        switch (grid[final.first][final.second]) {
        case 0:
            move_list.push_back(string("UP"));
            break;
        case 1:
            move_list.push_back(string("DOWN"));
            break;
        case 2:
            move_list.push_back(string("LEFT"));
            break;
        case 3:
            move_list.push_back(string("RIGHT"));
            break;
        }
        final.first -= MOVE_LIST[grid[final.first][final.second]][0];
        final.second -= MOVE_LIST[grid[final.first][final.second]][1];
    }
    for (size_t i = move_list.size() - 1; i < move_list.size(); -- i) {
        cout << move_list[i] << endl;
    }
}
int main(void) {

    int m;
    vector <string> grid;

    cin >> m;

    for(int i=0; i<m; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    displayPathtoPrincess(m,grid);

    return 0;
}
