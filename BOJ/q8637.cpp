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
    sort(v.begin(),v.end());
    int l;
    l = 0;
    ans = 0;
    for(int r=2;r<N;r++) {
        while(l+1 < r && v[l]+v[l+1] <= v[r]) {
            l++;
        }
        if(v[l]+v[l+1] > v[r]) {
            ans = max(ans,r-l+1);
        }
    }
    cout<<ans<<"\n";
    return 0;
}