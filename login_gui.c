#define UNICODE
#define _UNICODE
#include <windows.h>
#include <wchar.h>
#include <stdlib.h>
#define ID_USERNAME 101
#define ID_PASSWORD 102
#define ID_LOGIN 103
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    static HWND hEditUsername, hEditPassword, hStaticMsg, hLoginButton;
    switch (msg)
    {
    case WM_CREATE:
    {
        LPCREATESTRUCT pcs = (LPCREATESTRUCT)lParam;
        // Create title
        CreateWindowW(
            L"STATIC",
            L"Welcome to Login System",
            WS_VISIBLE | WS_CHILD | SS_CENTER,
            0,
            20,
            300,
            30,
            hWnd,
            NULL,
            pcs->hInstance,
            NULL);
        // Username field with label
        CreateWindowW(
            L"STATIC",
            L"Username:",
            WS_VISIBLE | WS_CHILD | SS_CENTER,
            30,
            70,
            240,
            25,
            hWnd,
            NULL,
            pcs->hInstance,
            NULL);
        hEditUsername = CreateWindowW(
            L"EDIT",
            L"",
            WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL | ES_CENTER,
            30,
            95,
            240,
            30,
            hWnd,
            (HMENU)ID_USERNAME,
            pcs->hInstance,
            NULL);
        // Password field with label
        CreateWindowW(
            L"STATIC",
            L"Password:",
            WS_VISIBLE | WS_CHILD | SS_CENTER,
            30,
            135,
            240,
            25,
            hWnd,
            NULL,
            pcs->hInstance,
            NULL);
        hEditPassword = CreateWindowW(
            L"EDIT",
            L"",
            WS_VISIBLE | WS_CHILD | WS_BORDER | ES_PASSWORD | ES_AUTOHSCROLL | ES_CENTER,
            30,
            160,
            240,
            30,
            hWnd,
            (HMENU)ID_PASSWORD,
            pcs->hInstance,
            NULL);
        // Login button
        hLoginButton = CreateWindowW(
            L"BUTTON",
            L"Login",
            WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
            100,
            210,
            100,
            35,
            hWnd,
            (HMENU)ID_LOGIN,
            pcs->hInstance,
            NULL);
        // Message display
        hStaticMsg = CreateWindowW(
            L"STATIC",
            L"",
            WS_VISIBLE | WS_CHILD | SS_CENTER,
            30,
            260,
            240,
            25,
            hWnd,
            NULL,
            pcs->hInstance,
            NULL);
        break;
    }
    case WM_COMMAND:
    {
        if (LOWORD(wParam) == ID_LOGIN)
        {
            wchar_t username[50], password[50];
            GetDlgItemTextW(hWnd, ID_USERNAME, username, 50);
            GetDlgItemTextW(hWnd, ID_PASSWORD, password, 50);
            if (wcscmp(username, L"admin") == 0 && wcscmp(password, L"password") == 0)
            {
                SetWindowTextW(hStaticMsg, L"Login Successful!");
                system("main.exe");
                DestroyWindow(hWnd);
            }
            else
            {
                SetWindowTextW(hStaticMsg, L"Invalid Credentials!");
            }
        }
        break;
    }
    case WM_DESTROY:
    {
        PostQuitMessage(0);
        break;
    }
    default:
        return DefWindowProcW(hWnd, msg, wParam, lParam);
    }
    return 0;
}
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nShowCmd)
{
    WNDCLASSW wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInst;
    wc.lpszClassName = L"LoginWindow";
    wc.hCursor = LoadCursorW(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
    RegisterClassW(&wc);
    // Create a centered window
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
    int windowWidth = 300;
    int windowHeight = 320;
    int posX = (screenWidth - windowWidth) / 2;
    int posY = (screenHeight - windowHeight) / 2;
    HWND hWnd = CreateWindowW(
        L"LoginWindow",
        L"Login System",
        WS_OVERLAPPED | WS_SYSMENU,
        posX,
        posY,
        windowWidth,
        windowHeight,
        NULL,
        NULL,
        hInst,
        NULL);
    ShowWindow(hWnd, nShowCmd);
    UpdateWindow(hWnd);
    MSG msg;
    while (GetMessageW(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    return (int)msg.wParam;
}
