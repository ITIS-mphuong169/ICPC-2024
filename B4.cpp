//
// Created by Macbook on 23/07/2024.
//
// D: THANG MAY

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

int solve(int n, int s, int e, int u, int d) {
    if (s == e)
    {
        return 0; // Đã ở tầng đích
    }
    vector<bool> visited(n + 1, false);
    queue<pair<int, int>> q; // (tầng hiện tại, số lần bấm nút)

    q.push({s, 0});
    visited[s] = true;

    while (!q.empty()) {
        int c = q.front().first;
        int step = q.front().second;
        q.pop();

        // Thử bấm nút "UP"
        if (c + u <= n && !visited[c + u])
        {
            if (c + u == e)
            {
                return step + 1;
            }
            q.push({c + u, step + 1});
            visited[c + u] = true;
        }

        // Thử bấm nút "DOWN"
        if (c - d >= 1 && !visited[c - d])
        {
            if (c - d == e) {
                return step + 1;
            }
            q.push({c - d, step + 1});
            visited[c - d] = true;
        }
    }

    return -1; // Không thể đến tầng EN
}

int main()
{
    int n, bd, kt , u, d;
    cin >> n >> bd >> kt >> u >> d;
    int res = solve(n, bd, kt, u, d);
    cout << res << endl;
}
