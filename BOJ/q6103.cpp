#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 25001;
ll M[MAX_N];
ll B[MAX_N];
ll N,X,Y,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>X>>Y;
    for(int i=0;i<N;i++) {
        cin>>M[i]>>B[i];
    }
    sort(M,M+N);
    sort(B,B+N);
    ans = 0;
    for(int i=0;i<N;i++) {
        if(M[i] <= B[i]) {
            ans+=(B[i]-M[i])*X;
        }
        else {
            ans+=(M[i]-B[i])*Y;
        }
    }
    cout<<ans<<"\n";
    return 0;
}