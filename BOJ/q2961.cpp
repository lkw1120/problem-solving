#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
int N,A,B,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>A>>B;
        v.push_back({A,B});
    }
    ans = INT_MAX;
    for(int i=1;i<(1<<N);i++) {
        A = 1;
        B = 0;
        for(int j=0;j<N;j++) {
            if(i&(1<<j)){ 
                A*=v[j].first;
                B+=v[j].second;
            }
        }
        ans = min(ans,abs(A-B));
    }
    cout<<ans<<"\n";
    return 0;
}