#include<bits/stdc++.h>
using namespace std;
int dX[8] = {0,1,1,1,0,-1,-1,-1};
int dY[8] = {1,1,0,-1,-1,-1,0,1};
int arr[1001][1001] = {0};
int N,M,ans;
void solve(int n, int m) {
	queue<pair<int,int>> q;
	q.push({n,m});
	arr[n][m] = 0;
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i=0;i<8;i++) {
			int dx = x+dX[i];
			int dy = y+dY[i];
			if(0 <= dx && dx < N && 0 <= dy && dy < M && arr[dx][dy]) {
				arr[dx][dy] = 0;
				q.push({dx,dy});
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			cin>>arr[i][j];	
		}
	}
	ans = 0;
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			if(arr[i][j]) {
				ans++;
				solve(i,j);
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}