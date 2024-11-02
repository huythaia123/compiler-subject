/* nhận biết các quan hệ so sánh */

#include <stdio.h>
#include <string.h>

struct Stage {
    int op_l, op_g, op_e, op_other;
};

int kiemTraKyTu(char c) {
    if (c == '<') {
        return 1;
    } else if (c == '=') {
        return 2;
    } else if (c == '>') {
        return 3;
    }
    return -1; /* ký tự khác */
}

int main(int argc, char const *argv[]) {
    struct Stage s[10];

    s[0].op_l = 1;     /* LT */
    s[0].op_e = 4;     /* EQ */
    s[0].op_g = 5;     /* GT */
    s[0].op_other = 7; /* err */

    s[1].op_e = 2;                 /* LE */
    s[1].op_g = 3;                 /* DIF */
    s[1].op_l = s[1].op_other = 7; /* err */

    s[2].op_e = s[2].op_g = s[2].op_l = s[2].op_other = 7; /* err */

    s[3].op_e = s[3].op_g = s[3].op_l = s[3].op_other = 7; /* err */

    s[4].op_e = s[4].op_g = s[4].op_l = s[4].op_other = 7; /* err */

    s[5].op_e = 6;                             /* GT */
    s[5].op_g = s[5].op_g = s[5].op_other = 7; /* err */

    s[6].op_e = s[6].op_g = s[6].op_l = s[6].op_other = 7; /* err */

    char token[100];

    printf("Enter string: ");
    scanf("%s", token);

    int current_state = 0;
    for (size_t i = 0; i < strlen(token); i++) {
        int ktkt = kiemTraKyTu(token[i]);
        switch (ktkt) {
        case 1:
            current_state = s[current_state].op_l;
            break;
        case 2:
            current_state = s[current_state].op_e;
            break;
        case 3:
            current_state = s[current_state].op_g;
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
        if (current_state == 7)
            break;
    }

    /* xác định trạng thái cuối cùng */
    switch (current_state) {
    case 1:
        printf("=> LT\n");
        break;
    case 2:
        printf("=> LE\n");
        break;
    case 3:
        printf("=> DIF\n");
        break;
    case 4:
        printf("=> EQ\n");
        break;
    case 5:
        printf("=> GT\n");
        break;
    case 6:
        printf("=> GE\n");
        break;
    case 7:
        printf("=> Error conditions\n");
        break;
    default:
        printf("Error any\n");
        break;
    }

    return 0;
}
