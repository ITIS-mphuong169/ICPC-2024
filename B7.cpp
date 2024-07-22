//
// Created by Macbook on 23/07/2024.
//
// G: HOAN VI

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

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long sum = 0;
    if (n >= 2)
    {
        for (int i = 1; i <= n - 1; i++)
        {
            sum += i;
        }
    }
    else
        sum = 0;
    cout << sum << endl;
}