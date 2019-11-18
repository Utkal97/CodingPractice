#pragma once
#include<bits/stdc++.h>
using namespace std;

// explanation: https://www.nayuki.io/page/next-lexicographical-permutation-algorithm
// runtime complexity : O(n), space complexity : O(1)

string biggerIsGreater(string w)
{
	//from the right, find the first encounter of consecutively decreasing elements.
	int first_enc;
	for (first_enc = w.size() - 1; first_enc >= 1; first_enc--)
	{
		if (w[first_enc] > w[first_enc - 1])
			break;
	}

	//If all elements are in decreasing order, no lexicographically order exists
	if (first_enc == 0)
		return "no answer";

	else
	{
		int pivot = first_enc - 1,i;
		for (i = w.size() - 1; i > pivot; i--)
			if (w[i] > w[pivot])
				break;

		char temp = w[pivot];
		w[pivot] = w[i];
		w[i] = temp;

		for (int i = pivot + 1, j = w.size()-1; i < j; i++, j--)
		{
			temp = w[i];
			w[i] = w[j];
			w[j] = temp;
		}
	}
	return w;
}