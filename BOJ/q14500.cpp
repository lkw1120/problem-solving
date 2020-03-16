#include<bits/stdc++.h>
#define MAX 501
using namespace std;
int paper[MAX][MAX] = {0};
int visited[MAX][MAX] = {0};
int dX[4] = {0,-1,0,1};
int dY[4] = {-1,0,1,0}; 
int N, M;
int ans = 0;
void dfs(int x, int y, int cnt, int sum) {
    if(cnt == 4) {
        ans = (ans < sum)? sum: ans;
        return ;
    }
    visited[x][y] = 1;
    for(int i=0;i<4;i++) {
        if(0 <= x+dX[i] && x+dX[i] < N
        && 0 <= y+dY[i] && y+dY[i] < M
        && visited[x+dX[i]][y+dY[i]] == 0) {
            dfs(x+dX[i],y+dY[i],cnt+1,sum+paper[x+dX[i]][y+dY[i]]);
        }
    }
    visited[x][y] = 0;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin>>N>>M;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin>>paper[i][j];
        }
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            int sum[4] = {0};
            for(int k=0;k<4;k++) {
                sum[k] = paper[i][j];
                for(int l=0;l<4;l++) {
                    if(0 <= i+dX[l] && i+dX[l] < N
                    && 0 <= j+dY[l] && j+dY[l] < M
                    && k != l) {
                        sum[k]+=paper[i+dX[l]][j+dY[l]];
                    }
                }
            }
            ans = (ans < *max_element(sum,sum+4))? *max_element(sum,sum+4): ans;
            dfs(i,j,1,paper[i][j]);
        }
    }
	cout<<ans<<"\n";
	return 0;
}