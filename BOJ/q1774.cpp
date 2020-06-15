#include<bits/stdc++.h>
using namespace std;
const int MAX = 1001;
vector<pair<int,int>> loc;
priority_queue<pair<double,pair<int,int>>> pq;
int p[MAX] = {0};
int N,M,X,Y;
double D,ans;
int find(int x) {
    if(x == p[x]) return x;
    else return p[x] = find(p[x]);
}
bool check(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return true;
    else return false;
}
void merge(int x, int y) {
    x = find(x);
    y = find(y);
    p[y] = x;
}
void init() {
    for(int i=0;i<MAX;i++) {
        p[i] = i;
    }
}
double dist(int x, int y) {
    int dx = abs(loc[x].first-loc[y].first);
    int dy = abs(loc[x].second-loc[y].second);
    return sqrt(pow(dx,2) + pow(dy,2));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    cin>>N>>M;
    for(int i=0;i<N;i++) {
        cin>>X>>Y;
        loc.push_back({X,Y});
    }
    for(int i=0;i<M;i++) {
        cin>>X>>Y;
        merge(X-1,Y-1);
    }
    for(int i=0;i<N;i++) {
        for(int j=i+1;j<N;j++) {
            D = dist(i,j);
            pq.push({-D,{i,j}});
        }
    }
    int cnt = M;
    while(!pq.empty()) {
        D = -pq.top().first;
        X = pq.top().second.first;
        Y = pq.top().second.second;
        pq.pop();
        if(!check(X,Y)) {
            merge(X,Y);
            ans+=D;
            cnt++;
            if(cnt == N-1) break;
        }
    }
    cout<<fixed;
    cout.precision(2);
    cout<<ans<<"\n";
    return 0;
}