// the game you play in the house in zelda wind waker, you know
// by NH35 approximately in december 2020

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

////////////// VARIABLES ///////////////////


#define tmpCaseChar '?'

int nbExchangeValue = 100; //must be odd
#define RandBorneMax 16
#define RandBorneMin 1
int value1 = 0;
int value2 = 0;

bool isWin = false;
char ghostVar;
char grid[16 + 1 + 1]; //array 0 to 16 + the 16th case + the transistion case

int position = 16;
char instruction = ' ';

//////////////// SHOW ////////////////////
void show(void)
{
    system("cls"); //"clear" on linux (see #define)

    printf("------------------------------------\n");
    printf("  _____             _      \n");
    printf(" |_   _| __ ___ _ _|_|___  \n");
    printf("   | |  |. | . | | | |   | \n");
    printf("   |_| |___|_  |___|_|_|_| \n");
    printf("             |_|           by NH35\n");
    printf("------------------------------------\n");

    //printf("---------\n");
    printf("     %c %c %c %c \n", grid[1], grid[2], grid[3], grid[4]);
    printf("     %c %c %c %c        press 'h'\n", grid[5], grid[6], grid[7], grid[8]);
    printf("     %c %c %c %c        for help\n", grid[9], grid[10], grid[11], grid[12]);
    printf("     %c %c %c %c \n", grid[13], grid[14], grid[15], grid[16]);
    printf("------------------------------------\n");
}

void mix(void)
{
    for (int i = 0; i < nbExchangeValue; i++)
    {
        do
        {
            value1 = rand() % (RandBorneMax - RandBorneMin + 1 ) + RandBorneMin;
            value2 = rand() % (RandBorneMax - RandBorneMin + 1 ) + RandBorneMin;
        } while (value1 == value2);

        if (value1 == position)
        {
            position = value2;
        }
        else if (value2 == position)
        {
            position = value1;
        }

        grid[17] = grid[value1];
        grid[value1] = grid[value2];
        grid[value2] = grid[17];
        grid[17] = tmpCaseChar;
        show();
    }
}

int main(void)
{
    ///////// CASES NAME /////////////

    grid[0] = '!';                    //non utilisé
    grid[17] = tmpCaseChar; //case d'echange temporaire (#define)

    grid[1] = 'A';
    grid[2] = 'B';
    grid[3] = 'C';
    grid[4] = 'D';

    grid[5] = 'E';
    grid[6] = 'F';
    grid[7] = 'G';
    grid[8] = 'H';

    grid[9] = 'I';
    grid[10] = 'J';
    grid[11] = 'K';
    grid[12] = 'L';

    grid[13] = 'M';
    grid[14] = 'N';
    grid[15] = 'O';
    grid[16] = ' '; //case vide déplaçable

    show();

    //////////// LOOP //////////////
    show();
    mix();
    while (instruction != 'x' && isWin == false)
    {
        scanf("%c", &instruction);

        switch (instruction)
        {
        case 'z':
            if (position <= 4)
            {
                printf("but nothing happen..\n");
            }
            else
            {
                grid[17] = grid[position];
                grid[position] = grid[position - 4];
                grid[position - 4] = grid[17];
                grid[17] = tmpCaseChar;
                position = position - 4;
            }
            break;

        case 'q':
            if ((position - 1) % 4 == 0)
            {
                printf("but nothing happen..\n");
            }
            else
            {
                grid[17] = grid[position];
                grid[position] = grid[position - 1];
                grid[position - 1] = grid[17];
                grid[17] = tmpCaseChar;
                position = position - 1;
            }
            break;
        case 's':
            if (position >= 13)
            {
                printf("but nothing happen..\n");
            }
            else
            {
                grid[17] = grid[position];
                grid[position] = grid[position + 4];
                grid[position + 4] = grid[17];
                grid[17] = tmpCaseChar;
                position = position + 4;
            }
            break;
        case 'd':
            if (position % 4 == 0)
            {
                printf("but nothing happen..\n");
            }
            else
            {
                grid[17] = grid[position];
                grid[position] = grid[position + 1];
                grid[position + 1] = grid[17];
                grid[17] = tmpCaseChar;
                position = position + 1;
            }
            break;

        case 'm':
            mix();
            break;

        case 'h':
            system("cls");

            printf(" COMMANDS LIST :\n\n");
            printf(" 'h' : Show commands list.\n");
            printf(" 'z' : move the empty space UP.\n");
            printf(" 'q' : move the empty space LEFT.\n");
            printf(" 's' : move the empty space DOWN.\n");
            printf(" 'd' : move the empty space RIGHT.\n");
            printf(" 'm' : Mix elements positions.\n");
            printf(" 'c' : Show credits.\n");
            printf(" 'p' : Show available parameters.\n");
            printf(" 'x' : Exit.\n");

            printf("\n Note : it is possible to combine commands (ex wwwasssddssaa).\n");
            printf(" Try to do it in only one line ! ;)\n");
            printf(" One time i did it randomly zqdsdsddzqsd and win XD\n");
            printf("\n ------------------------------------\n");
            printf(" Press x + tenter to left this menu.\n");

            scanf(" %c", &ghostVar);
            break;

        case 'c':
            system("cls");

            printf(" Taquin completly create by NH35 the 26/10/2020.\n");
            printf("\n ------------------------------------\n");
            printf(" Press x + tenter to left this menu.\n");

            scanf(" %c", &ghostVar);
            break;

        case 'p':
            system("cls");

            printf("There is no parameters. I was lazy\n");
            
            printf("\n ------------------------------------\n\n");
            printf(" Press x + tenter to left this menu.\n");

            scanf(" %c", &ghostVar);
            break;
        case 'e':
            system("cls");

            printf("Nothing to see here !\n");
           

            scanf(" %c", &ghostVar);
            break;
        default:

            break;
        }
        show();

        ////////// WIN ////////////

        if (grid[1] == 'A' && grid[2] == 'B' && grid[3] == 'C' && grid[4] == 'D' && grid[5] == 'E' && grid[6] == 'F' && grid[7] == 'G' && grid[8] == 'H' && grid[9] == 'I' && grid[10] == 'J' && grid[11] == 'K' && grid[12] == 'L' && grid[13] == 'M' && grid[14] == 'N' && grid[15] == 'O')
        {
            printf(" This is the win !\n Enter 'x' to left the game, 'm' to do it again.");
            isWin = true;
        }
    }
    system("cls");
}
