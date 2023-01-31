#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "camp_cleanup.h"

bool is_in(struct section section1, struct section section2)
{
    return section1.start >= section2.start && section2.end >= section1.end;
}

void create_section_assignment_pair(char *input, struct elf_pair *elf_pair)
{
    unsigned int start1;
    unsigned int end1;
    unsigned int start2;
    unsigned int end2;

    sscanf(input, "%u-%u,%u-%u\n", &start1, &end1, &start2, &end2);

    elf_pair->left.start = start1;
    elf_pair->left.end = end1;
    elf_pair->right.start = start2;
    elf_pair->right.end = end2;
}

bool either_is_in(struct elf_pair elf_pair)
{
    return is_in(elf_pair.left, elf_pair.right) || is_in(elf_pair.right, elf_pair.left);
}

bool is_overlap(struct elf_pair elf_pair)
{
    return (elf_pair.left.start >= elf_pair.right.start && elf_pair.left.start <= elf_pair.right.end) || (elf_pair.left.end >= elf_pair.right.start && elf_pair.left.end <= elf_pair.right.end) 
        || (elf_pair.right.start >= elf_pair.left.start && elf_pair.right.start <= elf_pair.left.end) || (elf_pair.right.end >= elf_pair.left.start && elf_pair.right.end <= elf_pair.left.end);
}
