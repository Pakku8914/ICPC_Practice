#include <iostream>
using namespace std;

#define MAX_N 1000
// 日数
int n;
// データセット
int v[MAX_N];
// カウント用変数
int cnt = 0;

void solve() {
    for (int i = 2; i <= n; i++) {
        // 前日と翌日より該当日の人数が多い場合
        if (max(v[i - 1], v[i]) == max(v[i], v[i + 1])) {
            cnt++;
            i++;
        }
    }
}

int main()
{
    //データ代入
    cin >> n;
    v[0], v[1] = 0;
    for (int i = 2; i <= n; i++) {
        cin >> v[i];
    }

    solve();

    cout << cnt << endl;

    return 0;
}
