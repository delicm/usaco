#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, k; cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    int dist = 0;
    for(int i = 0; i < n; i++)
    {
        while(a[i]+k >= a[i+dist] && i+dist < n) dist++;
        a[i]=dist;
        dist--;
    }

    return 0;
}
