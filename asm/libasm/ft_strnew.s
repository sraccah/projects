global _ft_strnew

extern _ft_bzero
extern _malloc

_ft_strnew:
	push 	rdi;		// on push rdi (arg)
	inc 	rdi;		// on inc rdi (rdi + 1)
	call 	_malloc;	// call _malloc
	jc 		ft_null;	// ft_null()
	pop 	rsi;		// on pop rsi
	push 	rax;		// on push rax
	dec 	rsi;		// on dec rsi (rsi - 1)
	mov 	rdi, rax;	// rdi = rax
	call 	_ft_bzero;	// call ft_strlen
	pop 	rax;		// on pop rax
	ret;				// return

ft_null:
	mov rax, 0;			// rax = 0
	ret;				// return