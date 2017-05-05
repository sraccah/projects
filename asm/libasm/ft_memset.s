global _ft_memset

_ft_memset:
	push 	rdi;		// on push la dest
	mov 	rcx, rdx;	// on met la len dans le compteur
	mov 	rax, rsi;	// on met la source dans rax
	cld;				// 0->DF (On incrémente RSI dans le sens du DF)
	rep 	stosb;		// On store dans RDI et inc dans le sens du flag
	jmp		ft_ret;		// On return

ft_ret:
	pop 	rax;		// on pop la rax
	ret;				// return
