#include <iostream>
#include <windows.h>
#include <Psapi.h>
#include <string>

using namespace std;

HANDLE GetProccessByName(string name) {
    DWORD processes[1024], bytesReturned; //Всего максимум выделяем 1024 элементов под процессы
    unsigned int numProcesses; //Количество процессов
    if (EnumProcesses(processes,sizeof(processes),&bytesReturned)) { //Массив который хранит процессы sizeof(processes) ну размер одного элемента 
    //bytesReturned нужен для вычисления кол-во процессов она возращает сколько байт было заполненно, а для того чтобы узнать количество разделим на DWORD
        numProcesses = bytesReturned / sizeof(DWORD);
        for (unsigned int i = 0; i < numProcesses; i++) { 
                    //PROCESS_QUERY_INFORMATION | PROCESS_VM_READ это флаги. PROCESS_QUERY_INFORMATION это получение информации о процессе, PROCESS_VM_READ чтение
                    //FALSE вы не планируете передавать этот дескриптор другим процессам
                    //PID процесса представляет идентификатор процесса, который вы хотите открыть
                  HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processes[i]);
                  if (hProcess) {
                    TCHAR processName[MAX_PATH]; //Хранит расположение к пути исполняемому файлу с максмальной длинной пути (MAX_PATH)
                if (GetModuleFileNameEx(hProcess, nullptr, processName, MAX_PATH)) { //Получаем путь
                    std::string processNameStr(processName);
                    size_t found = processNameStr.find_last_of("\\");
                    if (found != std::wstring::npos) {
                        std::string executableName = processNameStr.substr(found + 1);
                        if (executableName == name) {
                            return hProcess;
                        }
                    }
                }
                CloseHandle(hProcess);
                  }
        }
    }
    return NULL;
}

string GetProccessPath(HANDLE hProcess) {
    TCHAR path[MAX_PATH];
    if(GetModuleFileNameEx(hProcess,nullptr,path,MAX_PATH)) {
        string result(path);
        return result;
    }
    else throw new invalid_argument("hProcess not correct");
}



