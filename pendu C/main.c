#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_MOTS 1000
#define TAILLE_MOTS 50
#define TENTATIVE_MAX 7

char nomJoueur[30];
char lettre_trouve;
char mots[MAX_MOTS][TAILLE_MOTS];
char lettre_essayer[26] = {0};
char lettre_incorrecte[26] = {0};
int nombreMots = 0;
int tentative = 0;
int j = 0, k = 0;
int rejouer = 1;

void afficher_pendu(int tentative) {
    switch (tentative) {
        case 1:
            printf("   ____ \n");
            printf("   |    |       \n");
            printf("   |    o       \n");
            printf("   |            \n");
            printf("   |            \n");
            printf("   |            \n");
            printf("  _|_           \n");
            printf(" |   |______    \n");
            printf(" |          |   \n");
            printf(" |__________|   \n");
            printf("tentative : 6/7\n");
            break;
        case 2:
            printf("   ____ \n");
            printf("   |    |       \n");
            printf("   |    o       \n");
            printf("   |    |       \n");
            printf("   |            \n");
            printf("   |            \n");
            printf("  _|_           \n");
            printf(" |   |______    \n");
            printf(" |          |   \n");
            printf(" |__________|   \n");
            printf("tentative : 5/7\n");
            break;
        case 3:
            printf("   ____ \n");
            printf("   |    |       \n");
            printf("   |    o       \n");
            printf("   |   /|       \n");
            printf("   |            \n");
            printf("   |            \n");
            printf("  _|_           \n");
            printf(" |   |______    \n");
            printf(" |          |   \n");
            printf(" |__________|   \n");
            printf("tentative : 4/7\n");
            break;
        case 4:
            printf("   ____ \n");
            printf("   |    |       \n");
            printf("   |    o       \n");
            printf("   |   /|\\      \n");
            printf("   |            \n");
            printf("   |            \n");
            printf("  _|_           \n");
            printf(" |   |______    \n");
            printf(" |          |   \n");
            printf(" |__________|   \n");
            printf("tentative : 3/7\n");
            break;
        case 5:
            printf("   ____ \n");
            printf("   |    |       \n");
            printf("   |    o       \n");
            printf("   |   /|\\      \n");
            printf("   |    |       \n");
            printf("   |            \n");
            printf("  _|_           \n");
            printf(" |   |______    \n");
            printf(" |          |   \n");
            printf(" |__________|   \n");
            printf("tentative : 2/7\n");
            break;
        case 6:
            printf("   ____ \n");
            printf("   |    |       \n");
            printf("   |    o       \n");
            printf("   |   /|\\      \n");
            printf("   |    |       \n");
            printf("   |   /        \n");
            printf("  _|_           \n");
            printf(" |   |______    \n");
            printf(" |          |   \n");
            printf(" |__________|   \n");
            printf("tentative : 1/7\n");
            break;
        case 7:
            printf("   ____ \n");
            printf("   |    |       \n");
            printf("   |    o       \n");
            printf("   |   /|\\      \n");
            printf("   |    |       \n");
            printf("   |   / \\      \n");
            printf("  _|_           \n");
            printf(" |   |______    \n");
            printf(" |          |   \n");
            printf(" |__________|   \n");
            printf("tentative : 0/7\n");
            break;
        default:
            printf("   ____ \n");
            printf("   |    |       \n");
            printf("   |            \n");
            printf("   |            \n");
            printf("   |            \n");
            printf("   |            \n");
            printf("  _|_           \n");
            printf(" |   |______    \n");
            printf(" |          |   \n");
            printf(" |__________|   \n");
            printf("tentative : 7/7\n");
            break;
    }
}

char lire_une_lettre() {
    char buffer[10];
    char lettre;

    while (1) {
        printf("Entrez une lettre : ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, " %c", &lettre) == 1 && isalpha(lettre) && buffer[1] == '\n') {
                return lettre;
            }
        }
        printf("Entree invalide. Veuillez entrer UNE seule lettre (pas de chiffres ou symboles).\n");
    }
}

int demander_rejouer() {
    char buffer[10];
    int choix;

    while (1) {
        printf("Voulez-vous rejouer ? (1 pour oui, 0 pour non) : ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, " %d", &choix) == 1 && (choix == 0 || choix == 1)) {
                return choix;
            }
        }
        printf("Entree invalide. Veuillez entrer 1 pour oui ou 0 pour non.\n");
    }
}

int main() {


    while (rejouer) {

        while(1) {
               printf("Entrez votre nom : ");
        if(fgets(nomJoueur, sizeof(nomJoueur), stdin) != NULL) {
            nomJoueur[strcspn(nomJoueur, "\n")] = '\0';
            if (strlen(nomJoueur) == 0) {
                printf ("Le nom ne peut pas etre vide. Veulliez entrez un autre nom.\n");
            } else {
                break;
            }
        };
        }



        printf("Bienvenue, %s, dans le jeu du pendu !\n", nomJoueur);

        FILE *file = fopen("..\\words.txt", "r");
        if (file == NULL) {
            printf("Erreur lors de l'ouverture du fichier.\n");
            return 1;
        }

        while (fgets(mots[nombreMots], TAILLE_MOTS, file) != NULL && nombreMots < MAX_MOTS) {
            mots[nombreMots][strcspn(mots[nombreMots], "\n")] = '\0';
            nombreMots++;
        }
        fclose(file);

        srand(time(NULL));
        int random_world = rand() % nombreMots;
        char *mot_pendu = mots[random_world];
        int length = strlen(mot_pendu);

        char underscore[TAILLE_MOTS];
        for (int i = 0; i < length; i++) {
            underscore[i] = '_';
        }
        underscore[length] = '\0';

        do {

            printf("\nLe mot est : %s\n", underscore);
            printf("Lettres incorrectes essayees : ");
            for (int i = 0; i < k; i++) {
                printf("%c ", lettre_incorrecte[i]);
            }
            printf("\n");

            afficher_pendu(tentative);
            lettre_trouve = lire_une_lettre();

            bool deja_essaye = 0;
            for (int i = 0; i < j; i++) {
                if (lettre_trouve == lettre_essayer[i]) {
                    deja_essaye = 1;
                    break;
                }
            }

            if (deja_essaye) {
                printf("Vous avez deja essaye cette lettre : %c\n", lettre_trouve);
                continue;
            }

            lettre_essayer[j++] = lettre_trouve;

            bool lettre_correcte = 0;
            for (int i = 0; i < length; i++) {
                if (tolower(mot_pendu[i]) == tolower(lettre_trouve) && underscore[i] == '_') {
                    underscore[i] = mot_pendu[i];
                    lettre_correcte = 1;
                }
            }

            if (!lettre_correcte) {
                printf("Lettre incorrecte !\n");
                lettre_incorrecte[k++] = lettre_trouve;
                tentative++;
            }

        } while (tentative < TENTATIVE_MAX && strcmp(underscore, mot_pendu) != 0);

        afficher_pendu(tentative);
        if (strcmp(underscore, mot_pendu) == 0) {
            printf("Felicitations, %s ! Vous avez devine le mot : %s\n", nomJoueur, mot_pendu);
        } else {
            printf("Dommage, %s. Le mot etait : %s\n", nomJoueur, mot_pendu);
        }


        tentative = 0;
        j = 0;
        k = 0;
        memset(lettre_essayer, 0, sizeof(lettre_essayer));
        memset(lettre_incorrecte, 0, sizeof(lettre_incorrecte));

        rejouer = demander_rejouer();
    }

    return 0;
}