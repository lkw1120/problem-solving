#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    ans = N-1+v[N-1];
    cout<<ans<<"\n";
    return 0;
}