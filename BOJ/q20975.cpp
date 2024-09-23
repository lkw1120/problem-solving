#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A[21];
ll B[21];
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>A[i];
    }
    for(int i=1;i<=N;i++) {
        cin>>B[i];
    }
    sort(A+1,A+N+1);
    ans = 1;
    for(int i=N;i>=1;i--) {
        int cnt = 0;
        for(int j=1;j<=N;j++) {
            if(A[i] <= B[j]) {
                cnt++;
            }
        }
        ans*=cnt-(N-i);
    }
    cout<<ans<<"\n";
    return 0;
}