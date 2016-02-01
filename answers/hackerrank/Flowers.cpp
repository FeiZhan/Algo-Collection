//@result Submitted a few seconds ago • Score: 35.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s Test Case #2: 0s Test Case #3: 0s Test Case #4: 0s Test Case #5: 0s Test Case #6: 0s Test Case #7: 0s Test Case #8: 0s Test Case #9: 0s Test Case #10: 0s

/* Sample program illustrating input/output */
#include<iostream>
#include <algorithm>
using namespace std;

int main(void){

//Helpers for input and output

   int N, K;
   cin >> N >> K;
    int C[N];
   for(int i = 0; i < N; i++){
      cin >> C[i];
   }

   int result = 0;
   sort(C, C + N, greater<int> ());
   int level = 1;
   int count = 0;
   for (int i = 0; i < N; ++ i) {
       result += level * C[i];
       //cout << "debug " << level << " " << count << " " << C[i] << " " << result << endl;
       ++ count;
       if (count >= K) {
           ++ level;
           count = 0;
       }
   }

   cout << result << "\n";

   return 0;
}
