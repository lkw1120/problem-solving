#include<bits/stdc++.h>
using namespace std;
int arr[3][101];
int N,A,B,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<3;i++) {
        cin>>A;
        for(int j=-2;j<=2;j++) {
            arr[i][(N+A+j)%N]++;
        }
    }
    for(int i=0;i<3;i++) {
        cin>>B;
        for(int j=-2;j<=2;j++) {
            arr[i][(N+B+j)%N]++;
        }
    }
    if(5 <= N) {
        ans = 250;
        int tmp = 1;
        for(int i=0;i<3;i++) {
            int cnt = 0;
            for(int j=0;j<N;j++) {
                if(arr[i][j] == 2) {
                    cnt++;
                }
            }
            tmp*=cnt;
        }
        ans-=tmp;
    }
    else {
        ans = N*N*N;
    }
    cout<<ans<<"\n";
    return 0;
}