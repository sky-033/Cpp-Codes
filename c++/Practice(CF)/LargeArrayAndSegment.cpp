#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define ff(i,a,n) for(lli i=a;i<n;i++)
#define fa(v) for (auto &it : v) 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,k,x,sum=0,S=0,sum1=0,ss=0;
        cin>>n>>k>>x;
        vll a(n),prefixsum(n);
        f(i,n){
            cin>>a[i];
            sum+=a[i];
        }
        prefixsum[n-1]=a[n-1];
        for(lli i=n-2;i>=0;i--){
            prefixsum[i]=prefixsum[i+1]+a[i];
        }
        sum1=sum;
        sum*=k;
        lli ans=0;
        bool flag=true;
        if(sum<x) flag=false;
        else{
            ss=x/sum1;
            ss*=n;
            if(x%sum1==0) ss--;
            lli temp=x%sum1;
            if(temp!=0){
                for(lli i=n-1;i>=0;i--){
                    if(prefixsum[i]>=temp){
                        ans=n-i-1;
                        break;
                    }
                }
            }
            
        }
        // if(sum1==x) cout<<1<<endl;
        if(flag==true)  cout<<k*n-ss-ans<<endl;
        else cout<<0<<endl;

    }
    return 0;
}