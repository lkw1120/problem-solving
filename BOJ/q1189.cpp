#include<bits/stdc++.h>
using namespace std;
bool visited[5][5] = {false};
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
vector<string> v;
int R,C,K,ans;
void dfs(int x, int y, int k) {
	if(x == R-1 && y == C-1 && k == K) {
		ans++;
		return ;
	}
	if(k < K) {
		for(int i=0;i<4;i++) {
			int dx = x+dX[i];
			int dy = y+dY[i];
			if(0 <= dx && dx < R && 0 <= dy && dy < C &&
			   v[dx][dy] != 'T' && !visited[dx][dy]) {
				visited[dx][dy] = true;
				dfs(dx,dy,k+1);
				visited[dx][dy] = false;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>R>>C>>K;
	v.resize(R);
	for(int i=R-1;i>=0;i--) {
		cin>>v[i];
	}
	ans = 0;
	if(v[0][0] != 'T' && v[R-1][C-1] != 'T') {
		visited[0][0] = true;
		dfs(0,0,1);
	}
	cout<<ans<<"\n";
	return 0;
}