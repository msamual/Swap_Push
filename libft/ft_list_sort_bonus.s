extern	_ft_list_size
extern	_check
	section	.text
	global	_ft_list_sort

_ft_list_sort:
				push	r15
				push	r14
				push	r13
				push	r12
				push	r11
				mov		r15,	rdi		; r15 = begin_list
				mov		r11,	rsi
				push	rdi
				push	rsi
				mov		rdi,	[r15]
				call	_ft_list_size
				pop		rsi
				pop		rdi
				cmp		rax,	2
				jl		return				; if list_zize < 2 return
				cmp		rsi,	0
				je		return				; if *cmp == 0 return
				mov		r12,	1
				mov		r14,	[r15]		; r14 = current_node
				mov		r13,	[r14 + 8]	; r13 = next_node

loop1:
				cmp		r12,	0			; r12 - check sorted
				jz		return
				mov		r12,	0
				mov		r14,	[r15]		; r14 = current_node
				mov		r13,	[r14 + 8]	; r13 = next_node
		loop2:
				cmp		r13,	0
				je		loop1
				mov		rdi,	[r14]
				mov		rsi,	[r13]
				call	r11
				cmp		rax,	0
				jle		increment
				push	qword[r14]
				push	qword[r13]
				pop		qword[r14]
				pop		qword[r13]
				inc		r12
				jmp		increment

increment:
				mov		r14,	r13
				mov		r13,	[r14 + 8]
				jmp		loop2

return:
				pop		r11
				pop		r12
				pop		r13
				pop		r14
				pop		r15
				ret

