#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <array>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

std::wstring sudoku;
std::array<int, 81> ar = { 8, 5, 0, 0, 0, 2, 4, 0, 0,
                             7, 2, 0, 0, 0, 0, 0, 0, 9,
                             0, 0, 4, 0, 0, 0, 0, 0, 0,
                             0, 0, 0, 1, 0, 7, 0, 0, 2,
                             3, 0, 5, 0, 0, 0, 9, 0, 0,
                             0, 4, 0, 0, 0, 0, 0, 0, 0,
                             0, 0, 0, 0, 8, 0, 0, 7, 0,
                             0, 1, 7, 0, 0, 0, 0, 0, 0,
                             0, 0, 0, 0, 3, 6, 0, 4, 0};
std::array<int, 81> solved = { 8, 5, 9, 6, 1, 2, 4, 3, 7,
                               7, 2, 3, 8, 5, 4, 1, 6, 9,
                               1, 6, 4, 3, 7, 9, 5, 2, 8,
                               9, 8, 6, 1, 4, 7, 3, 5, 2,
                               3, 7, 5, 2, 6, 8, 9, 1, 4,
                               2, 4, 1, 5, 9, 3, 7, 8, 6,
                               4, 3, 2, 9, 8, 1, 6, 7, 5,
                               6, 1, 7, 4, 2, 5, 8, 9, 3,
                               5, 9, 8, 7, 3, 6, 2, 4, 1 };


int * index = nullptr;
int WIDTH = 38;
int HEIGHT = 19;
int USER_POS = WIDTH + 2;
int ARR_LOCATION = 0;
int ARR_LENGTH = 81;

void ClearScreen()
{
    COORD cursorPosition;	    cursorPosition.X = 0;	cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void getUserPos(char key = 0)
{
    switch (key)
    {
        case UP:
            if (USER_POS - WIDTH <= WIDTH)
            {
                USER_POS += WIDTH * (HEIGHT - 3);
                ARR_LOCATION += 72;
            }
            else
            {
                USER_POS-= WIDTH * 2;
                ARR_LOCATION -= 9;
            }
            break;
        case DOWN:
            if (USER_POS + WIDTH >= WIDTH * (HEIGHT - 1))
            {
                USER_POS -= WIDTH * (HEIGHT - 3);
                ARR_LOCATION -= 72;
            }
            else
            {
                USER_POS+= WIDTH * 2;
                ARR_LOCATION += 9;
            }
            break;
        case RIGHT:
            for (int i = USER_POS + 2; i < sudoku.length(); ++i) {
                if (sudoku[i] == '&')
                {
                    USER_POS = i - 1;
                    ARR_LOCATION++;
                    if(ARR_LOCATION >= ARR_LENGTH){
                        ARR_LOCATION = 0;
                    }
                    return;
                }
            }
            USER_POS = WIDTH;
            getUserPos(key);
            break;
        case LEFT:
            for (int i = USER_POS; i > 0; --i) {
                if (sudoku[i] == '&')
                {
                    USER_POS = i - 1;
                    ARR_LOCATION--;
                    if(ARR_LOCATION < 0){
                        ARR_LOCATION = ARR_LENGTH - 1;
                    }
                    return;
                }
            }
            USER_POS = (int) sudoku.length() - WIDTH;
            getUserPos(key);
            break;
        default:
            break;

    }
}

void printSudoku()
{
    ClearScreen();
    index = ar.data();
    int col = 0;
    for (int i = 0; i < sudoku.length(); i++)
    {
        if (i == USER_POS)
        {
            std::wcout << '|';
            continue;
        }
        if (sudoku[i] == '&')
        {
            if (*index != 0)
            {
                std::wcout << *index;
            }
            else
            {
                std::wcout << ' ';
            }
            index++;
        }
        else
        {
            std::wcout << sudoku[i];
        }
        col++;

    }
    std::cout << std::endl;

}

int main()
{
    sudoku += L"\nÉÍÍÍÍÍÍÍÍÍÍÍËÍÍÍÍÍÍÍÍÍÍÍËÍÍÍÍÍÍÍÍÍÍÍ»";
    sudoku += L"\nº & ³ & ³ & º & ³ & ³ & º & ³ & ³ & º";
    sudoku += L"\nºÄÄÄÅÄÄÄÅÄÄÄºÄÄÄÅÄÄÄÅÄÄÄºÄÄÄÅÄÄÄÅÄÄÄº";
    sudoku += L"\nº & ³ & ³ & º & ³ & ³ & º & ³ & ³ & º";
    sudoku += L"\nºÄÄÄÅÄÄÄÅÄÄÄºÄÄÄÅÄÄÄÅÄÄÄºÄÄÄÅÄÄÄÅÄÄÄº";
    sudoku += L"\nº & ³ & ³ & º & ³ & ³ & º & ³ & ³ & º";
    sudoku += L"\nÌÍÍÍÍÍÍÍÍÍÍÍÎÍÍÍÍÍÍÍÍÍÍÍÎÍÍÍÍÍÍÍÍÍÍÍ¹";
    sudoku += L"\nº & ³ & ³ & º & ³ & ³ & º & ³ & ³ & º";
    sudoku += L"\nºÄÄÄÅÄÄÄÅÄÄÄºÄÄÄÅÄÄÄÅÄÄÄºÄÄÄÅÄÄÄÅÄÄÄº";
    sudoku += L"\nº & ³ & ³ & º & ³ & ³ & º & ³ & ³ & º";
    sudoku += L"\nºÄÄÄÅÄÄÄÅÄÄÄºÄÄÄÅÄÄÄÅÄÄÄºÄÄÄÅÄÄÄÅÄÄÄº";
    sudoku += L"\nº & ³ & ³ & º & ³ & ³ & º & ³ & ³ & º";
    sudoku += L"\nÌÍÍÍÍÍÍÍÍÍÍÍÎÍÍÍÍÍÍÍÍÍÍÍÎÍÍÍÍÍÍÍÍÍÍÍ¹";
    sudoku += L"\nº & ³ & ³ & º & ³ & ³ & º & ³ & ³ & º";
    sudoku += L"\nºÄÄÄÅÄÄÄÅÄÄÄºÄÄÄÅÄÄÄÅÄÄÄºÄÄÄÅÄÄÄÅÄÄÄº";
    sudoku += L"\nº & ³ & ³ & º & ³ & ³ & º & ³ & ³ & º";
    sudoku += L"\nºÄÄÄÅÄÄÄÅÄÄÄºÄÄÄÅÄÄÄÅÄÄÄºÄÄÄÅÄÄÄÅÄÄÄº";
    sudoku += L"\nº & ³ & ³ & º & ³ & ³ & º & ³ & ³ & º";
    sudoku += L"\nÈÍÍÍÍÍÍÍÍÍÍÍÊÍÍÍÍÍÍÍÍÍÍÍÊÍÍÍÍÍÍÍÍÍÍÍ¼";

    printSudoku();
    char input = 0;
    while (1)
    {
        input = 0;
        //std::cin >> input;
        input = (char) _getch();
        if (input)
        {
            if (ar == solved){
                std::cout << "solved!" << std::endl;
            }else
                std::cout << "not solved!" << std::endl;
            //std::cout << (int) input << std::endl;
            if (49 <= input and input <= 57)
            {
                ar[ARR_LOCATION] = (int) input - 0x30;
            }
            else if (input == 8)
            {
                ar[ARR_LOCATION] = 0;
            }
            else
            {
                getUserPos(input);
            }
            printSudoku();
        }
    }
    return 0;
}
