#pragma once

struct elf {
	unsigned long *calories;
	size_t size;
};

int compare_elf(const void *lhe, const void *rhe);

void destroy_elf(struct elf elf);

void add_calories(struct elf *current_elf, unsigned long calories);

unsigned long total_of_calories(struct elf elf);

