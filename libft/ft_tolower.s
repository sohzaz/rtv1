	.section	__TEXT,__text,regular,pure_instructions
	.globl	_ft_tolower
	.align	4, 0x90
_ft_tolower:                            ## @ft_tolower
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
	mov	DWORD PTR [RBP - 4], EDI
	cmp	DWORD PTR [RBP - 4], 65
	jl	LBB0_3
## BB#1:
	cmp	DWORD PTR [RBP - 4], 90
	jg	LBB0_3
## BB#2:
	mov	EAX, DWORD PTR [RBP - 4]
	add	EAX, 32
	mov	DWORD PTR [RBP - 4], EAX
LBB0_3:
	mov	EAX, DWORD PTR [RBP - 4]
	pop	RBP
	ret
	.cfi_endproc


.subsections_via_symbols
