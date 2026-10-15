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
        vll ans(n+1);
        ans[0]=1,ans[n]=1;
        sor(a);
        vll extra(n+2,0),hsh(n+2,0),prefixSum(n+2,0);
        f(i,n){
            hsh[a[i]]++;
        }
        lli ct=0;
        ff(0,n+2,1){
            if(hsh[i]>1) ct=ct+(hsh[i]-1);
            extra[i]=ct;
        }
        prefixSum[0]=hsh[0];
        ff(1,n+2,1) prefixSum[i]=hsh[i]+prefixSum[i-1];
        vp ind;
        ff(0,n+2,1){
            if(hsh[i]!=0){
                lli mini=max(1LL,hsh[i]);
                lli maxi=min(n-1,prefixSum[n+1]-prefixSum[i]+hsh[i]+(i-1>=0? extra[i-1]:0));
                ind.push_back({mini,maxi});
            }
            else{
                lli mini=max(1LL,hsh[i]);
                lli maxi=min(n-1,prefixSum[n+1]-prefixSum[i]+hsh[i]+(i-1>=0? extra[i-1]:0));
                ind.push_back({mini,maxi});
                break;
            }
        }
        // ff(0,n+2,1) cout<<extra[i]<<" ";
        vll left(n+2,0),right(n+2,0);
        vll hshL(n+2,0),hshR(n+2,0);
        // fa(ind) cout<<it.first<<" "<<it.second<<endl;
        fa(ind){
            hshL[it.first]++;
            hshR[it.second]++;
        }
        left[1]=hshL[1];
        ff(2,n,1){
            left[i]=left[i-1]+hshL[i];
        }
        right[n-1]=hshR[n-1];
        for(lli i=n-2;i>=0;i--){
            right[i]=right[i+1]+hshR[i];
        }
        ff(1,n,1){
            ans[i]=min(left[i],right[i]);
        }
        ff(0,n+1,1) cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}