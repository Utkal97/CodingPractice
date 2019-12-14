#include<bits/stdc++.h>

using namespace std;


//Hoare's partition (not general partition) :
int partition(int arr[], int pivotIndex, int lo, int hi)
{
	while(lo<hi) {

		while(arr[lo] < arr[pivotIndex] && lo<hi) {
			lo+=1;
		}
			
		while(arr[hi] >= arr[pivotIndex] && lo<hi) {
			hi-=1;
		}

		if(arr[lo] > arr[pivotIndex] && arr[hi] < arr[pivotIndex]) {
			int temp=arr[lo];
			arr[lo]=arr[hi];
			arr[hi]=temp;
		}
	}
		
	return lo;
}

void quicksort(int arr[],int lo,int hi)
{
	if(lo==hi)
		return;

	else if(lo<hi) {
	
		int pivotIndex = hi;
	
		cout<<"placing "<<arr[pivotIndex];
		
		pivotIndex = partition(arr,pivotIndex,lo,hi);
		
		cout<<", its correct pos is "<<pivotIndex<<endl;
		
		int temp = arr[pivotIndex];
		arr[pivotIndex] = arr[hi];
		arr[hi] = temp;
		
		for(int i=lo;i<=hi;i++) {
			printf("%d ",arr[i]);
		}	cout<<endl;
		quicksort(arr,lo,pivotIndex-1);
		quicksort(arr,pivotIndex+1,hi);
		return;
	}
	else
		return;
}

int main()
 {
	int T=10;
	scanf("%d",&T);
	while(T--) {
		int n;
		scanf("%d",&n);
		int arr[n];
		for(int i=0;i<n;i++) {
			scanf("%d",&arr[i]);
		}

		quicksort(arr,0,n-1);
		for(int i=0;i<n;i++) {
			printf("%d ",arr[i]);
		}
		cout<<endl;
	}
	return 0;
}
