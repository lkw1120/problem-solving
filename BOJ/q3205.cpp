#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,K,F,X,Y,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    cin>>F;
    v.resize(N+1);
    for(int i=0;i<F;i++) {
        cin>>X>>Y;
        v[X]+=Y;
    }
    int pages = 1;
    int cur = 0;
    for(int i=1;i<=N;i++) {
        int w = 1+v[i];
        if(cur+w > K) {
            pages++;
            cur = 0;
        }
        cur += w;
    }
    ans = pages;
    cout<<ans<<"\n";
    return 0;
}