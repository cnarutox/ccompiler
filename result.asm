
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
main:
	li $t1,0
	move $t2,$t1
	li $t1,1
	move $t3,$t1
	li $t1,1
	move $t4,$t1
	blt $t2,$t3,label0
	j label1
label0:
	li $t1,0
	move $t0,$a0
	move $a0,$t1
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal print
	lw $ra,0($sp)
	addi $sp,$sp,4
	j label1
label1:
	beq $t3,$t4,label2
	j label3
label2:
	li $t1,1
	move $t0,$a0
	move $a0,$t1
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal print
	lw $ra,0($sp)
	addi $sp,$sp,4
	j label3
label3:
	blt $t3,$t2,label4
	j label5
label5:
	li $t1,2
	move $t0,$a0
	move $a0,$t1
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal print
	lw $ra,0($sp)
	addi $sp,$sp,4
	j label4
label4:
	beq $t2,$t3,label6
	j label7
label7:
	li $t1,3
	move $t0,$a0
	move $a0,$t1
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal print
	lw $ra,0($sp)
	addi $sp,$sp,4
	j label6
label6:
	beq $t2,$t4,label8
	j label9
label8:
	li $t1,4
	move $t0,$a0
	move $a0,$t1
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal print
	lw $ra,0($sp)
	addi $sp,$sp,4
	j label9
label9:
	li $t1,0
	move $v0,$t1
	jr $ra
