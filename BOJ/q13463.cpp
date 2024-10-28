#include<bits/stdc++.h>
using namespace std;
const int MAX = 2e5+1;
vector<int> v[MAX];
int line[MAX];
int cnt[MAX];
bool check[MAX];
int C,P,X,L,A,B;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>C>>P>>X>>L;
    for(int i=0;i<P;i++) {
        cin>>A>>B;
        v[A].push_back(B);
        v[B].push_back(A);
    }
    for(int i=1;i<=C;i++) {
       line[i] = v[i].size(); 
    }
    queue<int> q;
    q.push(L);
    check[L] = true;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(auto next: v[now]) {
            cnt[next]++;
            if(line[next] <= 2*cnt[next] && !check[next]) {
                q.push(next);
                check[next] = true;
            }
        }
    }
    if(check[X]) {
        cout<<"leave"<<"\n";
    }
    else {
        cout<<"stay"<<"\n";
    }
    return 0;
}