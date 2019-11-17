#include<stdio.h>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

//Brute Force :
/* Generate all the subsets possible.
	Arrange them in descending order of size.
	Iterate through subsets (start from highest size):For each subset,
		check if any of the two elements add to k. 
		If they do, go to next subset.
		Else If no such pair exists: return the size of subset
*/

//Optimal Solution : runtime: O(n), space complexity : O(n)

/*	Sum of a pair of numbers A,B is divisible by k if (A%k + B%k) = k.
	So, convert the given list into the list of remainder values.
	We only need the size of maximal subset, so:
	Take a freq count of each such remainder.
	For each A%k, there exists only one B%k such that (A%k + B%k) = k. 
	(for example, let k=3, if A%3 = 1, its B%3 must be 2 such that ,(A%k + B%k) = k.
	So, for maximal subset, we got to choose between no.of elements having A%k and no.of elements having B%k.
	and add the max of two to the subset size.
	There are also elements with A%k = B%K. For all those, we have to add only one to the result since have two
	of them will spoil the req'd.
*/

int nonDivisibleSubset(int k, vector<int> s) {
	int count = 0;

	for (int i=0; i < s.size(); i++)
	{
		s[i] = s[i] % k;
	}

	map<int, int> freq;
	for (int i = 0; i < s.size(); i++)
	{
		freq[s[i]]+=1;
	}

	for (int i = 1; i < k/2+1; i++)
	{
		if(k-i!=i)
			count += max(freq[i], freq[k - i]);
		else
		{
			count += 1;
		}
	}

	if (freq[0] > 0)
		count += 1;

	return count;
}