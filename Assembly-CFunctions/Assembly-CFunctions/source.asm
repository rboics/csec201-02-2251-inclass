.586					;assembler
.model flat,stdcall		;assembler
.stack 4096				;assembler

includelib libcmt.lib					;linker
includelib legacy_stdio_definitions.lib	;linker

extern scanf:NEAR		;like a func prototype
						;promise that scanf will be there post-linking
extern printf:NEAR		;like a func prototype
						;promise that printf will exist post-linking

.data
;0 = NULL BYTE
;0ah = \n
inputstr BYTE "%d",0
outputstr BYTE "Your number is: %d", 0ah, 0

.code
main PROC c
	;function prologue
	push ebp
	mov ebp,esp

	;int x = 0;
	sub esp,4		;int x... from here on out, x is ebp-4
	mov eax,0
	mov [ebp-4],eax	;x=0

	mov ecx, 900	;We're going to need this later on

	;save registers to prevent scanf from modifying
	push eax
	push ebx
	push ecx
	push edx

	;scanf("%d", &x);
	mov eax,ebp
	sub eax,4
	push eax	
	push offset inputstr	;offset is like &
	call scanf
	add esp,8	;&x is 4 bytes long, offset inputstr is 4 bytes

	;restore registers
	pop edx
	pop ecx
	pop ebx
	pop eax

	;save registers to prevent printf from modifying
	push eax
	push ebx
	push ecx
	push edx

	;printf("Your number is: %d\n", x);
	push [ebp-4]	;contents of x onto the stack
	push offset outputstr ;addr of "Your number is: %d\n"
	call printf
	add esp,8

	;restore registers
	pop edx
	pop ecx
	pop ebx
	pop eax


	;function epilogue
	mov esp, ebp
	pop ebp
	ret
main endp
end