#include<bits/stdc++.h>
using namespace std;
vector<pair<pair<int,int>,int>> v;
int N,X,Y,A,B;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>X>>Y;
        v.push_back({{X,Y},i});
    }
    sort(v.begin(),v.end());
    for(int i=1;i<N;i++) {
        A = v[i-1].second;
        B = v[i].second;
        cout<<A<<" "<<B<<"\n";
    }
    return 0;
}