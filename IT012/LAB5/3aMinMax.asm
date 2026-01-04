.data
phantu: .asciiz "Nhap so phan tu: "
tong: .asciiz "\nTong: "
arr: .word 0:10
space: .asciiz " "
endline: .asciiz "\n" 
.text 
li $v0, 4
la $a0, phantu 
syscall 
li $v0, 5 
syscall
move $s0, $v0
li $t0, 0
la $a1, arr
loop1:
beq $t0, $s0, end_loop1
li $v0, 5
syscall
sw $v0, ($a1)
addi $t0, $t0, 1
addi $a1, $a1, 4
j loop1

end_loop1:
li $t0, 0
la $a1, arr
li $t3, 0
loop2:
beq $t0, $s0, end_loop2
lw $t2, ($a1)
add $t3, $t3, $t2
addi $t0, $t0, 1
addi $a1, $a1, 4
j loop2
end_loop2:
li $v0, 4
la $a0, tong 
syscall 
move $a0, $t3 
li $v0, 1 
syscall