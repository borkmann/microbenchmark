	.text
	.p2align 6
	.globl	testl
	.type	testl, @function
testl:
	.rept 4096
	testl	$7, %edi
	.endr
	ret
	.size	testl, .-testl
	.section	.note.GNU-stack,"",@progbits
