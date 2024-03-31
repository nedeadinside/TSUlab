#include<fstream>
#include<random>
#include "sort.h"
#include "player.h"

using namespace std;

int main() {
    int n = 100;
    srand(42);

    player** PL;
    PL = new player * [n];

    for (int i = 0; i < n; i++)
        PL[i] = new player(rand() % 26, rand() % 6, rand() % 241 + 60, rand() % 21, i + 1);

    Sort<player>::piramid(n, PL);

    ofstream fout;
    fout.open("Outpl.txt", ios::trunc);

    for (int i = 0; i < n; i++)
        fout << *PL[i] << "\n";

    fout.close();
    return 0;
}
