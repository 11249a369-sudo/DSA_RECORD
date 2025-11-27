#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;
void push(char c) {
    stack[++top] = c;
}
char pop() {
    return stack[top--];
}

int main() {
    char str[100], reversed[100];
    int i = 0;

    printf("Enter a string: ");
    scanf("%s", str);
    for (i = 0; i < strlen(str); i++) {
        push(str[i]);
    }
    for (i = 0; i < strlen(str); i++) {
        reversed[i] = pop();
    }

    reversed[i] = '\0';

    printf("Reversed string: %s\n", reversed);

    return 0;
}
