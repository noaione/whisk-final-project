#ifndef MOD_HOMEPAGE_H
#define MOD_HOMEPAGE_H

#define CLEAR system("cls||clear")
#define ENTER printf("Press enter to continue...")

struct Recipes {
  char description[255];
  char instructions[555];
  char ingridient[555];
};
struct Node {
  char name[255];
  Recipes recipes;
  int sumCooked;
  Node* next;
} *base;

void close();
void homePage();
void printRecipes(Node* root);
void searchRecipes(Node* root, char* name);
int countRecipes(Node* root);
void showPreferences();
void printHomePage();
void homePage();

#endif /* MOD_HOMEPAGE_H */