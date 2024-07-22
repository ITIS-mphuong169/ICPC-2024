//
// Created by Macbook on 23/07/2024.
//
// J: PHAN TU NHO NHAT CUA DAY CON

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <string>
#include <iomanip>
#include<sstream>
#include <queue>
#include<math.h>
#include<string.h>
#include <fstream>
#include<stack>
#include<limits>


using namespace std;

using ll = long long;


vector<int> SlidingWindow(const vector<int> &a)
{
    int n = a.size();
    vector<int> left(n), right(n), result(n);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && a[s.top()] >= a[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            left[i] = -1;
        }
        else
        {
            left[i] = s.top();
        }
        s.push(i);
    }
    while (!s.empty())
    {
        s.pop();
    }
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && a[s.top()] >= a[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            right[i] = n;
        } else
        {
            right[i] = s.top();
        }
        s.push(i);
    }
    vector<int> b(n, -1e9);
    for (int i = 0; i < n; i++)
    {
        int length = right[i] - left[i] - 1;
        b[length - 1] = max(b[length - 1], a[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        b[i] = max(b[i], b[i + 1]);
    }
    return b;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> result = SlidingWindow(a);
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}