.origin $0000
	jmp Main
.origin $8000

.include "other_fi,le.inc", "another_file.asm"

public Main:
	ldi b, 17 + 6
	add3 b, 20 - 3, 9 - 15
	sto [Result], a
	halt
	
.define NULL, 0
protected Result:
	.byte 15 + 49 - 7 * 4,0, "test string\" with, \\\" escaped characters \\", NULL

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
