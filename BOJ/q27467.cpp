#include<bits/stdc++.h>
using namespace std;
double p,q;
int N,A;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    p = q = 0;
    while(N--) {
        cin>>A;
        if(3 < A) {
            A%=3;
        }
        if(A == 1) {
            p++;
        }
        else if(A == 2) {
            p--,q--;
        }
        else {
            q++;
        }
    }
    cout.precision(10);
    cout<<fixed;
    cout<<p<<" "<<q<<"\n";
    return 0;
    
}