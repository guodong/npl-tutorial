/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/


#include "reg_classes.h"
#include "base/cLog.h"

void ing_pkt_counter::set_pkt_count(_32bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 31;
    }

    pkt_count(maxbit, minbit) = value;
}

ing_pkt_counter::ing_pkt_counter() {
    uint i;

    pkt_count = (_32bits)(0);
}

void ing_pkt_counter::print() {
#ifndef NO_CONSOLE_OUTPUT
    uint i;

    bmi_log->normal("ing_pkt_counter->pkt_count = 0x" + pkt_count.to_string(SC_HEX_US, false));
#endif
}

int ing_pkt_counter::compare(ing_pkt_counter *ref, ing_pkt_counter *ref_mask) {
    uint mismatch = 0;
    uint i;

    if (ref_mask == NULL) {
        if (pkt_count != ref->pkt_count) {
            mismatch = 1;
        }
    } else {
        if ((pkt_count & ref_mask->pkt_count) != (ref->pkt_count & ref_mask->pkt_count)) {
            mismatch = 1;
        }
    }

    return mismatch;
}

void ing_pkt_counter::deep_copy(ing_pkt_counter *ref) {
    uint i;

    pkt_count = ref->pkt_count;
}

