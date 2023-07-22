#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
queue<pair<pair<int,int>,int>> q;
bool visited[1001][1001] = {false};
int arr[1001][1001] = {0};
int R,C,N,ans;
void solve() {
	while(!q.empty()) {
		int r = q.front().first.first;
		int c = q.front().first.second;
		int d = q.front().second;
		q.pop();
		if(r == R-1) {
			ans = d;
			break;
		}
		for(auto next: v) {
			int dx = r+next.first;
			int dy = c+next.second;
			if(0 <= dx && dx < R && 0 <= dy && dy < C &&
			   arr[dx][dy] && !visited[dx][dy]) {
				visited[dx][dy] = true;
				q.push({{dx,dy},d+1});
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>R>>C;
	for(int i=0;i<R;i++) {
		for(int j=0;j<C;j++) {
			cin>>arr[i][j];
		}
	}
	cin>>N;
	int r,c;
	for(int i=0;i<N;i++) {
		cin>>r>>c;
		v.push_back({r,c});
	}
	ans = -1;
	for(int j=0;j<C;j++) {
		if(arr[0][j]) {
			q.push({{0,j},0});
			visited[0][j] = true;
		}
	}
	solve();
	cout<<ans<<"\n";
	return 0;
}