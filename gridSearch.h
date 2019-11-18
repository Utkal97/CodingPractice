#pragma once
#include<vector>
#include<string>
#include<iostream>
using namespace std;

string gridSearch(vector<string> G, vector<string> P) {
	if (G.size() < P.size() || G[0].size() < P[0].size())
	{
		cout << "Pattern is larger than Grid" << endl;
		return "NO";
	}
	
	for (int i = 0; i <= G.size() - P.size(); i++)
	{
		for (int j = 0; j <= G[0].size() - P[0].size(); j++)
		{
			if (P[0][0] == G[i][j])
			{
				bool match = true;
				for (int p_i = 0; p_i < P.size() && i+p_i<G.size(); p_i++)
				{
					for (int p_j = 0; p_j < P[0].size()&& j+p_j<G[0].size(); p_j++)
					{
						if (G[i + p_i][j + p_j] != P[p_i][p_j])
						{
							match = false;
							break;
						}
					}
					if (match == false)
						break;
				}
				if (match == true)
					return "YES";
			}
		}
	}
	return "NO";
}