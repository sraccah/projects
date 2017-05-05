global _ft_isdigit

_ft_isdigit:
	cmp 		rdi, '0';	// if (c < 0)
	jl 			ft_false;	// 	return (0)
	cmp 		rdi, '9';	// if (c > 9)
	jg 			ft_false;	// 	return (0)
	jmp			ft_true;	// return (1)

ft_true:
	mov 		rax, 1;		// rax = 1 (donc on return 1)
	ret;					// return

ft_false:
	mov 		rax, 0;		// rax = 0 (donc on return 0)
	ret;					// return