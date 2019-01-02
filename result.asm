
.data
_prompt: .asciiz "Enter an integer:"
_ret: .asciiz "\n"
.globl main
.text
read:
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
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal read
	lw $ra,0($sp)
	move $t1,$v0
	addi $sp,$sp,4
	move $t2,$t1
	li $t1,2
	move $t3,$t1
label0:
	li $t1,5
	blt $t3,$t1,label1
	j label2
label1:
	li $t1,2
	div $t2,$t1
	mflo $t1
	move $t2,$t1
	li $t1,1
	add $t4,$t3,$t1
	move $t3,$t4
	j label0
label2:
	move $t0,$a0
	move $a0,$t2
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal print
	lw $ra,0($sp)
	addi $sp,$sp,4
	li $t1,0
	move $v0,$t1
	jr $ra
