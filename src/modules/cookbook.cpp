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

void add_recipe(){
    Cookbook *temp_recipe = (Cookbook *)malloc(sizeof(Cookbook));
    temp_recipe->title = (char *)malloc(sizeof(char)); 
    printf("Input recipe name: ");
    scanf("%[^\n]", temp_recipe->title); getchar();
    //input bahan resep
    puts("Input ingredients [Type \"done\" when done inputting]:");
    int i = 0;
    while(strcmp(temp_recipe->ingredient[i], "done") == 0){
        printf("Ingridient no.%d: ", i + 1);
        scanf("%[^\n]", temp_recipe->ingredient);
    }
    //input langkah membuat
    puts("Input process [Type \"done\" when done inputting]:");
    int j = 0;
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
