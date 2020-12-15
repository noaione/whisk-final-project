#ifndef MOD_HOMEPAGE_H
#define MOD_HOMEPAGE_H

struct Recipes {
    char description[255];
    char instructions[555];
    char ingridient[555];
};

// Renamed because conflict
struct HomepageNode {
    char name[255];
    Recipes recipes;
    int sumCooked;
    HomepageNode* next;
};

void close();
void homePage();
void printRecipes(HomepageNode* root);
void searchRecipes(HomepageNode* root, char* name);
int countRecipes(HomepageNode* root);
void showPreferences();
void printHomePage();
void homePage();

#endif /* MOD_HOMEPAGE_H */