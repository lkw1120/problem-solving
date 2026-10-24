#include<bits/stdc++.h>
using namespace std;
vector<int> v,vv;
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    v.resize(N);
    vv.resize(N);
    for(int i=0;i<N;i++) {
        cin>>v[i];
        vv[i] = v[i];
    }
    sort(vv.begin(),vv.end(),greater<>());
    for(int i=0;i<N;i++) {
        if(v[i] == vv[0]) {
            cout<<vv[1]<<"\n";
        }
        else {
            cout<<vv[0]<<"\n";
        }
    }
    return 0;
}