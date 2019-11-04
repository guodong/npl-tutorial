/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/


#include "bmodel.h"

void _BModel::create_checksum0(_8bits* pkt, egr_pkt_t* egress_pkt, _16bits* hdr_checksum, _4bits* version, _4bits* hdr_len, _8bits* tos, _16bits* v4_length, _16bits* id, _3bits* flags, _13bits* frag_offset, _8bits* ttl, _8bits* protocol, _32bits* sip, _32bits* dip) {
    uint i;
    _32bits num_values;
    _32bits payload_offset;
    packet_base_t *packet = (packet_base_t*)(egress_pkt);
    header_base_t *header;
    header_base_t *base_header;
    _8bits include_payload = 0;
    _17bits sum_carry;
    _32bits value_index;
    _16bits value;
    _16bits sum;
    _1bit carry;
    _16bits *val_array = new _16bits[pkt_len + MAX_ENCAP];

    value_index = 0;
    value(15,12) = (*version)(3, 0);
    value(11,8) = (*hdr_len)(3, 0);
    value(7,0) = (*tos)(7, 0);
    val_array[value_index] = value;

    value_index = 1;
    value(15,0) = (*v4_length)(15, 0);
    val_array[value_index] = value;

    value_index = 2;
    value(15,0) = (*id)(15, 0);
    val_array[value_index] = value;

    value_index = 3;
    value(15,13) = (*flags)(2, 0);
    value(12,0) = (*frag_offset)(12, 0);
    val_array[value_index] = value;

    value_index = 4;
    value(15,8) = (*ttl)(7, 0);
    value(7,0) = (*protocol)(7, 0);
    val_array[value_index] = value;

    value_index = 5;
    value(15,0) = (*sip)(31, 16);
    val_array[value_index] = value;

    value_index = 6;
    value(15,0) = (*sip)(15, 0);
    val_array[value_index] = value;

    value_index = 7;
    value(15,0) = (*dip)(31, 16);
    val_array[value_index] = value;

    value_index = 8;
    value(15,0) = (*dip)(15, 0);
    val_array[value_index] = value;

    if (include_payload == HEADER_PAYLOAD_CHKSUM) {
        value_index += 1;
        for (i = payload_offset; i < (pkt_len - NUM_BYTES_CRC); i += 2) {
            value(15, 8) = pkt[i];

            if ((pkt_len - NUM_BYTES_CRC) < (i + 2)) {
                value(7, 0) = (_8bits)(0x0U);
            } else {
                value(7, 0) = pkt[i + 1];
            }

            val_array[value_index] = value;
            value_index++;
        }

        num_values = value_index;
    } else {
        num_values = value_index + 1;
    }

    sum_carry = 0x0;
    for (i = 0; i < num_values; i++) {
        sum_carry += val_array[i];
        sum = sum_carry(15, 0);
        carry = sum_carry(16, 16);

        if (carry != 0x0) {
            sum_carry += carry;
            sum = sum_carry(15, 0);
            carry = 0x0;
            sum_carry(16, 16) = 0x0;
        }
    }

    *hdr_checksum = ~sum;
    delete[] val_array;
}

void _BModel::update_packet_length0(void* egress_pkt, void* ipv4, _16bits* v4_length, _8bits* pkt_len_type, _8bits* pkt_trun_mode) {
    _32bits length_field;
    packet_length_update(egress_pkt, ipv4, &length_field, pkt_len_type, pkt_trun_mode);
    *v4_length = length_field(15, 0);
}

void _BModel::update_packet_length1(void* egress_pkt, void* udp, _16bits* udp_length, _8bits* pkt_len_type, _8bits* pkt_trun_mode) {
    _32bits length_field;
    packet_length_update(egress_pkt, udp, &length_field, pkt_len_type, pkt_trun_mode);
    *udp_length = length_field(15, 0);
}

