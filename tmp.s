f:
PUSH0:
sw $a0, 4($sp)
nop
sw $a1, 8($sp)
nop
addiu $sp, $sp, -40
sw $ra, 40($sp)
nop
sw $fp, 36($sp)
nop
sw $s0, 4($sp)
nop
sw $s1, 8($sp)
nop
sw $s2, 12($sp)
nop
sw $s3, 16($sp)
nop
sw $s4, 20($sp)
nop
sw $s5, 24($sp)
nop
sw $s6, 28($sp)
nop
sw $s7, 32($sp)
nop
move $fp, $sp
body2:
# reading variable x
lw $s0, 44($fp) 
nop
# reading variable y
lw $s1, 48($fp) 
nop
addu $v0, $s0, $s1
b POP1
nop
POP1:
lw $s0, 12($sp)
nop
lw $s1, 16($sp)
nop
lw $s2, 20($sp)
nop
lw $s3, 24($sp)
nop
lw $s4, 28($sp)
nop
lw $s5, 32($sp)
nop
lw $s6, 36($sp)
nop
lw $s7, 40($sp)
nop
lw $ra, 48($sp)
nop
lw $fp, 44($sp)
nop
move $sp, $fp
jr $ra
nop


.global f
