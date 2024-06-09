#include<bits/stdc++.h>
using namespace std;
int arr[101][102];
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin>>arr[i][j];
        }
    }
    ans = 0;
    for(int i=1;i<=N;i++) {
        int a,b;
        a = b = 0;
        for(int j=1;j<=M+1;j++) {
            if(arr[i][j] == 1 && arr[i][j-1] != 1) {
                a++;
            }
            if(arr[i][j] == 2 && arr[i][j-1] != 2) {
                b++;
            }
            if(arr[i][j] == 0 && (a || b)) {
                ans+=min(a,b)+1;
                a = b = 0;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}