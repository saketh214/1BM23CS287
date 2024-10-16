#include <stdio.h>
#include<string.h>

char stack[30];
char infix[30], result[30];
int top=-1, pos=0;

int precedence(char s){
    if(s=='^') return 3;
    else if(s=='*' || s=='/') return 2;
    else if(s=='+' || s=='-') return 1;
    else if(s=='(') return 0;
}

void push(char s){
    top++;
    stack[top]=s;
}

char pop(){
    char temp = stack[top];
    top--;
    return temp;
}

void infix_to_postfix(){
    char ch;
    int len=strlen(infix);
    int c=0;
    while(c<len){
        ch=infix[c];
        if(ch=='('){
            push(ch);
        }
        else if(ch==')'){
            char temp=pop();
            while(temp!='('){
                result[pos]=temp;
                pos++;
                temp=pop();
            }
        }
        else if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^'){
            while(top>=0 && precedence(stack[top])>=precedence(ch)){
                char temp2=pop();
                result[pos]=temp2;
                pos++;
            }
            push(ch);
        }
        else{
            result[pos]=ch;
            pos++;
        }
        c++;
    }

    while(top>=0){
        char temp3=pop();
        result[pos]=temp3;
        pos++;
    }
}
int main(){
    printf("Enter infix expression: \n");
    scanf("%s",&infix);
    infix_to_postfix();
    printf("Postfix expression is: %s",result);
}
