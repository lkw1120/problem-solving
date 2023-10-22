#include<bits/stdc++.h>
using namespace std;
int arr[11][11] = {0};
int dp[11][11] = {0};
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
bool visited[11][11] = {false};
int N,ans;
bool check(int x, int y) {
	bool flag = !visited[x][y];
	for(int i=0;i<4;i++) {
		if(visited[x+dX[i]][y+dY[i]]) {
			flag = false;	
		}
	}
	return flag;
}
void plant(int x, int y, bool flag) {
	visited[x][y] = flag;
	for(int i=0;i<4;i++) {
		visited[x+dX[i]][y+dY[i]] = flag;	
	}
}
void dfs(int depth, int cost) {
	if(depth == 3) {
		ans = min(ans,cost);
		return ;
	}
	for(int i=2;i<N;i++) {
		for(int j=2;j<N;j++) {
			if(check(i,j)) {
				plant(i,j,true);
				dfs(depth+1,cost+dp[i][j]);
				plant(i,j,false);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) {
			cin>>arr[i][j];	
		}
	}
	for(int i=2;i<N;i++) {
		for(int j=2;j<N;j++) {
			dp[i][j]+=arr[i][j];
			for(int k=0;k<4;k++) {
				dp[i][j]+=arr[i+dX[k]][j+dY[k]];	
			}
		}
	}
	ans = INT_MAX;
	dfs(0,0);
	cout<<ans<<"\n";
	return 0;
}