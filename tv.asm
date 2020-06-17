section	.text
   global  en_code
   global  de_code

en_code:
	push	rbp
	mov	rbp,rsp
	push	rsi
	mov	cl,[rbp - 8]
	mov	ax,[rdi]
	ror	ax,cl
	mov	[r13],ax
	mov	rax,r13
	leave
	ret


de_code:
	push	rbp
	mov	rbp,rsp
	push	rsi
	mov	cl,[rbp - 8]
	mov	ax,[rdi]
	rol	ax,cl
	mov	[r13],ax
	mov	rax,r13
	leave
	ret


