#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll MOD = INT_MAX;
char arr[1001][1001];
bool visited[1001][1001];
ll dp[1001][1001];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int N,ans;
bool bfs() {
	queue<pair<int,int>> q;
	q.push({1,1});
	arr[1][1] = '$';
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i=0;i<4;i++) {
			int dx = x+dX[i];
			int dy = y+dY[i];
			if(0 < dx && dx <= N && 0 < dy && dy <= N && arr[dx][dy] == '.') {
				arr[dx][dy] = '$';
				q.push({dx,dy});
			}
		}
	}
	return arr[N][N] == '$';
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) {
			cin>>arr[i][j];
		}
	}
	dp[1][1] = 1;
	visited[1][1] = true;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) {
			if(i == 1 && j == 1) continue;
			if(arr[i][j] == '.') {
				dp[i][j] = (dp[i-1][j]+dp[i][j-1])%MOD;
				if(visited[i-1][j] || visited[i][j-1]) {
					visited[i][j] = true;
				}
			}
		}
	}
	ans = dp[N][N];
	if(ans || visited[N][N]) {
		cout<<ans<<"\n";
	}
	else {
		if(bfs()) {
			cout<<"THE GAME IS A LIE"<<"\n";
		}
		else {
			cout<<"INCONCEIVABLE"<<"\n";	
		}
	}
	return 0;
}