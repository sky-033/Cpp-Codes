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
#define sor(x) sort(all(x))
#define setbits(x) __builtin_popcountll(x)
#define bitlen(x) 64-__builtin_clzll(x)
const lli N=2e5+10;
const lli M=1e9+7; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,k;
        cin>>n>>k;
        vll a(n),s(n);
        f(i,n){
            cin>>a[i];
            s[i]=a[i];
        }
        sor(s);
        bool flag=true;
        lli val=s[k-1];
        vll palindrome;
        f(i,n){
            if(a[i]<=val) palindrome.push_back(a[i]);
        }
        lli l=0,h=palindrome.size()-1;
        lli canBeDel=palindrome.size()-(k-1);
        while(l<h){
            if(palindrome[l]!=palindrome[h]){
                if(palindrome[l]==val){
                    l++;
                    canBeDel--;
                }
                else if(palindrome[h]==val){
                    h--;
                    canBeDel--;
                }
                else{
                    flag=false;
                    break;
                }
            }
            else{
                l++,h--;
            }
        }
        if(flag && canBeDel>=0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}