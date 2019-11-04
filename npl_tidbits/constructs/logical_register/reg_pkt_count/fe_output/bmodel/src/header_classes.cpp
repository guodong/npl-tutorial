/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/


#include "header_classes.h"
#include "bmodel.h"

l2_t::l2_t() {
    macda = (_48bits)(0x0U);
    macsa = (_48bits)(0x0U);
    ethertype = (_16bits)(0x0U);
    _PRESENT = (_1bit)(0x0U);
    _PRESENT_CUR = (_1bit)(0x0U);
    num_bytes = 14;
    last_header_op = 0x0U;
    hdr_bytes = new _8bits[num_bytes];
}

l2_t::~l2_t() {
    delete[] hdr_bytes;
}

void l2_t::set_resetval() {
    uint i;

    reset_header_base_class();
    macda = (_48bits)(0x0U);
    macsa = (_48bits)(0x0U);
    ethertype = (_16bits)(0x0U);
    _PRESENT = (_1bit)(0x0U);
    _PRESENT_CUR = (_1bit)(0x0U);
    num_bytes = 14;
    last_header_op = 0x0U;
    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = 0x0U;
    }

}

int l2_t::extract_fields(_8bits *pkt, _32bits *hdr_ptr, _32bits *pkt_len) {
    uint byte_ptr;
    uint i;

    start_byte = *hdr_ptr;
    if (*pkt_len < (start_byte+14)) {
        // Remaining packet bytes are less than fixed header size
        *hdr_ptr = *pkt_len;
        return -1;
    }
    byte_ptr = 0;
    for (i = 0; i < 6; i++) {
        if (i != 5) {
            macda |= (((_48bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (6 - i - 1))));
        } else {
            macda |= (((_48bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 6;
    for (i = 0; i < 6; i++) {
        if (i != 5) {
            macsa |= (((_48bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (6 - i - 1))));
        } else {
            macsa |= (((_48bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 12;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            ethertype |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (2 - i - 1))));
        } else {
            ethertype |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    *hdr_ptr +=  (byte_ptr + i);
    stop_byte = *hdr_ptr - 1;

    pack();

    return 0;
}

void l2_t::pack() {
    uint byte_ptr;
    uint i;

    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = 0x0U;
    }

    byte_ptr = 0;
    for (i = 0; i < 6; i++) {
        if (i != 5) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((macda) >> (8 * (6 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((macda) << 0));
        }
    }
    byte_ptr = 6;
    for (i = 0; i < 6; i++) {
        if (i != 5) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((macsa) >> (8 * (6 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((macsa) << 0));
        }
    }
    byte_ptr = 12;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((ethertype) >> (8 * (2 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((ethertype) << 0));
        }
    }
    update_header_location();

}

void l2_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->normal("l2_t->macda = 0x" + macda.to_string(SC_HEX_US, false));
    bmi_log->normal("l2_t->macsa = 0x" + macsa.to_string(SC_HEX_US, false));
    bmi_log->normal("l2_t->ethertype = 0x" + ethertype.to_string(SC_HEX_US, false));
    bmi_log->normal("l2_t->_PRESENT = 0x" + _PRESENT.to_string(SC_HEX_US, false));
    bmi_log->normal("l2_t->_PRESENT_CUR = 0x" + _PRESENT_CUR.to_string(SC_HEX_US, false));
#endif
}

void l2_t::deep_copy(l2_t *ref) {
    uint i;

    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = ref->hdr_bytes[i];
    }

    start_byte = ref->start_byte;
    stop_byte = ref->stop_byte;
    num_bytes = ref->num_bytes;
    last_header_op = ref->last_header_op;
    macda = ref->macda;
    macsa = ref->macsa;
    ethertype = ref->ethertype;
    _PRESENT = ref->_PRESENT;
    _PRESENT_CUR = ref->_PRESENT_CUR;
}

vlan_t::vlan_t() {
    pcp = (_3bits)(0x0U);
    cfi = (_1bit)(0x0U);
    vid = (_12bits)(0x0U);
    ethertype = (_16bits)(0x0U);
    _PRESENT = (_1bit)(0x0U);
    _PRESENT_CUR = (_1bit)(0x0U);
    num_bytes = 4;
    last_header_op = 0x0U;
    hdr_bytes = new _8bits[num_bytes];
}

vlan_t::~vlan_t() {
    delete[] hdr_bytes;
}

void vlan_t::set_resetval() {
    uint i;

    reset_header_base_class();
    pcp = (_3bits)(0x0U);
    cfi = (_1bit)(0x0U);
    vid = (_12bits)(0x0U);
    ethertype = (_16bits)(0x0U);
    _PRESENT = (_1bit)(0x0U);
    _PRESENT_CUR = (_1bit)(0x0U);
    num_bytes = 4;
    last_header_op = 0x0U;
    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = 0x0U;
    }

}

int vlan_t::extract_fields(_8bits *pkt, _32bits *hdr_ptr, _32bits *pkt_len) {
    uint byte_ptr;
    uint i;

    start_byte = *hdr_ptr;
    if (*pkt_len < (start_byte+4)) {
        // Remaining packet bytes are less than fixed header size
        *hdr_ptr = *pkt_len;
        return -1;
    }
    byte_ptr = 0;
    pcp = (_3bits)((pkt[*hdr_ptr + byte_ptr] >> 5) & 0x7);

    byte_ptr = 0;
    cfi = (_1bit)((pkt[*hdr_ptr + byte_ptr] >> 4) & 0x1);

    byte_ptr = 0;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            vid |= (((_12bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (2 - i - 1))));
        } else {
            vid |= (((_12bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 2;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            ethertype |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (2 - i - 1))));
        } else {
            ethertype |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    *hdr_ptr +=  (byte_ptr + i);
    stop_byte = *hdr_ptr - 1;

    pack();

    return 0;
}

void vlan_t::pack() {
    uint byte_ptr;
    uint i;

    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = 0x0U;
    }

    byte_ptr = 0;
    hdr_bytes[byte_ptr] |= (_8bits)((((_8bits)(pcp)) << 5) & (_8bits)(0xe0U));
    byte_ptr = 0;
    hdr_bytes[byte_ptr] |= (_8bits)((((_8bits)(cfi)) << 4) & (_8bits)(0x10U));
    byte_ptr = 0;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((vid) >> (8 * (2 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((vid) << 0));
        }
    }
    byte_ptr = 2;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((ethertype) >> (8 * (2 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((ethertype) << 0));
        }
    }
    update_header_location();

}

void vlan_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->normal("vlan_t->pcp = 0x" + pcp.to_string(SC_HEX_US, false));
    bmi_log->normal("vlan_t->cfi = 0x" + cfi.to_string(SC_HEX_US, false));
    bmi_log->normal("vlan_t->vid = 0x" + vid.to_string(SC_HEX_US, false));
    bmi_log->normal("vlan_t->ethertype = 0x" + ethertype.to_string(SC_HEX_US, false));
    bmi_log->normal("vlan_t->_PRESENT = 0x" + _PRESENT.to_string(SC_HEX_US, false));
    bmi_log->normal("vlan_t->_PRESENT_CUR = 0x" + _PRESENT_CUR.to_string(SC_HEX_US, false));
#endif
}

void vlan_t::deep_copy(vlan_t *ref) {
    uint i;

    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = ref->hdr_bytes[i];
    }

    start_byte = ref->start_byte;
    stop_byte = ref->stop_byte;
    num_bytes = ref->num_bytes;
    last_header_op = ref->last_header_op;
    pcp = ref->pcp;
    cfi = ref->cfi;
    vid = ref->vid;
    ethertype = ref->ethertype;
    _PRESENT = ref->_PRESENT;
    _PRESENT_CUR = ref->_PRESENT_CUR;
}

void grp_t::set_l2(l2_t *ref) {
    uint i;
    l2->deep_copy(ref);
}

void grp_t::set_vlan_tag(vlan_t *ref) {
    uint i;
    vlan_tag->deep_copy(ref);
}

grp_t::grp_t() {
    uint i;
    l2 = new l2_t;
    vlan_tag = new vlan_t;
}

void grp_t::set_resetval() {
    uint i;
    l2->set_resetval();
    vlan_tag->set_resetval();
}

grp_t::~grp_t() {
    uint i;
    delete l2;
    delete vlan_tag;
}

void grp_t::deep_copy(grp_t *ref) {
    uint i;
    l2->deep_copy(ref->l2);
    vlan_tag->deep_copy(ref->vlan_tag);
}

void pkt_t::set_grp(grp_t *ref) {
    uint i;
    grp->deep_copy(ref);
}

pkt_t::pkt_t() {
    uint i;
    _match_id = 0;
    grp = new grp_t;

    num_hdr = 2;
    hdr_ptr_array = (header_base_t **)(malloc(2 * sizeof(header_base_t *)));

}

pkt_t::~pkt_t() {
    delete grp;
    free(hdr_ptr_array);
}

void pkt_t::set_resetval() {
    grp->set_resetval();
    num_hdr = 2;
    grp->l2->hdr_id = 0;
    hdr_ptr_array[0] = grp->l2;
    grp->vlan_tag->hdr_id = 1;
    hdr_ptr_array[1] = grp->vlan_tag;
}

void pkt_t::deep_copy(pkt_t *ref) {
    uint i;
    grp->deep_copy(ref->grp);
}

