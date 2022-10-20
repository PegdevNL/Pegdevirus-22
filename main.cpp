#include <iostream>
#include <Windows.h>

const int pattern[] = {0x45, 0x47, 0x47, 0x49, 0x4E, 0x47, VK_RETURN};

void SendKey(int key)
{
    INPUT ip;

    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    ip.ki.wVk = key;
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));

    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
}

int main(void)
{
    ShowWindow(GetConsoleWindow(), SW_HIDE);

    while(TRUE)
    {
        if(GetAsyncKeyState(VkKeyScanW('p')))
        {
            for(auto k : pattern)
            {
                SendKey(k);
            }
            Sleep(1000);
        }
    }
}