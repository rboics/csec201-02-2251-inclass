#include <stdio.h>
#include <windows.h>

//An instance of this type will be used to hold
//the address of dllDemo
typedef (__stdcall* hello_funct)();	
typedef int (__stdcall* math_fun1)(int, int);
typedef int(__stdcall* math_fun2)(int);

int main(void) {
	//Generate "press any key to continue"
	system("pause");

	//The HINSTANCE type is a "handle"
	//"Handles" are just pointers to system resources
	//Note: The L in the arg to load library is
	HINSTANCE importedDLL = LoadLibrary(L"D:\\csec201-2251-02\\ExampleDLL\\Debug\\ExampleDLL.dll");
	//Bad file path: D:\csec201-2251-02\ExampleDLL\x64\Debug\ExampleDLL.dll
	//The \x64\ in the file path is indicator I built the DLL
	// for the wrong CPU architecture
	//Good file path: D:\csec201-2251-02\ExampleDLL\Debug\ExampleDLL.dll

	system("pause");

	//Logic to verify that load library was able to find and import the DLL
	if (importedDLL == NULL) {
		printf("DLL was not loaded\n");
		return 0;
	}
	else {
		printf("DLL was loaded properly\n");
	}

	system("pause");

	//Search through the loaded DLL for the function named dllDemo
	//return the address of that function
	//store the address in the pointer fun1
	hello_funct fun1 = (hello_funct)GetProcAddress(importedDLL, "_dllDemo@0");
	if (fun1 == NULL) printf("_dllDemo@0 not located in the DLL\n");
	else printf("_dllDemo@0 located in the DLL at %p\n", fun1);
	fun1();
	system("pause");

	math_fun1 fun2 = (math_fun1)GetProcAddress(importedDLL, "_add_and_double@8");
	if (fun2 == NULL) printf("_add_and_double@8 not located in the DLL\n");
	else printf("_add_and_double@8 located in the DLL at %p\n", fun2);
	int result = fun2(10, 3);
	printf("Result is %d\n", result);
	system("pause");

	math_fun2 fun3 = (math_fun1)GetProcAddress(importedDLL, "double_it");
	if (fun3 == NULL) printf("double_it not located in the DLL\n");
	else {
		printf("double_it located in the DLL at %p\n", fun2);
		result = fun3(10, 3);
		printf("Result is %d\n", result);
	}
	system("pause");
}