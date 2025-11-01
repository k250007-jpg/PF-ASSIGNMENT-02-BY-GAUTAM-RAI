#include <stdio.h>

#define ROWS 5
#define COLS 5

#define POWER 0
#define OVERLOAD 1
#define MAINT 2

int getMask(int bit){
    return (1 << bit);
}

void update(int grid[ROWS][COLS], int r, int c, int flag, int set){
    int mask = getMask(flag);
    if(set == 1)
        grid[r][c] |= mask;
    else
        grid[r][c] &= ~mask;
}

void show(int grid[ROWS][COLS], int r, int c){
    int val = grid[r][c];
    printf("\nSector [%d][%d]\n", r, c);
    printf("Power: %s\n", (val & getMask(POWER)) ? "ON" : "OFF");
    printf("Overload: %s\n", (val & getMask(OVERLOAD)) ? "YES" : "NO");
    printf("Maintenance: %s\n", (val & getMask(MAINT)) ? "YES" : "NO");
}

void diagnostic(int grid[ROWS][COLS]){
    int over=0, maint=0;
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            if(grid[i][j] & getMask(OVERLOAD)) over++;
            if(grid[i][j] & getMask(MAINT)) maint++;
        }
    }
    printf("\n--- System Diagnostic ---\n");
    printf("Overloaded sectors = %d\n", over);
    printf("Maintenance needed = %d\n", maint);
}

int main(){
    int grid[ROWS][COLS] = {0};
    int ch, r, c, flag, set;
    
    printf("=== IESCO Power Grid Monitoring ===\n");

    while(1){
        printf("\n1. Update Sector\n");
        printf("2. Check Sector\n");
        printf("3. Run Diagnostic\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        if(ch == 4){
            printf("Exiting...\n");
            break;
        }

        if(ch == 1){
            printf("Enter row & column (0-4): ");
            scanf("%d%d", &r, &c);
            if(r<0 || r>=ROWS || c<0 || c>=COLS){
                printf("Invalid input!\n");
                continue;
            }
            printf("Flag (0=Power,1=Overload,2=Maintenance): ");
            scanf("%d", &flag);
            if(flag<0 || flag>2){
                printf("Wrong flag!\n");
                continue;
            }
            printf("Set(1) or Clear(0): ");
            scanf("%d", &set);
            update(grid, r, c, flag, set);
            printf("Updated!\n");
        }
        else if(ch == 2){
            printf("Enter row & column: ");
            scanf("%d%d", &r, &c);
            if(r<0 || r>=ROWS || c<0 || c>=COLS){
                printf("Invalid sector!\n");
                continue;
            }
            show(grid, r, c);
        }
        else if(ch == 3){
            diagnostic(grid);
        }
        else{
            printf("Invalid option!\n");
        }
    }

    return 0;
}

