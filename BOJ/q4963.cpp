#include<bits/stdc++.h>
#define MAX 51
using namespace std;
int matrix[MAX][MAX];
int dpW[8] = {1,1,0,-1,-1,-1,0,1};
int dpH[8] = {0,1,1,1,0,-1,-1,-1};
int W, H, ans;
void isle(int h, int w) {
    if(matrix[h][w]==0) return ;
    matrix[h][w] = 0;
    for(int i=0;i<8;i++) {
        if(dpW[i]+w <= W && dpW[i]+w > 0 && dpH[i]+h <= H && dpH[i]+h > 0) {
            isle(dpH[i]+h,dpW[i]+w);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    while(true) {
        ans = 0;
        cin>>W>>H;
        if(W==0 && H==0) break;
        for(int i=1;i<=H;i++) {
            for(int j=1;j<=W;j++) {
                cin>>matrix[i][j];
            }
        }
        for(int i=1;i<=H;i++) {
            for(int j=1;j<=W;j++) {
                if(matrix[i][j]==1) {
                    isle(i,j);
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}