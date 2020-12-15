#ifndef MOD_COOKBOOK_H
#define MOD_COOKBOOK_H

// Definisikan semua struct dan sebagainya di sini.
struct Cookbook{
    char *title;
    char *ingredient[255];
    char *step[255];
};

struct Node{
    Cookbook *lists;
    Node *next, *prev;
} *head, *tail, *curr;

void cook_book();
void *create_recipe(Cookbook *recipe);
void add_recipe();
void view_cookbook();
#endif /* MOD_COOKBOOK_H */