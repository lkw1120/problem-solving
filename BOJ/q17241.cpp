#include<bits/stdc++.h>
using namespace std;
vector<int> v[200001];
bool give[200001];
bool like[200001];
int N,M,Q,A,B,C;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M>>Q;
    for(int i=0;i<M;i++) {
        cin>>A>>B;
        v[A].push_back(B);
        v[B].push_back(A);
    }
    while(Q--) {
        cin>>C;
        int cnt = 0;
        if(!give[C]) {
            give[C] = true;
            if(!like[C]) {
                like[C] = true;
                cnt++;
            }
            for(auto n: v[C]) {
                if(!like[n]) {
                    like[n] = true;
                    cnt++;
                }
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}