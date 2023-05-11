#include<bits/stdc++.h>
using namespace std;
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
vector<string> v;
int R,C,ans;
void solve(int x, int y) {
	queue<pair<int,int>> q;
	q.push({x,y});
	v[x][y] = 'W';
	while(!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(int i=0;i<4;i++) {
			int dx = x+dX[i];
			int dy = y+dY[i];
			if(0 <= dx && dx < R && 0 <= dy && dy < C && v[dx][dy] != 'W') {
				v[dx][dy] = 'W';
				q.push({dx,dy});
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>R>>C;
	v.resize(R);
	for(int i=0;i<R;i++) {
		cin>>v[i];	
	}
	ans = 0;
	for(int i=0;i<R;i++) {
		for(int j=0;j<C;j++) {
			if(v[i][j] == 'L') {
				ans++;
				solve(i,j);
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}