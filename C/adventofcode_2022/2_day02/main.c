#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

    size_t len = 0;
    ssize_t nread;
    char *line = NULL;
    int point_count_part1 = 0;
    int point_count_part2 = 0;

    while ((nread = getline(&line, &len, stdin)) != 1)
    {
            if (strcmp(line, "A X\n") == 0)
            {
                    point_count_part1 += 4;
                    point_count_part2 += 3;
            }
            if (strcmp(line, "A Y\n") == 0)
            {
                    point_count_part1 += 8;
                    point_count_part2 += 4;
            }
            if (strcmp(line, "A Z\n") == 0)
            {
                    point_count_part1 += 3;
                    point_count_part2 += 8;
            }
            if (strcmp(line, "B X\n") == 0)
            {
                    point_count_part1 += 1;
                    point_count_part2 += 1;
            }
            if (strcmp(line, "B Y\n") == 0)
            {
                    point_count_part1 += 5;
                    point_count_part2 += 5;
            }
            if (strcmp(line, "B Z\n") == 0)
            {
                    point_count_part1 += 9;
                    point_count_part2 += 9;
            }
            if (strcmp(line, "C X\n") == 0)
            {
                    point_count_part1 += 7;
                    point_count_part2 += 2;
            }
            if (strcmp(line, "C Y\n") == 0)
            {
                    point_count_part1 += 2;
                    point_count_part2 += 6;
            }
            if (strcmp(line, "C Z\n") == 0)
            {
                    point_count_part1 += 6;
                    point_count_part2 += 7;
            }
    }

    printf("%d\n", point_count_part1);
    printf("%d\n", point_count_part2);

    free(line);

    return 0;
}
