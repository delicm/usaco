#include <iostream>
#include <algorithm>

using namespace std;

#define int long long int

bool cmp(pair<int, int> a, pair <int, int> b)
{
    return a.first > b.first;
}

int32_t main()
{
    int n, m, r; cin >> n >> m >> r;

    int c[n];
    pair<int, int> milk[m];
    int neighbor[r];

    for(int i = 0; i < n; i++) cin >> c[i];
    for(int i = 0; i < m; i++) cin >> milk[i].second >> milk[i].first;
    for(int i = 0; i < r; i++) cin >> neighbor[i];

    sort(c, c+n, greater<int>());
    sort(milk, milk+m, cmp);
    sort(neighbor, neighbor+r, greater<int>());

    for(int i = 1; i < r; i++) neighbor[i] += neighbor[i-1];

    int curShop = 0, partial = 0;

    for(int i = 0; i < n; i++)
    {
        int sold = 0, total = c[i];
        int profit = 0;

        while(sold < total)
        {
            if(curShop == n) break;
            if(total-sold >= milk[curShop].second-partial)
            {
                sold+=milk[curShop].second-partial;
                profit+=(milk[curShop].second-partial)*milk[curShop].first;
                partial = 0;
                curShop++;
            }
            else
            {
                profit+=(total-sold)*milk[curShop].first;
                partial = partial + (total-sold);
                sold = total;
            }
        }

        if(i == 0) c[i] = profit;
        else c[i] = profit+c[i-1];
    }

    int sol = 0;

    for(int i = 0; i < n; i++)
    {
        if(n-2-i >= 0 && n-2-i < r) sol = max(sol, c[i]+neighbor[n-2-i]);
    }

    cout << sol;


    /*for(int i = 0; i < n; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < r; i++)
    {
        cout << neighbor[i] << " ";
    }
    */

    return 0;
}
