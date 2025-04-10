#include<bits/stdc++.h>
using namespace std;
int arr[21];
int digits[21][10];
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>arr[i];
    }
    for(int i=0;i<N;i++) {
        int tmp = arr[i];
        for (int j=0;j<10;j++) {
            digits[i][j] = tmp%10;
            tmp/=10;
        }
    }
    int subset = 1<<N;
    ans = 0;
    for(int k=1;k<subset;k++) {
        bool flag = true;
        for(int j=0;j<10 && flag;j++) {
            int sum = 0;
            for(int i=0;i<N;i++) {
                if(k & (1<<i)) {
                    sum+=digits[i][j];
                    if(10 <= sum) {
                        flag = false;
                        break;
                    }
                }
            }
        }
        if(flag) {
            int cnt = 0;
            int tmp = k;
            while(tmp) {
                cnt+=tmp%2;
                tmp/=2;
            }
            ans = max(ans,cnt);
        }
    }
    cout<<ans<<"\n";
    return 0;
}