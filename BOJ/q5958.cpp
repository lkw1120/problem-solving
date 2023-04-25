#include<bits/stdc++.h>
using namespace std;
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
vector<string> v;
int N,ans;
void bfs(int n, int m) {
	queue<pair<int,int>> q;
	q.push({n,m});
	v[n][m] = '.';
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i=0;i<4;i++) {
			int dx = x+dX[i];
			int dy = y+dY[i];
			if(0 <= dx && dx < N && 0 <= dy && dy < N && v[dx][dy] == '*') {
				v[dx][dy] = '.';
				q.push({dx,dy});
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];	
	}
	ans = 0;
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			if(v[i][j] == '*') {
				bfs(i,j);
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}