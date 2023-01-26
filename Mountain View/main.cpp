#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n; cin >> n;
    pair <int, int> m[n];
    pair <int, int> x[n+1];

    for(int i = 0; i < n; i++) cin >> m[i].first >> m[i].second;
    for(int i = 0; i < n; i++)
    {
        x[i].first = m[i].first - m[i].second;
        x[i].second = m[i].first + m[i].second;
    }

    x[n].first = INT_MAX;
    x[n].second = INT_MAX;
    sort(x, x+n);

    int rightMax = x[0].second-1, sol = 0;
    for(int i = 0; i < n; i++)
    {
        while(x[i].first == x[i+1].first) i++;
        if(x[i].second > rightMax)
        {
            sol++;
            rightMax = x[i].second;
        }
    }

    cout << sol;

    return 0;
}
