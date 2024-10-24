#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    v.resize(N);
    int tmp = 0;
    for(int i=0;i<N;i++) {
        cin>>v[i];
        tmp^=v[i];
    }
    ans = tmp;
    for(int i=0;i<N;i++) {
        ans = max(tmp^v[i],ans);
    }
    cout<<ans<<ans<<"\n";
    return 0;
}