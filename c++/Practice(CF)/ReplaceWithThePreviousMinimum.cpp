#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
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
        string s;
        cin>>s;
        lli indx=-1,maxi=-1;
        if(k<s[0]-'a'){
            char minic=s[0]-k;
            char maxic=s[0];
            f(i,n){
                if(s[i]<=maxic && s[i]>=minic){
                    s[i]=minic;
                }
            }
        }
        else{
            f(i,n){
                lli val=s[i]-'a';
                if(k-val>=0){
                    maxi=max(maxi,val);
                }
                else{
                    k-=maxi;
                    indx=i;
                    break;
                }
            }
            char maxic='a'+maxi;
            f(i,n){
                if(s[i]<=maxic) s[i]='a';
            }
            if(indx!=-1){
                // cout<<k<<" ";
                char chotu=s[indx]-k;
                char thres=s[indx];
                for(lli i=0;i<n;i++){
                    if(s[i]<=thres && s[i]>=chotu) s[i]=chotu;
                }
            }
        }
        cout<<s<<'\n';
    }
    return 0;
}