#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int MAX = 3601;
int arr[MAX];
vector<int> v;
int T,N,K;
void find() {
    fill(arr,arr+MAX,INF);
    queue<int> q;
    q.push(0);
    arr[0] = 0;
    while(!q.empty()) {
        int k = q.front();
        q.pop();
        for(auto step: v) {
            int dist = k+step;
            if(dist < 0) dist = 0;
            if(MAX <= dist) dist = MAX-1;
            if(arr[dist] != INF) continue;
            arr[dist] = arr[k]+1;
            q.push(dist);
        }
    }
    return ;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        v.clear();
        cin>>N>>K;
        v.resize(N);
        for(int i=0;i<N;i++) {
            cin>>v[i];
        }
        find();
        int cnt,gap;
        gap = K;
        while(arr[gap] == INF) {
            gap++;
        }
        cnt = arr[gap];
        gap-=K;
        cout<<cnt<<" "<<gap<<"\n";
    }
    return 0;
}