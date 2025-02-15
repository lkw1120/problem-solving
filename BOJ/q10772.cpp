#include<bits/stdc++.h>
using namespace std;
int dp[251][251][251];
int N,K,ans;
int find(int x, int y, int z) {
    int& res = dp[x][y][z];
    if(res) {
        return res;
    }
    if(x == 1 || x == y) {
        res = 1;
        return res;
    }
    for(int i=z;i*x<=y;i++) {
        res+=find(x-1,y-i,i);
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>K;
    ans = find(K,N,1);
    cout<<ans<<"\n";
    return 0;
}