#pragma once

typedef char crate;

struct stack;

struct dock;

struct instructions;

struct work_zone;

struct work_zone *work_zone_filler(char **raw_input);

char *result(struct work_zone *work_zone, size_t i);

void free_work_zone(struct work_zone *work_zone);
