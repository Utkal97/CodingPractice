#include<iostream>
#include<vector>
#include<set>
#include<stdio.h>
using namespace std;

vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
	set<int> leaderboard;
	for (int i = 0; i < scores.size(); i++)
	{
		leaderboard.insert(scores[i]);
	}
	set <int > ::iterator it;
	int l_size = leaderboard.size();

	vector<int> result;
	for (int i = 0; i < alice.size(); i++)
	{
		leaderboard.insert(alice[i]);

		/*for (it = leaderboard.begin(); it != leaderboard.end(); ++it)
			cout << ' ' << *it;
		cout << endl << "after removing:";*/


		int temp = std::distance(leaderboard.begin(), leaderboard.find(alice[i]));

		
		if (l_size < leaderboard.size())
		{
			leaderboard.erase(alice[i]);
		}

		else
			temp += 1;

		/*for (it = leaderboard.begin(); it != leaderboard.end(); ++it)
			cout << ' ' << *it;
		cout << endl;*/

		temp = leaderboard.size() + 1 - temp;
		result.push_back(temp);
	}
	/*for (int i = 0; i < result.size(); i++)
		cout << result[i] << endl;*/
	return result;

}

