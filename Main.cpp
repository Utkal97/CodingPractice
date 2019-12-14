#include "activityNotifications.h"
int main()
{
	int t = 15;
	while (t--)
	{
		int n,d;
		scanf_s("%d %d", &n,&d);
		
		
		vector<int> expenditure;
		for (int i = 0; i < n; i++)
		{
			int temp;
			cin >> temp;
			expenditure.push_back(temp);
		}
		int count = activityNotifications(expenditure, d);
		cout << endl;
	}
	return 0;
}

