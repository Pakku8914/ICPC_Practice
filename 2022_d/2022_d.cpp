#include <iostream>
using namespace std;

#define MAX_N 10000
#define MAX_K 10000
// n: �l��
// k: �Q�[�g��
int n, k;
// ���݂̗�
int s[MAX_N];
// �ڕW��
int t[MAX_N];

void solve() {

}

int main() {
    while (true) {
        cin >> n >> k;
        if (n == 0 && k == 0) {
            break;
        }
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> t[i];
        }

        solve();
    }
    return 0;
}
