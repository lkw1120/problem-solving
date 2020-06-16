#include<bits/stdc++.h>
using namespace std;
const int MAX = 101;
vector<pair<double,double>> star;
priority_queue<pair<double,pair<int,int>>> pq;
int p[MAX] = {0};
int N,M;
double X,Y,D,ans;
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
    double dx = abs(star[x].first-star[y].first);
    double dy = abs(star[x].second-star[y].second);
    return sqrt(pow(dx,2) + pow(dy,2));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>X>>Y;
        star.push_back({X,Y});
    }
    for(int i=0;i<N;i++) {
        for(int j=i+1;j<N;j++) {
            D = dist(i,j);
            pq.push({-D,{i,j}});
        }
    }
    int cnt = 0;
    while(!pq.empty() && cnt != N-1) {
        D = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        if(!check(x,y)) {
            merge(x,y);
            ans+=D;
            cnt++;
        }
    }
    cout<<fixed;
    cout.precision(2);
    cout<<ans<<"\n";
    return 0;
}