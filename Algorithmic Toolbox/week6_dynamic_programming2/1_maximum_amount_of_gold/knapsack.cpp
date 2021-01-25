#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long w, n, i, j;
    cin>>w>>n;
    vector<vector<long long> > arr( n+1 , vector<long long> (w+1));
    vector<long long>weight(n+1);
    for( i=1; i<n+1; i++)
        cin>>weight[i];
    for( i=0; i<n+1; i++)
    {
        for( j=0; j<w+1; j++)
        {
            if( i==0 || j==0)
            {
                arr[i][j]=0;
            }
            else
            {
                if(weight[i] <= j)
                {
                    if(arr[i-1][j] > (weight[i]+arr[i-1][j-weight[i]]))
                        arr[i][j] = arr[i-1][j];
                    else
                        arr[i][j] = weight[i]+arr[i-1][j-weight[i]];
                }
                else
                    arr[i][j] = arr[i-1][j];
            }
        }
    }
    cout<<arr[n][w]<<endl;
}