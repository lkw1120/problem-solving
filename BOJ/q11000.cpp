#include<bits/stdc++.h>
using namespace std;
priority_queue<int> pq;
vector<pair<int,int>> v;
int N,S,T,ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>S>>T;
        v.push_back({S,T});
    }
    sort(v.begin(),v.end(),less<pair<int,int>>());
    pq.push(-v[0].second);
    for(int i=1;i<N;i++) {
        if(-pq.top() > v[i].first) {
            pq.push(-v[i].second);
        }
        else {
            pq.pop();
            pq.push(-v[i].second);
        }
    }
    ans = pq.size();
    cout<<ans<<"\n";
    return 0;
}