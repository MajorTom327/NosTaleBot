#include "visual.h"

void    show_bar(void)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int col;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    col = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int i(-1);
    while (++i < col)
        std::cout << "#";
    //std::cout << std::endl;
}

void    align_name(char * appname)
{
    int lenght;
    int col;

    lenght = 0;
    while (appname[lenght] != '\0')
        lenght++;
    system("cls");
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    col = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int sizeBefore = (col - lenght) / 2;
    show_bar();
    for (int i = 0;i <= sizeBefore; i++)
        std::cout << " ";
    std::cout << appname << std::endl;
    show_bar();
}

void    show_help(void)
{
    std::cout << "HOME: Start Bot\nEND: Pause Bot\nF12: Quit" << std::endl;
    show_bar();
}
