#include <iostream>
#include "celeste_lib.h"

// ###################################################################################
//                                  Platform Globals 
// ###################################################################################
static bool running = true;

// ###################################################################################
//                                  Platform Globals 
// ###################################################################################
bool platform_create_window(int width, int height, const char* title);
void platform_update_window();

// ###################################################################################
//                                  Windows Platform
// ###################################################################################

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>

static HWND window;

// -----------------------------------------------------------------------------
// Window procedure
// -----------------------------------------------------------------------------
LRESULT CALLBACK windows_window_callback(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
    switch (msg){
        case WM_CLOSE:
            running = false;
            DestroyWindow(hwnd);
            return 0;

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProcA(hwnd, msg, wParam, lParam);
}

bool platform_create_window(int width, int height, const char* title){
    HINSTANCE instance = GetModuleHandleA(0);

    const char* class_name = "CelesteWindowClass";

    WNDCLASSA wc = {};
    wc.hInstance = instance;
    wc.hIcon = LoadIcon(instance, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = class_name;
    wc.lpfnWndProc = windows_window_callback;

    if (!RegisterClassA(&wc)){
        return false;
    }

    int dwStyle = WS_OVERLAPPEDWINDOW;

    window = CreateWindowExA(
        0,
        class_name,
        title,
        dwStyle,
        100,100,
        width,
        height,
        NULL,
        NULL,
        instance,
        NULL
    );

    if (window == NULL){
        return false;
    }

    ShowWindow(window, SW_SHOW);
    UpdateWindow(window);


    return true;
}

void platform_update_window(){
    MSG msg;
    while (PeekMessageA(&msg, NULL, 0, 0, PM_REMOVE)){
        if (msg.message == WM_QUIT){
            running = false;
        }
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }
}

#endif


int main()
{   
    platform_create_window(1200, 720, "Celeste");

    SM_TRACE("Prout");
    SM_WARN("Prout");
    SM_ERROR("Prout");
    SM_ASSERT(false,"Prout")
    

    while (running)
    {
        platform_update_window();
        // update
    }
    return 0;
}

