global _ft_isalpha

_ft_isalpha:
	cmp 		rdi, 'A';	// if (c < 'A')
	jl 			ft_false;	// 	return (0)
	cmp 		rdi, 'z';	// if (c > 'z')
	jg 			ft_false;	//	return (0)
	cmp 		rdi, 'Z';	// if (c <= 'Z')
	jle 		ft_true;	//	return (1)
	cmp 		rdi, 'a';	// if (c >= 'a')
	jge 		ft_true;	// return (1)

ft_true:
	mov 		rax, 1;		// rax = 1 (donc on return 1)
	ret;					// return

ft_false:
	mov 		rax, 0;		// rax = 0 (donc on return 0)
	ret;					// return