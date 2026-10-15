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
        vll a;
        while(n>0){
            lli r=n%10;
            a.push_back(r);
            n=n/10;
        }
        lli size=a.size();
        lli a1,a2,a3,a4;
        f(i,size){
            if(a[i]==0){
                a1=i;
                for(lli j=i+1;j<size;j++){
                    if(a[j]==0 || a[j]==5){
                        a2=j;
                        break;
                    }
                }
            }
        }
        f(i,size){
            if(a[i]==5){
                a3=i;
                for(lli j=i+1;j<size;j++){
                    if(a[j]==2 || a[j]==7){
                        a4=j;
                        break;
                    }
                }
            }
        }
        lli ans2=a4-1;
        lli ans1=a2-1;
        cout<<min(ans1,ans2)<<endl;
    }
    return 0;
}