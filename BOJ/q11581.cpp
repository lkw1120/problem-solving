#include<bits/stdc++.h>
#define MAX 101
#define INF 999999999
using namespace std;
int arr[MAX][MAX] = {0};
int N,M,C,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	fill(&arr[0][0],&arr[MAX-1][MAX],INF);
	cin>>N;
	for(int i=1;i<N;i++) {
		cin>>M;
		for(int j=0;j<M;j++) {
			cin>>C;
			arr[i][C] = 1;
		}
	}
	for(int j=1;j<=N;j++) {
		for(int i=1;i<=N;i++) {	
			for(int k=1;k<=N;k++) {
				if(arr[i][k] > arr[i][j] + arr[j][k]) {
					arr[i][k] = arr[i][j] + arr[j][k];
				}
			}
		}
	}
	bool flag = true;
	for (int i=1;i<=N;i++) {
		if(arr[1][i] != INF && arr[i][i] != INF) {
			flag = false;
		}
	}
	if(flag) {
		cout<<"NO CYCLE"<<"\n";	
	}
	else {
		cout<<"CYCLE"<<"\n";	
	}
	return 0;
}