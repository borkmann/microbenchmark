	.text
	.p2align 4,,15
	.globl	testw
	.type	testw, @function
testw:
	testw	$7, %di
	ret
	.size	testw, .-testw
	.section	.note.GNU-stack,"",@progbits
