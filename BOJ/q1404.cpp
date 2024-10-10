#include<bits/stdc++.h>
using namespace std;
double arr[8][8];
double win[8][4];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=0;i<8;i++) {
        for(int j=i+1;j<8;j++) {
            int n;
            cin>>n;
            arr[i][j] = (double)n/100;
            arr[j][i] = 1-arr[i][j];
        }
    }
    // R1
    for(int i=0;i<8;i++) {
        if(i%2) {
            win[i][1] = arr[i][i-1];
        }
        else {
            win[i][1] = arr[i][i+1];
        }
    }
    // R2
    for(int i=0;i<8;i++) {
        if(i%4 == 0) {
            win[i][2]+=win[i][1]*win[i+2][1]*arr[i][i+2];
            win[i][2]+=win[i][1]*win[i+3][1]*arr[i][i+3];
        }
        if(i%4 == 1) {
            win[i][2]+=win[i][1]*win[i+1][1]*arr[i][i+1];
            win[i][2]+=win[i][1]*win[i+2][1]*arr[i][i+2];
        }
        if(i%4 == 2) {
            win[i][2]+=win[i][1]*win[i-2][1]*arr[i][i-2];
            win[i][2]+=win[i][1]*win[i-1][1]*arr[i][i-1];
        }
        if(i%4 == 3) {
            win[i][2]+=win[i][1]*win[i-3][1]*arr[i][i-3];
            win[i][2]+=win[i][1]*win[i-2][1]*arr[i][i-2];
        }
    }
    // R3
    for(int i=0;i<8;i++) {
        if(i < 4) {
            for(int j=0;j<4;j++) {
                win[i][3]+=win[i][2]*win[4+j][2]*arr[i][4+j];
            }
        }
        else {
            for(int j=0;j<4;j++) {
                win[i][3]+=win[i][2]*win[j][2]*arr[i][j];
            }
        }
    }
    cout<<fixed;
    cout.precision(10);
    for(int i=0;i<8;i++) {
        cout<<win[i][3]<<" ";
    }
    cout<<"\n";
    return 0;
}