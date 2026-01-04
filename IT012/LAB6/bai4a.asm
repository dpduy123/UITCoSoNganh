.data
a: .word 6      # Khai báo biến a và gán giá trị là 6
b: .word 5      # Khai báo biến b và gán giá trị là 5
c: .space 4     # Khai báo biến c là một word (4 bytes)
d: .space 4     # Khai báo biến d là một word (4 bytes)

.text
main:
    # Gán giá trị 6 vào biến a
    li $t0, 6          # $t0 = 6
    sw $t0, a          # a = $t0
    
    # Gán giá trị 5 vào biến b
    li $t1, 5          # $t1 = 5
    sw $t1, b          # b = $t1
    
    # Tính giá trị của biến c (a - b)
    lw $t2, a          # $t2 = a
    lw $t3, b          # $t3 = b
    sub $t4, $t2, $t3  # $t4 = $t2 - $t3
    sw $t4, c          # c = $t4
    
    # Tính giá trị của biến d (a + b)
    lw $t5, a          # $t5 = a
    lw $t6, b          # $t6 = b
    add $t7, $t5, $t6  # $t7 = $t5 + $t6
    sw $t7, d          # d = $t7
    
    # Kết thúc chương trình
    li $v0, 10         # $v0 = 10 (số 10 cho syscall exit)
    syscall            # Gọi hàm system call
