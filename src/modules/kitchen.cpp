// include any modules here

#include <stdio.h>

#include "kitchen.h"
#include "utils.h"

// TODO: CHANGE ALL THE WEIRD VARIABLE AND WORD LMAO

// Dibutuhkan di sini:
/*
    A place for users to see the dishes they want to cook, the ingredients they need, and a
    simplified list of instructions.
*/

void lets_cook_something_bois(Cookbook *recipe) {
    printf("Let's start cooking %s!", recipe->title);
    puts("You need:");
    // loop through ingredient yo
    printf("There's %d steps, you need to press Enter inbetween steps!\n");
    puts("Are you ready? press Enter to see the cooking process!");
    getchar();
    // loop through steps with getchar inbetween
    puts("");
    puts("Congratulations, you (hopefully) make a good %s, enjoy it!");
}

// need to expose cookbook node to public eyes.
void kitchenmenu() {
    CLEAR;
    puts("What's poppin today?");
    int choice = -1;
    // infer from total cookbook.
    int max = viewCookbook();
    do {
        printf("What do you want to cook today? ");
        scanf("%d", &choice);
        getchar();
    } while (choice < 1 || choice > max);
    choice--;
    Cookbook *recipe = yoinkCookbookTutorial(choice);
    if (!recipe) {
        puts("Sorry this recipe is not available :(");
        ENTER;
        getchar();
        return;
    }
    lets_cook_something_bois(recipe);
    ENTER;
    getchar();
}