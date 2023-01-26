#include <iostream>

using namespace std;

int main()
{
    int n, t; cin >> n >> t;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    int bmax = 0, btemp = 0, ttemp = 0;
    for(int i = 0; i < n; i++)
    {
        while(ttemp < t && btemp+i < n)
        {
            if(ttemp + a[btemp+i] <= t)
            {
                btemp++;
                ttemp+=a[btemp-1+i];
            }
            else break;
        }
        bmax = max(bmax, btemp);
        btemp--;
        ttemp-=a[i];
    }

    cout << bmax;

    return 0;
}
