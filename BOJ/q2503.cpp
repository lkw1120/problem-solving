#include <bits/stdc++.h>
using namespace std;
int guess[101][3];
int strike[101];
int ball[101];
int N,ans;
pair<int,int> countSB(int arr[3], int g[3]) {
    int s,b;
    s = b = 0;
    for(int i=0;i<3;i++) {
        if(g[i] == arr[i]) {
            s++;
        } 
        else if(g[i] == arr[(i+1)%3] || g[i] == arr[(i+2)%3]) {
            b++;
        }
    }
    return {s,b};
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        string str;
        cin>>str>>strike[i]>>ball[i];
        for(int j=0;j<3;j++) {
            guess[i][j] = str[j]-'0';
        }
    }
    ans = 0;
    for(int i=1;i<10;i++) {
        for(int j=1;j<10;j++) { 
            if(i != j) {
                for(int k=1;k<10;k++) {
                    if(i != k && j != k) {
                        int arr[3] = {i,j,k};
                        bool valid = true;
                        for(int q=0;q<N;q++) {
                            auto [s,b] = countSB(arr, guess[q]);
                            if(s != strike[q] || b != ball[q]) {
                                valid = false;
                                break;
                            }
                        }
                        if(valid) {
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}