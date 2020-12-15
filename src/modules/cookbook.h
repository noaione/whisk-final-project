#ifndef MOD_COOKBOOK_H
#define MOD_COOKBOOK_H

// Definisikan semua struct dan sebagainya di sini.
struct Cookbook {
    char* title;
    char* ingredient[255];
    char* step[255];
};

void add_recipe();
void cook_book();

int viewCookbook();
// TODO: rename function
Cookbook *yoinkCookbookTutorial(int position);

#endif /* MOD_COOKBOOK_H */