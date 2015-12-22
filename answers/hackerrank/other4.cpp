/*
 * Complete the function below.
 */
vector < string > Braces(vector < string > values) {
    vector<string> answers;
    // for each string
    for (size_t i = 0; i < values.size(); ++ i) {
        // use a stack to match braces
        stack<char> brace_stack;
        bool flag = true;
        // for each char
        for (size_t j = 0; j < values[i].size(); ++ j) {
            switch (values[i][j]) {
            // left brace
            case '(':
            case '[':
            case '{':
                brace_stack.push(values[i][j]);
                break;
            // right brace
            case ')':
                // if not match
                if (brace_stack.empty() || brace_stack.top() != '(') {
                    flag = false;
                }
                // if match
                else {
                    brace_stack.pop();
                }
                break;
            case ']':
                if (brace_stack.empty() || brace_stack.top() != '[') {
                    flag = false;
                }
                else {
                    brace_stack.pop();
                }
                break;
            case '}':
                if (brace_stack.empty() || brace_stack.top() != '{') {
                    flag = false;
                }
                else {
                    brace_stack.pop();
                }
                break;
            }
            if (! flag) {
                break;
            }
        }
        answers.push_back((flag && brace_stack.empty()) ? "YES" : "NO");
    }
    return answers;

}
// for each string
// time complexity: O(N)
// space complexity: O(N)


/*
 * Complete the function below.
 */
int palindrome(string str) {
    vector<vector<bool> > dp(str.length(), vector<bool> (str.length(), false));
    // for each substring with length i
    for (size_t i = 0; i < str.length(); ++ i) {
        // for each substring starting at j
        for (size_t j = 0; i + j < str.length(); ++ j) {
            // dp[a][b] starts at a, ends at b
            // palindrome:
            // 1. length is 1;
            // 2. length is 2, and characters are the same;
            // 3. length is more than 2, first char is the same as the last char, other chars are palindrome
            dp[j][j + i] = 0 == i || (1 == i && str[j] == str[j + i]) || (i > 1 && dp[j + 1][i + j - 1] && str[j] == str[i + j]);
        }
    }
    // use set (better if unordered_set) to filter out duplicates
    set<string> palin_list;
    for (size_t i = 0; i < dp.size(); ++ i) {
        for (size_t j = 0; j < dp[i].size(); ++ j) {
            if (dp[i][j]) {
                palin_list.insert(str.substr(i, j - i + 1));
            }
        }
    }
    return palin_list.size();
}
// time complexity: O(N^2)
// space complexity: O(N^2)


/*
 * Complete the function below.
 */
vector < int > mergeArrays(vector < int > a, vector < int > b) {
    vector<int> merge;
    for (size_t i = 0, j = 0; i < a.size() || j < b.size(); ) {
        // if both arrays exist
        if (i < a.size() && j < b.size()) {
            if (a[i] <= b[j]) {
                merge.push_back(a[i]);
                ++ i;
            }
            else {
                merge.push_back(b[j]);
                ++ j;
            }
        }
        // if only a exists
        else if (i < a.size()) {
            merge.push_back(a[i]);
            ++ i;
        }
        // if only b exists
        else if (j < b.size()) {
            merge.push_back(b[j]);
            ++ j;
        }
    }
    return merge;
}
// time complexity: O(a + b)
// space complexity: O(a + b)
