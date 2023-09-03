#ifndef PROCESS_H
#define PROCESS_H
#include <string>
#include <windows.h>

using namespace std;

HANDLE GetProccessByName(string name);

string GetProccessPath (HANDLE hProcess);

#endif