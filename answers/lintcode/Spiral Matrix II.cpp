class Solution {
public:
    /**
     * @param n an integer
     * @return a square matrix
     */
    vector<vector<int>> generateMatrix(int n) {
        // Write your code here
        vector<vector<int> > matrix;
        if (1 == n) {
            matrix.push_back(vector<int> (1, 1));
        }
        else if (2 == n) {
            vector<int> temp(2, 0);
            temp[0] = 1;
            temp[1] = 2;
            matrix.push_back(temp);
            temp[0] = 4;
            temp[1] = 3;
            matrix.push_back(temp);
        }
        else if (n > 2) {
            matrix = generateMatrix(n - 2);
            for (size_t i = 0; i < matrix.size(); ++ i) {
                for (size_t j = 0; j < matrix[i].size(); ++ j) {
                    matrix[i][j] += n * n - (n - 2) * (n - 2);
                }
                matrix[i].push_back(n + 1 + i);
                matrix[i].insert(matrix[i].begin(), n * n - (n - 2) * (n - 2) - i);
            }
            vector<int> temp(n, 0);
            for (size_t i = 0; i < temp.size(); ++ i) {
                temp[i] = i + 1;
            }
            matrix.insert(matrix.begin(), temp);
            for (size_t i = 0; i < temp.size(); ++ i) {
                temp[i] = 3 * n - 2 - i;
            }
            matrix.push_back(temp);
        }
        return matrix;
    }
};
