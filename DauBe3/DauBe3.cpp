#include<iostream>
#include<iomanip>
#include<windows.h>
#include"mmsystem.h"
#include <cstdlib>
#include<thread>
#pragma comment(lib, "Winmm.lib")
using namespace std;

void TextColor(int x)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}

void SET_COLOR(int color)
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

void drawI() {
    for (int i = 1; i <= 6; i++) {
        cout << left << setw(79) << " ";
        for (int j = 1; j <= 5; j++) {
            TextColor(2);
            if (i == 1 || i == 6) {
                cout << "*";
            }
            else if (i == 2 || i == 3 || i == 4 || i == 5) {
                if (j == 3) cout << "*";
                else cout << " ";
            }
        }
        Sleep(100);
        cout << endl;
    }
}



void drawHeart() {
    float x, y, z;
    for (y = 1.5; y > -1.5; y -= 0.1) {
        cout << left << setw(50) << " ";
        for (x = -1.5; x < 1.5; x += 0.05) {
            z = x * x + y * y - 1;
            putchar(z * z * z - x * x * y * y * y <= 0.0 ? '*' : ' ');
        }
        Sleep(100);
        putchar('\n');
    }
}



void drawU() {
    for (int i = 1; i <= 8; i++) {
        cout << left << setw(73) << " ";
        for (int j = 1; j <= 15; j++) {
            TextColor(1);
            if (i == 8) cout << "*";
            if (i == 1 || i == 2 || i == 3 || i == 4 || i == 5 || i == 6 || i == 7) {
                if (j == 1 || j == 15) cout << "*";
                else cout << " ";
            }
        }
        Sleep(100);
        cout << endl;
    }
}

void YourFunction()
{
    PlaySound(TEXT("music.wav"), NULL, SND_FILENAME | SND_SYNC);
}


int main() {
    thread worker1(YourFunction);
    while (true)
    {
        system("cls");
        drawI();
        SET_COLOR(4);
        drawHeart();
        drawU();
        Sleep(200);
        system("color 5");
        Sleep(500);
    }
    return 0;
}