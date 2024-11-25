//
// Created by Ye on 24-11-25.
//
#include <stdio.h>

#define MAX_SIZE 10005

char stack[MAX_SIZE];
int top = -1;

void Push(char m) {
    if (top < MAX_SIZE - 1) {
        top++;
        stack[top] = m;
    }
}

void Pop() {
    if (top != -1) {
        top--;
    }
}

void Clear(){
    top = -1;
}

int main() {
    int T = 0;
    scanf("%d", &T);

    for (int k = 0; k < T; k++){
        char s[10005];
        scanf("%s", s);

        int i = 0;
        int a = 0;
        while(s[i] != '\0'){
            if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
                Push(s[i]);
                a = 1;
            }else{
                switch(s[i]){
                case ')':
                    if (top != -1){
                        if (stack[top] == '('){
                            Pop();
                        }
                        else
                            printf("False\n");
                    }
                    break;
                case ']':
                    if (top != -1){
                        if (stack[top] == '['){
                            Pop();
                        }
                        else
                            printf("False\n");
                    }
                    break;
                case '}':
                    if (top != -1){
                        if (stack[top] == '{'){
                            Pop();
                        }
                        else
                            printf("False\n");
                    }
                    break;
                default:
                    printf("False\n");
                    break;
                }
            }
            i++;
        }
        if (a == 1 && top == -1){
            printf("True\n");
        }
        Clear();
    }
    return 0;
}