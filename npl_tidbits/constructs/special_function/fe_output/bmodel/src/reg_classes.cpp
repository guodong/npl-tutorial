/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/


#include "reg_classes.h"
#include "base/cLog.h"

void ts_ctrl::set_enable(_1bit value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 0;
    }

    enable(maxbit, minbit) = value;
}

ts_ctrl::ts_ctrl() {
    uint i;

    enable = (_1bit)(1);
}

void ts_ctrl::print() {
#ifndef NO_CONSOLE_OUTPUT
    uint i;

    bmi_log->normal("ts_ctrl->enable = 0x" + enable.to_string(SC_HEX_US, false));
#endif
}

int ts_ctrl::compare(ts_ctrl *ref, ts_ctrl *ref_mask) {
    uint mismatch = 0;
    uint i;

    if (ref_mask == NULL) {
        if (enable != ref->enable) {
            mismatch = 1;
        }
    } else {
        if ((enable & ref_mask->enable) != (ref->enable & ref_mask->enable)) {
            mismatch = 1;
        }
    }

    return mismatch;
}

void ts_ctrl::deep_copy(ts_ctrl *ref) {
    uint i;

    enable = ref->enable;
}

