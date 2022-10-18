#include<bits/stdc++.h>
using namespace std;
string str[2];
bool visited[2][51] = {false};
int dX[3] = {0,1,-1};
int dY[3] = {1,0,0};
int M,B,ans;
void solve(int n, int m) {
	for(int i=0;i<M;i++) {
		visited[0][i] = (str[0][i] != '.');
		visited[1][i] = (str[1][i] != '.');
	}
	queue<pair<pair<int,int>,int>> q;
	q.push({{n,m},1});
	visited[n][m] = true;
	while(!q.empty()) {
		n = q.front().first.first;
		m = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		if(m == M-1) {
			int tmp = 2*M-cnt-B;
			ans = max(ans,tmp);
		}
		for(int i=0;i<3;i++) {
			int dx = n+dX[i];
			int dy = m+dY[i];
			if(0 <= dx && dx < 2 && 0 <= dy && dy < M
			   && str[dx][dy] == '.' && !visited[dx][dy]) {
				visited[dx][dy] = true;
				q.push({{dx,dy},cnt+1});
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>M;
	cin>>str[0];
	cin>>str[1];
	B = 0;
	for(int i=0;i<M;i++) {
		if(str[0][i] == '#') B++;
		if(str[1][i] == '#') B++;
	}
	ans = 0;
	if(str[0][0] == '.') {
		solve(0,0);
	}
	if(str[1][0] == '.') {
		solve(1,0);	
	}
	cout<<ans<<"\n";
	return 0;	
}