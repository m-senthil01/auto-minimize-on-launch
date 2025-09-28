// ==WindhawkMod==
// @id              auto-minimize-on-launch
// @name            Auto Minimize on Launch
// @description     Automatically minimizes specified apps when they start
// @version         1.0
// @author          Senthil01
// @include         *
// ==/WindhawkMod==

// ==WindhawkModSettings==
/*
- targetProcess: notepad.exe
  $name: Target Process
  $description: The process name to auto-minimize (e.g., notepad.exe)
*/
// ==/WindhawkModSettings==

#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h> // ✅ Needed for GetModuleBaseNameW
#include <string>

#pragma comment(lib, "psapi.lib") // ✅ Link the Psapi library

std::wstring targetProcess;

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
    DWORD pid = 0;
    GetWindowThreadProcessId(hwnd, &pid);

    HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pid);
    if (hProcess) {
        WCHAR exeName[MAX_PATH];
        if (GetModuleBaseNameW(hProcess, nullptr, exeName, MAX_PATH)) {
            if (_wcsicmp(exeName, targetProcess.c_str()) == 0) {
                ShowWindow(hwnd, SW_MINIMIZE);
            }
        }
        CloseHandle(hProcess);
    }

    return TRUE;
}

UINT_PTR g_timerId = 0;

void CALLBACK TimerProc(HWND, UINT, UINT_PTR, DWORD) {
    EnumWindows(EnumWindowsProc, 0);
}

BOOL Wh_ModInit() {
    Wh_Log(L"Mod initialized");

    WCHAR buffer[260];
    Wh_GetStringSetting(L"targetProcess", buffer, ARRAYSIZE(buffer));
    targetProcess = buffer;

    // ✅ Set timer with a real callback
    g_timerId = SetTimer(nullptr, 1, 1000, TimerProc);

    return TRUE;
}

void Wh_ModUninit() {
    Wh_Log(L"Mod unloaded");
    if (g_timerId)
        KillTimer(nullptr, g_timerId);
}

void Wh_ModSettingsChanged() {
    Wh_Log(L"Settings changed");
    WCHAR buffer[260];
    Wh_GetStringSetting(L"targetProcess", buffer, ARRAYSIZE(buffer));
    targetProcess = buffer;
}
