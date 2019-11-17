#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;
void extraLongFactorials(int n)
{
	vector<int> fact;
	fact.push_back(1);
	int term = 2;
	while (term<=n)
	{
		int prev_carry = 0, carry = 0;
		cout << "fact of " << term << ": ";
		for (int i = 0; i < fact.size(); i++)
		{
			carry = (fact[i] * term + prev_carry) / 10;
			fact[i] = (fact[i] * term + prev_carry) % 10;
			prev_carry = carry;
		}

		while (carry > 0)
		{
			int curr_term = carry % 10;
			fact.push_back(curr_term);
			carry /= 10;
		}
			

		for (int i = 0; i < fact.size(); i++)
		{
			cout << fact[i]<<"";
		}
		cout << endl;
		term++;
	}
	for (int i = 0, j = fact.size() - 1; i <= j; i++, j--)
	{
		int temp = fact[i];
		fact[i] = fact[j];
		fact[j] = temp;
	}
	for (int i = 0; i < fact.size(); i++)
		cout << fact[i];
	cout << endl;
	return;
}

