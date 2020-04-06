#include<bits/stdc++.h>
#define MAX 100001
using namespace std;
vector<pair<int,pair<int,int>>> v;
int parent[MAX];
int N,M,A,B,C,D,ans;
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
    if(x == y) {
        return true;
    }
    else {
        return false;
    }
}
void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x!=y) {
        parent[y] = x;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin>>N>>M;
    for(int i=0;i<MAX;i++) {
        parent[i] = i; 
    }
    for(int i=0;i<M;i++) {
        cin>>A>>B>>C;
        v.push_back({C,{A,B}});
    }
    sort(v.begin(),v.end());
    ans = 0;
    D = 0;
    for(int i=0;i<M;i++) {
        A = v[i].second.first;
        B = v[i].second.second;
        C = v[i].first;
        if(!check(A,B)) {
            merge(A,B);
            ans+=C;
            D = max(C,D);
        }
    }
    ans-=D;
    cout<<ans<<"\n";
    return 0;
}