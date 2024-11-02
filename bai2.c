/* chương trình nhận biết số */
#include <stdio.h>
#include <string.h>

struct Stage {
    int op_sign, op_digit, op_dot, op_other;
};

int kiemTraKyTu(char c) {
    if (c == '+' || c == '-') {
        return 1; /* dấu âm dương */
    } else if (c >= '0' && c <= '9') {
        return 2; /* chữ số */
    } else if (c == '.') {
        return 3; /* dấu chấm */
    }
    return -1; /* ký tự khác */
}

int main(int argc, char const *argv[]) {
    struct Stage s[10];

    s[0].op_sign = 1;
    s[0].op_digit = 2;
    s[0].op_dot = s[0].op_other = 5; /* err */

    s[1].op_digit = 2;
    s[1].op_sign = s[1].op_dot = s[1].op_other = 5; /* err */

    s[2].op_digit = 2;
    s[2].op_dot = 3;
    s[2].op_sign = s[2].op_other = 5; /* err */

    // s[3].op_digit = 4;
    // s[3].op_sign = s[3].op_other = s[3].op_dot = 5; /* err */
    s[3].op_digit = 4;
    s[3].op_dot = 5;
    s[3].op_other = 5;
    s[3].op_sign = 5;

    s[4].op_digit = 4;
    s[4].op_dot = s[4].op_other = s[4].op_sign = 5; /* err */

    char token[100];

    printf("Enter string: ");
    scanf("%s", token);

    int current_state = 0;
    /* duyệt từng ký tự trong chuỗi */
    for (size_t i = 0; i < strlen(token); i++) {
        int ktkt = kiemTraKyTu(token[i]);

        switch (ktkt) {
        case 1:
            current_state = s[current_state].op_sign;
            break;
        case 2:
            current_state = s[current_state].op_digit;
            break;
        case 3:
            current_state = s[current_state].op_dot;
            break;
        case -1:
            current_state = s[current_state].op_other;
            break;
        default:
            break;
        }

        printf("index: %d, character: %c, check type token: %d, current state: "
               "%d\n",
               i, token[i], ktkt, current_state);

        if (current_state == 5) {
            break;
        }
    }

    /* xác định trạng thái cuối cùng */
    switch (current_state) {
    case 2:
        printf("=> Integer\n");
        break;
    case 3:
        printf("Error: Missing number after the \".\" \"%s\"\n", token);
        break;
    case 4:
        printf("=> Deciaml\n");
        break;
    case 5:
        printf("Error: Not a number \"%s\"\n", token);
        break;
    default:
        break;
    }
}
