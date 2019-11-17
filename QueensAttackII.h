#pragma once
#include<bits/stdc++.h>
using namespace std;

/*
Brute force: time complexity : O(max(n,k)), space complexity : O(n^2) -
Create a 2D matrix (called board), of size N*N initialized to zeros.
Wherever there are obstacles, replace those x,y coordinates on board with 1.
So, obstacles represent 1s and rest of coordinates are 0s.
Now, For each of eight directions, start from queen's position 
	go until you either find an obstacle(i.e., 1) (or) you reach the boundary. Keep count the steps.
	add those steps to the final attack count.
So, you get no. of counts in all directions added to final attack count and then return it.
*/

/*
Optimal : time complexity : O(k), space complexity : O(1) -
Initialize the attack counts in each of 8 directions with max possible attack distance in that direction.
Now, traverse through obstacles list. For each obstacle:
	if it lies in any of the direction of queen's path:
		then, if the max possible attack distance > dist between queen and obstacle: 
			then, max possible attack distance can be only until that obstacle.
So, we get max possible attack distances in 8 eight directions considering all obstacles. Add them up and
return it.
*/
int queensAttack(int n, int k, int r_q, int c_q, vector< vector<int> > obstacles) {

	int N = r_q-1, NE = min(r_q-1, n-c_q), E = n-c_q, SE = min(n-r_q, n-c_q), S = n-r_q, 
		SW = min(n-r_q, c_q-1), W = c_q-1, NW = min(r_q-1, c_q-1);
	for (int i = 0; i < obstacles.size(); i++)
	{
		int x = obstacles[i][0], y = obstacles[i][1];
		int xdist = abs(r_q - x) - 1, ydist = abs(c_q - y) - 1;

		//if obstacle lies vertical
		if (c_q == y)
		{
			if (r_q > x  &&  N > xdist )
				N = xdist;
			else if (r_q < x  &&  S > xdist)
				S = xdist;
		}
		//if obstacle lies horizontal
		else if (r_q == x)
		{
			if (c_q < y && E > ydist)
				E = ydist;
			else if (c_q > y && W > ydist)
				W = ydist;
		}

		//if obstacle lies on diagonal (NE-SW)
		else if ((r_q - x) == (-1)*(c_q - y))
		{
			if (r_q > x && NE > xdist)
				NE = xdist;
			else if (r_q < x && SW > xdist )
				SW = xdist;
		}

		//if obstacle lies on diagonal (NW-SE)
		else if ((r_q - x) == (c_q - y))
		{
			if (r_q > x && NW > xdist)
				NW = xdist;
			else if (r_q < x && SE > xdist)
				SE = xdist;
		}
	}
	//printf("%d %d %d %d %d %d %d %d\n", N, NE, E, SE, S, SW, W, NW);
	int count = N + NE + E + SE + S + SW + W + NW;
	return count;
}