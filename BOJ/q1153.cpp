#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e6+1;
int arr[4];
bool p[MAX];
int N;
void eratosthenes() {
    fill(p,p+MAX,true);
    p[0] = p[1] = false;
    for(int i=2;i*i<MAX;i++) {
        if(p[i]) {
            for(int j=2;i*j<MAX;j++) {
                p[i*j] = false;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    eratosthenes();
    cin>>N;
    if(N < 8) {
        cout<<-1<<"\n";
    }
    else {
        if(N%2) {
            N-=5;
            arr[0] = 2;
            arr[1] = 3;
        }
        else {
            N-=4;
            arr[0] = 2;
            arr[1] = 2;
        }
        for(int i=2;i<=N/2;i++) {
            if(p[i] && p[N-i]) {
                arr[2] = i;
                arr[3] = N-i;
                break;
            }
        }
        for(int i=0;i<4;i++) {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}