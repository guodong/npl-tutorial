/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/


#include "bmodel.h"

void _BModel::update_mid__pkt__grp__vlan_tag() {
    if (pkt->grp->vlan_tag->_PRESENT == 1) {
        pkt->_match_id(1, 1) = 1;
    }
}

void _BModel::update_mid__pkt__grp__l2() {
    if (pkt->grp->l2->_PRESENT == 1) {
        pkt->_match_id(0, 0) = 1;
    }
}

void _BModel::update_mid__pkt__grp() {
    if (pkt->grp->vlan_tag->_PRESENT == 1) {
        pkt->_match_id(1, 1) = 1;
    }
    if (pkt->grp->l2->_PRESENT == 1) {
        pkt->_match_id(0, 0) = 1;
    }
}

void _BModel::update_mid__pkt() {
    if (pkt->grp->vlan_tag->_PRESENT == 1) {
        pkt->_match_id(1, 1) = 1;
    }
    if (pkt->grp->l2->_PRESENT == 1) {
        pkt->_match_id(0, 0) = 1;
    }
}

