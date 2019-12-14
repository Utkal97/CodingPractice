#pragma once
#include<vector>
#include<iostream>
#include<set>
using namespace std;

//Runtime complexity = O(testcases*n*logn), space complexity = O(n)
/*
The solution doesn't depend on k but only n.
Put all the numbers from 1 to n in a set. Now, we have to put elements of the set into our result vector in the right positions.
Given condition is | pos[i] - i | = k. 
					=> pos[i] - i = +k (or) -k
					=> pos[i] = i+k (or) i-k

We iterate starting from 1->n.Since we need ascending lexicographical order, we check if i-k exists before checking i+k.
	If i-k exists:
		Remove 'i-k' element from set and place it in vector.  =>O(logn) for removal from set
	Else if i+k exists:
		Remove 'i+k' element from set and place it in vector.  =>O(logn) for removal from set
	Else: (Fail case)
		return -1;
*/

vector<int> absolutePermutation(int n, int k) {
	set<int> set_n;
	for (int i = 1; i <= n; i++)
		set_n.insert(i);

	vector<int> pos;
	for (int i = 0; i < n; i++)
	{
		if (set_n.find((i + 1) - k) != set_n.end())
		{
			pos.push_back((i + 1) - k);
			set_n.erase((i + 1) - k);
		}
		else if (set_n.find((i + 1) + k) != set_n.end())
		{
			pos.push_back((i + 1) + k);
			set_n.erase((i + 1) + k);
		}
		else
		{
			return { -1 };
		}
	}
	return pos;
}