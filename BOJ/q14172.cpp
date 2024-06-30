#include<bits/stdc++.h>
using namespace std;
vector<pair<pair<int,int>,int>> v;
map<pair<int,int>,bool> mp;
int N,X,Y,P,ans;
int find(int x, int y, int p) {
    mp[{x,y}] = true;
    int cnt = 1;
    for(auto item: v) {
        X = item.first.first;
        Y = item.first.second;
        P = item.second;
        int d = (X-x)*(X-x)+(Y-y)*(Y-y);
        if(!mp[{X,Y}] && d <= p*p) {
            cnt+=find(X,Y,P);
        }
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>X>>Y>>P;
        v.push_back({{X,Y},P});
    }
    ans = 0;
    for(auto item: v) {
        mp.clear();
        X = item.first.first;
        Y = item.first.second;
        P = item.second;
        ans = max(find(X,Y,P),ans);
    }
    cout<<ans<<"\n";
    return 0;
}