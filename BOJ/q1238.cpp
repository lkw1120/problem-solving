#include<bits/stdc++.h>
#define MAX 1000+1
#define INF 100*1000+1
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int Road[MAX][MAX] = {0};
    int N,M,X,ans;
    int start,end,time;
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++) {
            if(i==j)
                Road[i][j] = 0;
            else
                Road[i][j] = INF;
        }
    }
    cin>>N>>M>>X;
    for(int i=0;i<M;i++) {
        cin>>start>>end>>time;
        Road[start][end] = time;
    }
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=N;j++) {
                if(Road[i][k] + Road[k][j] < Road[i][j]) {
                    Road[i][j] = Road[i][k] + Road[k][j];
                }
            }
        }
    }
    ans = 0;
    for(int i=1;i<=N;i++) {
        ans = max(ans,Road[i][X] + Road[X][i]);
    }
    cout<<ans<<"\n";
    return 0;
}