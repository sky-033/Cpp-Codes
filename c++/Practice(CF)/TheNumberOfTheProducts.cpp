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
    lli n;
    cin>>n;
    vll a(n);
    f(i,n) cin>>a[i];
    vll prefix(n,0),ansPos(n,0);
    lli ct=0;
    f(i,n){
        if(a[i]<0) ct++;
        prefix[i]=ct;
    }
    f(i,n){
        if(a[i]<0 && prefix[i]!=1){
            lli indx=lower_bound(all(prefix),prefix[i]-1)-prefix.begin();
            lli indx2=lower_bound(all(prefix),prefix[i]-2)-prefix.begin();
            if(a[indx2]>0 || prefix[i]==2) ansPos[i]=(indx-indx2+1);
            else{
                ansPos[i]=(indx-indx2);
                ansPos[i]+=ansPos[indx2];
            }

        }
    }
    lli l=0,ctpos=0,lastneg=-1;
    while(l<n){
        if(a[l]>0){
            ctpos++;
            if(lastneg!=-1){
                ansPos[l]+=ctpos+ansPos[lastneg];
            }
            else{
                ansPos[l]=ctpos;
            }
        }
        else{
            lastneg=l;
            ctpos=0;
        }
        l++;
    }
    lli positive=0;
    f(i,n) positive+=ansPos[i];

    vll ansNeg(n,0);
    f(i,n){
        if(a[i]<0){
            lli count=upper_bound(all(prefix),prefix[i]-1)-lower_bound(all(prefix),prefix[i]-1);
            lli indx=lower_bound(all(prefix),prefix[i]-2)-prefix.begin();
            if(prefix[i]==1) ansNeg[i]=(count+1);
            else{
                ansNeg[i]=count;
                if(prefix[i]>2) ansNeg[i]+=ansNeg[indx];
            }

        }
    }

    l=0,lastneg=-1;
    while(l<n){
        if(a[l]>0){
            if(lastneg!=-1){
                ansNeg[l]=ansNeg[lastneg];
            }
            else{
                ansNeg[l]=0;
            }
        }
        else{
            lastneg=l;
        }
        l++;
    }

    lli negative=0;
    f(i,n) negative+=ansNeg[i];

    cout<<negative<<" "<<positive<<endl;
    return 0;
}