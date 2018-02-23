	.text
	.p2align 6
	.globl	testw
	.type	testw, @function
testw:
	.rept 4096
	testw	$7, %di
	.endr
	ret
	.size	testw, .-testw
	.section	.note.GNU-stack,"",@progbits
