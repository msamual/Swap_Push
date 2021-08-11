section	.text
global	_ft_strcmp

_ft_strcmp:
			push	rdx
			push	rcx
			xor		rdx,	rdx
			xor		rcx,	rcx

loop:
			cmp		byte [rdi], 0
			jz		return
			mov		dl, byte [rdi]
			mov		cl, byte [rsi]
			cmp		rdx, rcx
			jnz		return
			inc		rdi
			inc		rsi
			jmp		loop

return:
			mov		dl, byte [rdi]
			mov		cl, byte [rsi]
			sub		rdx, rcx
			mov		rax, rdx
			pop		rcx
			pop		rdx
			ret
