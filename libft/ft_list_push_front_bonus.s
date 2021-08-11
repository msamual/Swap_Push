extern	_malloc

	section	.text
	global	_ft_list_push_front

_ft_list_push_front:
					push	r8
					push	rdi
					push	rsi
					mov		rdi,		16
					call	_malloc
					cmp		rax,		0
					jz		error
					pop		rsi
					pop		rdi
					mov		qword[rax],	rsi
					mov		r8,		[rdi]
					mov		[rax + 8],	r8
					mov		[rdi],		rax
					pop		r8

error:
					ret