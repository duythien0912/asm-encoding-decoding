section	.text
   global  en_code
   global  de_code

en_code:
	;khởi tạo stack
	push	rbp 
	mov	rbp,rsp
	;đưa giá trị của rsi(biến thứ 2 truyền vào khi gọi function trong C vào stack
	push	rsi
	;lấy giá trị của rsi trong stack đưa vào cl
	mov	cl,[rbp - 8]
	;lấy giá trị của rdi(biến thứ nhất truyền vào) cho vào ax
	mov	ax,[rdi]
	;xoay trái giá trị trong ax với số bit xoay chứa trong cl
	ror	ax,cl
	;đưa giá trị của ax vào r13
	mov	[r13],ax
	;đưa giá trị của r13 vào rax
	mov	rax,r13
	;giải phóng bộ nhớ cho stack
	leave
	ret

de_code:
	;khởi tạo stack
	push	rbp
	mov	rbp,rsp
	;đưa giá trị của rsi(biến thứ 2 truyền vào khi gọi function trong c) vào stack
	push	rsi
	;lấy giá trị của rsi trong stack đưa vào cl
	mov	cl,[rbp - 8]
	;lấy giá trị của rdi(biến thứ nhất truyền vào) cho vào ax
	mov	ax,[rdi]
	;xoay phải giá trị trong ax với số bit xoay chứa trong cl
	rol	ax,cl
	;đưa giá trị của ax vào r13
	mov	[r13],ax
	;đưa giá trị của r13 vào rax
	mov	rax,r13
	;giải phóng bộ nhớ cho stack
	leave
	ret