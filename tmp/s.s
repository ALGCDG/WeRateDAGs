f:
b stack_handle0
body1:
li $v0, 3
sw $v0, -12($s7)
lw $t0, -12($s7) 
li $t1, 2
sllv $v0, $t0, $t1
sw $v0, -16($s7)
lw $t1, -16($s7) 
lw $t0, -12($s7) 
divu $v0, $t1, $t0
mfhi $v0
b end2
b end2
stack_handle0:
addiu $sp, $sp, -48
sw $ra, -4($fp)
sw $fp, -8($fp)
move $t0, $fp
move $fp, $sp
sw $s0, 4($sp)
sw $s1, 8($sp)
sw $s2, 12($sp)
sw $s3, 16($sp)
sw $s4, 20($sp)
sw $s5, 24($sp)
sw $s6, 28($sp)
sw $s7, 32($sp)
move $s7, $t0
b body1
end2:
lw $s0, 4($sp)
lw $s1, 8($sp)
lw $s2, 12($sp)
lw $s3, 16($sp)
lw $s4, 20($sp)
lw $s5, 24($sp)
lw $s6, 28($sp)
lw $s7, 32($sp)
lw $ra, 48($sp)
lw $fp, 44($sp)
move $sp, $fp
jr $ra
nop
.global f
