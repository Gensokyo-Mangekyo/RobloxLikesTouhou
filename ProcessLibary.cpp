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
        std::this_thread::sleep_for(std::chrono::microseconds(10));
    }
    std::this_thread::sleep_for(std::chrono::seconds(15));
    TerminateProcess(Process,0);
}

extern "C" __declspec(dllexport) VOID WaitProcessRoblox() {
    AwaitProcess();
}







