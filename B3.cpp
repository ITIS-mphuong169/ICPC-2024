//
// Created by Macbook on 23/07/2024.
//
// C: BAI TOAN N QUAN HAU

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

int n, x[100], cot[100], cheo1[100], cheo2[100], cnt = 0;
void Try(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (!cot[j] && !cheo1[i + j] && !cheo2[i - j + n])
        {
            x[i] = j;
            cot[j] = 1;
            cheo1[i + j] = 1;
            cheo2[i - j + n] = 1;
            if (i == n)
            {
                cnt++;
            }
            else
            {
                Try(i + 1);
            }
            cot[j] = 0;
            cheo1[i + j] = 0;
            cheo2[i - j + n] = 0;
        }
    }
}
int main()
{
    cin >> n;
    Try(1);
    cout << cnt << endl;
}