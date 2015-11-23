#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



int main()
{
    long long n, k; cin >> n >> k;
    vector<int> prices;
    for(int i = 0; i < n; i++)
    {
        int p; cin >> p;
        prices.push_back(p);
    }

    int answer = 0;

    // Write the code for computing the final answer using n,k,prices
    sort(prices.begin(), prices.end());
    int price = 0;
    for (answer = 0; answer < prices.size() && price + prices[answer] <= k; ++ answer) {
        price += prices[answer];
    }

    cout << answer << endl;

    return 0;
}
