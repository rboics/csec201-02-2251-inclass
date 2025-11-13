.586					;This indicates what version of masm is being used
.model flat, stdcall	;This specified the memory model
						;In a nutshell, how function calls occur

.stack 2048				;Specify size of stack in bytes

;These two lines are commented out
;Because I realized my VS setup is incomplete

;includelib libcmt.lib
;includelib legacy_stdio_definitions.lib	;printf/scanf
;The above two lines are linking instructions
;That import common libraries

;Function prototype for a Windows function for ending a process
ExitProcess PROTO, dwExitCode: DWORD

.data
	;If we had global vars, we put them here

.code ;Where we put our code

main PROC c	;where main begins
	push ebp		;save the previous function's base pointer
	mov ebp, esp	;copy the stack pointer into the base pointer

	;int x = 0
	sub esp, 4		;move the stack pointer down 4 bytes
					;to make room for a new int
					;whenever we want to use x, we can use [ebp-4]
	mov eax,0
	mov [ebp-4], eax

	;x = x + 1
	mov eax,[ebp-4]	; mov x into the register
	add eax, 1		; add 1 to eax
	mov [ebp-4],eax	; mov the value of the register back into x


	add esp,4	;remove x from the stack
	mov esp, ebp	;undoes mov ebp, esp
	pop ebp			;undo push ebp

main endp	;where main ends
end min

	