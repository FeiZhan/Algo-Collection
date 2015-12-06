// Q1

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    string text;
    cin >> text;
    stack<char> text_stack;
    bool flag = true;
    for (size_t i = 0; i < text.length(); ++ i) {
        switch (text[i]) {
        // if left delimiter, push into stack
        case '(':
        case '[':
        case '{':
        case '<':
            text_stack.push(text[i]);
            break;
        // if right delimiter
        case ')':
            // if not match, break
            if (text_stack.empty() || '(' != text_stack.top()) {
                flag = false;
            }
            // if match, remove left delimiter
            else {
                text_stack.pop();
            }
            break;
        case ']':
            if (text_stack.empty() || '[' != text_stack.top()) {
                flag = false;
            }
            else {
                text_stack.pop();
            }
            break;
        case '}':
            if (text_stack.empty() || '{' != text_stack.top()) {
                flag = false;
            }
            else {
                text_stack.pop();
            }
            break;
        case '>':
            if (text_stack.empty() || '<' != text_stack.top()) {
                flag = false;
            }
            else {
                text_stack.pop();
            }
            break;
        default:
            break;
        }
        if (! flag) {
            break;
        }
    }
    // if stack is not empty, it does not match
    cout << (flag && text_stack.empty() ? "true" : "false") << endl;
    return 0;
}
// time complexity: O(n)
// space complexity: worst O(n)

// Q2

#include <iostream>
#include <vector>
using namespace std;

void convert(size_t prebegin, size_t preend, const vector<int> &preorder, size_t postbegin, size_t postend, vector<int> &postorder) {
    // if beyond scope, exit
    if (prebegin > preend || preend >= preorder.size()) {
        return;
    }
    // the leftmost node in pre-order is root
    int root = preorder[prebegin];
    size_t rightbegin = prebegin + 1;
    // the beginning of right tree is larger than the root
    while (rightbegin < preorder.size() && preorder[rightbegin] <= preorder[prebegin]) {
        ++ rightbegin;
    }
    // convert left tree
    convert(prebegin + 1, rightbegin - 1, preorder, postbegin, postbegin + rightbegin - prebegin - 2, postorder);
    // convert right tree
    convert(rightbegin, preend, preorder, postbegin + rightbegin - prebegin - 1, postend - 1, postorder);
    // set the root to post-order
    postorder[postend] = root;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<int> preorder;
    int num = 0;
    while (cin >> num) {
        preorder.push_back(num);
    }
    vector<int> postorder(preorder.size(), -1);
    // covert from pre-order to post-order recursively
    convert(0, preorder.size() - 1, preorder, 0, postorder.size() - 1, postorder);
    for (size_t i = 0; i < postorder.size(); ++ i) {
        cout << postorder[i] << endl;
    }
    return 0;
}
// time complexity: O(nlogn)
// space complexity: O(n)

// Q3
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long long order = 0;
    long long size = 0;
    cin >> order >> size;
    // set numbers as 64 bits (long long)
    vector<long long> nums(size, 0);
    // initialize with ascending order
    std::iota(nums.begin(), nums.end(), 0);
    // C++ STL makes life easier. Time complexity: O(N * M) too large
    /*while (order --) {
        next_permutation(nums.begin(), nums.end());
    }*/
    long long factorial = 1;
    for (long long i = 1; i <= size; ++ i) {
        factorial *= i;
    }
    vector<long long> answer;
    for (long long i = 0; i < size; ++ i) {
        factorial /= size - i;
        // select the order of the i-th number
        long long num = order / factorial;
        answer.push_back(nums[num]);
        // remove the selected number from list
        nums.erase(nums.begin() + num);
        order %= factorial;
    }
    for (size_t i = 0; i < answer.size(); ++ i) {
        cout << (i ? " " : "") << answer[i];
    }
    cout << endl;
    return 0;
}
// time complexity: O(N)
// space complexity: O(N)

// Q4
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

// use depth-first search to find paths
void dfs(int steps, size_t x, size_t y, vector<vector<int> > &board) {
    // if beyond the size of the board, or visited before, or blocked
    if (x >= board.size() || y >= board[x].size() || board[x][y] <= steps || board[x][y] < 0) {
        return;
    }
    // set the steps to a smaller value
    board[x][y] = steps;
    // search via eight squares that a knight can jump
    dfs(steps + 1, x - 2, y - 1, board);
    dfs(steps + 1, x - 2, y + 1, board);
    dfs(steps + 1, x - 1, y - 2, board);
    dfs(steps + 1, x - 1, y + 2, board);
    dfs(steps + 1, x + 1, y - 2, board);
    dfs(steps + 1, x + 1, y + 2, board);
    dfs(steps + 1, x + 2, y - 1, board);
    dfs(steps + 1, x + 2, y + 1, board);
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int height = 0;
    int width = 0;
    cin >> height >> width;
    vector<vector<int> > board(height, vector<int> (width, INT_MAX));
    int startx = 0;
    int starty = 0;
    cin >> startx >> starty;
    int targetx = 0;
    int targety = 0;
    cin >> targetx >> targety;
    int block_num = 0;
    cin >> block_num;
    while (block_num --) {
        int blockx = 0;
        int blocky = 0;
        cin >> blockx >> blocky;
        // -1 means blocked
        board[blockx][blocky] = -1;
    }
    dfs(0, startx, starty, board);
    cout << board[targetx][targety] << endl;
    return 0;
}
// time complexity: O(N * M)
// space complexity: O(N * M)
