#include<bits/stdc++.h>
using namespace std;
int N,K;
int gcd(int a, int b) {
    return b == 0? a: gcd(b,a%b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    int g = gcd(N,K);
    bool flag = true;
    for(int i=0;i<N;i++) {
        int x;
        cin>>x;
        if((x%g) != (i%g)) {
            flag = false;
            break;
        }
    }
    if(flag) {
        cout<<"YES"<<"\n";
    }
    else {
        cout<<"NO"<<"\n";
    }
    return 0;
}