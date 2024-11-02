// chương trình nhận biết tên biến
#include <stdio.h>
#include <string.h>

struct Stage {
    int op_alpha, op_digit, op_other;
};

int kiemTraKyTu(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return 1; /* chữ cái */
    } else if (c >= '0' && c <= '9') {
        return 2; /* chữ số */
    }
    return -1; /* ký tự khác */
}

int main(int argc, char const *argv[]) {
    struct Stage s[2];

    s[0].op_alpha = 1;
    s[0].op_digit = 2; /* err */
    s[0].op_other = 2; /* err */

    s[1].op_alpha = 1;
    s[1].op_digit = 1;
    s[1].op_other = 2; /* err */

    char token[100];

    printf("Enter string: ");
    scanf("%s", token);

    int current_state = 0;
    /* duyệt từng ký tự trong chuỗi */
    for (size_t i = 0; i < strlen(token); i++) {
        int ktkt = kiemTraKyTu(token[i]);

        switch (ktkt) {
        case -1: /* khác */
            current_state = s[current_state].op_other;
            break;
        case 1: /* chữ cái */
            current_state = s[current_state].op_alpha;
            break;
        case 2: /* chữ số */
            current_state = s[current_state].op_digit;
            break;
        default:
            break;
        }

        printf("index: %d, character: %c, check type token: %d, current state: "
               "%d\n",
               i, token[i], ktkt, current_state);

        if (current_state == 2) {
            break; /* thoát vòng lặp */
        }
    }

    /* xác định trạng thái cuối cùng */
    switch (current_state) {
    case 1:
        printf("=> Variable\n");
        break;
    case 2:
        printf("Error: Loi ten bien \"%s\"\n", token);
        break;
    default:
        break;
    }

    return 0;
}
