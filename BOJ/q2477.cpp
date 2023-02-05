#include<bits/stdc++.h>
using namespace std;
queue<pair<int,int>> q;
int K,N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>K;
    for(int i=0;i<6;i++) {
        cin>>N>>M;
        q.push({N,M});
    }
    ans = 0;
    while(true) {
        vector<pair<int,int>> v;
        for(int i=0;i<4;i++) {
            v.push_back(q.front());
            q.pop();
        }
        if(v[0].first == v[2].first && v[1].first == v[3].first) {
            ans-=v[1].second*v[2].second;
            int a,b;
            a = q.front().second;
            q.pop();
            b = q.front().second;
            q.pop();
            ans+=a*b;
            break;
        }
        else {
            for(int i=0;i<4;i++) {
                q.push(v[i]);
            }
            q.push(q.front());
            q.pop();
        }
    }
    ans*=K;
    cout<<ans<<"\n";
    return 0;
}