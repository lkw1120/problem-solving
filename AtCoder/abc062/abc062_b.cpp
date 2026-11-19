#include<bits/stdc++.h>
using namespace std;
vector<string> v,vv;
int H,W;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>H>>W;
    v.resize(H);
    for(int i=0;i<H;i++) {
        cin>>v[i];
    }
    vv.resize(H+2);
    for(int i=0;i<H+2;i++) {
        for(int j=0;j<W+2;j++) {
            if(i == 0 || i == H+1 || j == 0 || j == W+1) {
                vv[i]+="#";	
            }
            else {
                vv[i]+=v[i-1][j-1];	
            }
        }
    }
    for(auto item: vv) {
        cout<<item<<"\n";	
    }
    return 0;
}