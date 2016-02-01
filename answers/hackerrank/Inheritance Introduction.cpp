//@result Submitted a few seconds ago • Score: 10.00 Status: Accepted Test Case #0:   0s

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Triangle{
    public:
       void triangle(){
           cout<<"I am a triangle\n";
       }
};
class Isosceles : public Triangle{
    public:
       void isosceles(){
          cout<<"I am an isosceles triangle\n";
       }
        //Write your code here.
        void description(void) {
            cout << "In an isosceles triangle two sides are equal" << endl;
        }
};
int main(){
    Isosceles isc;
    isc.isosceles();
     isc.description();
    isc.triangle();
    return 0;
}
