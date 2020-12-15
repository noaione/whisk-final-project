// A place for users to browse and discover recipes that are relevant to their preferences
// call function homePage in main.cpp
// struct node dan recipes di taruh di main, variabel sumCooked ketika di createNode dibuat 0, setiap kali cook di tambah 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "homepage.h"
#include "utils.h"

Node *homepageBase;

void close() {
    ENTER;
    getchar();
    CLEAR;
}

void printRecipes(Node* root) {
    if (!root) {
        puts("Data tidak ditemukan!");
    }
    else {
        printf("Description:\t %s\n", root->recipes.description);
        printf("Instruction:\t %s\n", root->recipes.instructions);
        printf("Ingridient:\t %s\n", root->recipes.ingridient);
    }
}

void searchRecipes(Node* root, char* name) {
    if (root) {
        if (!strcmp(root->name, name)) {
            printRecipes(root);
            return;
        }
        else {
            root = root->next;
        }
    }
    printRecipes(root);
    return;
}

int countRecipes(Node* root) {
    int i = 0;
    while (root) {
        root->next;
        i++;
    }
    return i;
}

void showPreferences(Node* root) {
    int sumRecipes = countRecipes(root);
    int max[5] = {};
    for (int i = 0; i < 5 && i < sumRecipes; i++) {
        Node* temp = root;
        while (temp) {
            //printf("%s\n", root->name);
            if (temp->sumCooked > max[i] && (i > 0) ? temp->sumCooked < max[i - 1] : 1) {
                max[i] = temp->sumCooked;
            }
            temp = temp->next;
        }
    }
    for (int i = 0; i < 5 && i < sumRecipes; i++) {
        Node* temp = root;
        while (temp) {
            (temp->sumCooked == max[i]) ? printf("%s\n", root->name) : 1;
            temp = temp->next;
        }
    }
}

void printHomePage() {
    CLEAR;
    puts("============================= HOME PAGE =============================");
    puts("==================== browse and discover recipes ====================");
    puts("");
    puts(">> 1. Search Recipes");
    puts(">> 2. Show Preferences");
    puts(">> 3. Back");
    puts("");
}

void homePage() {
    int choise = 0;
    while (!choise) {
        printHomePage();
        scanf("%d", &choise); getchar();
        if (choise == 1) {
            CLEAR;
            char name[255];
            printf("Input recipes name: ");
            scanf("%[^\n]", name); getchar();
            searchRecipes(homepageBase, name);
        }
        else if (choise == 2) {
            CLEAR;
            if (!homepageBase) {
                puts("No Recipes Yet!");
            }
            else {
                showPreferences(homepageBase);
            }
        }
        else if (choise == 3) {
            break;
        }
        choise = 0;
    }
    close();
}

// int main() {
//   homePage();
//   return 0;
// }