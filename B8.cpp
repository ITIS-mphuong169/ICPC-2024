//
// Created by Macbook on 23/07/2024.
//
// H: UOC CHUNG LON NHAT

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int maxA = *max_element(a.begin(), a.end());
        vector<int> freq(maxA + 1, 0);
        for (int i = 0; i < n; i++)
        {
            freq[a[i]]++;
        }
        for (int i = maxA; i >= 1; i--)
        {
            int count = 0;
            for (int j = i; j <= maxA; j += i)
            {
                count += freq[j];
            }
            if (count >= 2)
            {
                cout << i << endl;
                break;
            }
        }
    }
}
