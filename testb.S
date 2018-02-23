	.text
	.p2align 6
	.globl	testb
	.type	testb, @function
testb:
	.rept 4096
	testb	$7, %dil
	.endr
	ret
	.size	testb, .-testb
	.section	.note.GNU-stack,"",@progbits
