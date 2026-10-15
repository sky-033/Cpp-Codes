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

void solve(){
    lli n,k;
    cin>>n>>k;
    vll a(n);
    map<lli,vll> mp;
    f(i,n){
        cin>>a[i];
        lli val=a[i]%k;
        mp[val].push_back(a[i]);
    }
    lli ct=0;
    fa(mp){
        if(it.second.size()%2!=0){
            ct++;
        }
    }
    if(n%2==0 && ct!=0){
        cout<<-1<<endl;
        return;
    }
    if(n%2==1 && ct>1){
        cout<<-1<<endl;
        return;
    }
    lli ans=0;
    if(n%2==0){
        fa(mp){
            vll temp=it.second;
            sort(all(temp));
            lli m=it.second.size();
            ff(0,m,2){
                ans+=(temp[i+1]-temp[i])/k;
            }
        }
    }
    else{
        // cout<<"FUCK"<<endl;
        fa(mp){
            vll temp=it.second;
            sort(all(temp));
            lli m=it.second.size();
            if(m&1){
                lli siz=m/2;
                if(siz==0) continue;
                vll prefix(siz+1,0),suffix(siz+1,0);
                ff(0,siz,1){
                    prefix[i+1]=prefix[i]+(temp[2*i+1]-temp[2*i])/k;
                }
                ff(0,siz,1){
                    suffix[i+1]=suffix[i]+(temp[m-1-2*i]-temp[m-1-2*i-1])/k;
                }
                lli toAdd=1e18;
                ff(0,siz+1,1){
                    lli cost=prefix[i]+suffix[siz-i];
                    toAdd=min(toAdd,cost);
                }
                ans+=toAdd;
            }
            else{
                ff(0,m,2){
                    ans+=(temp[i+1]-temp[i])/k;
                }
            }
        }
    }
     cout<<ans<<endl;
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