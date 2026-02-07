#include<bits/stdc++.h>
using namespace std;
const int MAX_C = 100001;
int N,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    vector<int> row(MAX_C,0);
    vector<int> col(MAX_C,0);
    vector<int> diag1(2*MAX_C,0);
    vector<int> diag2(2*MAX_C,0);
    ans = -1;
    for(int i=1;i<=N;i++) {
        int x,y;
        cin>>x>>y;
        if(ans != -1) continue;
        int a = ++row[y];
        int b = ++col[x];
        int c = ++diag1[(x-y)+100000];
        int d = ++diag2[x+y];
        if(a >= K || b >= K || c >= K || d >= K) {
            ans = i;
        }
    }
    cout<<ans<<"\n";
    return 0;
}