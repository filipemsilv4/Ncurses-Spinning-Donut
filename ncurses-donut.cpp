// Compile with at least c++11 -> "g++ -std=c++11 main.cpp sort.cpp -lncurses -o main"
#include <ncurses.h>
#include <unistd.h>
#include <math.h>
#include <algorithm>

int main(void){
    // Originally Code by Andy Sloane https://www.a1k0n.net/2011/07/20/donut-math.html
    float A = 0, B = 0, i, j, z[1760];
    char b[1760];
    initscr(); // Initialize ncurses
    noecho(); // Don't echo keystrokes to the screen
    curs_set(0); // Hide the cursor
    clear(); // Clear the screen
    for(;;) {
        memset(b, 32, 1760);
        memset(z, 0, 7040);
        for(j = 0; 6.28 > j; j += 0.07) {
            for(i = 0; 6.28 > i; i += 0.02) {
                float c = sin(i), d = cos(j), e = sin(A), f = sin(j), g = cos(A), h = d + 2, D = 1 / (c * h * e + f * g + 5), l = cos(i), m = cos(B), n = sin(B), t = c * h * g - f * e;
                int x = 40 + 30 * D * (l * h * m - t * n), y = 12 + 15 * D * (l * h * n + t * m), o = x + 80 * y, N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);
                if(22 > y && y > 0 && x > 0 && 80 > x && D > z[o]) {
                    z[o] = D;
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }
        move(0, 0); // Move the cursor to the top-left corner of the screen
        for(int k = 0; 1761 > k; k++) {
            addch(k % 80 ? b[k] : '\n');
        }
        
        refresh(); // Refresh the screen
        A += 0.04;
        B += 0.02;
        usleep(50000); // Sleep for 50 milliseconds to slow down the animation
    }
    endwin(); // End ncurses mode
}