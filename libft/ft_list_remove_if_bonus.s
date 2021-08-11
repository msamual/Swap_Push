extern	_free
	section	.text
	global	_ft_list_remove_if

_ft_list_remove_if:
					push	rsp
					push	rdi
					push	rsi
					push	rdx
					push	r15
					push	r14
					push	r13
					push	r12
					push	r11
					mov		r15,	rdi			;	r15 = **begin_list
					cmp		r15,	0			;	if (!begin_list)
					jz		return				;		return
					mov		r14,	[rdi]		;	r14 = *begin_list
					cmp		r14,	0			;	if (!*begin_list)
					jz		return				;		return
					mov		r13,	[r14 + 8]	;	r13 = *begin_list->next
					mov		r12,	rsi			;	r12 = *data_ref
					mov		r11,	rdx			;	r11 = *function_cmp

loop1:
					cmp		r14,	0
					jz		return

					mov		rdi,	[r14]		;	s1 = *begin_list->data
					mov		rsi,	r12			;	s2 = data_ref
					call	r11					;	if (cmp(s1, s2) == 0)
					jz		remove_first		;	remove
					jmp		loop2

remove_first:
					mov		rdi,	[r15]		;tmp = *begin_list
					mov		[r15],	r13			;	*begin_list = (*begin_list)->next
					cmp		r13,	0
					jz		return
					mov		r14,	r13			;	current = (*begin_list)->next
					mov		r13,	[r14 + 8]	;	next = current->next
					jmp		loop1

loop2:
					cmp		r13,	0
					jz		return
					mov		rdi,	[r13]		;s1 = next->data
					mov		rsi,	r12			;s2 = data_ref
					call	r11					;	if (cmp(s1, s2) == 0)
					jz		remove_next			;	remove
					mov		r14,	r13
					mov		r13,	[r14 + 8]
					jmp		loop2

remove_next:
					push	qword[r13 + 8]		;
					pop		qword[r14 + 8]		;	current->next = current->next->next
					mov		rdi,	r13
					mov		r13,	[r14 + 8]	;	next = current->next

					jmp		loop2

return:
					pop		r11
					pop		r12
					pop		r13
					pop		r14
					pop		r15
					pop		rdx
					pop		rsi
					pop		rdi
					pop		rsp
					ret