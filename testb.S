	.text
	.p2align 4,,15
	.globl	testb
	.type	testb, @function
testb:
	testb	$7, %dil
	ret
	.size	testb, .-testb
	.section	.note.GNU-stack,"",@progbits
