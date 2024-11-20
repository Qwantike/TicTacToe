using namespace std;

class TicTacToe
{
private:
    int T[3][3];

public:
    TicTacToe();
    void affichage();
    int jeuOrdi(int &bestMove);
    int jeuHumain(int &bestMove);
    int arbitre();
    bool plein();
    bool vide(int i);
    bool coupGagnant(int player, int &bestMove);
    bool victoire(int player);
    bool checkLigne(int i, int player);
    bool checkColonne(int i, int player);
    bool checkDiago(int player);
    void retourArriere(int i);
    void jouer(int i, int player);
    int actionHumain();
};
