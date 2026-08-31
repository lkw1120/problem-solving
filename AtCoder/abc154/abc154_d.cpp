#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,K;
double ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin>>v[i];
    }
    int sum = 0;
    for(int i=0;i<K;i++) {
        sum+=v[i]+1;
    }
    int mx = sum;
    for(int i=K;i<N;i++) {
        sum+=v[i]+1;
        sum-=v[i-K]+1;
        mx = max(mx,sum);
    }
    ans = mx/2.0;
    cout<<fixed<<setprecision(10)<<ans<<"\n";
    return 0;
}