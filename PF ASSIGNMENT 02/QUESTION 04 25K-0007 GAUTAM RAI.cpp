#include <stdio.h>
#define MAX 5


void push(int s[], int *top);
void pop(int s[], int *top);
void peek(int s[], int top);
void display(int s[], int top);

int main() {
    int stack[MAX];
    int top = -1;
    int ch;

    do {
        printf("\n=== Stack Menu ===\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                push(stack, &top);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                peek(stack, top);
                break;
            case 4:
                display(stack, top);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    } while(ch != 5);

    return 0;
}

void push(int s[], int *top) {
    int val;
    if(*top == MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        printf("Enter value: ");
        scanf("%d", &val);
        (*top)++;
        s[*top] = val;
        printf("Pushed %d\n", val);
    }
}

void pop(int s[], int *top) {
    if(*top == -1) {
        printf("Stack Underflow!\n");
    } else {
        printf("Popped %d\n", s[*top]);
        (*top)--;
    }
}

void peek(int s[], int top) {
    if(top == -1) {
        printf("Stack Empty!\n");
    } else {
        printf("Top element: %d\n", s[top]);
    }
}

void display(int s[], int top) {
    if(top == -1) {
        printf("Stack Empty!\n");
    } else {
        printf("\nStack elements:\n");
        for(int i = top; i >= 0; i--) {
            printf("%d\n", s[i]);
        }
    }
}



