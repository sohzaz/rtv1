	.section	__TEXT,__text,regular,pure_instructions
	.globl	_ft_putchar
	.align	4, 0x90
_ft_putchar:                            ## @ft_putchar
	.cfi_startproc
## BB#0:
	push	RBP
Ltmp2:
	.cfi_def_cfa_offset 16
Ltmp3:
	.cfi_offset rbp, -16
	mov	RBP, RSP
Ltmp4:
	.cfi_def_cfa_register rbp
	sub	RSP, 16
	mov	AL, DIL
	mov	EDI, 1
	lea	RSI, QWORD PTR [RBP - 1]
	movabs	RDX, 1
	mov	BYTE PTR [RBP - 1], AL
	call	_write
	mov	QWORD PTR [RBP - 16], RAX ## 8-byte Spill
	add	RSP, 16
	pop	RBP
	ret
	.cfi_endproc


.subsections_via_symbols
