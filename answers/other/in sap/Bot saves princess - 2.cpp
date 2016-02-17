#include <iostream>
#include <vector>
using namespace std;
void nextMove(int n, int r, int c, vector <string> grid) {
    //your logic here
    pair<size_t, size_t> mario;
    pair<size_t, size_t> princess;
    for (size_t i = 0; i < grid.size(); ++ i) {
        for (size_t j = 0; j < grid.size(); ++ j) {
            switch (grid[i][j]) {
            case 'm':
                mario.first = i;
                mario.second = j;
                break;
            case 'p':
                princess.first = i;
                princess.second = j;
                break;
            default:
                break;
            }
        }
    }
    string move;
    if (mario.first > princess.first) {
        move = "UP";
    }
    else if (mario.first < princess.first) {
        move = "DOWN";
    }
    else if (mario.second > princess.second) {
        move = "LEFT";
    }
    else if (mario.second < princess.second) {
        move = "RIGHT";
    }
    cout << move << endl;
}
int main(void) {

    int n, r, c;
    vector <string> grid;

    cin >> n;
    cin >> r;
    cin >> c;

    for(int i=0; i<n; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    nextMove(n, r, c, grid);
    return 0;
}
