/*
 * Complete the function below.
 */
int countUneatenLeaves(int N, vector < int > A) {
    // if a relatively small test case
    if (N < 10000000) {
        // time complexity: O(N * K)
        int count = 0;
        for (int i = 1; i <= N; ++ i) {
            bool flag = true;
            for (size_t j = 0; j < A.size(); ++ j) {
                if (0 == i % A[j]) {
                    flag = false;
                    break;
                }
            }
            count += flag;
        }
        return count;
    }
    else {
        // time complexity: O(2 ^ K)
        vector<vector<int> > subsets;
        // obtain subsets by bit manipulation
        for (int i = 0; i < (1 << A.size()); ++ i) {
            vector<int> subset;
            for (size_t j = 0; j < A.size(); ++ j) {
                if (i & (1 << j)) {
                    subset.push_back(A[j]);
                }
            }
            subsets.push_back(subset);
        }
        int count = N;
        for (size_t i = 0; i < subsets.size(); ++ i) {
            if (subsets[i].size() == 0) {
                continue;
            }
            int target = subsets[i][0];
            // compute lcm
            for (size_t j = 1; j < subsets[i].size(); ++ j) {
                int a = target;
                int b = subsets[i][j];
                while (b != 0) {
                    int temp = b;
                    b = a % b;
                    a = temp;
                }
                target = target * subsets[i][j] / a;
            }
            count += (N / target) * (subsets[i].size() % 2 ? -1 : 1);
        }
        return count;
    }
}


/*
 * Complete the function below.
 */
string compress(string str) {
    size_t current = 0;
    int count = 1;
    for (size_t i = 1; i <= str.length(); ++ i) {
        // found a new character, or reach the end
        if (i == str.length() || str[i] != str[i - 1]) {
            // reuse original string
            str[current] = str[i - 1];
            ++ current;
            // attach a number
            if (count > 1) {
                string num(to_string(count));
                for (size_t j = 0; j < num.length(); ++ j) {
                    str[current + j] = num[j];
                }
                current += num.length();
            }
            count = 1;
        }
        // found a repeated character
        else if (str[i] == str[i - 1]) {
            ++ count;
        }
    }
    return str.substr(0, current);
}
