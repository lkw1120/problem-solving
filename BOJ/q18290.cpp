#include<bits/stdc++.h>
using namespace std;
int dX[4] = {1,0,-1,0};
int dY[4] = {0,1,0,-1};
int arr[11][11] = {0};
bool visited[11][11] = {false};
int N,M,K,ans;
bool check(int x, int y) {
	for(int i=0;i<4;i++) {
		int dx = x+dX[i];
		int dy = y+dY[i];
		if(0 <= dx && dx < N && 0 <= dy && dy < M && visited[dx][dy]) {
			return false;
		}
	}
	return true;
}
void solve(int sum, int k) {
	if(k == K) {
		ans = max(ans,sum);
		return ;
	}
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			if(!visited[i][j] && check(i,j)) {
				visited[i][j] = true;
				solve(sum+arr[i][j],k+1);
				visited[i][j] = false;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>K;
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			cin>>arr[i][j];	
		}
	}
	ans = INT_MIN;
	solve(0,0);
	cout<<ans<<"\n";
	return 0;
}