#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// PENGATURAN GAME
const int WAKTU_GAME = 600;
const int DURASI_TIKUS = 30;
const int JEDA_TIKUS = 10;
const int NYAWA_AWAL = 3;

// FUNGSI GAMBAR PAPAN 3X3
void gambarpapan(int tikus) {
    int mulaiY = 5;
    int mulaiX = 5;

    for (int baris = 0; baris < 3; baris++) {
        int y = mulaiY + baris * 2;

        // gambar garis pembatas atas
        mvprintw(y, mulaiX, "+---+---+---+");

        //isi kotak
        move(y + 1, mulaiX);
        for (int kolom = 0; kolom < 3; kolom++){
            int nomor = baris * 3 + kolom + 1;
            printw("|");
            if (nomor == tikus) {
                attron(COLOR_PAIR(1) | A_BOLD);
                printw(" (O) ");
                attroff(COLOR_PAIR(1) | A_BOLD);
            } else {
                printw(" %d ", nomor);
            }

        }
        printw("|");
    }
    // gambar garis pembatas terakhir
    mvprintw(mulaiY + 6, mulaiX, "+---+---+---+");
}