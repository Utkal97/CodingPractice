#pragma once
#include<bits/stdc++.h>
using namespace std;

/*
Solution : O( no. of testcases * (n^2))
A container can't change the no. of balls. It contains same no. of balls all the time since, when u take out a ball,
you place another ball in return.
Think about the final phase, where we need : all balls of a type need to be in one container and no container must 
have two types of balls.
So, at req'd final phase, capacity of a container = no.of balls of a type it will hold.
We check if this state is achievavle (possible or not).
For this to be possible, we need to check if all containers can accomodate balls with above criteria.

The sum of elements of ith row (say, cap_i) will give capacity of container 'i'. ith container will always hold cap_i
balls.
The sum of elements of jth col (say, freq_j) will give no.of balls of type 'j'.
Put these two in two lists and check whether they are accomodable.
To check accomodability : sort both lists and check if each element is same.
*/

string organizingContainers(vector<vector<int>> container) {

	vector<int> container_capacity, freq_of_balltype;
	for (int i = 0; i < container.size(); i++)
	{
		int count = 0;
		for (int j = 0; j < container[0].size(); j++)
			count += container[i][j];
		container_capacity.push_back(count);
	}

	for (int i = 0; i < container[0].size(); i++)
	{
		int count = 0;
		for (int j = 0; j < container.size(); j++)
		{
			count += container[j][i];
		}
		freq_of_balltype.push_back(count);
	}

	sort(container_capacity.begin(), container_capacity.end());
	sort(freq_of_balltype.begin(), freq_of_balltype.end());


	for (int i = 0; i < freq_of_balltype.size(); i++)
	{
		if (freq_of_balltype[i] != container_capacity[i])
			return "Impossible";
	}
	return "Possible";
	
}