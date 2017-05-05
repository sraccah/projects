global _ft_strdup

extern _malloc
extern _ft_strlen

_ft_strdup:
	push 	rdi;		// on push rdi (arg)
	call 	_ft_strlen;	// call ft_strlen
	jmp		ft_alloc;	// ft_alloc()

ft_alloc:
	mov 	rcx, rax;	// rcx = len
	push 	rcx;		// on push rcx
	mov 	rdi, rax;	// rdi = len
	inc 	rdi;		// on inc rdi (len + 1)
	call 	_malloc;	// call _malloc
	jc 		ft_ret;		// ft_ret()
	jmp		ft_memcpy;	// ft_memcpy()

ft_memcpy:
	pop 	rcx;		// on pop rcx
	pop 	rsi;		// on pop rsi
	mov 	rdi, rax;	// rsi = rax
	cld;				// 0->DF (On incrémente RSI dans le sens du DF)
	rep 	movsb;		// On fait un memcpy()

ft_ret:
	ret; 				// return