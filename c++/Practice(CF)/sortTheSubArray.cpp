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
        vll a(n),a1(n);
        f(i,n) cin>>a[i];
        f(i,n) cin>>a1[i];
        lli indx1=-1,indx2=-1;
        f(i,n){
            if(a[i]!=a1[i]) indx1=i;
        }
        rf(i,n){
            if(a[i]!=a1[i]) indx2=i;
        }
        lli i=indx1-1,j=indx1;
        while(i>=0){
            if(a1[j]>=a1[i]){
                j--;
                i--;
            }
            else{
                break;
            }
        }
        indx1=j;
        
        lli l=indx2,h=indx2+1;
        while(h<n){
            if(a1[h]>=a1[l]){
                h++;
                l++;
            }
            else break;
        }
        indx2=l;

        cout<<indx1+1<<" "<<indx2+1<<endl;
    }
    return 0;
}