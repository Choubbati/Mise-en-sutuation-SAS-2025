#include <stdio.h>
#include <string.h>

struct Produit {
    char Nom[50];
    float prix;
    int quantite;
    int categorie;
};

void afficheProduit(struct Produit inventaire[], int n) {
    printf("id | Nom | Prix | Quantité | Catégorie\n");
    for (int i = 0; i < n; i++) {
        printf("%d) %s - %.2f - %d - %d\n", i + 1, inventaire[i].Nom, inventaire[i].prix, inventaire[i].quantite, inventaire[i].categorie);
    }
}

void chercheProduit(struct Produit inventaire[], int n, char productSearch[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(inventaire[i].Nom, productSearch) == 0) {
            printf("Produit trouvé : %s - %.2f - %d - %d\n", inventaire[i].Nom, inventaire[i].prix, inventaire[i].quantite, inventaire[i].categorie);
            return;
        }
    }
    printf("Produit non trouvé.\n");
}

int supprimerProduit(struct Produit inventaire[], int n, char nomSup[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(inventaire[i].Nom, nomSup) == 0) {
            for (int j = i; j < n - 1; j++) {
                inventaire[j] = inventaire[j + 1];
            }
            printf("Le produit '%s' a été supprimé.\n", nomSup);
            return n - 1;
        }
    }
    printf("Produit non trouvé pour suppression.\n");
    return n;
}

int main() {
    struct Produit inventaire[50];
    int n = 0, choix;
    char productSearch[50];
    char nomSup[50];

    do {
        printf("\n=========== MENU ===========\n");
        printf("1. Ajouter produit\n");
        printf("2. Afficher inventaire\n");
        printf("3. Rechercher produit\n");
        printf("4. Supprimer produit\n");
        printf("5. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Combien de produits voulez-vous ajouter ? ");
                int ajout;
                scanf("%d", &ajout);

                for (int i = 0; i < ajout; i++) {
                    printf("Produit %d\n", n + 1);
                    printf("Nom : ");
                    scanf("%s", inventaire[n].Nom);

                    do {
                        printf("Prix : ");
                        scanf("%f", &inventaire[n].prix);
                        printf("Quantite : ");
                        scanf("%d", &inventaire[n].quantite);
                    } while (inventaire[n].prix < 0 || inventaire[n].quantite <= 0);

                    printf("Categorie (1-3) : ");
                    scanf("%d", &inventaire[n].categorie);

                    n++;
                }
                break;

            case 2:
                afficheProduit(inventaire, n);
                break;

            case 3:
                printf("Entrer le nom du produit à rechercher : ");
                scanf("%s", productSearch);
                chercheProduit(inventaire, n, productSearch);
                break;

            case 4:
                printf("Entrer le nom du produit à supprimer : ");
                scanf("%s", nomSup);
                n = supprimerProduit(inventaire, n, nomSup);
                break;

            case 5:
                printf("Au revoir !\n");
                break;

            default:
                printf("Choix invalide.\n");
        }

    } while (choix != 5);

    return 0;
}
