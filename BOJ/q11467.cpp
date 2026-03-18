#include<bits/stdc++.h>
using namespace std;
vector<string> v;
int b,w;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>b>>w;
    int c = 2*max(b,w);
    int r = 4;
    v.resize(r,string(c,'@'));
    for(int i=2;i<4;i++) {
        for(int j=0;j<c;j++) {
            v[i][j] = '.';
        }
    }
    for(int i=0;i<w-1;i++) {
        v[0][2*i] = '.';
    }
    for(int i=0;i<b-1;i++) {
        v[3][2*i] = '@';
    }
    cout<<r<<" "<<c<<"\n";
    for(auto str: v) {
        cout<<str<<"\n";
    }
    return 0;
}