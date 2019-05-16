, store left operand in 0
------------------------------------------------ subtract '0' from 0
>, store right operand in 1
------------------------------------------------- subtract '1' from 1
<
[>>>[>]+[<]<<-]> set a number of cells to 1 equal to first operand
[[>]>[+>]<[<]<-]>> for each of these new cells add value of second operand
[
	[>]< go to the last cell
	[[<]<+>>[>]<-] add value of last cell to 1
	<[<]> go to 3
]
<< return to product
[>>+>+<<<-]>>> copy product to 3 and 4
[<<<+>>>-] copy product back into 1
<<+> store 1 in 2
[
	<-> decrement original product
	[
		>++++++++++< store 10 in 3
		[->-[>+>>]>[+[-<+>]>+>>]<<<<<] divide by 10?
		++++++++++++++++++++++++++++++++++++++++++++++++ add 48 to remainder
		>[-] clear 4
		>[<<+>>-] copy remainder character to 5
		>[<<+>>-] get next digit in 6
		<<
	]
	>
]
<[->++++++++++++++++++++++++++++++++++++++++++++++++>] store '0' if no remainder
<[.[-]<]< print each digit
[-]++++++++++. print line break
