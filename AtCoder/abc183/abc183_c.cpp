#include<bits/stdc++.h>
using namespace std;
int T[9][9];
int N,K,ans;
void travel(int cur, int mask, int sum) {
    int p = (1<<N)-1;
    if(cur == 1 && mask == p && sum == K) {
        ans++;
        return ;
    }
    for(int j=1;j<=N;j++) {
        if(cur == j) continue;
        if((1<<(j-1)) & mask) continue;
        travel(j,mask+(1<<(j-1)),sum+T[cur][j]);
    }
    return ;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cin>>T[i][j];
        }
    }
    ans = 0;
    travel(1,0,0);
    cout<<ans<<"\n";
    return 0;
}