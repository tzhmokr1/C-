#include <stdio.h>
#include <stdlib.h>


int insert(char ** p)
{
	int number = 1;
	int count = 0;
	while (number != 0) {
		printf("Please enter an name (1 word) or q to quit\n");
		char *s = malloc(100);
		scanf("%s", s);
		if (s[0] == 'q') {
			return count;
		}
		else {
			*p = s;
			p++;
			count++;
		}
	}
}


int main()
{
	char *names[100];
	int num_entries = insert(names);
	printf("A total of %d names have been entered.\n", num_entries);
	int i;
	for (i = 0; i < num_entries; i++) {
		printf("%s\n", names[i]);
	}
	return 0;
}