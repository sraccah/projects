global	_ft_tolower

_ft_tolower:
	mov		rax, rdi;	// rax = c
	cmp		rax, 'A';	// if (rax < 'A')
	jl		ft_ret;		// ft_ret
	cmp		rax, 'Z';	// else if (rax > 'Z')
	jg		ft_ret;		// ft_ret
	add		rax, 32;	// else rax + 32

ft_ret:
	ret;				// return