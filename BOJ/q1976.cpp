#include<bits/stdc++.h>
using namespace std;
const int MAX = 201;
int p[MAX] = {0};
int city[MAX][MAX] = {0};
vector<int> v;
int N,M,m;
int find(int x) {
    if(p[x] == x) return x;
    else return p[x] = find(p[x]);
}
bool check(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return true;
    else return false;
}
void bind(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) p[y] = x;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0;i<MAX;i++) {
        p[i] = i;
    }
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cin>>city[i][j];
            if(city[i][j]) {
                bind(i,j);
            }
        }
    }
    for(int i=0;i<M;i++) {
        cin>>m;
        v.push_back(m);
    }
    bool flag = true;
    for(int i=1;i<v.size();i++) {
        if(!check(v[i],v[i-1])) {
            flag = false;
            break;
        }
    }
    if(flag) {
        cout<<"YES"<<"\n";
    }
    else {
        cout<<"NO"<<"\n";
    }
    return 0;
}