%define MACH_SYSCALL(nb)	0x2000000 | nb
%define STDOUT				1
%define WRITE				4
%define ZERO				0x00

GLOBAL _ft_puts
 
_ft_puts:
	mov 	rcx, 0;						// i = 0
	mov		r10, rdi;					// char *bkp = char *s1
	mov		rax, MACH_SYSCALL(WRITE);	// sys write
	jmp 	ft_loop;					// ft_loop()

ft_loop:								// while()
	mov		r9b, [rdi];					// char c  = *str
	cmp 	r9b, ZERO;					// if c == NULL
	je 		ft_write;					// ft_write()
	inc		rdi;						// str++
	inc 	rcx;						// i++
	jmp 	ft_loop;					// on boucle le while()

ft_write:					
	lea		rsi, [rel r10];				// arg 2 = char   ( write(?, char, ?) )
	mov		rdi, STDOUT;				// arg 1 = STDOUT ( write(fd, ?, ?) )
	mov		rdx, rcx;					// arg 3 = 1      ( write(?, ?, len) )
	syscall;							// call write(STDOUT, char c, 1)
	ret;								// return
