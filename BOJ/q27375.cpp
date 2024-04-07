#include<bits/stdc++.h>
using namespace std;
vector<pair<int,pair<int,int>>> v;
int N,K,W,S,E,ans;
void find(int n, int m, int end, int sum) {
    if(sum == K) {
        ans++;
        return ;
    }
    int size = v.size();
    for(int i=n;i<size;i++) {
        if(v[i].first == 5) break;
        int w = v[i].first;
        int s = v[i].second.first;
        int e = v[i].second.second;
        if((m != w || (m == w && end < s)) && sum+(e-s+1) <= K) {
            find(i,w,e,sum+(e-s+1));
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>K;
    for(int i=0;i<N;i++) {
        cin>>W>>S>>E;
        v.push_back({W,{S,E}});
    }
    sort(v.begin(),v.end());
    ans = 0;
    find(0,1,-1,0);
    cout<<ans<<"\n";
    return 0;
}