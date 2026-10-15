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
pair<string,string>findMaxZeros(const string&s){
    string max1="";
    string max2="";
    int n=s.length();
    int i=0;
    while (i<n){
        if(s[i]=='0'){
            int j=i;
            while(j<n && s[j]=='0'){
                j++;
            }
            int len=j-i;
            string current=s.substr(i,len);

            if(len>max1.length()){
                max2=max1;
                max1=current;
            }else if(len>max2.length() && current!=max1){
                max2=current;
            }
            i=j;
        }else{
            i++;
        }
    }
    return {max1, max2};
}
pair<string,string>findMaxOnes(const string&s){
    string max1="";
    string max2="";
    int n=s.length();
    int i=0;
    while (i<n){
        if(s[i]=='1'){
            int j=i;
            while(j<n && s[j]=='1'){
                j++;
            }
            int len=j-i;
            string current=s.substr(i,len);

            if(len>max1.length()){
                max2=max1;
                max1=current;
            }else if(len>max2.length() && current!=max1){
                max2=current;
            }
            i=j;
        }else{
            i++;
        }
    }
    return {max1, max2};
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        string s;
        cin>>s;
        auto zeroes=findMaxZeros(s);
        auto ones=findMaxOnes(s);
        lli a=zeroes.first.size()+zeroes.second.size();
        lli b=ones.first.size()+ones.second.size();
        if(a>b){
            
        }
        else{
            lli l1=0,h1=0,size1=0;
            while(h1<n){
                if(s[h1]=='1'){
                    size1=h1-l1+1;
                    h1++;
                    if(size1==ones.first.size()){
                        h1--;
                        break;
                    }
                }
                else{
                    l1=h1;
                    h1++;
                }
            }
            lli l2=0,h2=0,size2=0;
            while(h2<n){
                if(s[h2]=='1'){
                    size2=h2-l2+1;
                    h2++;
                    if(size2==ones.second.size()){
                        h2--;
                        break;
                    }
                }
                else{
                    l2=h2;
                    h2++;
                }
                
            }
        }
        
    }
    return 0;
}