#include<bits/stdc++.h>
using namespace std;
vector<string> v;
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int T,H,W,ans;
void dfs(int h, int w) {
	queue<pair<int,int>> q;
	q.push({h,w});
	v[h][w] = '.';
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i=0;i<4;i++) {
			int dx = x+dX[i];
			int dy = y+dY[i];
			if(0 <= dx && dx < H && 0 <= dy && dy < W && v[dx][dy] == '#') {
				v[dx][dy] = '.';
				q.push({dx,dy});
			}
		}
	}
	ans++;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		v.clear();
		cin>>H>>W;
		v.resize(H);
		for(int i=0;i<H;i++) {
			cin>>v[i];
		}
		ans = 0;
		for(int i=0;i<H;i++) {
			for(int j=0;j<W;j++) {
				if(v[i][j] == '#') {
					dfs(i,j);
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}