#include <iostream>
#define WINVER 0x0500
#include <windows.h>
//#include <winuser.h>
#include <time.h>
#include "visual.h"
#include "bot.h"

LPCSTR LGameWindow = "NosTale";
std::string GameStatus;
bool updateNextRun;
bool isGameAvail;

int main()
{
    bool bot_status;
    int refreshTimer;
    int botTimer;
    int total_life;
    int current_life;
    INPUT ip;
    RECT r;

    HWND console = GetConsoleWindow();
    GetWindowRect(console, &r);
    MoveWindow(console,r.left, r.top,400,512 ,true);

    bot_status = false;
    refreshTimer = clock();
    botTimer = clock();
    total_life = 0;
    current_life = 0;
    // Set up a generic keyboard event.
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0; // hardware scan code for key
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;


    //Handle part
    HWND hGameWindow = NULL;
    DWORD dwProcID = NULL;
    HANDLE hProcHandle = NULL;
    int GameAvailTMR = clock();

    //Main Loop
    while (!GetAsyncKeyState(VK_F12))
    {

        GameAvailTMR = clock();
        isGameAvail = false;

        hGameWindow = FindWindow(NULL,LGameWindow); // trouver la fenetre
        if (hGameWindow)
        {
            GetWindowThreadProcessId(hGameWindow, &dwProcID);//Get process ID
            if (dwProcID != 0) // Si process est ok
            {
                hProcHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcID);
                if (hProcHandle == INVALID_HANDLE_VALUE || hProcHandle == NULL)
                {
                    if (hProcHandle == INVALID_HANDLE_VALUE)
                        GameStatus = "INVALID_HANDLE_VALUE";
                    else
                        GameStatus = "NULL";
                    if (GetLastError() == 5)
                        GameStatus = "/!\\ ACCES DENIED /!\\ -> Redemarrer le BOT en Administrateur";
                }
                else
                {
                    GameStatus = "Processus ok";
                    isGameAvail = true;
                }
            }
            else
            {
                GameStatus = "Impossible de recuperer l'id de processus";
            }
        }
        else
        {
            GameStatus = "NosTale n'a pas ete trouver !";
        }
        read_memory(hProcHandle, &total_life, &current_life);

        if (clock() - refreshTimer > 300)
        {
            refreshTimer = clock();
            align_name("Mega Bot by MajorTom");
            std::cout << "Game Status: " << GameStatus << std::endl;
            show_bar();
            show_help();
            std::cout << "Life: " << current_life << "/" << total_life << "\t\t\t\t" << int(((float)current_life / (float)total_life)*100) << "%" << std::endl;
            std::cout << "BOT: "<< ((bot_status) ? "ON" : "OFF") << std::endl;
        }
        if (GetAsyncKeyState(VK_HOME) && bot_status == false)
        {
            bot_status = true;
            botTimer = clock();
        }
        if (GetAsyncKeyState(VK_END) && bot_status == true)
        {
            bot_status = false;
        }

        if (bot_status == true)
        {
            if (clock() - botTimer > 500)
            {
                //bot
                /*
                if (int(((float)current_life / (float)total_life)*100) < 25)
                {
                    MessageBox(NULL,"Vie basse, faite une pause...","Vie Basse", 0);
                    while (int(((float)current_life / (float)total_life)*100) != 100)
                        read_memory(hProcHandle,&total_life, &current_life);
                    MessageBox(NULL,"Reprise du Bot...","Vie Haute", 0);
                }
                else
                    bot_action(ip);*/
                bot_action(ip);
                botTimer = clock();
            }
        }
    }
    return 0;
}
