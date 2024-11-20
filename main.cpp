#include "TicTacToe.cpp"
#include <time.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int ORDI = 1;
    int VORDI = 1;
    int HUMAIN = -1;
    int VHUMAIN = -1;
    TicTacToe *game = new TicTacToe();
    // faire une pièce entre 0 et 1 pour savoir qui commence.
    srand(time(NULL));
    int piece = rand() % 2;
    // 0 humain premier
    // 1 ordi premier
    int check = -20;
    while (check != -1 && check != 1 && check != 0)
    {
        game->affichage();
        // Humain joue
        if (piece == 0)
        {
            game->jouer(game->actionHumain(), HUMAIN);
        }
        // Ordi joue
        else if (piece == 1)
        {
            int bestMove;
            game->jeuOrdi(bestMove);
            game->jouer(bestMove, ORDI);
        }
        cout << endl;
        check = game->arbitre();
        if (piece == 0)
            piece = 1;
        else
            piece = 0;
    }
    if (check == -1)
    {
        cout << "Victoire ! " << endl;
    }
    if (check == 1)
    {
        cout << "Perdu ! " << endl;
    }
    if (check == 0)
    {
        cout << "Match nul !" << endl;
    }
}