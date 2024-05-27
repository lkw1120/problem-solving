#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
int N,X,Y,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>X>>Y;
        v.push_back({X,Y});
    }
    v.push_back(v[0]);
    int sum = 0;
    int minX,maxX,minY,maxY;
    minX = maxX = v[0].first;
    minY = maxY = v[0].second;
    for(int i=1;i<=N;i++) {
        sum+=max(abs(v[i].first-v[i-1].first),abs(v[i].second-v[i-1].second));
        minX = min(minX,v[i].first);
        maxX = max(maxX,v[i].first);
        minY = min(minY,v[i].second);
        maxY = max(maxY,v[i].second);
    }
    ans = sum-2*((maxX-minX)+(maxY-minY));
    cout<<ans<<"\n";
    return 0;
}