//@result Submitted a few seconds ago • Score: 35.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s Test Case #2: 0s Test Case #3: 0s Test Case #4: 0s Test Case #5: 0s Test Case #6: 0s Test Case #7: 0.04s Test Case #8: 0.05s Test Case #9: 0.05s Test Case #10: 0.04s Test Case #11: 0.05s Test Case #12: 0.03s Test Case #13: 0.05s Test Case #14: 0.03s Test Case #15: 0s Test Case #16: 0s

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int getUnfairness(int N, int K, int list[]) {
    sort(list, list + N);
    int unfair = INT_MAX;
    for (int i = K - 1; i < N; ++ i) {
        unfair = min(unfair, list[i] - list[i - K + 1]);
    }
    return unfair;
}
int main() {
    int N, K, unfairness = INT_MAX;
    cin >> N >> K;
    int list[N];
    for (int i=0; i<N; i++)
        cin >> list[i];

    /** Write the solution code here. Compute the result, store in  the variable unfairness --
    and output it**/
    unfairness = getUnfairness(N, K, list);

    cout << unfairness << "\n";
    return 0;
}
