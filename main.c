#include <stdio.h>
#include "menu.h"

int main(){
    int n;
    do{
        print_menu();
        printf("\n\nDo you want try again?\n"
               "1)Yes, one more time\n"
               "2)No, quit\n");
        scanf_s("%d", &n);
        while (n != 1 && n != 2){
            printf("Nonexistent option selected. Try again:\n");
            scanf_s("%d", &n);
        }
    } while (n==1);
    return 0;
}