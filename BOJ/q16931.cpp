#include<bits/stdc++.h>
using namespace std;
int arr[102][102];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int N,M,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			cin>>arr[i][j];	
		}
	}
	ans = 0;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			for(int k=0;k<4;k++) {
				int dx = i+dX[k];
				int dy = j+dY[k];
				if(arr[dx][dy] < arr[i][j]) {
					ans+=arr[i][j]-arr[dx][dy];
				}
			}
		}
	}
	ans+=2*N*M;
	cout<<ans<<"\n";
} 