#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,N,M,A;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>N>>M>>A;
        cout<<"Case #"<<t<<": ";
        if(N*M < A) {
            cout<<"IMPOSSIBLE"<<"\n";
            continue;
        }
        ll x1,x2,x3,y1,y2,y3;
        x1 = y1 = 0;
        if(A%N == 0 && A/N <= M) {
            x2 = N, y2 = 0;
            x3 = 0, y3 = A/N;
        }
        else if(A%M == 0 && A/M <= N) {
            x2 = 0, y2 = M;
            x3 = A/M, y3 = 0;
        }
        else {
            x2 = N, y2 = 1;
            y3 = (A + N - 1)/N;  
            x3 = y3*N - A;
            if(M < y3 || x3 < 0 || N < x3) {
                x2 = 1, y2 = M;
                x3 = (A + M - 1)/M;
                y3 = M * x3 - A;
                if(N < x3 || y3 < 0 || M < y3) {
                    cout<<"IMPOSSIBLE"<<"\n";
                    continue;
                }
            }
        }
        cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<"\n";
    }
    return 0;
}