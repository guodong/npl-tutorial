/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/


#include "reg_classes.h"
#include "base/cLog.h"

void tpid_values::set_tpid0(_16bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

    tpid0(maxbit, minbit) = value;
}

void tpid_values::set_tpid1(_16bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

    tpid1(maxbit, minbit) = value;
}

void tpid_values::set_tpid2(_16bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

    tpid2(maxbit, minbit) = value;
}

void tpid_values::set_tpid3(_16bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

    tpid3(maxbit, minbit) = value;
}

tpid_values::tpid_values() {
    uint i;

    tpid0 = (_16bits)(33024);
    tpid1 = (_16bits)(37120);
    tpid2 = (_16bits)(34984);
    tpid3 = (_16bits)(0);
}

void tpid_values::print() {
#ifndef NO_CONSOLE_OUTPUT
    uint i;

    bmi_log->normal("tpid_values->tpid0 = 0x" + tpid0.to_string(SC_HEX_US, false));
    bmi_log->normal("tpid_values->tpid1 = 0x" + tpid1.to_string(SC_HEX_US, false));
    bmi_log->normal("tpid_values->tpid2 = 0x" + tpid2.to_string(SC_HEX_US, false));
    bmi_log->normal("tpid_values->tpid3 = 0x" + tpid3.to_string(SC_HEX_US, false));
#endif
}

int tpid_values::compare(tpid_values *ref, tpid_values *ref_mask) {
    uint mismatch = 0;
    uint i;

    if (ref_mask == NULL) {
        if (tpid0 != ref->tpid0) {
            mismatch = 1;
        }
    } else {
        if ((tpid0 & ref_mask->tpid0) != (ref->tpid0 & ref_mask->tpid0)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (tpid1 != ref->tpid1) {
            mismatch = 1;
        }
    } else {
        if ((tpid1 & ref_mask->tpid1) != (ref->tpid1 & ref_mask->tpid1)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (tpid2 != ref->tpid2) {
            mismatch = 1;
        }
    } else {
        if ((tpid2 & ref_mask->tpid2) != (ref->tpid2 & ref_mask->tpid2)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (tpid3 != ref->tpid3) {
            mismatch = 1;
        }
    } else {
        if ((tpid3 & ref_mask->tpid3) != (ref->tpid3 & ref_mask->tpid3)) {
            mismatch = 1;
        }
    }

    return mismatch;
}

void tpid_values::deep_copy(tpid_values *ref) {
    uint i;

    tpid0 = ref->tpid0;
    tpid1 = ref->tpid1;
    tpid2 = ref->tpid2;
    tpid3 = ref->tpid3;
}

void tpid_enable::set_reg_val(_4bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 3;
    }

    reg_val(maxbit, minbit) = value;
}

tpid_enable::tpid_enable() {
    uint i;

    reg_val = (_4bits)(7);
}

void tpid_enable::print() {
#ifndef NO_CONSOLE_OUTPUT
    uint i;

    bmi_log->normal("tpid_enable->reg_val = 0x" + reg_val.to_string(SC_HEX_US, false));
#endif
}

int tpid_enable::compare(tpid_enable *ref, tpid_enable *ref_mask) {
    uint mismatch = 0;
    uint i;

    if (ref_mask == NULL) {
        if (reg_val != ref->reg_val) {
            mismatch = 1;
        }
    } else {
        if ((reg_val & ref_mask->reg_val) != (ref->reg_val & ref_mask->reg_val)) {
            mismatch = 1;
        }
    }

    return mismatch;
}

void tpid_enable::deep_copy(tpid_enable *ref) {
    uint i;

    reg_val = ref->reg_val;
}

