#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elf.h"
#include "elf_list.h"

static void destroy(struct elf_list elf_list, char *line);
static void reset_current_elf(struct elf *current_elf);
static void print_result(struct elf_list elf_list);

//////////////////////////////////////////////////////////////////////////

int main(void) {

	ssize_t read;
	size_t len = 0;
	char *line = NULL;
	struct elf_list elf_list = {.elves = NULL, .size = 0};
	struct elf current_elf = {.calories = NULL, .size = 0};

	while ((read = getline(&line, &len, stdin)) != -1)
	{
		if (read == 1)
		{
			elf_append(&elf_list, current_elf);
			reset_current_elf(&current_elf);
			continue;
		}
		add_calories(&current_elf, strtoul(line, NULL, 10));
	}

	elf_append(&elf_list, current_elf);

	print_result(elf_list);

	destroy(elf_list, line);

	return 0;
}

//////////////////////////////////////////////////////////////////////////

static void destroy(struct elf_list elf_list, char *line)
{
	destroy_elves(elf_list);

	free(line);
}

static void reset_current_elf(struct elf *current_elf)
{
	memset(current_elf, 0, sizeof(struct elf)); //pour la blague//
	//current_elf->calories = NULL;
	//current_elf->size = 0;
}

static void print_result(struct elf_list elf_list)
{
	printf("highest calories worn: %lu\n", highest_n_calories(elf_list, 1));
	printf("TOP 3 highest calories added: %lu\n", highest_n_calories(elf_list, 3));
}

