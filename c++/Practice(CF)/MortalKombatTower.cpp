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
        lli n;
        cin>>n;
        vll a(n);
        f(i,n) cin>>a[i];
        queue<pair<lli,lli>> q;
        lli ct=1,prv=a[0];
        ff(1,n,1){
            if(a[i]==prv) ct++;
            else{
                q.push({prv,ct});
                ct=1;
                prv=a[i];
            }
        }
        q.push({prv,ct});
        vp adj;
        while(!q.empty()){
            auto val=q.front();
            q.pop();
            adj.push_back(val);
        }
        lli times=1,skip=0;
        // fa(adj) cout<<it.first<<" "<<it.second<<endl;
        for(auto it=adj.begin();it!=adj.end();){
            lli val=(*it).first;
            lli cnt=(*it).second;
            // cout<<cnt<<" ";
            if(val==0){
                if(times%2) times++;
            }
            else{
                if(cnt==1 && times%2){
                    skip+=1;
                    it++;
                    if(it==adj.end()) break;
                    cnt+=(*it).second;
                    times++;
                }
                else if(times%2){
                    lli x=cnt/3;
                    if(cnt%3!=0) x++;
                    skip+=x;
                    if(cnt%3!=1) times++;
                }
                else{
                    lli x=cnt/3;
                    skip+=x;
                    if(cnt%3!=0) times++;
                }
            }
            // cout<<skip<<" ";
            it++;
        }
        cout<<skip<<endl;
    }
    return 0;
}