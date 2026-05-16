#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,T,H,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    T = 0;
    for(int i=0;i<N;i++) {
        cin>>H;
        ll q = H/5;
        T+=q*3;
        H%=5;
        while(H > 0) {
            T++;
            if(T%3 == 0) {
                H-=3;
            }
            else {
                H--;
            }
        }
    }
    ans = T;
    cout<<T<<"\n";
    return 0;
}