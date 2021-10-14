//
// Created by Jinyu Zhu on 2021/9/12.
//

#include "bits/stdc++.h"

using namespace std;

int main() {
    string workStr;
    string gymStr;
    getline(cin, workStr);
    getline(cin, gymStr);

    vector<int> work;
    vector<int> gym;
    int tmp;
    stringstream wss(workStr);
    while (wss >> tmp) {
        work.push_back(tmp);
    }
    stringstream gss(gymStr);
    while (gss >> tmp) {
        gym.push_back(tmp);
    }

    int n = work.size();
    // dp[i][0/1/2] 工作/健身/休息
    vector<vector<int>> dp(n, vector<int>(3, -1));      // -1代表做不到
    // init
    if (work[0]) dp[0][0] = 0;  // 最小休息0天
    if (gym[0]) dp[0][1] = 0;
    dp[0][2] = 1;

    for (int i = 1; i < n; i++) {
        if (work[i]) {
            // 可以工作, 前一天健身 or 休息
            // 休息是一定可以的
            dp[i][0] = dp[i - 1][2];
            // 健身不一定可以
            if (gym[i - 1] && dp[i - 1][1] != -1)
                dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        }

        if (gym[i]) {
            // 可以健身，前一天工作 or 休息
            dp[i][1] = dp[i - 1][2];
            if (work[i - 1] && dp[i - 1][0] != -1)
                dp[i][1] = min(dp[i][1], dp[i - 1][0]);
        }

        // 可以休息
        dp[i][2] = dp[i - 1][2] + 1;
        if (gym[i - 1] && dp[i - 1][1] != -1)
            dp[i][2] = min(dp[i][2], 1 + dp[i - 1][1]);
        if (work[i - 1] && dp[i - 1][0] != -1)
            dp[i][2] = min(dp[i][2], 1 + dp[i - 1][0]);
    }

//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < 3; j++) {
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }

    int m = n;
    for (int i = 0; i < 3; i++) {
        if (dp[n-1][i] != -1) m = min(m, dp[n-1][i]);
    }
    cout << m;
    return 0;

}