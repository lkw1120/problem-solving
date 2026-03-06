#include<bits/stdc++.h>
using namespace std;
int N,M,K;
double ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>K;
    cout<<fixed<<setprecision(6);
    for(int i=1;i<=K;i++) {
        ans = 1.0;
        if(i <= N-M) {
            double none = 1.0;
            for(int j=0;j<i;j++) {
                none*=(double)(N-M-j)/(N-j);
            }
            ans-=none;
        }
        cout<<ans<<"\n";
    }
    return 0;
}