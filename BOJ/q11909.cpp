#include<bits/stdc++.h>
#define INF 99999999
#define MAX 2223
using namespace std;
int arr[MAX][MAX] = {0};
int cost[MAX][MAX] = {0};
int dX[2] = {0,1};
int dY[2] = {1,0};
int N,diff,ans;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin>>N;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cin>>arr[i][j];
            cost[i][j] = INF;
        }
    }
    ans = -1;
    cost[1][1] = 0;
    for(int x=1;x<=N;x++) {
        for(int y=1;y<=N;y++) {
            for(int i=0;i<2;i++) {
                if(x+dX[i] <= N && y+dY[i] <= N) {
                    if(arr[x+dX[i]][y+dY[i]] < arr[x][y]) {
                        cost[x+dX[i]][y+dY[i]] = min(cost[x][y],cost[x+dX[i]][y+dY[i]]);
                    }
                    else {
                        diff = arr[x+dX[i]][y+dY[i]]-arr[x][y];
                        cost[x+dX[i]][y+dY[i]] = min(cost[x+dX[i]][y+dY[i]],cost[x][y]+diff+1);
                    }
                }
            }
        }
    }
    ans = cost[N][N];
    cout<<ans<<"\n";
	return 0;
}