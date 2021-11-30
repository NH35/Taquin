#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/////////////////////////////////

#define cls clear //si activé alors c'est pour linux

#define CaseTemporaireSymbole '?'

int nbEchangeValeur = 100; //doit etre pair
#define RandBorneMax 16
#define RandBorneMin 1
int valeur1 = 0;
int valeur2 = 0;

bool victoire = false;
char variableFantome;
char tableau[16 + 1 + 1]; //tableau de 0 a 15 + la case 16 + case de transition

int localisation = 16;
char instruction = ' ';

////////////////////////////////////
void afficher(void)
{
    system("cls"); //"clear" sous linux (voir #define)

    printf("------------------------------------\n");
    printf("  _____             _      \n");
    printf(" |_   _| __ ___ _ _|_|___  \n");
    printf("   | |  |. | . | | | |   | \n");
    printf("   |_| |___|_  |___|_|_|_| \n");
    printf("             |_|           by hippo\n");
    printf("------------------------------------\n");

    //printf("---------\n");
    printf("     %c %c %c %c \n", tableau[1], tableau[2], tableau[3], tableau[4]);
    printf("     %c %c %c %c        press 'h'\n", tableau[5], tableau[6], tableau[7], tableau[8]);
    printf("     %c %c %c %c        for help\n", tableau[9], tableau[10], tableau[11], tableau[12]);
    printf("     %c %c %c %c \n", tableau[13], tableau[14], tableau[15], tableau[16]);
    printf("------------------------------------\n");
}

void melanger(void)
{
    for (int i = 0; i < nbEchangeValeur; i++)
    {
        do
        {
            valeur1 = rand() % (RandBorneMax - RandBorneMin + 1 ) + RandBorneMin;
            valeur2 = rand() % (RandBorneMax - RandBorneMin + 1 ) + RandBorneMin;
        } while (valeur1 == valeur2);

        if (valeur1 == localisation)
        {
            localisation = valeur2;
        }
        else if (valeur2 == localisation)
        {
            localisation = valeur1;
        }

        tableau[17] = tableau[valeur1];
        tableau[valeur1] = tableau[valeur2];
        tableau[valeur2] = tableau[17];
        tableau[17] = CaseTemporaireSymbole;
        afficher();
    }
}

int main(void)
{
    /////////ATTRIBUTION DES NOMS DE CASES/////////////

    tableau[0] = '!';                    //non utilisé
    tableau[17] = CaseTemporaireSymbole; //case d'echange temporaire (#define)

    tableau[1] = 'A';
    tableau[2] = 'B';
    tableau[3] = 'C';
    tableau[4] = 'D';

    tableau[5] = 'E';
    tableau[6] = 'F';
    tableau[7] = 'G';
    tableau[8] = 'H';

    tableau[9] = 'I';
    tableau[10] = 'J';
    tableau[11] = 'K';
    tableau[12] = 'L';

    tableau[13] = 'M';
    tableau[14] = 'N';
    tableau[15] = 'O';
    tableau[16] = ' '; //case vide déplaçable

    afficher();

    ////////////BOUCLE DE tableau//////////////
    afficher();
    melanger();
    while (instruction != 'x' && victoire == false)
    {
        scanf("%c", &instruction);

        switch (instruction)
        {
        case 'z':
            if (localisation <= 4)
            {
                printf("mais rien ne se passe..\n");
            }
            else
            {
                tableau[17] = tableau[localisation];
                tableau[localisation] = tableau[localisation - 4];
                tableau[localisation - 4] = tableau[17];
                tableau[17] = CaseTemporaireSymbole;
                localisation = localisation - 4;
            }
            break;

        case 'q':
            if ((localisation - 1) % 4 == 0)
            {
                printf("mais rien ne se passe..\n");
            }
            else
            {
                tableau[17] = tableau[localisation];
                tableau[localisation] = tableau[localisation - 1];
                tableau[localisation - 1] = tableau[17];
                tableau[17] = CaseTemporaireSymbole;
                localisation = localisation - 1;
            }
            break;
        case 's':
            if (localisation >= 13)
            {
                printf("mais rien ne se passe..\n");
            }
            else
            {
                tableau[17] = tableau[localisation];
                tableau[localisation] = tableau[localisation + 4];
                tableau[localisation + 4] = tableau[17];
                tableau[17] = CaseTemporaireSymbole;
                localisation = localisation + 4;
            }
            break;
        case 'd':
            if (localisation % 4 == 0)
            {
                printf("mais rien ne se passe..\n");
            }
            else
            {
                tableau[17] = tableau[localisation];
                tableau[localisation] = tableau[localisation + 1];
                tableau[localisation + 1] = tableau[17];
                tableau[17] = CaseTemporaireSymbole;
                localisation = localisation + 1;
            }
            break;

        case 'm':
            melanger();
            break;

        case 'h':
            system("cls");

            printf(" LISTE DES COMMANDES :\n\n");
            printf(" 'h' : Afficher la liste des commandes.\n");
            printf(" 'z' : Deplacer vers le haut la case vide.\n");
            printf(" 'q' : Deplacer vers la gauche la case vide.\n");
            printf(" 's' : Deplacer vers le bas la case vide.\n");
            printf(" 'd' : Deplacer vers la droite la case vide.\n");
            printf(" 'm' : Melanger le taquin.\n");
            printf(" 'c' : Afficher les credits.\n");
            printf(" 'p' : Afficher les parametres disponibles.\n");
            printf(" 'x' : Quitter.\n");

            printf("\n Note : Il est possible de combiner les commandes (ex qzdsdzdszzzqsssddqz).\n");
            printf(" Essaye donc de le faire en une ligne ! ;)\n");
            printf(" Une fois j'ai tappe au pif zqdsdsddzqsd et j'ai reussi XD\n");
            printf("\n ------------------------------------\n");
            printf(" Appuyer sur x + entrer pour quitter ce menu.\n");

            scanf(" %c", &variableFantome);
            break;

        case 'c':
            system("cls");

            printf(" Taquin creer completement par Hippolyte ROUSSEL le 26/10/2020.\n");
            printf("\n ------------------------------------\n");
            printf(" Appuyer sur x + entrer pour quitter ce menu.\n");

            scanf(" %c", &variableFantome);
            break;

        case 'p':
            system("cls");

            printf("enfaite y'a pas de parametre j'avais la flemme...\n");
            
            printf("\n ------------------------------------\n\n");
            printf("Appuyer sur x + entrer pour quitter ce menu.\n");

            scanf(" %c", &variableFantome);
            break;
        case 'e':
            system("cls");

            printf("Nothing to see here !\n");
           

            scanf(" %c", &variableFantome);
            break;
        default:

            break;
        }
        afficher();

        //////////VICTOIRE////////////

        if (tableau[1] == 'A' && tableau[2] == 'B' && tableau[3] == 'C' && tableau[4] == 'D' && tableau[5] == 'E' && tableau[6] == 'F' && tableau[7] == 'G' && tableau[8] == 'H' && tableau[9] == 'I' && tableau[10] == 'J' && tableau[11] == 'K' && tableau[12] == 'L' && tableau[13] == 'M' && tableau[14] == 'N' && tableau[15] == 'O')
        {
            printf(" C'est la victoire !\n Entrer 'x' pour arreter, 'r' pour recommencer.");
            victoire = true;
        }
    }
    system("cls");
}
