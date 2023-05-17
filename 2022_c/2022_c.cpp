#include <iostream>
#include <vector>
using namespace std;

#define MAX_N_M 1000000

// ����
// ���K��
int n;
// �x��
int m;
int ans;

bool dfs(int x, int y, int cntx = 1, int cnty = 1, int sum = 0) {
    if (x == n && y == m) { // �T���I������
        if (ans == 0 && sum < 0) { // ���������ɂȂ�ꍇ
            ans = sum;
        }
        else if (ans < sum) { // �ʏ��r
            ans = sum;
        }
        return false;
    }

    if (x != n) {
        if (dfs(x + 1, y, cntx + 1, 1, sum + (2 * cntx - 1)))return true;
    }

    if (y != m) {
        if (dfs(x, y + 1, 1, cnty + 1, sum - (2 * cnty - 1)))return true;
    }

    return false;
}

void solve() {
    dfs(0, 0);
}

int main() {
    while (true) {
        ans = 0;
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }

        solve();
        cout << ans << endl;
    }

    return 0;
}
