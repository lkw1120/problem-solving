#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 31;
vector<pair<int,int>> v;
ll dp[MAX_N][MAX_N];
ll N,M,A,B,ans;
void init() {
    for(int i=0;i<MAX_N;i++) {
        dp[i][0] = dp[i][i] = 1;
        for(int j=1;j<i;j++) {
            dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    cin>>N>>M;
    for(int i=0;i<M;i++) {
        cin>>A>>B;
        v.push_back({A,B});
    }
    v.push_back({0,0});
    sort(v.begin(),v.end());
    int size = v.size();
    bool flag = false;
    ans = 1;
    for(int i=1;i<size;i++) {
        int a1,b1,a2,b2;
        a1 = v[i-1].first;
        b1 = v[i-1].second;
        a2 = v[i].first;
        b2 = v[i].second;
        int a = a2-a1;
        int b = b2-b1;
        if(a < b || b < 0) {
            flag = true;
            break;
        }
        ans*=dp[a][b];
    }
    if(!flag) {
        int tmp = v[size-1].first;
        ans*=(1LL<<(N-1-tmp));
    }
    else {
        ans = 0;
    }
    cout<<ans<<"\n";
    return 0;
}