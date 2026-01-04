.data
	Sum: .word 0 # Khai bao Sum = 0
.text

main:
	lw $s2 Sum #Gan thanh ghi $s2 cho bien Sum
	addi $s0, $0, 1 # Khoi tao i = 1 
	
	FOR: 
		slt $t0, $s1, $s0 # $t0 = n < i?
		bne $t0, $0, END # if (n < i) go to END
		add $s2, $s2, $s0  #Sum = Sum + i
		addi $s0, $s0, 1 # i = i + 1
	j FOR
	END:
