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
struct Node{
    Cookbook *lists;
    Node *next, *prev;
} *head, *tail, *curr;


void *create_recipe(Cookbook *recipe){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->lists = recipe;
    temp->next = temp->prev = NULL;

    if(!head){
        head = tail = temp;
    }
    else{
        head->prev = temp;
        head->next = head;
        head = temp;
    }
}

int i = 0, j = 0;
void add_recipe(){
    Cookbook *temp_recipe = (Cookbook *)malloc(sizeof(Cookbook));
    temp_recipe->title = (char *)malloc(sizeof(char)); 
    printf("Input recipe name: ");
    scanf("%[^\n]", temp_recipe->title); getchar();
    //input bahan resep
    puts("Input ingredients [Type \"done\" when done inputting]:");
    while(strcmp(temp_recipe->ingredient[i], "done") == 0){
        printf("Ingridient no.%d: ", i + 1);
        scanf("%[^\n]", temp_recipe->ingredient);
    }
    //input langkah membuat
    puts("Input process [Type \"done\" when done inputting]:");
    while(strcmp(temp_recipe->step[j], "done") == 0){
        printf("Step no.%d: ", j + 1);
        scanf("%[^\n]", temp_recipe->step);
    }
    create_recipe(temp_recipe);
    puts("");
    puts("Recipe Successfully updated!");
    printf("Press Enter to Continue...");
    getchar();
}

void view_cookbook(){
    int menu;
    puts("===========");
    puts("|  Recipe |");
    puts("===========");
    int i = 0;
    curr = head;
    if(!curr){
        puts("No Recipe Available");
        puts("Please Add the Recipe first!");
        printf("Press enter to continue...");
        getchar();
    }
    else{
        while(curr){
            i += 1;
            printf("%d. %s\n", i, curr->lists->title);
            puts("Ingredients: ");
            for(int n = 1; n <= i; n++){
                printf("%d. %s\n", n, curr->lists->ingredient);
            }
            puts("Steps: ");
            for(int n = 1; n <= j; n++){
                printf("%d. %s\n", n, curr->lists->step);
            }
        }
    }
    
}

void cook_book(){
    bool flag = true;
    int option;
    while(flag){
        while(option > 3 || option < 1){
            puts("1. View Cookbook");
            puts("2. Add Recipe");
            puts("3. Exit");
            printf(">> ");
            scanf("%d", &option);
        }
        switch (option){
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
