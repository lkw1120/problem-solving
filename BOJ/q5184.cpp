#include<bits/stdc++.h>
using namespace std;
double arr[201];
double diff[201];
int K,L,R,N;
double ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>K;
    for(int t=1;t<=K;t++) {
        cin>>L>>R>>N;
        for(int i=0;i<N;i++) {
            cin>>arr[i];
        }
        double base = 0.0;
        for(int i=0;i<N;i++) {
            base+=(1.0-arr[i]);
        }
        for(int i=0;i<N;i++) {
            diff[i] = 2.0*arr[i]-1.0;
        }
        sort(diff,diff+N,greater<double>());
        double best = 0.0;
        double acc = 0.0;
        bool flag = true;
        for(int i=0;i<=N;i++) {
            if(0 < i) {
                acc+=diff[i-1];
            }
            if(L <= i && i <= R) {
                if(flag) {
                    best = acc;
                    flag = false;
                }
                else {
                    best = max(best, acc);
                }
            }
        }
        ans = base+best;
        cout<<"Data Set "<<t<<":"<<"\n";
        cout<<fixed<<setprecision(2)<<ans<<"\n";
    }
    return 0;
}