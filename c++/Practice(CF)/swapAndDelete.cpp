#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define fa(v) for (auto &it : v) 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        lli n=s.size();
        lli ct0=0,ct1=0,indx=-1;
        bool flag=false;
        f(i,n){
            if(s[i]=='0') ct0++;
            else ct1++;
        }
        if(ct0==ct1) cout<<0<<endl;
        else if(ct0>ct1){
            f(i,n){
                if(ct1<=0){
                    indx=i;
                    break;
                }
                if(s[i]=='0') ct1--;
                else ct0--;
            }
            for(lli i=indx;i<n;i++){
                if(indx!=-1){
                    if(s[i]=='1') ct0--;
                    else{
                        flag=false;
                        break;
                    }
                }
            }
            cout<<ct0<<endl;
        }
        else{
            f(i,n){
                if(ct0<=0){
                    indx=i;
                    break;
                }
                if(s[i]=='0') ct1--;
                else ct0--;
            }
            for(lli i=indx;i<n;i++){
                if(indx!=-1){
                    if(s[i]=='0') ct1--;
                    else{
                        flag=false;
                        break;
                    }
                }
            }
            cout<<ct1<<endl;
        }
    }
    return 0;
}