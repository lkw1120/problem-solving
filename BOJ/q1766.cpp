#include<bits/stdc++.h>
#define MAX 32001
using namespace std;
vector<int> v[MAX];
priority_queue<int,vector<int>,greater<int>> pq;
int indeg[MAX] = {0};
int N,M,A,B;
int main() {
    ios_base::sync_with_stdio(false);
    cin>>N>>M;
    for(int i=0;i<M;i++) {
        cin>>A>>B;
        v[A].push_back(B);
        indeg[B]++;
    }
    for(int i=1;i<=N;i++) {
        if(indeg[i] == 0) {
            pq.push(i);
        }
    }
    while(!pq.empty()) {
        int a = pq.top();
        pq.pop();
        cout<<a<<" ";
        int size = v[a].size();
        for(int b=0;b<size;b++) {
            if(--indeg[v[a][b]] == 0) {
                pq.push(v[a][b]);
            }
        }
    }
    return 0;
}