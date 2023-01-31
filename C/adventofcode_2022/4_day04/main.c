#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "camp_cleanup.h"

int main(void)
{

	size_t len = 0;
	ssize_t nread;
	char *line = NULL;
	struct elf_pair elf_pair; 
	size_t count = 0;
        size_t count_overlap = 0;

	while ((nread = getline(&line, &len, stdin)) != -1)
	{
		create_section_assignment_pair(line, &elf_pair); 
		count += either_is_in(elf_pair);
                count_overlap += is_overlap(elf_pair); 
                printf("%d\n", is_overlap(elf_pair));
	}

        printf("result: %ld\n", count_overlap);
	printf("result: %ld\n", count);

	free(line);

	return 0;
}
