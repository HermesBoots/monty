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
<<++++++++++++++++++++++++++++++++++++++++++++++++. return to 1 and print it
