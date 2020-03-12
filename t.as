




main:
li $v0 1
beq $v0 $zero ternary_false0
ternary_true2:
li $v0 2
beq $zero $zero ternary_end1
ternary_false0:
li $v0 3
ternary_end1:
addu a $v0 $zero
li $v0 0
jr $ra
nop
