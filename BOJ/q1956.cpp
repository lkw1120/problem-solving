#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int arr[401][401];
int V,E,A,B,ans;
void preload() {
    for(int i=0;i<401;i++) {
        for(int j=0;j<401;j++) {
            if(i == j) continue;
            arr[i][j] = INF;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    preload();
    cin>>V>>E;
    for(int i=0;i<E;i++) {
        cin>>A>>B;
        cin>>arr[A][B];
    }
    for(int j=1;j<=V;j++) {
        for(int i=1;i<=V;i++) {
            for(int k=1;k<=V;k++) {
                if(i == j || j == k || k == i) continue;
                if(arr[i][j] + arr[j][k] < arr[i][k]) {
                    arr[i][k] = arr[i][j] + arr[j][k];
                }
            }
        }
    }
    ans = INF;
    for(int i=1;i<=V;i++) {
        for(int j=1;j<=V;j++) {
            if(i == j) continue;
            if(arr[i][j] != INF && arr[j][i] != INF) {
                ans = min(ans,arr[i][j]+arr[j][i]);
            }
        }
    }
    if(ans == INF) {
        ans = -1;
    }
    cout<<ans<<"\n";
    return 0;
}