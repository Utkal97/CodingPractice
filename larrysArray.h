#pragma once
#include<stdio.h>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

int find(vector<int> A, int x)
{
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] == x)
			return i;
	}
	return -1;
}

void print(vector<int> A, int min)
{
	for (int i = 0; i < A.size(); i++)
		cout << A[i] << " ";
	cout <<min<< endl;
	return;
}

// Complete the larrysArray function below.
string larrysArray(vector<int> A) {
	int min = 1;
	while (min <= A.size()) {
		if (min == A[min - 1])
		{
			min += 1;
		}
		else {
			int min_pos = find(A, min);
			if( ( min_pos<A.size() && (min_pos+1) - min >= 2 ) || (min_pos == A.size()-1) )
			{
				int temp = A[min_pos-2];
				A[min_pos-2] = A[min_pos-1];
				A[min_pos-1] = A[min_pos];
				A[min_pos] = temp;
			}
			else if ( min_pos<A.size()-1 && (min_pos + 1) - min == 1 )
			{
				int temp = A[min_pos - 1];
				A[min_pos - 1] = A[min_pos];
				A[min_pos] = A[min_pos+1];
				A[min_pos+1] = temp;
			}
			
		}
		print(A, min);
	}

	return "YES";
}