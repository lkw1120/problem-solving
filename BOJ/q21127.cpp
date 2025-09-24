#include<bits/stdc++.h>
using namespace std;
int N,M,K,A,B,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>K;
    A = 0;
    for(int i=0;i<N;i++) {
        int a;
        cin>>a;
        if(a == 0) A++;
    }
    B = 0;
    for(int i=0;i<M;i++) {
        int b;
        cin>>b;
        if(b == 1) B++;
    }
    for(int i=0;i<K;i++) {
        int s;
        cin>>s;
    }
    ans = abs(A-B);
    cout<<ans<<"\n";
    return 0;
}