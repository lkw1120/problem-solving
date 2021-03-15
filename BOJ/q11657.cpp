#include<bits/stdc++.h>
#define INF 999999999
#define MAX 501
using namespace std;
long long dist[MAX];
vector<pair<pair<int,int>,int>> v;
int N,M,a,b,c,ans;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    fill(dist,dist+MAX,INF);
    dist[1] = 0;
    cin>>N>>M;
    for(int i=0;i<M;i++) {
        cin>>a>>b>>c;
        v.push_back({{a,b},c});
    }
    for(int i=1;i<N;i++) {
        for(int j=0;j<v.size();j++) {
            int from = v[j].first.first;
            int to = v[j].first.second;
            int cost = v[j].second;
            if(dist[from] != INF && dist[from] + cost < dist[to]) {
                dist[to] = dist[from] + cost;
            }
        }
    }
    for(int j=0;j<v.size();j++) {
            int from = v[j].first.first;
            int to = v[j].first.second;
            int cost = v[j].second;
            if(dist[from] != INF && dist[from] + cost < dist[to]) {
                cout<<-1<<"\n";
                return 0;
            }
    }
    for(int i=2;i<=N;i++) {
        if(dist[i] == INF) dist[i] = -1;
        cout<<dist[i]<<"\n";
    }
	return 0;
}