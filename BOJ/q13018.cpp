#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,K;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    if(N-1 < K) {
        cout<<"Impossible"<<"\n";
    }
    else {
        v.resize(N+1);
        for(int i=1;i<=N;i++) {
            v[i] = i;
        }
        int tmp = (N-1)-K;
        int t = 2;
        while(t <= N && tmp) {
            swap(v[1],v[t]);
            t++;
            tmp--;
        }
        for(int i=1;i<=N;i++) {
            cout<<v[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}