//
// Created by Jinyu Zhu on 2021/8/8.
//

#include "bits/stdc++.h"
using namespace std;

int run() {

    int n, m;
    cin >> n;
    cin >> m;

    // 从m开始，向前走
    int step = 0;
    queue<int> q;
    q.push(m);

    map<int, int> stepMap;

    while (!q.empty()) {
        step++;
        int cnt = q.size();

        for (int i = 0; i < cnt; i++) {
            // pop一个
            int todo = q.front();
            q.pop();
            // 尝试
            for (int j = max(n, todo / 2 - 1); j < todo - 1; j++) {
                if (j > (todo - j) && j % (todo - j) == 0
                    && stepMap.find(j) == stepMap.end()) {
                    stepMap[j] = step;
                    if (j == n) return step;
                    q.push(j);
                }
            }
        }

    }
    return -1;

}

int main() {
    cout << run();
}