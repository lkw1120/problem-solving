#include<bits/stdc++.h>
using namespace std;
int N,M,K,ans;
int gcd(int a, int b) {
    return b == 0? a:gcd(b,a%b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M>>K;
    int cnt = 0;
    for(int x1=0;x1<=N;x1++) {
        for(int y1=0;y1<=M;y1++) {
            for(int x2=0;x2<=N;x2++) {
                for(int y2=0;y2<=M;y2++) {
                    if(gcd(abs(x1-x2),abs(y1-y2))+1 == K) {
                        cnt++;
                    }
                }
            }
        }
    }
    ans = cnt/2;
    cout<<ans<<"\n";
    return 0;
}