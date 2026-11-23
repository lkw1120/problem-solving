#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int x[4],y[4];
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<4;j++) {
            cin>>x[j]>>y[j];
        }
        vector<ll> v;
        for(int j=0;j<4;j++) {
            for(int k=j+1;k<4;k++) {
                ll dx = x[k]-x[j];
                ll dy = y[k]-y[j];
                v.push_back(dx*dx+dy*dy);
            }
        }
        sort(v.begin(),v.end());
        bool check = 
            v[0] > 0 && v[0] == v[1] && v[1] == v[2] && 
            v[2] == v[3] && v[4] == v[5] && v[5] == v[0]*2;
        ans = check? 1: 0;
        cout<<ans<<"\n";
    }
    return 0;
}