#include<bits/stdc++.h>
using namespace std;
char arr[1002][1002] = {' '};
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
string str;
int T,N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		fill(&arr[0][0],&arr[1001][1002],'.');
		cin>>N;
		for(int i=1;i<=N;i++) {
			cin>>str;
			for(int j=1;j<=N;j++) {
				arr[i][j] = str[j-1];
			}
		}
		queue<pair<int,int>> q;
		q.push({0,0});
		arr[0][0] = '&';
		ans = pow(N+2,2);
		while(!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			ans--;
			for(int i=0;i<4;i++) {
				int dx = x+dX[i];
				int dy = y+dY[i];
				if(0 <= dx && dx <= N+1 && 0 <= dy && dy <= N+1 && arr[dx][dy] == '.') {
					arr[dx][dy] = '&';
					q.push({dx,dy});
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}