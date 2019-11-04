/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/

#ifndef _REG_CLASSES
#define _REG_CLASSES

#include "bit_types.h"

class ing_pkt_counter;

class ing_pkt_counter {
public:
    _32bits pkt_count;

    ing_pkt_counter(void);

    void set_pkt_count(_32bits, int, int);

    void print(void);
    int compare(ing_pkt_counter *ref, ing_pkt_counter *ref_mask);
    void deep_copy(ing_pkt_counter *ref);

};

#endif
