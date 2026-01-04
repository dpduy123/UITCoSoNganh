.data 
	f: .word 0 
	g: .word 9
	h: .word 6
.text 

main:
	lw $t0 g
	lw $t1 h
	beq $s0, $s1, equal 
	sub $s2, $t0, $t1 
	j end
equal: 
	add $s2, $t0, $t1
end:
	sw $s2 f
