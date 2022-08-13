#include<bits/stdc++.h>
#define MAX 501
using namespace std;
int arr[MAX][MAX] = {0};
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int N,M,cnt,s,ans;
void dfs(int x, int y) {
	ans = max(ans,s);
	for(int i=0;i<4;i++) {
		if((0 < x+dX[i] && x+dX[i] <= N) &&
		   (0 < y+dY[i] && y+dY[i] <= M) &&
		   arr[x+dX[i]][y+dY[i]] != 0) {
			arr[x+dX[i]][y+dY[i]] = 0;
			s++;
			dfs(x+dX[i],y+dY[i]);
		}
		
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			cin>>arr[i][j];	
		}
	}
	cnt = ans = 0;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			if(arr[i][j] != 0) {
				cnt++;
				s = 1;
				arr[i][j] = 0;
				dfs(i,j);
			}
		}
	}
	cout<<cnt<<"\n";
	cout<<ans<<"\n";
	return 0;	
}