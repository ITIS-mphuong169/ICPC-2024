//
// Created by Macbook on 23/07/2024.
//
// I: SO NGUYEN LON
#include <bits/stdc++.h>

using namespace std;

int main() {
    string line;
    const long long intMax = numeric_limits<int>::max();
    long long totalSum = 0;

    while (getline(cin, line)) {
        istringstream stream(line);
        string token;

        while (stream >> token) {
            bool isNumber = true;
            for (char c : token) {
                if (!isdigit(c)) {
                    isNumber = false;
                    break;
                }
            }

            if (isNumber) {
                try {
                    long long number = stoll(token);
                    if (number > intMax) {
                        totalSum += number;
                    }
                } catch (out_of_range& e) {
                }
            }
        }
    }

    cout << totalSum << endl;

    return 0;
}