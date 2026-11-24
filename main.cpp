#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

const int WAKTU_GAME = 600;
const int DURASI_TIKUS = 30;
const int JEDA_TIKUS = 10;
const int NYAWA_AWAL = 3;

void gambarpapan(int tikus) {
    int mulaiY = 5;
    int mulaiX = 5;

    for (int baris = 0; baris < 3; baris++) {
        int y = mulaiY + baris * 2;

        mvprintw(y, mulaiX, "+---+---+---+");

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
    mvprintw(mulaiY + 6, mulaiX, "+---+---+---+");
}

int main() {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);

    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);

    srand(time(0));

    int skor = 0;
    int nyawa = NYAWA_AWAL;
    int sisaWaktu = WAKTU_GAME;
    int tikus = 0;
    int timerTikus = 0;
    int jeda = JEDA_TIKUS;
    string pesan = "Tekan angka 1-9 untuk memukul! (q = keluar)";
    int warnaPesan = 0;
    
}