#include<bits/stdc++.h>
using namespace std;
vector<int> v,vv;
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin>>v[i];	
    }
    ans = 0;
    vv.push_back(INT_MAX);
    for(int i=0;i<N;i++) {
        if(vv.back() > v[i]) {
            vv.push_back(v[i]);	
        }
        else {
            int idx = lower_bound(vv.begin(),vv.end(),v[i])-vv.begin();
            vv[idx] = v[i];
        }
    }
    ans = vv.size()-1;
    cout<<ans<<"\n";
    return 0;
}