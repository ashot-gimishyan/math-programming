#include "Real.h"

int main()
{
    printf("Your Boolean Expression: ");
    while (1) {
        char ch = getchar();
        if ('=' == ch) {
            break;
        }
        else if ('&' == ch) {
            getchar();
            Push(Pop() && Pop());
        }
        else if ('|' == ch) {
            getchar();
            Push(Pop() || Pop());
        }
        else if ('!' == ch) {
            Push(!Pop());
        }
        else if (ch == '0') {
            Push(0);
        }
        else if (ch == '1') {
            Push(1);
        }
    }

    printf("Result: %i\n", Pop());
    return 0;
}
