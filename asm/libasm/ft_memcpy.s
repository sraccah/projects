global _ft_memcpy

_ft_memcpy:
	push 	rdi;		// on push la dest
	mov 	rcx, rdx;	// on met la len dans le compteur
	cld;				// 0->DF (On incrémente RSI dans le sens du DF)
	rep 	movsb;		// On mov dans RDI et inc dans le sens du flag
	jmp		ft_ret;		// On return

ft_ret:
	pop 	rax;		// on pop la rax
	ret;				// return
