	.text
	.p2align 6
	.globl	testq
	.type	testq, @function
testq:
	.rept 4096
	testq	$7, %rdi
	.endr
	ret
	.size	testq, .-testq
	.section	.note.GNU-stack,"",@progbits
