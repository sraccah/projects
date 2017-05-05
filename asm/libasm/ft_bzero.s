%define	ZERO	0x00

GLOBAL _ft_bzero

_ft_bzero:
	mov		rcx, 0;				// i = 0;
	jmp		ft_cmp;				// ft_cmp();

ft_loop:
	mov 	byte [rdi], ZERO;	// str[nb] = '\0';
	inc 	rcx;				// i++;
	inc 	rdi;				// nb++;
	jmp 	ft_cmp;				// ft_cmp();

ft_cmp:
	cmp 	rsi, rcx;			// while (str[nb] != '\0');
	jne 	ft_loop; 			// ft_loop();