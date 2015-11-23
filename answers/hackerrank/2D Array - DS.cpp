#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<vector<int> > matrix(6, vector<int> (6, 0));
    for (int i = 0; i < 6; ++ i) {
        for (int j = 0; j < 6; ++ j) {
            int num = 0;
            cin >> num;
            matrix[i][j] = num;
        }
    }
    int largest = INT_MIN;
    int largesti = 0;
    int largestj = 0;
    for (int i = 0; i < 4; ++ i) {
        for (int j = 0; j < 4; ++ j) {
            int sum = matrix[i][j] + matrix[i][j + 1] + matrix[i][j + 2] + matrix[i + 1][j + 1] + matrix[i + 2][j] + matrix[i + 2][j + 1] + matrix[i + 2][j + 2];
            if (sum > largest) {
                largest = sum;
                largesti = i;
                largestj = j;
            }
        }
    }
    //cout << matrix[largesti][largestj] << " " << matrix[largesti][largestj + 1] << " " << matrix[largesti][largestj + 2] << endl << "   " << matrix[largesti + 1][largestj + 1] << endl << matrix[largesti + 2][largestj] << " " << matrix[largesti + 2][largestj + 1] << " " << matrix[largesti + 2][largestj + 2] << endl;
    cout << largest << endl;
    return 0;
}
