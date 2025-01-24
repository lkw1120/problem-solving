#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
int T,N,M,A,B,P,X,Y,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        v.clear();
        cin>>N>>M;
        cin>>A>>B;
        cin>>P;
        for(int i=0;i<P;i++) {
            cin>>X>>Y;
            v.push_back({X,Y});
        }
        sort(v.begin(),v.end());
        ans = INT_MAX;
        do {
            int a,b,dist;
            a = A, b = B;
            dist = 0;
            for(auto [x,y]: v) {
                dist+=abs(a-x)+abs(b-y);
                a = x;
                b = y;
            }
            dist+=abs(a-A)+abs(b-B);
            ans = min(ans,dist);
        } while(next_permutation(v.begin(),v.end()));
        cout<<"The shortest path has length "<<ans<<"\n";
    }
    return 0;
}