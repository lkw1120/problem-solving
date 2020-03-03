#include<bits/stdc++.h>
using namespace std;
int** pc;
int* infested;
int N, P, ans;
void dfs(int x) {
    ans++;
    for(int i=1;i<=N;i++) {
        if(pc[x][i]!=0 && infested[i]==0) {
            infested[i]++;
            dfs(i);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin>>N>>P;
    infested = (int*) malloc(sizeof(int)*(N+1));
    pc = (int**) malloc(sizeof(int*)*(N+1));
    pc[0] = (int*) malloc(sizeof(int)*(N+1)*(N+1));
    for(int i=1;i<=N;i++) {
        pc[i] = pc[i-1]+(N+1);
    }
    for(int i=0;i<P;i++) {
        int x,y;
        cin>>x>>y;
        pc[x][y] = pc[y][x] = 1;
    }
    ans=0;
    infested[1]++;
    dfs(1);
    free(infested);
    free(pc[0]);
    free(pc);
    ans--;
    cout<<ans<<"\n";
}