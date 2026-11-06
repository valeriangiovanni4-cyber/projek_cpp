#include <iostream>
#include <string>
using namespace std;

struct Game {
    string judul;
    int umurMin;
    string genre;
    int tahun;
    string tipe;
};

int main() {

    Game game[10] = {
        {"Minecraft",      7,  "sandbox", 2011, "multiplayer"},
        {"The Witcher 3",  18, "rpg",     2015, "singleplayer"},
        {"Hades",          12, "action",  2020, "singleplayer"},
        {"Portal 2",       12, "puzzle",  2011, "singleplayer"},
        {"Among Us",       10, "party",   2018, "multiplayer"},
        {"Elden Ring",     16, "rpg",     2022, "singleplayer"},
        {"Valorant",       16, "action",  2020, "multiplayer"},
        {"Genshin Impact", 12, "rpg",     2020, "multiplayer"},
        {"Tetris Effect",  3,  "puzzle",  2018, "singleplayer"},
        {"Terraria",       12, "sandbox", 2011, "multiplayer"}
    };
    int jumlah = 10;

    int umur, tahunMin;
    string genre, tipe;

    cout << "Umur kamu                          : ";
    cin >> umur;
    cout << "Genre (rpg/action/puzzle/sandbox/party) : ";
    cin >> genre;
    cout << "Rilis dari tahun berapa?           : ";
    cin >> tahunMin;
    cout << "Tipe (singleplayer/multiplayer)    : ";
    cin >> tipe;

    int skor[10];
    for (int i = 0; i < jumlah; i++) {
        skor[i] = 0;

        if (umur < game[i].umurMin) {
            skor[i] = -1;               
             else {
            if (game[i].genre == genre)      skor[i] += 3;
            if (game[i].tipe == tipe)        skor[i] += 2;
            if (game[i].tahun >= tahunMin)   skor[i] += 1;
        }
    }

    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - 1 - i; j++) {
            if (skor[j] < skor[j + 1]) {
                // tukar skor
                int tmpSkor = skor[j];
                skor[j] = skor[j + 1];
                skor[j + 1] = tmpSkor;
                // tukar game (harus ikut ditukar)
                Game tmpGame = game[j];
                game[j] = game[j + 1];
                game[j + 1] = tmpGame;
            }
        }
    }

    cout << "\n=== REKOMENDASI UNTUKMU ===\n";
    int nomor = 0;
    for (int i = 0; i < jumlah; i++) {
        if (skor[i] > 0 && nomor < 3) {
            nomor++;
            cout << nomor << ". " << game[i].judul
                 << " (" << game[i].genre << ", "
                 << game[i].tahun << ", "
                 << game[i].tipe << ")\n";
        }
    }

    if (nomor == 0) {
        cout << "Tidak ada game yang cocok.\n";
    }

    return 0;
}