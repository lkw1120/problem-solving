#include<bits/stdc++.h>
using namespace std;
int arr[101][101];
bool visited[101][101][4];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
vector<int> v;
int N,M,ans;
bool solve(int x, int y) {
	visited[x][y][0] = true;
	queue<pair<pair<int,int>,int>> q;
	q.push({{x,y},0});
	while(!q.empty()) {
		x = q.front().first.first;
		y = q.front().first.second;
		int d = q.front().second;
		q.pop();
		int dx = x+dX[d]*arr[x][y];
		int dy = y+dY[d]*arr[x][y];
		if(0 < dx && dx <= N && 0 < dy && dy <= M) {
			if(visited[dx][dy][d]) return true;
			visited[dx][dy][d] = true;
			q.push({{dx,dy},(d+1)%4});
		}
		else {
			return false;
		}
	}
	return true;
}
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
	for(int i=1;i<=N;i++) {
		fill(&visited[0][0][0],&visited[100][100][4],false);
		if(solve(i,1)) {
			v.push_back(i);
		}
	}
	ans = v.size();
	cout<<ans<<"\n";
	for(auto item: v) {
		cout<<item<<" ";	
	}
	cout<<"\n";
	return 0;
}