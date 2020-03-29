#include<bits/stdc++.h>
#define MAX 1001
using namespace std;
int matrix[MAX][MAX] = {0};
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        string str;
        cin>>str;
        for(int j=1;j<=M;j++) {
            matrix[i][j] = str[j-1]-'0';
        }
    }
    ans = 0;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            if(matrix[i][j] == 1) {
                matrix[i][j]+=min(min(matrix[i-1][j],matrix[i][j-1]),matrix[i-1][j-1]);
            }
            ans = max(ans,matrix[i][j]);
        }
    }
    cout<<ans*ans<<"\n";
    return 0;
}