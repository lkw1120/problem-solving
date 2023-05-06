#include<bits/stdc++.h>
using namespace std;
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int arr[501][501] = {0};
bool visited[501][501] = {false};
int N,M,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	string str;
	for(int i=0;i<N;i++) {
		cin>>str;
		for(int j=0;j<M;j++) {
			arr[i][j] = str[j]-'0';	
		}
	}
	queue<pair<pair<int,int>,int>> q;
	q.push({{0,0},0});
	visited[0][0] = true;
	ans = -1;
	while(!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int d = q.front().second;
		q.pop();
		if(x == N-1 && y == M-1) {
			ans = d;
			break;
		}
		for(int i=0;i<4;i++) {
			int dx = x+dX[i]*arr[x][y];
			int dy = y+dY[i]*arr[x][y];
			if(0 <= dx && dx < N && 0 <= dy && dy < M && !visited[dx][dy]) {
				visited[dx][dy] = true;
				q.push({{dx,dy},d+1});
			}
		}
	}
	if(ans < 0) {
		cout<<"IMPOSSIBLE"<<"\n";
	}
	else {
		cout<<ans<<"\n";	
	}
	return 0;
}