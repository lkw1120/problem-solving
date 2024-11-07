#include<bits/stdc++.h>
using namespace std;
vector<int> v[2];
int N,X,Y,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>X>>Y;
        v[(X+Y)%2].push_back(i);
    }
    if(v[0].size() != 0 && v[1].size() != 0) {
        cout<<"YES"<<"\n";
        for(int i=0;i<2;i++) {
            for(auto p: v[i]) {
                cout<<p<<" ";
            }
        }
        cout<<"\n";
    }
    else {
        cout<<"NO"<<"\n";
    }
    return 0;
}