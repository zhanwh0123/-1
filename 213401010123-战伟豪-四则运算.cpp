#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

void generate_expression_with_brackets(int num_questions, int max_num, char operator_choice) {
    for (int i = 0; i < num_questions; i++) {
        int num1 = random_int(1, max_num);
        int num2 = random_int(1, max_num);
        int num3 = random_int(1, max_num);

        printf("(");
        printf("%d %c %d", num1, operator_choice, num2);
        printf(") %c %d\n", operator_choice, num3);
    }
}

void generate_expression_without_brackets(int num_questions, int max_num, char operator_choice) {
    for (int i = 0; i < num_questions; i++) {
        int num1 = random_int(1, max_num);
        int num2 = random_int(1, max_num);

        printf("%d %c %d\n", num1, operator_choice, num2);
    }
}

int main() {
    int num_questions, max_num, with_brackets;
    char operator_choice;

    printf("请输入题目数量：");
    scanf("%d", &num_questions);

    printf("请选择运算符（+、-、*、/）：");
    scanf(" %c", &operator_choice);

    printf("请输入最大数：");
    scanf("%d", &max_num);

    printf("是否带括号？（1为是，0为否）：");
    scanf("%d", &with_brackets);

    srand(time(NULL));

    if (with_brackets) {
        generate_expression_with_brackets(num_questions, max_num, operator_choice);
    }
    else {
        generate_expression_without_brackets(num_questions, max_num, operator_choice);
    }

    return 0;
}
