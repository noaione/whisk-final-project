#ifndef MOD_COOKBOOK_H
#define MOD_COOKBOOK_H

// Definisikan semua struct dan sebagainya di sini.
struct Cookbook {
    char* title;
    char* ingredient[255];
    char* step[255];
};

struct Node {
    Cookbook *lists;
    Node *next, *prev;
};

void cook_book();
void *create_recipe(Cookbook *recipe);
void add_recipe();
int view_cookbook(bool show_extra);
Cookbook* yoinkCookbookTutorial(int position);

#endif /* MOD_COOKBOOK_H */