#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,N,R,C;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--) {
        cin>>N;
        R = C = 0;
        if(1 < N) {
            long double rt = sqrt((long double)N);
            ll k = (ll)ceil((rt-1.0L)/2.0L);
            ll L = 2LL*k;
            ll m = (2LL*k+1)*(2LL*k+1);
            ll d = m-N;
            if(d < L) {
                R = -k;
                C = k-d;
            }
            else if(d < 2*L) {
                R = -k+(d-L);
                C = -k;
            }
            else if(d < 3*L) {
                R = k;
                C = -k+(d-2*L);
            }
            else {
                R = k-(d-3*L);
                C = k;
            }
        }
        cout<<"("<<R<<","<<C<<")"<<"\n";
    }
    return 0;
}