//@result Submitted a minute ago • Score: 50.00 Status: Accepted Test Case #0: 0s Test Case #1: 1.58s Test Case #2: 1.57s Test Case #3: 1.56s Test Case #4: 1.61s Test Case #5: 1.56s Test Case #6: 1.58s Test Case #7: 1.55s Test Case #8: 1.61s Test Case #9: 0.78s Test Case #10: 0.77s

#include <iostream>
#include <deque>
using namespace std;
void printKMax(int arr[], int n, int k){
   //Write your code here.
   deque<int> arr_que;
   for (int i = 0; i < n; ++ i) {
       while (! arr_que.empty() && arr_que.front() <= i - k) {
           arr_que.pop_front();
       }
       while (! arr_que.empty() && arr[arr_que.back()] < arr[i]) {
           arr_que.pop_back();
       }
       arr_que.push_back(i);
       if (i + 1 > k) {
           cout << " ";
       }
       if (i + 1 >= k) {
           cout << arr[arr_que.front()];
       }
   }
   cout << endl;
}
int main(){

   int t;
   cin >> t;
   while(t>0) {
      int n,k;
       cin >> n >> k;
       int i;
       int arr[n];
       for(i=0;i<n;i++)
            cin >> arr[i];
       printKMax(arr, n, k);
       t--;
     }
     return 0;
}
