add_with_tax.o: add_with_tax.c add_with_tax.h
	gcc -c add_with_tax.c

datatype.o: datatype.c add_with_tax.h
	gcc -c datatype.c

launch: add_with_tax.o datatype.o
	gcc add_with_tax.o datatype.o -o launch
