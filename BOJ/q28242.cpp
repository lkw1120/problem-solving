#include<bits/stdc++.h>
using namespace std;
int N,A,B,C,D;
bool check(int a, int b, int c, int d) {
    return a*d+b*c == N+1;
}
bool factorizable() {
    int a,b,c,d;
    for(int i=1;i<=sqrt(N);i++) {
        if(N%i == 0) {
            a = i;
            c = N/i;
            for(int j=1;j<=sqrt(N+2);j++) {
                if((N+2)%j == 0) {
                    b = -j;
                    d = (N+2)/j;
                    if(check(a,b,c,d)) {
                        A = a,B = b,C = c,D = d;
                        return true;
                    }
                    if(check(a,-b,c,-d)) {
                        A = a,B = -b,C = c,D = -d;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    if(factorizable()) {
        cout<<A<<" "<<B<<" "<<C<<" "<<D<<"\n";
    }
    else {
        cout<<-1<<"\n";
    }
    return 0;
}