#include<bits/stdc++.h>
#define MAX 101
using namespace std;
int arr[MAX][MAX][MAX] = {0};
bool visited[MAX][MAX][MAX] = {0};
queue<pair<tuple<int,int,int>,int>> q;
int dX[6] = {1,0,0,-1,0,0};
int dY[6] = {0,1,0,0,-1,0};
int dZ[6] = {0,0,1,0,0,-1};
int M,N,H,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fill(&arr[0][0][0],&arr[MAX-1][MAX-1][MAX],-1);
	cin>>M>>N>>H;
	for(int k=1;k<=H;k++) {
		for(int i=1;i<=N;i++) {
			for(int j=1;j<=M;j++) {
				cin>>arr[k][i][j];
				if(arr[k][i][j] == 1) {
					q.push({make_tuple(k,i,j),0});
				}
				if(arr[k][i][j] != 0) {
					visited[k][i][j] = true;
				}
			}
		}
	}
	ans = 0;
	while(!q.empty()) {
		int z = get<0>(q.front().first);
		int x = get<1>(q.front().first);
		int y = get<2>(q.front().first);
		int day = q.front().second;
		ans = max(ans,day);
		q.pop();
		for(int i=0;i<6;i++) {
			if((0 < z+dZ[i] && z+dZ[i] <= H) &&
			   (0 < x+dX[i] && x+dX[i] <= N) && 
			   (0 < y+dY[i] && y+dY[i] <= M) &&
			   !visited[z+dZ[i]][x+dX[i]][y+dY[i]] &&
			   arr[z+dZ[i]][x+dX[i]][y+dY[i]] == 0) {
				visited[z+dZ[i]][x+dX[i]][y+dY[i]] = true;
				arr[z+dZ[i]][x+dX[i]][y+dY[i]] = 1;
				q.push({make_tuple(z+dZ[i],x+dX[i],y+dY[i]),day+1});
			}
		}
	}
	for(int k=1;k<=H;k++) {
		for(int i=1;i<=N;i++) {
			for(int j=1;j<=M;j++) {
				if(arr[k][i][j] == 0) ans = -1;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;	
}