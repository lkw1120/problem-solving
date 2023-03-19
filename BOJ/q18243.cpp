#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int arr[101][101] = {0};
int N,K,A,B;
string ans;
void preload() {
    for(int i=0;i<101;i++) {
        for(int j=0;j<101;j++) {
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
    cin>>N>>K;
    for(int i=0;i<K;i++) {
        cin>>A>>B;
        arr[A][B] = arr[B][A] = 1;
    }
    for(int j=1;j<=N;j++) {
        for(int i=1;i<=N;i++) {
            for(int k=1;k<=N;k++) {
                if(i == j || j == k || i == k) continue;
                if(arr[i][j]+arr[j][k] < arr[i][k]) {
                    arr[i][k] = arr[i][j]+arr[j][k];
                }
            }
        }
    }
    ans = "Small World!";
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            if(7 <= arr[i][j]) {
                ans = "Big World!"; 
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}