#include<bits/stdc++.h>
using namespace std;
int arr[5][5];
int K,X,Y,cnt;
bool check(int x, int y, int s) {
    for(int i=x;i<x+s;i++) {
        for(int j=y;j<y+s;j++) {
            if(arr[i][j]) return false;
        }
    }
    return true;
}
void tiling(int x, int y, int k) {
    cnt++;
    int s = k/2;
    if(check(x,y,s)) arr[x+s-1][y+s-1] = cnt;
    if(check(x+s,y,s)) arr[x+s][y+s-1] = cnt;
    if(check(x,y+s,s)) arr[x+s-1][y+s] = cnt;
    if(check(x+s,y+s,s)) arr[x+s][y+s] = cnt;
    if(k == 2) return ;
    tiling(x,y,s);
    tiling(x+s,y,s);
    tiling(x,y+s,s);
    tiling(x+s,y+s,s);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>K;
    cin>>X>>Y;
    K = 1<<K;
    arr[X][Y] = -1;
    tiling(1,1,K);
    for(int j=K;j>0;j--) {
        for(int i=1;i<=K;i++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}