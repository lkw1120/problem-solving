#include<bits/stdc++.h>
using namespace std;
int T,N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        cin>>N;
        int a,b,c,d,e;
        a = b = c = d = e = 0;
        a = N/60;
        N%=60;
        if(N <= 35) {
            b = N/10;
            N%=10;
            if(N <= 5) {
                d = N;
            }
            else {
                b++;
                e = 10-N;
            }
        }
        else {
            a++;
            c = 6-N/10;
            N%=10;
            if(N < 5) {
                d = N;
            }
            else {
                c--;
                e = 10-N;
            }
        }
        cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<"\n";
    }
    return 0;
}
