#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int x[n+2];
    int f[n+1];
    for(int i = 0; i <= n+1; i++) x[i] = 0;
    for(int i = 0; i <= n; i++) f[i] = 0;
    for(int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        x[a]++;
        x[b+1]--;
    }

    int add = 0;
    for(int i = 1; i <= n; i++)
    {
        add+=x[i];
        f[i]+=add;
    }

    sort(f, f+n);
    cout << f[(n+1)/2-1];

    return 0;
}
