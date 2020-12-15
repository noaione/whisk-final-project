#include <stdio.h>
#include <stdlib.h>

#include "modules/homepage.h"
#include "modules/cookbook.h"
#include "modules/kitchen.h"
#include "modules/utils.h"

int main() {
    puts("Welcome to Whisk!");
    TimeData *ctime = convertToTimeData(currentTime());
    printf("Current Time: %s, %s %s %d %s:%s:%s\n",ctime->swdays, ctime->pmdays, ctime->smonths,
            ctime->years, ctime->phours, ctime->pmins, ctime->psecs);
    puts("====================================================");
    // print menu and do stuff.
    bool exit_flag = false;
    do {
        int choose_flag = -1;
        do {
            // homepage.h/.cpp
            puts("1. Discover new recipes");
            // cookbook.h/.cpp
            puts("2. See saved recipes");
            // kitchen.h/.cpp
            puts("3. Kitchen - Cook a recipes!");
            // pantry.h/.cpp
            puts("4. Pantry");
            puts("5. Exit Whish");
            printf(">> ");
            scanf("%d", &choose_flag);
            getchar();
        } while (choose_flag < 1 || choose_flag > 5);
        switch (choose_flag) {
            case 1:
                puts("");
                homePage();
                break;
            case 2:
                puts("");
                cook_book();
                break;
            case 3:
                puts("");
                kitchenmenu();
                break;
            case 4:
                /* code */
                puts("");
                break;
            case 5:
                puts("");
                exit_flag = true;
                break;
        }
        if (exit_flag) {
            break;
        }
    } while (!exit_flag);
    puts("Thanks for using Whisk!");
    puts("See you again later!");
    return 0;
}