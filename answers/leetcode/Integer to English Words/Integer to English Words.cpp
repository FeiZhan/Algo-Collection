//@type  Math String
//@result 601 / 601 test cases passed. Status: Accepted Runtime: 12 ms Submitted: 1 minute ago

class Solution {
public:
    string numberToWords(int num) {
		string ans;
		if (0 == num) {
			ans = "Zero";
		}
		else if (num < 20) {
			ans = v1[num];
		}
		else if (num < 100) {
			ans = v2[num / 10];
			if (num % 10) {
				ans += " " + v1[num % 10];
			}
		}
		else if (num < 1000) {
			ans = v1[num / 100] + " Hundred";
			if (num % 100) {
				ans += " " + numberToWords(num % 100);
			}
		}
		else {
			int count = 0;
			if (num % 1000) {
				ans = numberToWords(num % 1000);
			}
			num /= 1000;
			while (num > 0) {
				string temp(ans);
				if (num % 1000) {
					ans = numberToWords(num % 1000) + " " + v[count];
					if (temp.length()) {
						ans += " " + temp;
					}
				}
				num /= 1000;
				++ count;
			}
		}
		return ans;
    }
	vector<string> v1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
	vector<string> v2 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
	vector<string> v = {"Thousand", "Million", "Billion"};
};