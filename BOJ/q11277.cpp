#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
int N,M,A,B,ans;
bool find(int n) {
    bool check[21] = {false};
    for(int i=0;i<N;i++) {
        check[i+1] = n&(1<<i);
    }
    bool l,r;
    for(auto [a,b]: v) {
        if(0 < a) {
            l = check[a];
        }
        else {
            l = !check[-a];
        }
        if(0 < b) {
            r = check[b];
        }
        else {
            r = !check[-b];
        }
        if(!l && !r) {
            return false;
        }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=0;i<M;i++) {
        cin>>A>>B;
        v.push_back({A,B});
    }
    ans = 0;
    for(int i=0;i<(1<<N);i++) {
        if(find(i)) {
            ans = 1;
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}