#include<bits/stdc++.h>
using namespace std;
int arr[501][501];
int N,M,A,B,C;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) {
			cin>>arr[i][j];	
		}
	}
	for(int j=1;j<=N;j++) {
		for(int i=1;i<=N;i++) {
			for(int k=1;k<=N;k++) {
				if(arr[i][j]+arr[j][k] < arr[i][k]) {
					arr[i][k] = arr[i][j]+arr[j][k];	
				}
			}
		}
	}
	for(int i=0;i<M;i++) {
		cin>>A>>B>>C;
		if(arr[A][B] <= C) {
			cout<<"Enjoy other party"<<"\n";	
		}
		else {
			cout<<"Stay here"<<"\n";	
		}
	}
	return 0;
}