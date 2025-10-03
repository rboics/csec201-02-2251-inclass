// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <stdio.h>

//Note: the extern line tells the linker that this function
//is going to be "exported". Other applications will be able
//to find this function if they load the DLL and call GetProcAddress
//on "dllDemo"
//I think of these functions like "public" functions in Java
extern "C" __declspec(dllexport)
void __stdcall dllDemo(void) {
    printf("Hello from dllDemo\n");
}
//I would think of notExported as a "private" function in Java
void notExported(void) {
    printf("Should not be able to be called\n");
}

//Not exported
// __stdcall not needed here (but also doesn't hurt)
int __stdcall double_it(int x) {
    return x * 2;
}

//__stdcall establishes the kind of stack frame the add_and_double
//function is going to use
//__stdcall must be present for exported functions that have return values
//or parameters
extern "C" __declspec(dllexport)
int __stdcall add_and_double(int a, int b) {
    int sum = a + b;
    return double_it(sum);     // uses the non-exported helper
}



//Function that gets called (for our purposes) twice
// 1) When the library is loaded
// 2) When the library is unloaded
// ----Library will always get unloaded when the program is done
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    //If you have code that should run when the library is loaded
    //Put it in the first two cases
    case DLL_PROCESS_ATTACH:
        printf("DLL was loaded\n");
        break;
    case DLL_THREAD_ATTACH:
    //If you have code that should run when the library is closed
    //Put it in the second two cases
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        printf("DLL was unloaded\n");
        break;
    }
    return TRUE;
}

