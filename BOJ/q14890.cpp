#include<bits/stdc++.h>
#define MAX 100
using namespace std;
int a[MAX*2][MAX];
int N,L,ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin>>N>>L;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            a[i+N][j] = a[j][i];
        }
    }
    for (int i=0;i<N*2;i++) {
        int c = 1;
        int j = 0;
        for (;j<N-1;j++) {
            if (a[i][j] == a[i][j+1]) c++;
            else if (a[i][j]+1 == a[i][j+1] && c >= L) c = 1;
            else if (a[i][j]-1 == a[i][j+1] && c >= 0) c = -L + 1;
            else break;
        }
        if (j == N-1 && c >= 0) ans++;
    }
    cout<<ans<<"\n";
    return 0;
}