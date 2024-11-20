#include "TicTacToe.h"
#include <iostream>
#include <string>
using namespace std;

int ORDI = 1;
int VORDI = 1;
int HUMAIN = -1;
int VHUMAIN = -1;
bool test = false;

TicTacToe::TicTacToe()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            this->T[i][j] = 0;
        }
    }
}

void TicTacToe::affichage()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "   " << T[i][j];
            if (j == 2)
            {
                cout << endl;
            }
        };
    }
}

int TicTacToe::jeuOrdi(int &bestMove)
{
    int arg;
    int res;
    if (this->plein())
    {
        return (0);
    }
    if (this->coupGagnant(ORDI, bestMove))
    {
        return VORDI;
    }
    int val = VHUMAIN;
    for (int i = 0; i < 9; i++)
    {
        if (this->vide(i))
        {
            jouer(i, ORDI);
            res = this->jeuHumain(arg);
            retourArriere(i);
            if (res > val)
            {
                val = res;
                bestMove = i;
            }
        }
    }
    return val;
}

int TicTacToe::jeuHumain(int &bestMove)
{
    int arg;
    int res;
    if (this->plein())
    {
        return (0);
    }
    if (this->coupGagnant(HUMAIN, bestMove))
    {
        return VHUMAIN;
    }
    int val = VORDI;
    for (int i = 0; i < 9; i++)
    {
        if (this->vide(i))
        {
            jouer(i, HUMAIN);
            res = this->jeuOrdi(arg);
            retourArriere(i);
            if (res < val)
            {
                val = res;
                bestMove = i;
            }
        }
    }
    return val;
}

bool TicTacToe::coupGagnant(int player, int &bestMove)
{
    bool gagner = false;
    int i = 0;
    while (i < 9 and gagner == false)
    {
        if (this->vide(i))
        {
            T[i / 3][i % 3] = player;
            if (this->victoire(player))
            {
                bestMove = i;
                gagner = true;
            }
            T[i / 3][i % 3] = 0;
        }
        i++;
    }
    return gagner;
}

void TicTacToe::retourArriere(int i)
{
    T[i / 3][i % 3] = 0;
}

bool TicTacToe::victoire(int player)
{
    if (test)
    {
        cout << "entrée victoire" << endl;
        cout << "player vaut : " << player << endl;
    }
    bool victory = false;
    int i = 0;
    while (i < 9 && victory == false)
    {
        if (checkLigne(i, player) || checkColonne(i, player) || checkDiago(player))
        {
            if (test)
            {
                cout << "on retourne une victoire validée" << endl;
            }
            victory = true;
        }
        i++;
    }
    return victory;
}

bool TicTacToe::checkLigne(int i, int player)
{
    if (test)
    {
        cout << "Entrée check ligne" << endl;
    }
    return T[i / 3][0] == player && T[i / 3][1] == player && T[i / 3][2] == player;
}

bool TicTacToe::checkColonne(int i, int player)
{
    if (test)
    {
        cout << "Entrée check colonne" << endl;
    }
    return T[0][i % 3] == player && T[1][i % 3] == player && T[2][i % 3] == player;
}

bool TicTacToe::checkDiago(int player)
{
    if (test)
    {
        cout << "Entrée check diago avec player = " << player << endl;
    }
    return ((T[0][0] == player && T[1][1] == player && T[2][2] == player) || (T[0][2] == player && T[1][1] == player && T[2][0] == player));
}

int TicTacToe::arbitre()
{
    if (test)
    {
        cout << "Entrée fonction arbitre" << endl;
        cout << "ORDI vaut : " << ORDI << endl;
        cout << "HUMAIN vaut : " << HUMAIN << endl;
    }
    if (this->victoire(ORDI))
    {
        if (test)
        {
            cout << "Victoire ordi validée" << endl;
        }
        return 1;
    }
    if (this->victoire(HUMAIN))
    {
        if (test)
        {
            cout << "Victoire humain validée" << endl;
        }
        return -1;
    }
    if (this->plein())
    {
        if (test)
        {
            cout << "Match nul validé" << endl;
        }
        return 0;
    }
    else
    {
        if (test)
        {
            cout << "Pas encore d'issue" << endl;
        }
        return -20;
    }
}

bool TicTacToe::plein()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (this->T[i][j] == 0)
                return false;
        }
    }
    return true;
}

bool TicTacToe::vide(int i)
{
    if (T[i / 3][i % 3] == 0)
    {
        return true;
    }
    else
        return false;
}

void TicTacToe::jouer(int i, int player)
{
    T[i / 3][i % 3] = player;
}

int TicTacToe::actionHumain()
{
    int i;
    cout << "Sur quelle case souhaitez-vous jouer ?" << endl;
    cin >> i;
    while ((i < 0 || i > 8) || !this->vide(i))
    {
        if (!this->vide(i))
        {
            cout << "Case remplie" << endl;
        }
        if (i < 0 || i > 8)
        {
            cout << "Case hors table";
        }
        cout << "Sur quelle case souhaitez-vous jouer ?" << endl;
        cin >> i;
    }
    return i;
}
