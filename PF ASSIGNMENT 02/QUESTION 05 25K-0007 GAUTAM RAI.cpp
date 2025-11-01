#include <stdio.h>
#include <string.h>


char toggleBits(char ch){
    ch = ch ^ (1<<1);  
    ch = ch ^ (1<<4);   
    return ch;
}


void reverseString(char str[]){
    int len = strlen(str);
    for(int i=0; i<len/2; i++){
        char temp = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = temp;
    }
}


void encodeMessage(char msg[]){
    reverseString(msg);
    for(int i=0; msg[i]!='\0'; i++){
        msg[i] = toggleBits(msg[i]);
    }
}


void decodeMessage(char msg[]){
    for(int i=0; msg[i]!='\0'; i++){
        msg[i] = toggleBits(msg[i]);
    }
    reverseString(msg);
}

int main(){
    char message[200];
    int choice;

    printf("=== TCS Secure Message Tool ===\n");

    while(1){
        printf("\n1. Encode Message\n");
        printf("2. Decode Message\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        if(choice==3){
            printf("Exiting...!\n");
            break;
        }

        switch(choice){
            case 1:
                printf("Enter message to encode: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = '\0';
                encodeMessage(message);
                printf("Encoded message: %s\n", message);
                break;

            case 2:
                printf("Enter message to decode: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = '\0';
                decodeMessage(message);
                printf("Decoded message: %s\n", message);
                break;

            default:
                printf("Invalid input, try again.\n");
        }
    }

    return 0;
}

