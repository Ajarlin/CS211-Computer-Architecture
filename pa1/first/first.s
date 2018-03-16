	.file	"first.c"
	.section	.rodata
.LC0:
	.string	"error"
.LC1:
	.string	"even"
.LC2:
	.string	"odd"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	cmpl	$1, -20(%rbp)
	jg	.L2
	movl	$.LC0, %edi
	call	puts
	movl	$0, %eax
	jmp	.L3
.L2:
	movq	-32(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, -4(%rbp)
	cmpl	$0, -4(%rbp)
	jg	.L4
	movl	$.LC0, %edi
	call	puts
	movl	$0, %eax
	jmp	.L3
.L4:
	movl	-4(%rbp), %eax
	andl	$1, %eax
	testl	%eax, %eax
	jne	.L5
	movl	$.LC1, %edi
	call	puts
	jmp	.L6
.L5:
	movl	$.LC2, %edi
	call	puts
.L6:
	movl	$0, %eax
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-16)"
	.section	.note.GNU-stack,"",@progbits
