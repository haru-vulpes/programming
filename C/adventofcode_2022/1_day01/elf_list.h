#pragma once

struct elf_list{
	struct elf *elves;
	size_t size;
};

void elf_append(struct elf_list *elf_list, struct elf current_elf);

void destroy_elves(struct elf_list elf_list);

unsigned long highest_n_calories(struct elf_list elf_list, size_t n);
