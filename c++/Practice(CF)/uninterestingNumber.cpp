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
const lli N=4e5+10; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int ct2=0,ct3=0,sum=0;
        f(i,s.size()){
            if(s[i]=='2') ct2++;
            else if(s[i]=='3') ct3++;
            sum+=int(s[i]-48);
        }
        sum=sum%9;
        int b1=9-sum,a1=18-sum;
        if(b1==0){
            cout<<"YES"<<endl;
        }
        else if(a1%2==0){
            if(a1==2){
                if(ct2>=1) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            else if(a1==4){
                if(ct2>=2) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            else if(a1==6){
                if(ct2>=3 || ct3>=1) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            else if(a1==8){
                if(ct2>=4 || (ct3>=1 && ct2>=1)) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            else if(a1==10){
                if(ct2>=5 || (ct3>=1 && ct2>=2)) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            else if(a1==12){
                if(ct2>=6 || (ct3>=1 && ct2>=3) || (ct3>=2)) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            else if(a1==14){
                if(ct2>=7 || (ct3>=1 && ct2>=4) || (ct3>=2 && ct2>=1)) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            else if(a1==16){
                if(ct2>=8 || (ct3>=2 && ct2>=2) || (ct3>=1 && ct2>=5)) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
        }
        else{
            if(b1==2){
                if(ct2>=1) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            else if(b1==4){
                if(ct2>=2) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            else if(b1==6){
                if(ct2>=3 || ct3>=1) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            else if(b1==8){
                if(ct2>=4 || (ct3>=1 && ct2>=1)) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}