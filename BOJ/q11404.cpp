#include<bits/stdc++.h>
#define MAX 100+1
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int cost[MAX][MAX] = {0};
    int N,M;
    cin>>N>>M;
    int A,B,C;
    for(int i=0;i<M;i++) {
        cin>>A>>B>>C;
        cost[A][B] = (cost[A][B] == 0)? C : min(cost[A][B],C);
    }
    for(int j=1;j<=N;j++) {
        for(int i=1;i<=N;i++) {
            if(cost[i][j] == 0) continue;
            for(int k=1;k<=N;k++) {
                if(cost[j][k] == 0 || i==k) continue;
                if(cost[i][k] == 0 
                || cost[i][k] > cost[i][j]+cost[j][k]) {
                    cost[i][k] = cost[i][j]+cost[j][k];
                }
            }
        }
    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cout<<cost[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}