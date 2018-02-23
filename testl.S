	.text
	.p2align 4,,15
	.globl	testl
	.type	testl, @function
testl:
	testl	$7, %edi
	ret
	.size	testl, .-testl
	.section	.note.GNU-stack,"",@progbits
