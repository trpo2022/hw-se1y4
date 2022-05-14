#include <lib/chessviz.h>

int w_pass = 0;
int w_x = -1;
int b_pass = 0;
int b_x = -1;

int main()
{
    char board[8][8];
    int MoveNum = 0;
    Create(board);
    Show(board);
    int n = 0;
    char w[7];
    char b[7];
    while (n == MoveNum) {
        MoveNum += 1;
        scanf("%d. ", &n);
        if (MoveNum == n) {
            scanf("%s", w);
            if (WinW(board, w, n)) {
                break;
            }
            scanf("%s", b);
            if (WinB(board, w, b, n)) {
                break;
            }
            printf("\n%d. %s %s \n", n, w, b);
            White(board, w);
            if (CheckW(board)) {
                ErrorC(2);
                break;
            }
            w_pass = 0;
            Black(board, b);
            if (CheckB(board)) {
                ErrorC(2);
                break;
            }
            b_pass = 0;
        } else {
            ErrorC(1);
            break;
        }
    }

    return 0;
}
