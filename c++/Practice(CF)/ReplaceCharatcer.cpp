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

vll fact(11);
void compute(){
    fact[0]=1;
    ff(1,11,1){
        fact[i]=i*fact[i-1];
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    compute();
    while(t--){
        lli n;
        cin>>n;
        string s;
        cin>>s;
        map<char,lli> freq;
        f(i,n) freq[s[i]]++;
        lli mini=1e5,maxi=-1;
        fa(freq){
            mini=min(mini,it.second);
            maxi=max(maxi,it.second);
        }
        char minic,maxic;
        fa(freq){
            if(it.second==maxi) maxic=it.first;
        }
        lli maxii=1e9;
        string ans;
        fa(freq){
            lli val=0;
            string ss=s;
            map<char,lli> temp;
            minic=it.first;
            f(i,n){
                if(ss[i]==minic){
                    ss[i]=maxic;
                    break;
                }
            }
            f(i,n) temp[ss[i]]++;
            val=fact[n];
            for(auto itt:temp){
                val/=fact[itt.second];
            }
            if(val<maxii){
                maxii=val;
                ans=ss;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}