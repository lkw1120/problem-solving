#include<bits/stdc++.h>
using namespace std;
vector<int> v,vv;
int N,A,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>A;
        v.push_back(A);
    }
    sort(v.begin(),v.end());
    if(N == 3) {
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(i != j) {
                    string str = to_string(v[i]) + to_string(v[j]);
                    vv.push_back(stoi(str));
                }
            }
        }
    }
    else {
        for(int i=0;i<4;i++) {
            for(int j=0;j<4;j++) {
                if(i != j) {
                    string str = to_string(v[i]) + to_string(v[j]);
                    vv.push_back(stoi(str));
                }
            }
        }
    }
    sort(vv.begin(),vv.end());
    ans = vv[2];
    cout<<ans<<"\n";
    return 0;
}