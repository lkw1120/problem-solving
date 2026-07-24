#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        int a;
        cin>>a;
        v.push_back({a,i});
    }
    sort(v.begin(),v.end(),greater<pair<int,int>>());
    for(auto [a,b]: v) {
        cout<<b<<"\n";
    }
    return 0;
}