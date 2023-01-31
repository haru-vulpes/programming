#include <stdlib.h>

#include "item.h"

item_t current_repetitive_item_value(item current_repetitive_item)
{
    if(current_repetitive_item >= 'a' && current_repetitive_item <= 'z')
        return current_repetitive_item - 'a' + 1;
    if(current_repetitive_item <= 'Z' && current_repetitive_item >= 'A')
        return current_repetitive_item - 'A' + 27;
    return '\0';
}
