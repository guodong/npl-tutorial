/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/


#include "header_classes.h"
#include "bmodel.h"

ethernet_t::ethernet_t() {
    macda = (_48bits)(0x0U);
    macsa = (_48bits)(0x0U);
    ether_type = (_16bits)(0x0U);
    _PRESENT = (_1bit)(0x0U);
    _PRESENT_CUR = (_1bit)(0x0U);
    num_bytes = 14;
    last_header_op = 0x0U;
    hdr_bytes = new _8bits[num_bytes];
}

ethernet_t::~ethernet_t() {
    delete[] hdr_bytes;
}

void ethernet_t::set_resetval() {
    uint i;

    reset_header_base_class();
    macda = (_48bits)(0x0U);
    macsa = (_48bits)(0x0U);
    ether_type = (_16bits)(0x0U);
    _PRESENT = (_1bit)(0x0U);
    _PRESENT_CUR = (_1bit)(0x0U);
    num_bytes = 14;
    last_header_op = 0x0U;
    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = 0x0U;
    }

}

int ethernet_t::extract_fields(_8bits *pkt, _32bits *hdr_ptr, _32bits *pkt_len) {
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
            ether_type |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (2 - i - 1))));
        } else {
            ether_type |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    *hdr_ptr +=  (byte_ptr + i);
    stop_byte = *hdr_ptr - 1;

    pack();

    return 0;
}

void ethernet_t::pack() {
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
            hdr_bytes[byte_ptr + i] |= (_8bits)(((ether_type) >> (8 * (2 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((ether_type) << 0));
        }
    }
    update_header_location();

}

void ethernet_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->normal("ethernet_t->macda = 0x" + macda.to_string(SC_HEX_US, false));
    bmi_log->normal("ethernet_t->macsa = 0x" + macsa.to_string(SC_HEX_US, false));
    bmi_log->normal("ethernet_t->ether_type = 0x" + ether_type.to_string(SC_HEX_US, false));
    bmi_log->normal("ethernet_t->_PRESENT = 0x" + _PRESENT.to_string(SC_HEX_US, false));
    bmi_log->normal("ethernet_t->_PRESENT_CUR = 0x" + _PRESENT_CUR.to_string(SC_HEX_US, false));
#endif
}

void ethernet_t::deep_copy(ethernet_t *ref) {
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
    ether_type = ref->ether_type;
    _PRESENT = ref->_PRESENT;
    _PRESENT_CUR = ref->_PRESENT_CUR;
}

vlan_t::vlan_t() {
    pcp = (_3bits)(0x0U);
    cfi = (_1bit)(0x0U);
    vid = (_12bits)(0x0U);
    ether_type = (_16bits)(0x0U);
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
    ether_type = (_16bits)(0x0U);
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
            ether_type |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (2 - i - 1))));
        } else {
            ether_type |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
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
            hdr_bytes[byte_ptr + i] |= (_8bits)(((ether_type) >> (8 * (2 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((ether_type) << 0));
        }
    }
    update_header_location();

}

void vlan_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->normal("vlan_t->pcp = 0x" + pcp.to_string(SC_HEX_US, false));
    bmi_log->normal("vlan_t->cfi = 0x" + cfi.to_string(SC_HEX_US, false));
    bmi_log->normal("vlan_t->vid = 0x" + vid.to_string(SC_HEX_US, false));
    bmi_log->normal("vlan_t->ether_type = 0x" + ether_type.to_string(SC_HEX_US, false));
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
    ether_type = ref->ether_type;
    _PRESENT = ref->_PRESENT;
    _PRESENT_CUR = ref->_PRESENT_CUR;
}

void grp_t::set_ether(ethernet_t *ref) {
    uint i;
    ether->deep_copy(ref);
}

void grp_t::set_vlan(vlan_t *ref) {
    uint i;
    vlan->deep_copy(ref);
}

grp_t::grp_t() {
    uint i;
    ether = new ethernet_t;
    vlan = new vlan_t;
}

void grp_t::set_resetval() {
    uint i;
    ether->set_resetval();
    vlan->set_resetval();
}

grp_t::~grp_t() {
    uint i;
    delete ether;
    delete vlan;
}

void grp_t::deep_copy(grp_t *ref) {
    uint i;
    ether->deep_copy(ref->ether);
    vlan->deep_copy(ref->vlan);
}

void ingress_pkt_t::set_group(grp_t *ref) {
    uint i;
    group->deep_copy(ref);
}

ingress_pkt_t::ingress_pkt_t() {
    uint i;
    _match_id = 0;
    group = new grp_t;

    num_hdr = 2;
    hdr_ptr_array = (header_base_t **)(malloc(2 * sizeof(header_base_t *)));

}

ingress_pkt_t::~ingress_pkt_t() {
    delete group;
    free(hdr_ptr_array);
}

void ingress_pkt_t::set_resetval() {
    group->set_resetval();
    num_hdr = 2;
    group->ether->hdr_id = 0;
    hdr_ptr_array[0] = group->ether;
    group->vlan->hdr_id = 1;
    hdr_ptr_array[1] = group->vlan;
}

void ingress_pkt_t::deep_copy(ingress_pkt_t *ref) {
    uint i;
    group->deep_copy(ref->group);
}

