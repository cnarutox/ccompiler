
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
	li $t1,10
	li $t2,12
	li $t3,9
	li $t4,13
	move $t0,$a0
	move $a0,$t1
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal print
	lw $ra,0($sp)
	addi $sp,$sp,4
	move $t2,$t3
	move $t5,$t1
	move $t0,$a0
	move $a0,$t5
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal print
	lw $ra,0($sp)
	addi $sp,$sp,4
	move $t6,$t2
	move $t7,$t1
	move $t8,$t4
	move $v0,$t9
	jr $ra
