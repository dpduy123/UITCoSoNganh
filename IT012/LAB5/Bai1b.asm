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
lw $t0 size3
lw $s0 size2 
la $s1 array2
la $s2 array3 
Loop: 
beq $t1, $t0, end
add $t2, $t1, $s1
lb $t3 ($t2) 

sub $t2, $s0, $t1
subi $t2, $t2, 1
add $t2, $t2, $s1 
lb $t4 ($t2) 

add $t5, $t3, $t4
add $t6, $t1, $s2
sb $t5, ($t6) 
addi $t1, $t1, 1
j Loop
end: