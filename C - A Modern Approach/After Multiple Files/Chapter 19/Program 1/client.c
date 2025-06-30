#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

bool is_left_bracket(char ch);
bool is_right_bracket(char ch);

int main() {
    Stack S;
    S = create();

    char ch, temp;
    bool nested_properly;

    printf("Enter parentheses and/or braces: ");
    while ((ch = getchar()) != '\n') {
        if (is_left_bracket(ch))   // Pushes the Braces/Parenthesis
            push(S, ch);
        else if (is_right_bracket(ch)) {  // Pops the Braces/Parenthesis
            temp = pop(S);
            if (ch == ')' && temp == '(')   // Checks whether the Parenthesis match the popped one or not
                nested_properly = true;    
            else if (ch == '}' && temp == '{') // Checks whether the Braces match the popped one or not
                nested_properly = true;
            else if (ch == ']' && temp == '[') // Checks whether the Square Bracket match the popped one or not
                nested_properly = true;
            else {                          // Checks for any other case i
                nested_properly = false;
                printf("Parenthesis/braces are not nested properly.");
                return 0;
            }
        }
    }
    
    if (!is_empty(S))      // Checks whether the array is empty or not if not then not nested properly.
        printf("Parenthesis/braces are not nested properly.");
    else if (nested_properly) // Checks whether the Braces/Parenthesis are nested properly.
        printf("Parenthesis/braces are nested properly.");
    
    destroy(S);
    return 0;
}


bool is_left_bracket(char ch) {
    return (ch == '(' || ch == '{' || ch == '[');
}
bool is_right_bracket(char ch) {
    return (ch == ')' || ch == '}' || ch == ']');
}