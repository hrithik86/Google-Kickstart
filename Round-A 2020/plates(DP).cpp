/*
Google kickstart Round A 2020
Plates - DP solution (Memoization)
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll takePlates(vector<vector<ll>>v,ll i, ll p,ll **dp){
    
    if(p<=0 || i>=v.size()) return 0;
    if(dp[i][p]!=INT_MIN){
        return dp[i][p];
    }
    for(ll j=0;j<v[i].size();j++){
        if(p-j>=0){
            if(dp[i+1][p-j]==INT_MIN){
                dp[i+1][p-j]=takePlates(v,i+1,p-j,dp);
            }
            ll sum=v[i][j]+dp[i+1][p-j];
            if(sum>dp[i][p]){
                dp[i][p]=sum;
            }
        }   
    }
    return dp[i][p];
}

int main() {
    ll T;
    cin>>T;
    for(ll t=1;t<=T;t++){
        ll n,m,p;
        cin>>n>>m>>p;
        vector<vector<ll> > vec( n);
        for(ll i=0;i<n;i++){
            vec[i].push_back(0);
            for(ll j=0;j<m;j++){
                ll x;
                cin>>x;
                vec[i].push_back(x);
            }
        }
        for(ll i=0;i<n;i++){
            for(ll j=1;j<=m;j++){
                vec[i][j]=vec[i][j]+vec[i][j-1];
            }
        }
        ll **dp=new ll*[n+1];
        for(ll i=0;i<n+1;i++){
            dp[i]=new ll[p+1];
            for(ll j=0;j<p+1;j++){
                dp[i][j]=INT_MIN;
            }
        }
        cout<<"Case #"<<t<<": "<<takePlates(vec,0,p,dp)<<"\n";
    }
    return 0;
}
