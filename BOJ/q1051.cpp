#include<bits/stdc++.h>
using namespace std;
char arr[54][54];
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=0;i<N;i++) {
        cin>>arr[i];
    }
    int K = min(N,M);
    ans = 0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            for(int k=0;k<K;k++) {
                if(i-k < 0 || j-k < 0) break;
                if(arr[i][j] == arr[i-k][j] &&
                   arr[i][j] == arr[i][j-k] &&
                   arr[i][j] == arr[i-k][j-k]) {
                    ans = max(ans,(k+1)*(k+1));
                }
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}