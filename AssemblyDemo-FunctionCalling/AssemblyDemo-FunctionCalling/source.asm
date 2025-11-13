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

	;function prologue -> always will be the same
	;	This sets up the function's stack frame
	push ebp ; Saves the base of the previous function's stack frame
			 ; so that we can pick up in the previous
			 ; function when this one is done
	
	mov ebp, esp	;sets the "base" of the active stack frame
					; to be the top of the stack

	;body of the main function

	;How would would I pass 5 as an argument to AddOne

	push 5

	;Call -> push eip
	;		 Copies the address of the label into eip
	call AddOne


	;function epilogue -> also, (almost) always the same
	mov esp, ebp	;Sets the "top" of the stack to be the 
					; base of the active stack frame
					; effectively, this "deletes" local variables
	pop ebp	; Restoring the previous function's stack frame

;Arguments will always ebp+8+x (x>=0)
;Local vars will always be ebp-x
;return values are done via eax (C standard)

;Create a "label"
;A name for a "region" - really a single line
AddOne:
	;function prologue
	push ebp
	mov ebp, esp

	;copy the argument into ebx
	mov ebx,[ebp+8]
	add ebx, 1

	;set up the return value
	mov eax, ebx

	;function epilogue
	mov esp, ebp
	pop ebp
	
	;At this point, if we managed memory right
	;esp will be point at the saved instruction pointer
	ret		;return keyword, basically alias for "pop eip"

main endp	;where main ends
end main