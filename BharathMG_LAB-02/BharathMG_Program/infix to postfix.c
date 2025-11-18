#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define N 100

int top = -1;
char stack[N];

// Function to return precedence of operators
int prec(char a)
{
    if (a == '^')
        return 3;
    if (a == '*' || a == '/')
        return 2;
    if (a == '+' || a == '-')
        return 1;
    return 0;
}

// Push into stack
void push(char a)
{
    if (top < N - 1)
        stack[++top] = a;
}

// Pop from stack
char pop()
{
    if (top >= 0)
        return stack[top--];
    return '\0';
}

// Peek top of stack
char peek()
{
    if (top == -1)
        return '\0';
    return stack[top];
}

// Convert infix to postfix
void infix_to_postfix(char exp[], char res[])
{
    int j = 0;

    for (int i = 0; i < strlen(exp); i++)
    {
        char c = exp[i];

        // Operand → directly add to result
        if (isalnum(c))
        {
            res[j++] = c;
        }
        // If '(' → push to stack
        else if (c == '(')
        {
            push(c);
        }
        // If ')' → pop until '('
        else if (c == ')')
        {
            while (peek() != '(' && top != -1)
            {
                res[j++] = pop();
            }
            pop(); // remove '('
        }
        // Operator
        else
        {
            while (top != -1 && prec(peek()) >= prec(c))
            {
                res[j++] = pop();
            }
            push(c);
        }
    }

    // Pop all remaining operators
    while (top != -1)
    {
        res[j++] = pop();
    }

    res[j] = '\0';
}

int main()
{
    char exp[N], result[N];

    printf("Enter infix expression: ");
    scanf("%s", exp);

    infix_to_postfix(exp, result);

    printf("Postfix expression: %s\n", result);

    return 0;
}
