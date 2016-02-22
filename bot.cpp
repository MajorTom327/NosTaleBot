#include "bot.h"

DWORD lifeBaseAdress = {0x08FCB398};
DWORD currentOffset = {0x4C};
DWORD totalOffset = {0x48};

void    bot_action(INPUT ip)
{
    ip.ki.wVk = VK_SPACE; // virtual-key code for the "a" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
    // Release the "A" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    ip.ki.wVk = 0x58; // X
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
/*
    ip.ki.wVk = 0x31; // 1
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    ip.ki.wVk = 0x32; // 2
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
/*
    ip.ki.wVk = 0x33; // 3
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    ip.ki.wVk = 0x34; // 4
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    ip.ki.wVk = 0x35; // 5
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
    */
}


void    read_memory(HANDLE hProcHandle, int *max_life, int *current_life)
{
    DWORD lifeTotalAddreToRead = lifeBaseAdress + totalOffset;
    ReadProcessMemory(hProcHandle,(BYTE*)lifeTotalAddreToRead,max_life,sizeof(max_life), NULL);
    DWORD lifeCurrentlAddreToRead = lifeBaseAdress + currentOffset;
    ReadProcessMemory(hProcHandle,(BYTE*)lifeCurrentlAddreToRead,current_life,sizeof(current_life), NULL);
}

void    sit_down(INPUT ip)
{
    ip.ki.wVk = 0x43; // C
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
}
