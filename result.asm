
.data
_prompt: .asciiz "Enter an integer:"
_ret: .asciiz "\n"
.globl main
.text
read:
    li $v0,4
    la $a0,_prompt
    syscall
    li $v0,5
    syscall
    jr $ra

print:
    li $v0,1
    syscall
    li $v0,4
    la $a0,_ret
    syscall
    move $v0,$0
    jr $ra
label4:
main:
	li $t1,0
	move $t2,$t1
label2:
	li $t1,4
	blt $t2,$t1,label0
	j label1
label5:
	li $t1,1
	add $t3,$t2,$t1
	move $t2,$t3
	j label2
label0:
	li $t1,2
	blt $t2,$t1,label3
	j label4
label3:
	li $t1,1
	li $t2,100
	mul $t3,$t1,$t2
	move $t0,$a0
	move $a0,$t3
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal print
	lw $ra,0($sp)
	addi $sp,$sp,4
	j label5
label1:
	li $t1,0
	move $v0,$t1
	jr $ra
