.origin $0000
	jmp Main
.origin $8000

.include "other_file.inc", "another_file.asm"

public Main:
	ldi b, 17 + 6
	add3 b, 20 - 3, 9 - 15
	sto [Result], a
	halt

protected Result:
	.byte 0

.define HAS_ADD3, 1
.if HAS_ADD3
	.macro add3, $a, $b, $c
		mvr a, $a
		add $b
		add $c
	.endmacro
.elif 0

.else
	.macro add3, $a, $b, $c
	.endmacro
.endif
