#include <stdio.h>
#include <ctype.h>

#define SIZE 50

char chars[SIZE];
int top = -1;

void push(char elem) {
    chars[++top] = elem;
}

char pop() {
    return chars[top--];
}

int pr(char elem) {
    switch (elem) {
        case '#':return 0;
        case '(':return 1;
        case '+':
        case '-':return 2;
        case '*':
        case '/':
        case '%':return 3;
        case '^':return 4;
        default: return -1; // Default case added to handle unknown characters
    }
}

int main() {
    char infix[50], postfix[50], ch;
    int i = 0, k = 0;
    
    printf("Enter the infix expression:\n");
    fgets(infix, sizeof(infix), stdin);

    push('#');
    
    while ((ch = infix[i++]) != '\0') {
        if (ch == '(')
            push(ch);
        else if (isalnum(ch))
            postfix[k++] = ch;
        else if (ch == ')') {
            while (chars[top] != '(')
                postfix[k++] = pop();
            pop(); // Pop '('
        } else {
            while (pr(chars[top]) >= pr(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }
    
    while (chars[top] != '#')
        postfix[k++] = pop();
    
    postfix[k] = '\0';
    
    printf("Infix expression is %s\nPostfix expression is %s\n", infix, postfix);

    return 0;
}
