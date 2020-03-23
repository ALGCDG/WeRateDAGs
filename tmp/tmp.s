f:
PUSH0:
sw $a0, 4($sp)
addiu $sp, $sp, -40
sw $ra, 40($sp)
sw $fp, 36($sp)
sw $s0, 4($sp)
sw $s1, 8($sp)
sw $s2, 12($sp)
sw $s3, 16($sp)
sw $s4, 20($sp)
sw $s5, 24($sp)
sw $s6, 28($sp)
sw $s7, 32($sp)
move $fp, $sp
body2:
# reading variable a
lw $t0, 44($fp) 
li $t1, 5
slt $v0, $t0, $t1
beq $v0, $zero, if_false4
if_true3:
# making room on the stack for arguments
addiu $sp, $sp, -4
move $fp, $sp 
# reading variable a
lw $t1, 44($fp) 
li $t0, 1
addu $a0, $t1, $t0
sw $a0, 4($fp)
jal f
nop
move $v0, $v0
# freeing function call arguments from stack
addiu $sp, $sp, 4
move $fp, $sp 
b POP1
b if_end5
if_false4:
li $v0, 0
b POP1
if_end5:
POP1:
lw $s0, 4($sp)
lw $s1, 8($sp)
lw $s2, 12($sp)
lw $s3, 16($sp)
lw $s4, 20($sp)
lw $s5, 24($sp)
lw $s6, 28($sp)
lw $s7, 32($sp)
lw $ra, 40($sp)
lw $fp, 36($sp)
move $sp, $fp
jr $ra
nop
.global f
