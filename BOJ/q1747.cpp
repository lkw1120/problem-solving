#include<bits/stdc++.h>
#define MAX 2000001
using namespace std;
bool isPrime[MAX];
int N,ans;
int main() {
    ios_base::sync_with_stdio(false);
    fill(isPrime,isPrime+MAX,true);
    isPrime[0] = isPrime[1] = false;
    for(int i=2;i*i<MAX;i++) {
        for(int j=2;j*i<MAX;j++) {
            isPrime[i*j] = false;
        }
    }
    cin>>N;
    for(int i=N;i<MAX;i++) {
        if(isPrime[i]) {
            string str = to_string(i);
            int size = str.size();
            bool isPalindrome = true;
            for(int i=0;i<size;i++) {
                if(str[i] != str[size-i-1]) {
                    isPalindrome = false;
                    break;
                }
            }
            if(isPalindrome) {
                ans = i;
                break;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}