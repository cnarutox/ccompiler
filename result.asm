
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
func:
label0:
	li $t1,0
	bgt $a0,$t1,label1
	j label2
label1:
	li $t1,1
	sub $t2,$a0,$t1
	move $a0,$t2
	move $t0,$a0
	move $a0,$a0
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal print
	lw $ra,0($sp)
	addi $sp,$sp,4
	j label0
label2:
	li $t1,0
	move $v0,$t1
	jr $ra
main:
	li $t1,5
	move $t2,$t1
	move $t0,$a0
	move $a0,$t2
	addi $sp,$sp,-24
	sw $t0,0($sp)
	sw $ra,4($sp)
	sw $t1,8($sp)
	sw $t2,12($sp)
	sw $t3,16($sp)
	sw $t4,20($sp)
	jal func
	lw $a0,0($sp)
	lw $ra,4($sp)
	lw $t1,8($sp)
	lw $t2,12($sp)
	lw $t3,16($sp)
	lw $t4,20($sp)
	addi $sp,$sp,24
	move $t1 $v0
	li $t1,0
	move $v0,$t1
	jr $ra
