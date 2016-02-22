#ifndef BOT_H_INCLUDED
#define BOT_H_INCLUDED
#define WINVER 0x0500
#include <windows.h>

void    bot_action(INPUT ip);
void    sit_down(INPUT ip);
void    read_memory(HANDLE hProcHandle, int *max_life, int *current_life);
#endif // BOT_H_INCLUDED
