#include<bits/stdc++.h>
using namespace std;
const int MAX = 100001;
int dist[MAX] = {0};
int past[MAX] = {0};
priority_queue<pair<int,int>> pq;
stack<int> s;
int N,K,ans;
void move() {
    while(!pq.empty()) {
        int now = pq.top().second;
        int nowDist = -pq.top().first;
        pq.pop();
        if(dist[now] < nowDist) continue;
        int next, nextDist;
        if(now < MAX-1) {
            next = now+1;
            nextDist = nowDist+1;
            if(dist[next] > nextDist) {
                dist[next] = nextDist;
                past[next] = now;
                pq.push({-nextDist,next});
            }
        }
        if(now > 0) {
            next = now-1;
            nextDist = nowDist+1;
            if(dist[next] > nextDist) {
                dist[next] = nextDist;
                past[next] = now;
                pq.push({-nextDist,next});
            }    
        }
        if(now*2 < MAX) {
            next = now*2;
            nextDist = nowDist+1;
            if(dist[next] > nextDist) {
                dist[next] = nextDist;
                past[next] = now;
                pq.push({-nextDist,next});
            }
        }
    }
    ans = dist[K];
    s.push(K);
    while(s.top() != N) {
        s.push(past[s.top()]);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fill(dist,dist+MAX,INT_MAX);
    cin>>N>>K;
    pq.push({0,N});
    dist[N] = 0;
    move();
    cout<<ans<<"\n";
    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<"\n";
    return 0;
}