#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int arr[101][101] = {0};
int N,W,P,A,B,C,ans;
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
    cin>>N>>W>>P;
    for(int i=0;i<W;i++) {
        cin>>A>>B>>C;
        arr[A][B] = arr[B][A] = C;
    }
    for(int j=1;j<=N;j++) {
        for(int i=1;i<=N;i++) {
            for(int k=1;k<=N;k++) {
                if(i == j || j == k || i == k) continue;
                if(arr[i][j] + arr[j][k] < arr[i][k]) {
                    arr[i][k] = arr[i][j] + arr[j][k];
                }
            }
        }
    }
    for(int i=0;i<P;i++) {
        cin>>A>>B;
        cout<<arr[A][B]<<"\n";
    }
    return 0;
}