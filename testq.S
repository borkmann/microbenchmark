	.text
	.p2align 4,,15
	.globl	testq
	.type	testq, @function
testq:
	testq	$7, %rdi
	ret
	.size	testq, .-testq
	.section	.note.GNU-stack,"",@progbits
