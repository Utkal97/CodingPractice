#include<bits/stdc++.h>

using namespace std;


//Hoare's partition (not general partition) :
int partition(int arr[], int pivotIndex, int lo, int hi)
{
	while(lo<hi) {

		//we leave elements that are less than pivot as it is
		while(arr[lo] <= arr[pivotIndex] && lo<hi) {				//lo<hi is important
			lo+=1;
		}
		
		//we leave elements that are greater than pivot to be on the rightside
		while(arr[hi] >= arr[pivotIndex] && lo<hi) {
			hi-=1;
		}
		
		//if there is a contradictory pair found, swap them
		if(arr[lo] > arr[pivotIndex] && arr[hi] < arr[pivotIndex]) {
			int temp=arr[lo];
			arr[lo]=arr[hi];
			arr[hi]=temp;
		}
	}
	
	//place the pivot at its right position, i.e., low
	if(lo <= hi) {
		int temp = arr[pivotIndex];
		arr[pivotIndex] = arr[lo];
		arr[lo] = temp;
	}
		
	return lo;			//low will be the position of pivot element in sorted list
}

void quicksort(int arr[],int lo,int hi)
{
	if(lo==hi)
		return;

	else if(lo<hi) {
	
		int pivotIndex = hi;		// we choose the rightmost element to be pivot. we can also choose random element between low and high
	
		//cout<<"placing "<<arr[pivotIndex];
		
		pivotIndex = partition(arr,pivotIndex,lo,hi);	//partition is a function that places the pivot at right position and returns its index

		//cout<<", its correct pos is "<<pivotIndex<<endl;
		
		/*
		for(int i=lo;i<=hi;i++) {
			printf("%d ",arr[i]);
		}	
		cout<<endl;
		*/
		
		//now that we placed current pivot in right place, we do the same for left side and right side of pivot without touching it.
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
