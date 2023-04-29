#include<bits/stdc++.h>
using namespace std;
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
vector<string> v;
int T,N,ans;
void solve(int x, int y) {
	queue<pair<pair<int,int>,int>> q;
	q.push({{x,y},0});
	v[x][y] = '*';
	while(!q.empty()) {
		x = q.front().first.first;
		y = q.front().first.second;
		int dist = q.front().second;
		q.pop();
		if(v[x][y] == 'd') {
			ans = dist;
			break;
		}
		for(int i=0;i<4;i++) {
			int dx = x+dX[i];
			int dy = y+dY[i];
			if(0 <= dx && dx < N && 0 <= dy && dy < N && v[dx][dy] != '*') {
				if(v[dx][dy] == '-') v[dx][dy] = '*';
				q.push({{dx,dy},dist+1});
			}
		}
	}
}
int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>N;
		v.resize(N);
		int x,y;
		for(int i=0;i<N;i++) {
			cin>>v[i];
			for(int j=0;j<N;j++) {
				if(v[i][j] == 's') {
					x = i,y = j;
				}
			}
		}
		ans = -1;
		solve(x,y);
		cout<<ans<<"\n";
		v.clear();
	}
    return 0;
}