#include<bits/stdc++.h>
using namespace std;
char arr[6][6];
bool visited[6][6];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int N,ans;
void dfs(int x, int y, string str) {
	int size = str.size();
	if(size%2 == 0) {
		int cnt = 0;
		for(int i=0;i<size/2;i++) {
			if(str[i] == '(') {
				cnt++;
			}
		}
		if(cnt == size/2) {
			for(int i=size/2;i<size;i++) {
				if(str[i] == ')') {
					cnt--;	
				}
			}
			if(cnt == 0) {
				ans = max(ans,size);
				return ;
			}
		}
	}
	for(int i=0;i<4;i++) {
		int dx = x+dX[i];
		int dy = y+dY[i];
		if(0 < dx && dx <= N && 0 < dy && dy <= N && !visited[dx][dy]) {
			visited[dx][dy] = true;
			dfs(dx,dy,str+arr[dx][dy]);
			visited[dx][dy] = false;
		}
	}
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
	ans = 0;
	if(arr[1][1] == '(') {
		visited[1][1] = true;
		dfs(1,1,"(");
	}
	cout<<ans<<"\n";
	return 0;
}