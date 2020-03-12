#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin>>N;
    int A[MAX] = {0};
    for(int i=0;i<N;i++) cin>>A[i];
    int B,C;
    cin>>B>>C;
    long long ans = 0;
    for(int i=0;i<N;i++) {
        A[i]-=B;
        ans++;
        if(A[i]>0) {
            ans+=(A[i]/C);
            if(A[i]%C!=0) ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}