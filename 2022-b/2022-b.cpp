#include <iostream>
using namespace std;

#define MAX_N 1001
int n;
int c[MAX_N][2];
int cnt = 0;

void solve() {
    // �������J�[�h�̐���
    int draw = 0;
    // ���[�v����p�ϐ�
    int circle = 0;
    while (true) {
        // ��l�ЂƂ胋�[�v
        for (int i = 1; i <= n; i++) {
            // �J�[�h�������ꍇ
            if (c[i][0] == 0 && c[i][1] == 0) {
                circle++;
                if (circle == n) {
                    return;
                }
                continue;
            }

            circle = 0;
            // �������J�[�h�Ǝ莝���J�[�h�̊m�F
            if (draw == c[i][0]) {
                draw = 0;
                c[i][0] = 0;
            }
            else if (draw == c[i][1]) {
                draw = 0;
                c[i][1] = 0;
            }
            // �莝����������Ă���ꍇ
            if (c[i][0] == c[i][1]) {
                c[i][0] = 0;
                c[i][1] = 0;
                continue;
            }

            if (draw == 0) { // �������J�[�h�������ꍇ
                // �莝���J�[�h�̏��������𔻒�
                if (c[i][0] < c[i][1]) {
                    // 1�����������Ă��Ȃ��ꍇ
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
                    // 1�����������Ă����Ȃ��ꍇ
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
            else { // �������J�[�h������ꍇ
                // 1�����������Ă��Ȃ��ꍇ
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
            // �������񐔃J�E���g
            cnt++;
            //cout << "count: " << cnt << endl << endl;
        }
    }
}

int main() {
    // �f�[�^����
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
