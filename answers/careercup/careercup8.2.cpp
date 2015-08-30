#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const unsigned MAX_DEC_LEN = 32;
const unsigned MAX_BIN_LEN = 32;
const vector<int> getBinary(const string &decimal)
{
	if (decimal.size() > MAX_DEC_LEN)
	{
		return vector<int>();
	}
	string::size_type dot = decimal.find('.');
	if (dot == string::npos)
	{
		dot = decimal.size();
	}
	vector<int> binary;
	vector<int> integer;
	for (string::size_type i = 0; i < dot; ++ i)
	{
		integer.push_back(static_cast<int>(decimal.at(i) - '0'));
	}
	bool one_flag;
	unsigned carry, new_carry;
	do
	{
		one_flag = false;
		carry = 0;
		for (vector<int>::iterator it = integer.begin(); it != integer.end(); ++ it)
		{
			new_carry = (*it + carry * 10) % 2;
			*it = (*it + carry * 10) / 2;
			carry = new_carry;
			if (one_flag == false && *it > 0)
			{
				one_flag = true;
			}
		}
		binary.push_back(carry);
		if (binary.size() >= MAX_BIN_LEN)
		{
			return vector<int>();
		}
	} while (one_flag == true);
	reverse(binary.begin(), binary.end());
	if (decimal.size() == dot)
	{
		return binary;
	}
	binary.push_back(-1);
	vector<int> frac;
	for (string::size_type i = dot+1; i < decimal.size(); ++ i)
	{
		frac.push_back(static_cast<int>(decimal.at(i) - '0'));
	}
	do
	{
		one_flag = false;
		carry = 0;
		for (vector<int>::reverse_iterator it = frac.rbegin(); it != frac.rend(); ++ it)
		{
			new_carry = (*it + carry) * 2 / 10;
			*it = (*it * 2 + carry) % 10;
			carry = new_carry;
			if (one_flag == false && *it > 0)
			{
				one_flag = true;
			}
		}
		binary.push_back(carry);
		if (binary.size() >= MAX_BIN_LEN)
		{
			return vector<int>();
		}
	}
	while (one_flag == true);
	return binary;
}
int main(int argc, char *argv[])
{
	vector<string> decimal;
	decimal.push_back("1.25");
	decimal.push_back("100");
	decimal.push_back("1.1");
	decimal.push_back("3.5");
	decimal.push_back("100.8125");
	vector<int> ret;
	for (vector<string>::size_type i = 0; i < decimal.size(); ++ i)
	{
		cout << "test case " << i << " dec: " << decimal.at(i) << " bin: " << flush;
		ret = getBinary(decimal.at(i));
		if (ret.size() == 0)
		{
			cout << "error" << endl;
			continue;
		}
		for (vector<int>::iterator it = ret.begin(); it != ret.end(); ++ it)
		{
			if (*it == -1)
			{
				cout << '.';
			}
			else
			{
				cout << *it;
			}
		}
		//if (ans.at(i) == getBinary(decimal.at(i)))
		//{
			//cout << "correct";
		//} else
		//{
			//cout << "wrong";
		//}
		cout << endl;
	}
}
