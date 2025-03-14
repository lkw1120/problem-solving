#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,N,D,G;
int gcd(int a, int b) {
    return b == 0? a: gcd(b,a%b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>N>>D>>G;
        bool possible = true;
        if((G == 100 && D != 100) || (G == 0 && D != 0)) {
            possible = false;
        }
        int n = 100/gcd(100,D);
        if(n > N) {
            possible = false;
        }
        cout<<"Case #"<<t<<": "<<(possible? "Possible": "Broken")<<"\n";
    }
    return 0;
}