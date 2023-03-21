#include<bits/stdc++.h>
using namespace std;
const int MAX = 100001;
vector<int> adj[MAX];
int parent[MAX][20];
int level[MAX],maxLevel;
int N,M,A,B,L,ans;
void makeTree(int n, int p) {
    level[n] = level[p]+1;
    parent[n][0] = p;
    for(int i=1;i<=maxLevel;i++) {
        parent[n][i] = parent[parent[n][i-1]][i-1];
    }
    int size = adj[n].size();
    for(int i=0;i<size;i++) {
        int c = adj[n][i];
        if (c != p) {
            makeTree(c,n);
        }
    }
}
int lca(int a, int b) {
    if(a == 1 || b == 1) {
        return 1;
    }
    if(level[a] < level[b]) {
        swap(a, b);
    }
    if(level[a] != level[b]) {
        for(int i=maxLevel;i>=0;i--) {
            if(level[parent[a][i]] >= level[b]) {
                a = parent[a][i];
            }
        }
    }
    int res = a;
    if(a != b) {
        for(int i=maxLevel;i>=0;i--) {
            if (parent[a][i] != parent[b][i]) {
                a = parent[a][i];
                b = parent[b][i];
            }
            res = parent[a][i];
        }
    }
    return res;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N-1;i++) {
        cin>>A>>B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    maxLevel = (int)floor(log2(MAX));
    makeTree(1,0);
    cin>>M;
    for(int i=0;i<M;i++) {
        cin>>A>>B;
        ans = lca(A,B);
        cout<<ans<<"\n";
    }
    return 0;
}