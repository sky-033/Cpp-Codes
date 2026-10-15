#include<bits/stdc++.h>
using namespace std;
typedef long long int lli; 
int main(){
    
    
        lli N,D;
        cin>>N>>D;
        vector<lli> P(N);
        for(int i=0;i<N;i++){
            cin>>P[i];
        }
        sort(P.begin(),P.end());
        lli low=0,high=N-1,ct=0;
        while(low<=high){
            int c=D/P[high]+1;
            high--;
            low+=(c-1);
            if(c<=N) ct++;
            N-=c;
        }
        cout<<ct<<endl;
    
    return 0;
}