#include<bits/stdc++.h>
using namespace std;

void printTree(int segmentTree[], int N) {
	cout<<"segment Tree looks like : ";
    for(int i=0;i<4*N;i++) {
        cout<<segmentTree[i]<<" ";
    }
    cout<<endl;	
}

void build(int sTree[], int A[],int N, int node, int start, int end) {
	if(start == end) {
		sTree[node] = A[start];
	}
	
	else {
		int mid = (end+start)/2;
		build(sTree, A, N, 2*node+1, start, mid);
		build(sTree, A, N, 2*node+2, mid+1, end);
		
		sTree[node] = min(sTree[2*node+1], sTree[2*node+2]);
	}
	return;
}

void update(int sTree[], int idx, int val, int node, int start, int end, int A[]) {
	if(start == end) {
		A[idx] = val;
		sTree[node] = val;
	}
	else {
		int mid = (start+end)/2;
		if(idx<=mid)
			update(sTree, idx, val, 2*node+1, start, mid, A);
		else
			update(sTree, idx, val, 2*node+2, mid+1, end, A);
		sTree[node] = min(sTree[2*node+1], sTree[2*node+2]);
	}
	return;
}

int getMin(int sTree[], int left, int right, int node, int start, int end) {

	if(end<left || right<start)
		return INT_MAX;

	if(left<=start && end<=right)
		return sTree[node];

	else {
		int mid = (start+end)/2;
		int leftSol = getMin(sTree, left, right, 2*node+1, start, mid);
		int rightSol = getMin(sTree, left, right, 2*node+2, mid+1, end);
		return min(leftSol, rightSol);
	}
}

void perform(int A[], int N, int q[][3], int Q) {
	int sTree[4*N];
	for(int i=0; i<4*N; i++) {
		sTree[i]=INT_MAX;
	}
	build(sTree,A,N,0, 0,N-1);
	printTree(sTree,N);
	
	for(int i=0;i<Q;i++) {
		if(q[i][0]==1) {
			int ind = q[i][1]-1, val = q[i][2];
			update(sTree,ind,val,0,0,N-1,A);
		}
		else if(q[i][0]==2) {
			int a = q[i][1]-1, b = q[i][2]-1;
			int mi = getMin(sTree,a,b,0,0,N-1);
		}
	}
	
	return;
}

int main() {
	int N=6,Q=2;
	scanf("%d %d",&N,&Q);
	int A[N];
	int q[Q][3];

	for(int i=0;i<N;i++) {
		scanf("%d",&A[i]);
	}
	for(int i=0;i<Q;i++) {
		char t;
		int a,b;
		cin>>t>>a>>b;
		if(t=='u') {
			q[i][0] = 1;
		}
		else
			q[i][0] = 2;
		
		q[i][1] = a;
		q[i][2] = b;
	}
	
	perform(A,N,q,Q);
	return 0;
}
