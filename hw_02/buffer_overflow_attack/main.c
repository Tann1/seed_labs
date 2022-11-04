#include <stdio.h>
#include <string.h>


#define BUFF_SIZE 4

int foo(char *str)
{
	char buff[BUFF_SIZE];
	printf("str: %s\n", str);	
	strcpy(buff, str);
	printf("buff %s\n", buff);
}

int bar()
{
	printf("ohhh f#@k, you've been hacked.\n");
}

int main(int agc, char *argv[])
{

	foo(argv[1]);
	return 0;	
}
