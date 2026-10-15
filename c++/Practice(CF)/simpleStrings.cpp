#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define g(j,n) for(lli j=0;j<n;j++)
#define h(k,n) for(lli k=0;k<n;k++)
#define rf(i,n) for(lli i=n-1;i>=0;i--)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
#define fa(v) for (auto &it : v) 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsor(x) sort(rall(x))
#define setbits(x) __builtin_popcountll(x)
const lli N=2e5+10;
const lli M=1e9+7; 
bool isValid(lli i,lli n){
    return i>=0 && i<n;
}
vector<char> alph={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin>>s;
    lli n=s.size();
    lli l=0;
    while(l<n-1){
        if(s[l]==s[l+1]){
            char char1='!',char2='!';
            if(isValid(l,n)){
                char1=s[l];
            }
            if(isValid(l+2,n)){
                char2=s[l+2];
            }
            fa(alph){
                if(it!=char1 && it!=char2){
                    s[l+1]=it;
                    break;
                }
            }
        }
        l++;
    }
    cout<<s<<endl;
    return 0;
}