#include <bits/stdc++.h>

using i64 = long long;

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> in(n + 1), id(n + 1), ans(n + 1);

    for (int i = 1; i <= n; i++) {
        std::cout << "? " << i << " ";
        for (int j = 1; j <= n; j++) {
            std::cout << (i == j ? 0 : 1) << " ";
        }
        std::cout << std::endl;

        std::cin >> in[i];
        in[i] = n - 1 - in[i];
        id[i] = i;
    }

    std::sort(id.begin() + 1, id.begin() + n + 1, [&](int x, int y) {
        return in[x] < in[y];
    });

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += in[id[i]];
        if (sum == i * (i - 1) / 2) {
            for (int j = 1; j <= i; j++) {
                ans[id[j]] = 1;
            }
            break;
        }
    }

    std::cout << "! ";
    for (int i = 1; i <= n; i++) {
        std::cout << ans[i];
    }
    std::cout << std::endl;

    return 0;
}
