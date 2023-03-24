#include<bits/stdc++.h>
using namespace std;
const int MAX = 51;
char arr[MAX][MAX];
int N,ans;
void check() {
    for(int i=0;i<N;i++) {
        int cnt = 1;
        for(int j=0;j<N;j++) {
            if(arr[i][j] == arr[i][j+1]) {
                cnt++;
            }
            else {
                if(ans < cnt) {
                    ans = cnt;
                }
                cnt = 1;
            }
        }
    }
    for(int j=0;j<N;j++) {
        int cnt = 1;
        for(int i=0;i<N;i++) {
            if(arr[i][j] == arr[i+1][j]) {
                cnt++;
            }
            else {
                if(ans < cnt) {
                    ans = cnt;
                }
                cnt = 1;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        string str;
        cin>>str;
        for(int j=0;j<N;j++) {
            arr[i][j] = str[j];
        }
    }
    ans = 0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N-1;j++) {
            swap(arr[i][j],arr[i][j+1]);
            check();
            swap(arr[i][j],arr[i][j+1]);
        }
    }
    for(int j=0;j<N;j++) {
        for(int i=0;i<N-1;i++) {
            swap(arr[i][j],arr[i+1][j]);
            check();
            swap(arr[i][j],arr[i+1][j]);
        }
    }
    cout<<ans<<"\n";
    return 0;
}