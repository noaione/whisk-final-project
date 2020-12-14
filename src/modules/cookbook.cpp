// include any modules here
#include "cookbook.h"
#include <stdio.h>
#include<stdlib.h>

// Dibutuhkan di sini:
/*
    A library of users’ saved recipes which could be manually inputted or saved from
    online sources.
*/

struct Node{
    Cookbook lists;
    Node *next, *prev;
} *head, *tail, *curr;

Node *create_node(Cookbook *recipe){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->lists = recipe;
    temp->next = temp->prev = NULL;
}

void add_recipe(){

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
            /* code */
            break;

        case 3:
            flag = false;
            break;
        }
    }
}
