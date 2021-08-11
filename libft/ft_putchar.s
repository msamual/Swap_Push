global _ft_putchar

section .text

_ft_putchar:
	push	rsi;
	mov		rsi, rdi
	mov		rdi, 1
	mov		rdx, 1
	mov		rax, 0x2000004
	push	rsi
	mov		rsi, rsp
	syscall
	pop		rsi
	pop		rsi
	ret
