#include <bits/stdc++.h>

using namespace std;
int n;
long long c[1000][1000];

int main()
{
    cin>>n;
    for(int i=0; i<=n; i++)
    {
        c[i][0]=1;
        for(int j=1; j<=i; j++)
        {
            c[i][j]=c[i-1][j-1]+c[i-1][j];
        }
    }

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            cout<<c[i][j]<<' ';
        }
        cout<<'\n';
    }


    return 0;
}
