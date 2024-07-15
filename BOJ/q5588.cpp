#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v1,v2;
map<pair<int,int>,int> mp;
int N,M,X,Y;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>M;
    for(int i=0;i<M;i++) {
        cin>>X>>Y;
        v1.push_back({X,Y});
    }
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>X>>Y;
        v2.push_back({X,Y});
    }
    for(int i=0;i<M;i++) {
        for(int j=0;j<N;j++) {
            X = v2[j].first-v1[i].first;
            Y = v2[j].second-v1[i].second;
            mp[{X,Y}]++;
        }
    }
    for(auto [a,b]: mp) {
        if(b == M) {
            X = a.first;
            Y = a.second;
        }
    }
    cout<<X<<" "<<Y<<"\n";
    return 0;
}