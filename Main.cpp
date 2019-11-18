#include "absolutePermutation.h"
int main()
{
	int t = 15;
	while (t--)
	{
		int n,k;
		scanf_s("%d %d",  &n,&k);
		vector<int> ap = absolutePermutation(n, k);
		for(int i=0;i<ap.size();i++)
			cout << ap[i] <<" ";
		cout << endl;
	}
	return 0;
}