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
    lli n,k1,k2;
    cin>>n>>k1>>k2;
    lli k=k1+k2;
    vll a(n),b(n);
    f(i,n) cin>>a[i];
    f(i,n) cin>>b[i];
    vll diff(n);
    f(i,n) diff[i]=abs(a[i]-b[i]);
    sor(diff);
    vll suff;
    // fa(diff) cout<<it<<" ";
    if(n==1){
        if(k>=diff[0]){
            k-=diff[0];
            k%=2;
            diff[0]=0;
            if(k) diff[0]=1;
        }
        else diff[0]-=k;
    }
    else{
        suff.push_back(diff[n-1]-diff[n-2]);
        for(lli i=n-2;i>=1;i--){
            lli curr=diff[i];
            lli prv=diff[i-1];
            suff.push_back((n-i)*(curr-prv)+suff.back());
        }
        // fa(suff) cout<<it<<" ";
        if(k==suff[n-2]){
            f(i,n) diff[i]=diff[0];
        }
        else if(k>suff[n-2]){
            k-=suff[n-2];
            f(i,n) diff[i]=diff[0];
            lli times=k/n;
            if(times-diff[0]>=0){
                f(i,n) diff[i]=0;
                k-=diff[0]*n;
                k%=2;
                if(k) diff[0]=1;
            }
            else{
                f(i,n) diff[i]-=times;
                k%=n;
                lli h=0;
                while(k>0){
                    diff[h]--;
                    h--;
                    k--;
                }
            }
        }
        else{
            lli indx=-1;
            f(i,n-1){
                if(k>=suff[i]) indx=i+1;
                else break;
            }
            if(indx!=-1){
                k-=suff[indx-1];
                lli val=diff[n-1-indx];
                reverse(all(diff));
                lli times=k/(indx+1);
                f(i,indx+1) diff[i]=val;
                f(i,indx+1) diff[i]-=times;
                k%=(indx+1);
                lli h=0;
                while(k>0){
                    diff[h]--;
                    h++;
                    k--;
                }
            }
            else diff[n-1]-=k;
        }
    }
    lli ans=0;
    reverse(all(diff));
    fa(diff) ans+=(it*it);
    cout<<ans<<endl;
    
    return 0;
}