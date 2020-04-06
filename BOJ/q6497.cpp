#include<bits/stdc++.h>
#define MAX 200000
using namespace std;
int parent[MAX] = {};
int M,N,X,Y,Z,ans;
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
    if(x != y) parent[y] = x;
}
int main() {
    ios_base::sync_with_stdio(false);
    while(true) {
        cin>>M>>N;
        if(M == 0 && N == 0) break;
        vector<pair<int,pair<int,int>>> v;
        for(int i=0;i<M;i++) {
            parent[i] = i;
        }
        ans = 0;
        for(int i=0;i<N;i++) {
            cin>>X>>Y>>Z;
            v.push_back({Z,{X,Y}});
            ans+=Z;
        }
        sort(v.begin(),v.end());
        for(int i=0;i<N;i++) {
            X = v[i].second.first;
            Y = v[i].second.second;
            Z = v[i].first;
            if(!check(X,Y)) {
                merge(X,Y);
                ans-=Z;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}