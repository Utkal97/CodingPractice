#pragma once
#include<vector>
#include<iostream>
#include<set>
using namespace std;

vector<int> absolutePermutation(int n, int k) {
	set<int> pos;
	for (int i = 1; i <= n; i++)
		pos.insert(i);

	int i = 1;
	vector<int> result;
	while (!pos.empty())
	{
		int index;
		if (pos.find(i - k) == pos.end() && pos.find(i + k) == pos.end())
			return { -1 };
		// if i-k exists, put its position in result.
		else if (pos.find(i - k) != pos.end())
		{
			// find the index of i-k in pos
			result.push_back(index);		//put index in result
		}

		//else if i+k exists, put its position in result
		else if (pos.find(i + k) != pos.end())
		{
			// find the index of i+k in pos
			result.push_back(index);		//put index in result
		}

	}
	return result;
}