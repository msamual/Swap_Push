section	.text
global	_ft_strcpy

_ft_strcpy:
			push	rcx
			mov		rax, rdi

loop:
			cmp		byte [rsi], 0
			jz		return
			mov		cl, byte [rsi]
			mov		byte [rdi], cl
			inc		rsi
			inc		rdi
			jmp		loop

return:
			mov		byte [rdi], 0
			pop		rcx
			ret
