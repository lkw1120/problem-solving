#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin>>v[i];
    }
    sort(v.rbegin(),v.rend());
    ans = -1;
    for(int i=0;i<N-2;i++) {
        if(v[i] < v[i+1]+v[i+2]) {
            ans = v[i]+v[i+1]+v[i+2];
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}