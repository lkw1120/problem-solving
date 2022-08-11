#include<bits/stdc++.h>
#define MAX 101
using namespace std;
bool visited[MAX][MAX][2] = {false};
int arr[MAX][MAX] = {0};
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int N,M,T,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M>>T;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			cin>>arr[i][j];	
		}
	}
	queue<pair<pair<int,int>,pair<int,int>>> q;
	q.push({{1,1},{0,0}});
	visited[1][1][0] = true;
	ans = INT_MAX;
	while(!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int t = q.front().second.first;
		int sword = q.front().second.second;
		q.pop();
		if(x == N && y == M) {
			if(t <= T) {
				ans = min(ans,t);
			}
		}
		for(int i=0;i<4;i++) {
			if((0 < x+dX[i]	&& x+dX[i] <= N) &&
			   (0 < y+dY[i] && y+dY[i] <= M) &&
			   (!visited[x+dX[i]][y+dY[i]][sword])) {
				if(sword == 0 && arr[x+dX[i]][y+dY[i]] == 1) {
					continue;
				}
				else if(sword == 0 && arr[x+dX[i]][y+dY[i]] != 1) {
					if(arr[x+dX[i]][y+dY[i]] == 2) {
						sword = 1;
					}
					visited[x+dX[i]][y+dY[i]][sword] = true;
					q.push({{x+dX[i],y+dY[i]},{t+1,sword}});
				}
				else {
					visited[x+dX[i]][y+dY[i]][sword] = true;
					q.push({{x+dX[i],y+dY[i]},{t+1,sword}});
				}
			}
		}
	}
	if(ans != INT_MAX) {
		cout<<ans<<"\n";
	}
	else {
		cout<<"Fail"<<"\n";
	}
	return 0;	
}