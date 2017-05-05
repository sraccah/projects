global	_ft_toupper

_ft_toupper:
	mov		rax, rdi;	// rax = c
	cmp		rax, 'a';	// if (rax < 'a')
	jl		ft_ret;		// ft_ret
	cmp		rax, 'z';	// else if (rax > 'z')
	jg		ft_ret;		// ft_ret
	sub		rax, 32;	// else rax - 32

ft_ret:
	ret;				// return
	