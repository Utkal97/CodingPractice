#pragma once
#include<vector>
#include<iostream>
using namespace std;

/*
The solution is pretty simple. runtime complexity : O(n^2), space complexity : depends upon function call stack,
for me its O(size of A), not A^2 since, memory doesn't multiply like in time complexity, it just adds up and deletes
when function call is finished.

Approach :
Each block is either : 1) at Corner, 2) at edge(excluding the corner), 3) inside the border blocks.
So, we have to calculate individual contribution of area by each block, which takes O(n^2) as we iterate through each block.
As there are 3 cases for a block, iterate through each block:
	for any block, top and bottom sides must be added to the total surface area
	if it is a corner:
		add the area if the block is upward protruding in that direction => 2 surrounded sides
		also add the area of outer sides.								 => 2 sides outwards
	else if its on edges:
		add the area if the block is upward protruding in that direction => 3 surrounded sides
		also add the area of outer sides.								 => 1 side outward
	else if its inside:
		add the area if the block is upward protruding in that direction => all 4 sides are surrounded

	as we got the individual contrib of that block, add it to total surface area.

	CALCULATION OF 4 SIDES ARE SEPERATELY WRITTEN AS FUNCTIONS FOR BETTER MAINTANABLITY OF CODE, BUT THIS INCREASES
	MEMORY USAGE.
*/

int northward_area(int r, int c, vector<vector<int>> A)
{
	if (r == 0)
		return A[r][c];
	else if (r - 1 >= 0)
	{
		if (A[r][c] <= A[r - 1][c])
			return 0;
		else
			return A[r][c] - A[r - 1][c];
	}
}

int eastward_area(int r, int c, vector<vector<int>> A)
{
	if (c == A[0].size() - 1)
		return A[r][c];
	else if (c + 1 <= A[0].size() - 1)
	{
		if (A[r][c] <= A[r][c + 1])
			return 0;
		else
			return A[r][c] - A[r][c + 1];
	}
}

int southward_area(int r, int c, vector<vector<int>> A)
{
	if (r == A.size() - 1)
		return A[r][c];
	else if (r + 1 <= A.size() - 1)
	{
		if (A[r][c] <= A[r + 1][c])
			return 0;
		else
			return A[r][c] - A[r + 1][c];
	}
}

int westward_area(int r, int c, vector<vector<int>> A)
{
	if (c == 0)
		return A[r][c];
	else if (c - 1 >= 0)
	{
		if (A[r][c] <= A[r][c - 1])
			return 0;
		else
			return A[r][c] - A[r][c - 1];
	}
}

int surfaceArea(vector<vector<int>> A) {
	int area = 0;
	for (int r = 0; r < A.size(); r++)
	{
		for (int c = 0; c < A[0].size(); c++)
		{
			int individual_contrib = 2;			//surface area of top side and bottom side

			//FOUR CORNERS
			if (r == 0 && c == 0)
			{
				individual_contrib += eastward_area(r, c, A);
				individual_contrib += southward_area(r, c, A);
				individual_contrib += 2*A[r][c];			//since north, west sides are open and they too contribute
			}

			else if (r == 0 && c == A[0].size()-1)
			{
				individual_contrib += westward_area(r, c, A);
				individual_contrib += southward_area(r, c, A);
				individual_contrib += 2 * A[r][c];			//since north, east sides are open and they too contribute
			}

			else if (r == A.size()-1 && c == 0)
			{
				individual_contrib += northward_area(r, c, A);
				individual_contrib += eastward_area(r, c, A);
				individual_contrib += 2 * A[r][c];			//since south,west sides are open and they too contribute
			}

			else if (r == A.size() - 1 && c == A[0].size() - 1)
			{
				individual_contrib += westward_area(r, c, A);
				individual_contrib += northward_area(r, c, A);
				individual_contrib += 2 * A[r][c];			//since south,east sides are open and they too contribute
			}

			//REST OF BLOCKS ON EDGES
			else if (c == 0)
			{
				individual_contrib += eastward_area(r, c, A);
				individual_contrib += northward_area(r, c, A);
				individual_contrib += southward_area(r, c, A);
				individual_contrib += A[r][c];				//west side contribution
			}

			else if (c == A[0].size()-1)
			{
				individual_contrib += westward_area(r, c, A);
				individual_contrib += northward_area(r, c, A);
				individual_contrib += southward_area(r, c, A);
				individual_contrib += A[r][c];
			}

			else if (r == 0)
			{
				individual_contrib += eastward_area(r, c, A);
				individual_contrib += westward_area(r, c, A);
				individual_contrib += southward_area(r, c, A);
				individual_contrib += A[r][c];
			}

			else if (r == A.size() - 1)
			{
				individual_contrib += eastward_area(r, c, A);
				individual_contrib += westward_area(r, c, A);
				individual_contrib += northward_area(r, c, A);
				individual_contrib += A[r][c];
			}

			//INNER BLOCKS
			else
			{
				individual_contrib += eastward_area(r, c, A);
				individual_contrib += southward_area(r, c, A);
				individual_contrib += northward_area(r, c, A);
				individual_contrib += westward_area(r, c, A);
			}
			//cout << "contribution of " << r << " " << c << " :" << individual_contrib << endl;
			area += individual_contrib;
		}

	}
	return area;
}