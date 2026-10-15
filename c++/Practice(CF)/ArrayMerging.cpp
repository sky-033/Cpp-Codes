#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fa(v) for (auto &it : v) 
const lli N=4e5+10; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        vll a(n),b(n);
        map<lli,lli> mpp,mpp1,ans;
        f(i,n) cin>>a[i];
        f(i,n) cin>>b[i];
        lli l=0,h=0;
        while(h<n){
            if(a[l]==a[h]){
                h++;
            }
            else{
                l=h;
                h++;
            }
            mpp[a[l]]=max(mpp[a[l]],h-l);
        }
        
        lli i=0,j=0;
        while(j<n){
            if(b[i]==b[j]){
                j++;
            }
            else{
                i=j;
                j++;
            }
            mpp1[b[i]]=max(j-i,mpp1[b[i]]);
        }
        fa(mpp){
            ans[it.first]=it.second;
        }
        fa(mpp1){
            ans[it.first]+=it.second;
        }
        lli maxi=0;
        fa(ans){
            maxi=max(maxi,it.second);
        }
        cout<<maxi<<endl;

    }
    return 0;
}