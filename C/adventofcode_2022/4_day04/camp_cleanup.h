#pragma once

struct section
{
	unsigned int start;
	unsigned int end;
};

struct elf_pair
{
	struct section left;
	struct section right;
};

void create_section_assignment_pair(char *input, struct elf_pair *elf_pair);

bool either_is_in(struct elf_pair elf_pair);

bool is_overlap(struct elf_pair);
