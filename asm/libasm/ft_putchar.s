%define MACH_SYSCALL(nb)	0x2000000 | nb
%define STDOUT				1
%define WRITE				4

GLOBAL _ft_putchar

section .data
	char:	db 	""

_ft_putchar:
	mov		[rel char], rdi;			// char = arg 1 (char = char du main)
	mov		rax, MACH_SYSCALL(WRITE);	// rax = write(fd, char, len)
	jmp		ft_write; 					// call ft_write
		
ft_write:
	lea		rsi, [rel char];			// arg 2 = char   ( write(?, char, ?) )
	mov		rdi, STDOUT;				// arg 1 = STDOUT ( write(fd, ?, ?) )
	mov		rdx, 1;						// arg 3 = 1      ( write(?, ?, len) )
	syscall;							// call write(STDOUT, char c, 1)
	ret;								// return
