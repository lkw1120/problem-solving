#include<bits/stdc++.h>
using namespace std;
vector<string> v;
string input,ans;
int N,M;
void solve() {
	for(int j=0;j<M;j++) {
		if(v[0].substr(j,3) == "###" &&
		   v[1].substr(j,3) == "#.#" && 
		   v[2].substr(j,3) == "#.#" &&
		   v[3].substr(j,3) == "#.#" && 
		   v[4].substr(j,3) == "###") {
			ans+="0";
			j+=3;
		}
		else if(
			v[0].substr(j,2) == "#." &&
			v[1].substr(j,2) == "#." &&
			v[2].substr(j,2) == "#." &&
			v[3].substr(j,2) == "#." &&
			v[4].substr(j,2) == "#.") {
			ans+="1";
			j++;
		}
		else if(
			v[0].substr(j,3) == "###" &&
			v[1].substr(j,3) == "..#" && 
			v[2].substr(j,3) == "###" &&
			v[3].substr(j,3) == "#.." && 
			v[4].substr(j,3) == "###") {
			ans+="2";
			j+=3;
		}
		else if(
			v[0].substr(j,3) == "###" &&
			v[1].substr(j,3) == "..#" && 
			v[2].substr(j,3) == "###" &&
			v[3].substr(j,3) == "..#" && 
			v[4].substr(j,3) == "###") {
			ans+="3";
			j+=3;
		}
		else if(
			v[0].substr(j,3) == "#.#" &&
			v[1].substr(j,3) == "#.#" && 
			v[2].substr(j,3) == "###" &&
			v[3].substr(j,3) == "..#" && 
			v[4].substr(j,3) == "..#") {
			ans+="4";
			j+=3;
		}
		else if(
			v[0].substr(j,3) == "###" &&
			v[1].substr(j,3) == "#.." && 
			v[2].substr(j,3) == "###" &&
			v[3].substr(j,3) == "..#" && 
			v[4].substr(j,3) == "###") {
			ans+="5";
			j+=3;
		}
		else if(
			v[0].substr(j,3) == "###" &&
			v[1].substr(j,3) == "#.." && 
			v[2].substr(j,3) == "###" &&
			v[3].substr(j,3) == "#.#" && 
			v[4].substr(j,3) == "###") {
			ans+="6";
			j+=3;
		}
		else if(
			v[0].substr(j,3) == "###" &&
			v[1].substr(j,3) == "..#" && 
			v[2].substr(j,3) == "..#" &&
			v[3].substr(j,3) == "..#" && 
			v[4].substr(j,3) == "..#") {
			ans+="7";
			j+=3;
		}
		else if(
			v[0].substr(j,3) == "###" &&
			v[1].substr(j,3) == "#.#" && 
			v[2].substr(j,3) == "###" &&
			v[3].substr(j,3) == "#.#" && 
			v[4].substr(j,3) == "###") {
			ans+="8";
			j+=3;
		}
		else if(
			v[0].substr(j,3) == "###" &&
			v[1].substr(j,3) == "#.#" && 
			v[2].substr(j,3) == "###" &&
			v[3].substr(j,3) == "..#" && 
			v[4].substr(j,3) == "###") {
			ans+="9";
			j+=3;
		}
	}
	
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	cin>>input;
	M = N/5;
	for(int i=0;i<5;i++) {
		v.push_back(input.substr(i*M,M)+".");
	}
	M++;
	ans = "";
	solve();
	cout<<ans<<"\n";
	return 0;
}