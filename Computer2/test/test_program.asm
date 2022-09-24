	.org $8000

	ldi a, 17 + 6 ; sum is 23
	ldi b,20-3;difference is            17
	add b                  ; sum is 40   
	sto [Result], a
	halt

	.org $8100
Result:
	.db 0
