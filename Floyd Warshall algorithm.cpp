#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define vec vector
#define inf (ll)1e9

vec<vec<ll > > solve(vec<vec<ll > > cost)
{
    ll n=cost.size()-1;
    vec<vec<ll > > dp=cost;

    for(ll k=1;k<n+1;k++)
    {
        for(ll i=1;i<n+1;i++)
        {
            for(ll j=1;j<n+1;j++)
            {
                if(dp[i][j]>dp[i][k]+dp[k][j])
                {
                    dp[i][j]=dp[i][k]+dp[k][j];
                }
            }
        }
    }

    return dp;

}

int main()
{
    ll n;

    cout<<"Enter the number of nodes: ";
    cin>>n;

    vec<vec<ll > > cost(n+1,vec<ll> (n+1));

    cout<<"Enter table containing costs of each node and enter -1 as infinity: "<<endl;

    for(ll i=1;i<n+1;i++)
    for(ll j=1;j<n+1;j++)
    {
        cin>>cost[i][j];
        if(cost[i][j]==-1)
        cost[i][j] = inf;
        if(i==j)
        cost[i][j]=0;
    }

    vec<vec<ll > > p=solve(cost);

    cout<<"The cost table accordin to Floyd Warshall Algorithm is: "<<endl;

    for(ll i=1;i<n+1;i++)
    {
        for(ll j=1;j<n+1;j++)
        cout<<p[i][j]<<' ';
        cout<<endl;
    }

}
