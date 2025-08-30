#include <bits/stdc++.h>
using namespace std;
int arr[251][251];
int prefix[251][251];
int N,R;
int sum(int x1, int y1, int x2, int y2) {
    if(x2 < x1 || y2 < y1) return 0;
    return prefix[x2][y2]-prefix[x1-1][y2]-prefix[x2][y1-1]+prefix[x1-1][y1-1];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>R;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cin>>arr[i][j];
        }
    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            prefix[i][j] = arr[i][j]+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
        }
    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            int x1 = max(1,i-R);
            int y1 = max(1,j-R);
            int x2 = min(N,i+R);
            int y2 = min(N,j+R);
            int w = sum(x1,y1,x2,y2);
            cout<<w<<" ";
        }
        cout<<"\n";
    }
    return 0;
}