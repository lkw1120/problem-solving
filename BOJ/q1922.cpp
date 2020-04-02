#include<bits/stdc++.h>
#define MAX 1001
using namespace std;
vector<pair<int,pair<int,int>>> edge;
int parent[MAX] = {0};
int N,M;
int A,B,C,ans;
int find(int x) {
    if(parent[x] == x) {
        return x;
    }
    else {
        return parent[x] = find(parent[x]);
    }
}
bool check(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) 
        return true;
    else 
        return false;
}
void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) {
        parent[y] = x;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin>>N>>M;
    for(int i=0;i<=N;i++) {
        parent[i] = i;
    }
    for(int i=0;i<M;i++) {
        cin>>A>>B>>C;
        edge.push_back({C,{A,B}});
    }
    sort(edge.begin(),edge.end());
    ans = 0;
    for(int i=0;i<M;i++) {
        A = edge[i].second.first; 
        B = edge[i].second.second;
        C = edge[i].first;
        if(!check(A,B)) {
            merge(A,B);
            ans+=C;
        }
    }
    cout<<ans<<"\n";
    return 0;
}