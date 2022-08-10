#include<bits/stdc++.h>
#define MAX 251
using namespace std;
int dX[8] = {0,1,0,-1,1,1,-1,-1};
int dY[8] = {1,0,-1,0,1,-1,1,-1};
int arr[MAX][MAX] = {0};
int M,N,ans;
void solve(int x, int y) {
	for(int i=0;i<8;i++) {
		if((0 < x+dX[i] && x+dX[i] <= M) &&
		   (0 < y+dY[i] && y+dY[i] <= N) &&
		   arr[x+dX[i]][y+dY[i]] == 1) {
			arr[x+dX[i]][y+dY[i]] = 0;
			solve(x+dX[i],y+dY[i]);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>M>>N;
	for(int i=1;i<=M;i++) {
		for(int j=1;j<=N;j++) {
			cin>>arr[i][j];
		}
	}
	ans = 0;
	for(int i=1;i<=M;i++) {
		for(int j=1;j<=N;j++) {
			if(arr[i][j]) {
				ans++;
				arr[i][j] = 0;
				solve(i,j);
			}
		}
	}
	cout<<ans<<"\n";
	return 0;	
}