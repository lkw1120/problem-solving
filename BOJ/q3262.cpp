#include<bits/stdc++.h>
using namespace std;
bool check[101][101];
int A,B,K;
int R,S,P,T,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fill(&check[0][0],&check[100][101],true);
    cin>>A>>B>>K;
    while(K--) {
        cin>>R>>S>>P>>T;
        int half = (P-1)/2;
        int top = max(1,R-half);
        int bottom = min(A,R+half);
        int left = max(1,S-half);
        int right = min(B,S+half);
        if(T == 1) {
            for(int i=1;i<=A;i++) {
                for(int j=1;j<=B;j++) {
                    if(check[i][j] && (i < top || bottom < i || j < left || right < j)) {
                        check[i][j] = false;
                    }
                }
            }
        }
        else {  
            for(int i=top;i<=bottom;i++) {
                for(int j=left;j<=right;j++) {
                    check[i][j] = false;
                }
            }
        }
    }
    ans = 0;
    for(int i=1;i<=A;i++) {
        for(int j=1;j<=B;j++) {
            if(check[i][j]) ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}