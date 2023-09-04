#include "Process.h"
#include <thread>
#include <Windows.h>

using namespace std;


void AwaitProcess() {
    HANDLE Process = NULL;
    Process = GetProccessByName("RobloxPlayerBeta.exe");
    while (Process == NULL)
    {
        Process = GetProccessByName("RobloxPlayerBeta.exe");
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::this_thread::sleep_for(std::chrono::seconds(17));

    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    // Вычислите координаты центра экрана
    int centerX = screenWidth / 2;
    int centerY = screenHeight / 2;

    for (size_t i = 0; i < 10; i++)
    {
         mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, centerX * 65535 / screenWidth, centerY * 65535 / screenHeight, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
     std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    
    TerminateProcess(Process,0);
}

extern "C" __declspec(dllexport) VOID WaitProcessRoblox() {
    AwaitProcess();
}







