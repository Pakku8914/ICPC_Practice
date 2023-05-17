#include <iostream>
using namespace std;

#define MAX_N 1001
int n;
int c[MAX_N][2];
int cnt = 0;

void solve() {
    // 引いたカードの数字
    int draw = 0;
    // ループ判定用変数
    int circle = 0;
    while (true) {
        // 一人ひとりループ
        for (int i = 1; i <= n; i++) {
            // カードが無い場合
            if (c[i][0] == 0 && c[i][1] == 0) {
                circle++;
                if (circle == n) {
                    return;
                }
                continue;
            }

            circle = 0;
            // 引いたカードと手持ちカードの確認
            if (draw == c[i][0]) {
                draw = 0;
                c[i][0] = 0;
            }
            else if (draw == c[i][1]) {
                draw = 0;
                c[i][1] = 0;
            }
            // 手持ちがそろっている場合
            if (c[i][0] == c[i][1]) {
                c[i][0] = 0;
                c[i][1] = 0;
                continue;
            }

            if (draw == 0) { // 引いたカードが無い場合
                // 手持ちカードの小さい方を判定
                if (c[i][0] < c[i][1]) {
                    // 1枚しか持っていない場合
                    if (c[i][0] != 0) {
                        draw = c[i][0];
                        c[i][0] = 0;
                    }
                    else {
                        draw = c[i][1];
                        c[i][1] = 0;
                    }
                }
                else {
                    // 1枚しか持っていいない場合
                    if (c[i][1] != 0) {
                        draw = c[i][1];
                        c[i][1] = 0;
                    }
                    else {
                        draw = c[i][0];
                        c[i][0] = 0;
                    }
                }
            }
            else { // 引いたカードがある場合
                // 1枚しか持っていない場合
                if (c[i][0] < draw) {
                    if (c[i][0] != 0) {
                        int temp = draw;
                        draw = c[i][0];
                        c[i][0] = temp;
                    }
                }
                if (c[i][1] < draw) {
                    if (c[i][1] != 0) {
                        int temp = draw;
                        draw = c[i][1];
                        c[i][1] = temp;
                    }
                }
            }
            // 引いた回数カウント
            cnt++;
            //cout << "count: " << cnt << endl << endl;
        }
    }
}

int main() {
    // データ入力
    while (true) {
        cin >> n;
        if (n == 0)break;
        for (int i = 1; i <= n; i++) {
            cin >> c[i][0] >> c[i][1];
        }

        solve();
        cout << cnt << endl;
        cnt = 0;
    }


    return 0;
}
