#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000001;
int p[MAX] = {0};
int N,M,op,a,b;
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
    for(int i=0;i<M;i++) {
        cin>>op>>a>>b;
        if(op == 0) {
            bind(a,b);
        }
        else {
            if(check(a,b)) {
                cout<<"YES"<<"\n";
            }
            else {
                cout<<"NO"<<"\n";
            }
        }
    }
    return 0;
}