.data    
	Nhapa: .asciiz "Nhap a: "    
	Nhapb: .asciiz "Nhap b: "    
	LonHon: .asciiz "So lon hon la: "    
	BangNhau: .asciiz "Hai so bang nhau va cung bang: "    
	Tong: .asciiz "\nTong: "    
	Hieu: .asciiz "\nHieu: "    
	Tich: .asciiz "\nTich: "    
	Thuong: .asciiz "\nThuong: "    
	newline: .asciiz "\n"
.text    
	addi  $v0, $0, 4           
	la  $a0, Nhapa              
	syscall    
	
	addi  $v0, $0, 5           
	syscall   
	 
	move  $s1, $v0             
	addi  $v0, $0, 4           
	la $a0, Nhapb              
	syscall    
	
	addi  $v0, $0, 5           
	syscall
	
	move  $s2, $v0             
	slt  $t1, $s1, $s2    
	beq  $t1, 1, bLon    
	bne  $s1, $s2, aLon    
	addi  $v0, $0, 4           
	la  $a0, BangNhau          
	syscall    
	addi  $v0, $0, 1           
	add  $a0, $s1, $0    
	syscall    
	j ketqua
aLon:    
	add  $t0, $s1, $0    
	j InSoLonHon

bLon:    
	add  $t0, $s2, $0

InSoLonHon:    
	addi  $v0, $0, 4           
	la  $a0, LonHon             
	syscall    
	addi  $v0, $0, 1           
	add  $a0, $t0, $0   
	syscall
	
ketqua:
	addi  $v0, $0, 4           
	la  $a0, Tong               
	syscall    
	
	add  $t0, $s1, $s2    
	add  $a0, $t0, $0    
	addi  $v0, $0, 1           
	syscall    
	
	addi  $v0, $0, 4           
	la $a0, Hieu              
	syscall    
	
	sub  $t0, $s1, $s2    
	add  $a0, $t0, $0    
	addi  $v0, $0, 1           
	syscall    
	
	addi  $v0, $0, 4           
	la  $a0, Tich               
	syscall    
	
	mul  $t0, $s1, $s2    
	add  $a0, $t0, $0    
	addi  $v0, $0, 1           
	syscall    
	
	addi  $v0, $0, 4          
	la  $a0, Thuong           
	syscall    
	
	mtc1  $s1, $f1
	cvt.s.w  $f1, $f1         
	mtc1  $s2, $f2              
	cvt.s.w  $f2, $f2           
	div.s  $f12, $f1, $f2       
	addi  $v0, $0, 2          
	
	syscall
