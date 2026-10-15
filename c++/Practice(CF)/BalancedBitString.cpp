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
        vector<vector<char>> v(k);
        lli ct1=0,ct0=0;
        for(lli i=0;i<k;i++){
            for(lli j=i;j<n;j+=k){
                v[i].push_back(s[j]);
            }
        }
        bool flag1=false,flag0=false;
        for(auto it:v){
            flag1=false;
            flag0=false;
            for(auto val:it){
                if(val=='1') flag1=true;
                else if(val=='0') flag0=true;
                if(flag1 && flag0) break;
            }
            if(flag1 && flag0) break;

            if(flag1) ct1++;
            else if(flag0) ct0++;
        }
        if(flag1 && flag0) cout<<"NO"<<endl;
        else{
            lli left=k-(ct0+ct1);
            lli diff=abs(ct0-ct1);
            if(left>=diff){
                left-=diff;
                if(left%2) cout<<"NO"<<endl;
                else cout<<"YES"<<endl;
            }
            else{
                if(diff==0) cout<<"YES<"<<endl;
                else cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}