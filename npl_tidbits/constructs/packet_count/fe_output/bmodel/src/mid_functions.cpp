/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/


#include "bmodel.h"

void _BModel::update_mid__ingress_pkt__group() {
    if (ingress_pkt->group->ether->_PRESENT == 1) {
        ingress_pkt->_match_id(0, 0) = 1;
    }
}

void _BModel::update_mid__ingress_pkt() {
    if (ingress_pkt->group->ether->_PRESENT == 1) {
        ingress_pkt->_match_id(0, 0) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__group__ether() {
    if (ingress_pkt->group->ether->_PRESENT == 1) {
        ingress_pkt->_match_id(0, 0) = 1;
    }
}

