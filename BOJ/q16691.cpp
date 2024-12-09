#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,M,X,S1,S2;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    X = N+1;
    M = X+1;
    while(1) {
        S1 = ((X-1)-N+1)*(N+X-1)/2;
        S2 = (M-(X+1)+1)*(X+1+M)/2;
        if(S1 == S2) {
            break;
        }
        else if(S1 < S2) {
            X++;
        }
        else if(S2 < S1) {
            M++;
        }
    }
    cout<<N<<" "<<X<<" "<<M<<"\n";
    return 0;
}