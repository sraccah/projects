global	_ft_strlen

_ft_strlen:
	mov		rcx, -1;	// rcx = -1
	mov 	rax, 0;		// rax = 0
	jmp		ft_loop;	// ft_loop()

ft_loop:
	cld;				// 0->DF (On incrémente RSI dans le sens du DF)
	repnz 	scasb;		// On mov dans RDI et inc dans le sens du flag
	not 	rcx;		// ??? rcx - 1 ??? (-7 sans ça !?!)
	jmp		ft_ret;		// on return

ft_ret:
	mov 	rax, rcx;	// rax = rcx
	sub		rax, 1;		// rax - 1 (\0)
	ret;				// return