#include <bits/stdc++.h>
using namespace std;
char arr[103][103];
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            arr[i][j] = '.';
        }
    }
    arr[0][0] = '#';
    for(int j=1;j<N;j++) {
        if((j+1)%2 == 0) {
            arr[0][j] = '#';
        }
    }
    int cnt = 1+N/2;
    int tmp = N-cnt;
    for(int i=2;i<2+tmp;i++) {
        arr[i-1][i-1] = '#';
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cout<<arr[i][j];
        }
        cout<<"\n";
    }
    return 0;
}