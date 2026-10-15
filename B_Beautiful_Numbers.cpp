#include<bits/stdc++.h>
using namespace std;

#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fa(v) for (auto &it : v) 
#define all(x) (x).begin(), (x).end()
#define setbits(x) __builtin_popcountll(x)
#define bitlen(x) 64-__builtin_clzll(x)
#define yes cout << "YES" << '\n'
#define no cout << "NO" << '\n'
#define endl '\n'
const lli N=2e5+10;
const lli M=1e9+7;

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

vll getDigits(long long n) {
    vll digits;
    if(n == 0) {
        digits.push_back(0);
        return digits;
    }

    n = abs(n);

    while(n > 0) {
        digits.push_back(n % 10);  // last digit
        n /= 10;
    }

    return digits;   // digits stored in reverse order
}
void solve(){
    lli n;
    cin>>n;
    vll digits=getDigits(n);
    sort(all(digits));
    lli len=digits.size();
    lli sum=0;
    string s=to_string(n);
    lli val=-1;
    char t=s[0];
    val=t-'0';
    lli ct=0;
    vll vec1;
    fa(digits){
        if(it==val && ct==0){
            ct++;
        }
        else{
            vec1.push_back(it);
        }
    }
    sum=val;
    debug(vec1,digits);
    lli rem=1;
    fa(vec1){
        if(sum+it<=9){
            sum+=it;
            rem++;
        }
        else break;
    }
    lli ans1=len-rem;
    lli ans2=1;
    sum=1;
    rem=0;
    fa(vec1){
        if(sum+it<=9){
            sum+=it;
            rem++;
        }
        else break;
    }
    cout<<min(len-rem,ans1)<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}