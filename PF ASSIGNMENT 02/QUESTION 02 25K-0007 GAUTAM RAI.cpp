#include <stdio.h>
#include <string.h>

char *codes[] = {"001", "002", "003", "004"};
char *names[] = {"Milk", "Bread", "Eggs", "Apples"};
float prices[] = {100, 200, 300, 150};
int stock[] = {50, 10, 20, 8};
int total_products = 4;

int find(char code[]) {
    for(int i=0; i<total_products; i++)
        if(strcmp(code, codes[i])==0) return i;
    return -1;
}

void showProducts() {
    printf("\nCode\tName\tStock\tPrice\n");
    for(int i=0; i<total_products; i++)
        printf("%s\t%s\t%d\t%.2f\n", codes[i], names[i], stock[i], prices[i]);
}

int main() {
    char name[50]="N/A", cnic[20]="N/A", code[10], promo[20];
    int choice, cartIdx[20], cartQty[20], cartCount=0;
    float total=0, discount=0;

    while(1) {
        printf("\n1.Enter Customer  2.Show Items  3.Add to Cart  4.Bill  5.Invoice  6.Exit\n> ");
        scanf("%d", &choice);

        if(choice==1) {
            printf("Name: "); scanf(" %[^\n]", name);
            printf("CNIC: "); scanf(" %[^\n]", cnic);
        }
        else if(choice==2) showProducts();

        else if(choice==3) {
            showProducts();
            printf("Enter code: "); scanf("%s", code);
            int idx = find(code);
            if(idx==-1) { printf("Not found!\n"); continue; }
            int qty; printf("Qty: "); scanf("%d", &qty);
            if(qty>stock[idx] || qty<=0) { printf("Invalid qty.\n"); continue; }
            cartIdx[cartCount]=idx; cartQty[cartCount++]=qty;
            printf("%d x %s added.\n", qty, names[idx]);
        }

        else if(choice==4) {
            if(cartCount==0) { printf("Cart empty.\n"); continue; }
            total=0;
            for(int i=0;i<cartCount;i++){
                float sub = prices[cartIdx[i]]*cartQty[i];
                printf("%s x %d = %.2f\n", names[cartIdx[i]], cartQty[i], sub);
                total += sub;
                stock[cartIdx[i]] -= cartQty[i];
            }
            printf("Total: %.2f\nPromo code (N if none): ", total);
            scanf("%s", promo);
            if(strcmp(promo,"Eid2025")==0){ discount=total*0.25; printf("Discount %.2f\n",discount); }
            else discount=0;
            printf("Payable: %.2f\n", total-discount);
        }

        else if(choice==5){
            printf("\n--- INVOICE ---\n%s (%s)\nTotal: %.2f\nDiscount: %.2f\nPayable: %.2f\n",
                   name, cnic, total, discount, total-discount);
        }

        else if(choice==6){ printf("Goodbye!\n"); break; }
        else printf("Invalid choice!\n");
    }
    return 0;
}

