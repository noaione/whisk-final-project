// include any modules here
#include "cookbook.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Dibutuhkan di sini:
/*
    A library of users’ saved recipes which could be manually inputted or saved froms
    online sources.
*/

// Renamed because conflict
CookbookNode* head, * tail, * curr;

void* create_recipe(Cookbook* recipe) {
    CookbookNode* temp = (CookbookNode*)malloc(sizeof(CookbookNode));
    temp->lists = recipe;
    temp->next = temp->prev = NULL;

    if (!head) {
        head = tail = temp;
    }
    else {
        head->prev = temp;
        head->next = head;
        head = temp;
    }
}

int i = 0, j = 0;
void add_recipe() {
    Cookbook* temp_recipe = (Cookbook*)malloc(sizeof(Cookbook));
    temp_recipe->title = (char*)malloc(sizeof(char));
    printf("Input recipe name: ");
    scanf("%[^\n]", temp_recipe->title); getchar();
    //input bahan resep
    puts("Input ingredients [Type \"done\" when done inputting]:");
    while (strcmp(temp_recipe->ingredient[i], "done") == 0) {
        printf("Ingridient no.%d: ", i + 1);
        temp_recipe->ingredient[i] = (char*)malloc(sizeof(temp_recipe->ingredient[i]));
        scanf("%[^\n]", temp_recipe->ingredient[i]);
    }
    //input langkah membuat
    puts("Input process [Type \"done\" when done inputting]:");
    while (strcmp(temp_recipe->step[j], "done") == 0) {
        printf("Step no.%d: ", j + 1);
        temp_recipe->step[j] = (char*)malloc(sizeof(temp_recipe->step[j]));
        scanf("%[^\n]", temp_recipe->step[j]);
    }
    create_recipe(temp_recipe);
    puts("");
    puts("Recipe Successfully updated!");
    printf("Press Enter to Continue...");
    getchar();
}

// TODO: Rename function
Cookbook* yoinkCookbookTutorial(int position) {
    if (!head) {
        return NULL;
    }
    curr = head;
    int iteration = 0;
    for (iteration; iteration < position; iteration++) {
        if (!curr) {
            break;
        }
        curr = curr->next;
    }
    if (iteration != position) {
        return NULL;
    }
    if (!curr) {
        return NULL;
    }
    return curr->lists;
}

int view_cookbook(bool show_extra = true) {
    int menu;
    puts("============");
    puts("|  Recipe  |");
    puts("============");
    int i = 0;
    curr = head;
    if (!curr) {
        puts("No Recipe Available");
        puts("Please Add the Recipe first!");
        printf("Press enter to continue...");
        getchar();
    } else {
        while (curr) {
            i += 1;
            printf("%d. %s\n", i, curr->lists->title);
            if (show_extra) {
                puts("Ingredients: ");
                for (int n = 1; n <= i; n++) {
                    printf("%d. %s\n", n, curr->lists->ingredient);
                }
                puts("Steps: ");
                for (int n = 1; n <= j; n++) {
                    printf("%d. %s\n", n, curr->lists->step);
                }
            }
        }
    }
    // return total
    return i;
}

void cook_book() {
    bool flag = true;
    int option;
    while (flag) {
        while (option > 3 || option < 1) {
            puts("1. View Cookbook");
            puts("2. Add Recipe");
            puts("3. Exit");
            printf(">> ");
            scanf("%d", &option);
        }
        switch (option) {
        case 1:
            view_cookbook();
            break;

        case 2:
            add_recipe();
            break;

        case 3:
            flag = false;
            break;
        }
    }
}
