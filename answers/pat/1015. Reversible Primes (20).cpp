//
#include <iostream>
using namespace std;

bool isPrime(int n)
{
     int i,count=0;
     if(n==0 || n==1)
       return false;
     else if(n==2)
       return true;
     else if(n%2==0)
       return false;
     for(i=1;i<=n;i++)
     {
        if(n%i==0)
          count++;  
     }
      if(count==2) // Why ? 
       return true;
      else
       return false; 
}

int main (int argc, char *argv[])
{
	int number(0), radix(0);
	while (cin >> number >> radix && number >= 0) {
		if (! isPrime(number)) {
			cout << "No" << endl;
			continue;
		}
		int digit(0), reverse(0);
		while (number > 0) {
			digit = number % radix;
			reverse = reverse * radix + digit;
			number /= radix;
		}
		cout << (isPrime(reverse) ? "Yes" : "No") << endl;
	}

	return 0;
}