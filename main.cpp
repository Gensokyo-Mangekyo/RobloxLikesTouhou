#include <Windows.h>

int main() {
    HMODULE dllHandle = LoadLibraryA("Process.dll"); // Замените на путь к вашей DLL
    if (dllHandle == NULL) {
        // Обработка ошибки, если DLL не была загружена
        return 1;
    }

    // Теперь вы можете использовать функции из DLL
    // Например, вызов функции WaitProcessRoblox:
    typedef void (*WaitProcessRobloxFunc)();
    WaitProcessRobloxFunc waitProcess = (WaitProcessRobloxFunc)GetProcAddress(dllHandle, "WaitProcessRoblox");
    if (waitProcess != NULL) {
        waitProcess();
    }

    // Освободите ресурсы после использования DLL
    FreeLibrary(dllHandle);

    return 0;
}