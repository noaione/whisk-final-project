// include any modules here
#include "cookbook.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Dibutuhkan di sini:
/*
    A library of users’ saved recipes which could be manually inputted or saved from
    online sources.
*/
struct Node {
    Cookbook* lists;
    Node* next, * prev;
} *head, * tail, * curr;


void* create_recipe(Cookbook* recipe) {
    Node* temp = (Node*)malloc(sizeof(Node));
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

void add_recipe() {
    Cookbook* temp_recipe = (Cookbook*)malloc(sizeof(Cookbook));
    temp_recipe->title = (char*)malloc(sizeof(char));
    printf("Input recipe name: ");
    scanf("%[^\n]", temp_recipe->title); getchar();
    //input bahan resep
    puts("Input ingredients [Type \"done\" when done inputting]:");
    int i = 0;
    while (strcmp(temp_recipe->ingredient[i], "done") == 0) {
        printf("Ingridient no.%d: ", i + 1);
        temp_recipe->ingredient[i] = (char*)malloc(sizeof(temp_recipe->ingredient[i]));
        scanf("%[^\n]", temp_recipe->ingredient[i]);
    }
    //input langkah membuat
    puts("Input process [Type \"done\" when done inputting]:");
    int j = 0;
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

int viewCookbook() {
    if (!head) {
        puts("There's no recipe saved.");
        return 0;
    }
    curr = head;
    int numbering = 1;
    int total = 0;
    while (curr) {
        printf("%d. %s", numbering, curr->lists->title);
        total++;
        numbering++;
        curr = curr->next;
    }
    curr = head;
    // N4O: return total for easier counting :)
    return total;
}

// TODO: Rename function
Cookbook *yoinkCookbookTutorial(int position) {
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
            /* code */
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
