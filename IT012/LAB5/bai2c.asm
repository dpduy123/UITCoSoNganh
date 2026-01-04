.data 
array1: .word 5, 6, 7, 8, 1, 2, 3, 9, 10, 4
size1: .word 10 
array2: .byte 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 
size2: .word 16
array3: .space 8
size3: .word 8
endline: .asciiz "\n"
space: .asciiz " " 

.text 
li $v0, 5 
syscall 
move $t0, $v0
li $v0, 5 
syscall 
move $t1, $v0

bne $t0, 1, secondarray
la $s0, array1 
sll $t1, $t1, 2
add $t2, $s0, $t1
lw $a0, ($t2) 
li $v0, 1
syscall 
j end

secondarray: 
beq $t0, 2, thirdarray
la $s0, array2
add $t2, $s0, $t1
lb $a0, ($t2) 
li $v0, 1
syscall 

thirdarray: 
la $s0, array3 
add $t2, $s0, $t1
lb $a0, ($t2) 
li $v0, 1
syscall 

end: