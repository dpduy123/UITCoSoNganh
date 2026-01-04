.data
i: .word 0    
j: .word 0      
f: .word 0   
g: .word 0     
h: .word 0     

.text
main:
    lw $s3, i
    lw $s4, j
    bne $s3, $s4, not_equal 
    nop         
                  
    lw $s1, g       
    lw $s2, h 
    add $t4, $s1, $s2   
    sw $t4, f           
    j end                 
    nop 
 
not_equal:
    lw $t5, g            
    lw $t6, h             
    sub $t7, $t5, $t6    
    sw $t7, f            
    
end:
    li $v0, 10            
    syscall               
