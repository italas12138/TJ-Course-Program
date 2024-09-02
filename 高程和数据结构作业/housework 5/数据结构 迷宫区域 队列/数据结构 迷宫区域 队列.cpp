#include <stdio.h>
#include <math.h>
#include <string.h>

char tree[100];
int idx = 0;

int get_tree_space(int line) {
    if (line == 2) {
        return 2;
    } else {
        return 2 * get_tree_space(line - 1) + 1;
    }
}

int get_slash_space(int line) {
    return 4 + (pow(2, line - 3) - 1) * 6;
}

int get_slash_md_sp(int line) {
    return (pow(2, line - 2) - 1) * 6 + 3;
}
void init_str(char str[], int i, int n, int length) {
    if (str[idx] == ' ') {
        return;
    }
    tree[n] = str[idx];
    init_str(str, idx++, 2 * n + 1, length);
    init_str(str, idx++, 2 * n + 2, length);
}

void print_BiTree(char str[]) {
    for (int i = 0; i < 100; i++) {
        tree[i] = '#';
    }
    init_str(str, 0, 0, strlen(str));
    int n = strlen(tree);
    for (int i = 0; i < 100; i++) {
        if (tree[i] != '#') {
            n = i + 1;
        }
    }
    int line_num = 0;
    for (; pow(2, line_num) - 1 < n; line_num++) {}
    int line = line_num - 1;
    for (int i = 0; line_num > 1; line_num--, i++) {
        int start_space_num = get_tree_space(line_num), space_of_two_point = get_tree_space(line_num + 1);
        for (int j = 0; j < start_space_num; j++)printf(" ");
        for (int j = pow(2, i) - 1; j < pow(2, i + 1) - 1; j++) {
            if (tree[j] != '#') {
                printf("%c", tree[j]);
            } else {
                printf(" ");
            }
            for (int k = 0; k < space_of_two_point; k++)printf(" ");
        }
        printf("\n");
        int start_sp = get_slash_space(line_num), middle_sp = get_slash_md_sp(line_num);
        int slash_num = pow(2, i);
        for (int j = 0; j < start_sp; j++)printf(" ");
        for (int j = 0; j < slash_num; j++) {
            int slash_to_tree_index = pow(2, i) - 1 + j;
            if (tree[slash_to_tree_index] != '#' && tree[2 * slash_to_tree_index + 1] != '#' &&
                2 * slash_to_tree_index + 1 < n) {
                printf("/");
            } else {
                printf(" ");
            }
            printf(" ");
            if (tree[slash_to_tree_index] != '#' && tree[2 * slash_to_tree_index + 2] != '#' &&
                2 * slash_to_tree_index + 2 < n) {
                printf("\\");
            } else {
                printf(" ");
            }
            for (int k = 0; k < middle_sp; k++)printf(" ");
        }
        printf("\n");
    }
    for (int i = pow(2, line) - 1; i < n; i += 2) {
        if (tree[i] != '#') {
            printf("%c", tree[i]);
        } else {
            printf(" ");
        }
        if (i + 1 < n) {
            if (tree[i + 1] != '#') {
                printf("   %c ", tree[i + 1]);
            } else {
                printf("     ");
            }
        }
    }

}

int main() {
    char str[100];
    gets(str);
    print_BiTree(str);
    return 0;
}
//测试样例：f后有三个空格，如果没有会出错
//abc  de g  f



