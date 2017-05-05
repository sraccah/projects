global _ft_isalnum

_ft_isalnum:
	cmp 		rdi, '0';	// if (c < '0')
	jb 			ft_false;	//	return (FALSE)
	cmp 		rdi, 'z';	// if (c > 'z')
	ja 			ft_false;	//	return (FALSE)
	cmp 		rdi, '9';	// if (c <= '9')
	jbe 		ft_true;	//	return (TRUE)
	cmp 		rdi, 'A';	// if (c < 'A')
	jb 			ft_false;	//	return (FALSE)
	cmp 		rdi, 'Z';	// if (c <= 'Z')
	jbe 		ft_true;	//	return (TRUE)
	cmp 		rdi, 'a';	// if (c < 'a')
	jb 			ft_false;	//	return (FALSE)
	jmp 		ft_true;	// return (TRUE)

ft_true:
	mov 		rax, 1;		// rax = 1 (donc on return 1)
	ret;					// return

ft_false:
	mov 		rax, 0;		// rax = 0 (donc on return 0)
	ret;					// return