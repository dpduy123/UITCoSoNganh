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

#mang1
la $s0 array1
lw $t0 size1
Loop1: beq $t1, $t0, end1 
sll $t2, $t1, 2 
add $t3, $s0, $t2
lw $s1, ($t3) 
li $v0, 1
add $a0, $0, $s1 
syscall 
addi $t1, $t1, 1
addi $v0, $0, 4 
la $a0, space 
syscall 
j Loop1
end1: 
la $a0, endline 
syscall

#mang2 
la $s0 array2
lw $t0 size2
addi $t1, $0, 0
Loop2: beq $t1, $t0, end2
add $t3, $s0, $t1
lb $s1, ($t3) 
li $v0, 1
add $a0, $0, $s1 
syscall 
addi $t1, $t1, 1
addi $v0, $0, 4 
la $a0, space 
syscall 
j Loop2
end2: 
la $a0, endline 
syscall
