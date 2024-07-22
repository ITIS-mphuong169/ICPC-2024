//
// Created by Macbook on 23/07/2024.
//
// A: DOI CHO KY TU

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
    string s;
    cin >> s;
    int m;
    cin >> m;
    vector<int> v(m);
    for (int i = 0; i < m; i++)
    {
        cin >> v[i];
    }
    int n = s.size();
    vector<int> cnt(n / 2, 0);
    // Đếm số lần mỗi vị trí cần được đảo ngược
    for (int i = 0; i < m; i++)
    {
        int ai = v[i];
        cnt[ai - 1]++;
    }
    // Tính tổng số lần đảo ngược cho từng vị trí từ đầu đến giữa
    for (int i = 1; i < n / 2; i++)
    {
        cnt[i] += cnt[i - 1];
    }
    // Thực hiện đảo ngược dựa trên tổng số lần
    for (int i = 0; i < n / 2; i++)
    {
        if (cnt[i] % 2 != 0)
        {
            swap(s[i], s[n - i - 1]);
        }
    }
    cout << s << endl;
}
