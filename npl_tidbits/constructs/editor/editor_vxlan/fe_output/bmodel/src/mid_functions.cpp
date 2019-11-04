/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/


#include "bmodel.h"

void _BModel::update_mid__ingress_pkt__group1() {
    if (ingress_pkt->group1->l2->_PRESENT == 1) {
        ingress_pkt->_match_id(0, 0) = 1;
    }
}

void _BModel::update_mid__egress_pkt__group2__vxlan() {
    if (egress_pkt->group2->vxlan->_PRESENT == 1) {
        egress_pkt->_match_id(3, 3) = 1;
    }
}

void _BModel::update_mid__egress_pkt__group3__l2() {
    if (egress_pkt->group3->l2->_PRESENT == 1) {
        egress_pkt->_match_id(4, 4) = 1;
    }
}

void _BModel::update_mid__ingress_pkt() {
    if (ingress_pkt->group1->l2->_PRESENT == 1) {
        ingress_pkt->_match_id(0, 0) = 1;
    }
    if (ingress_pkt->group2->vxlan->_PRESENT == 1) {
        ingress_pkt->_match_id(3, 3) = 1;
    }
    if (ingress_pkt->group2->ipv4->_PRESENT == 1) {
        ingress_pkt->_match_id(1, 1) = 1;
    }
    if (ingress_pkt->group2->udp->_PRESENT == 1) {
        ingress_pkt->_match_id(2, 2) = 1;
    }
    if (ingress_pkt->group4->ipv4->_PRESENT == 1) {
        ingress_pkt->_match_id(5, 5) = 1;
    }
    if (ingress_pkt->group4->udp->_PRESENT == 1) {
        ingress_pkt->_match_id(6, 6) = 1;
    }
    if (ingress_pkt->group4->vxlan->_PRESENT == 1) {
        ingress_pkt->_match_id(7, 7) = 1;
    }
    if (ingress_pkt->group3->l2->_PRESENT == 1) {
        ingress_pkt->_match_id(4, 4) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__group2__ipv4() {
    if (ingress_pkt->group2->ipv4->_PRESENT == 1) {
        ingress_pkt->_match_id(1, 1) = 1;
    }
}

void _BModel::update_mid__egress_pkt__group2__udp() {
    if (egress_pkt->group2->udp->_PRESENT == 1) {
        egress_pkt->_match_id(2, 2) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__group3__l2() {
    if (ingress_pkt->group3->l2->_PRESENT == 1) {
        ingress_pkt->_match_id(4, 4) = 1;
    }
}

void _BModel::update_mid__egress_pkt__group1__l2() {
    if (egress_pkt->group1->l2->_PRESENT == 1) {
        egress_pkt->_match_id(0, 0) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__group4__ipv4() {
    if (ingress_pkt->group4->ipv4->_PRESENT == 1) {
        ingress_pkt->_match_id(5, 5) = 1;
    }
}

void _BModel::update_mid__egress_pkt__group4() {
    if (egress_pkt->group4->vxlan->_PRESENT == 1) {
        egress_pkt->_match_id(7, 7) = 1;
    }
    if (egress_pkt->group4->ipv4->_PRESENT == 1) {
        egress_pkt->_match_id(5, 5) = 1;
    }
    if (egress_pkt->group4->udp->_PRESENT == 1) {
        egress_pkt->_match_id(6, 6) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__group4() {
    if (ingress_pkt->group4->ipv4->_PRESENT == 1) {
        ingress_pkt->_match_id(5, 5) = 1;
    }
    if (ingress_pkt->group4->udp->_PRESENT == 1) {
        ingress_pkt->_match_id(6, 6) = 1;
    }
    if (ingress_pkt->group4->vxlan->_PRESENT == 1) {
        ingress_pkt->_match_id(7, 7) = 1;
    }
}

void _BModel::update_mid__egress_pkt__group3() {
    if (egress_pkt->group3->l2->_PRESENT == 1) {
        egress_pkt->_match_id(4, 4) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__group1__l2() {
    if (ingress_pkt->group1->l2->_PRESENT == 1) {
        ingress_pkt->_match_id(0, 0) = 1;
    }
}

void _BModel::update_mid__egress_pkt() {
    if (egress_pkt->group1->l2->_PRESENT == 1) {
        egress_pkt->_match_id(0, 0) = 1;
    }
    if (egress_pkt->group4->vxlan->_PRESENT == 1) {
        egress_pkt->_match_id(7, 7) = 1;
    }
    if (egress_pkt->group4->ipv4->_PRESENT == 1) {
        egress_pkt->_match_id(5, 5) = 1;
    }
    if (egress_pkt->group4->udp->_PRESENT == 1) {
        egress_pkt->_match_id(6, 6) = 1;
    }
    if (egress_pkt->group2->vxlan->_PRESENT == 1) {
        egress_pkt->_match_id(3, 3) = 1;
    }
    if (egress_pkt->group2->ipv4->_PRESENT == 1) {
        egress_pkt->_match_id(1, 1) = 1;
    }
    if (egress_pkt->group2->udp->_PRESENT == 1) {
        egress_pkt->_match_id(2, 2) = 1;
    }
    if (egress_pkt->group3->l2->_PRESENT == 1) {
        egress_pkt->_match_id(4, 4) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__group2() {
    if (ingress_pkt->group2->vxlan->_PRESENT == 1) {
        ingress_pkt->_match_id(3, 3) = 1;
    }
    if (ingress_pkt->group2->ipv4->_PRESENT == 1) {
        ingress_pkt->_match_id(1, 1) = 1;
    }
    if (ingress_pkt->group2->udp->_PRESENT == 1) {
        ingress_pkt->_match_id(2, 2) = 1;
    }
}

void _BModel::update_mid__egress_pkt__group2() {
    if (egress_pkt->group2->vxlan->_PRESENT == 1) {
        egress_pkt->_match_id(3, 3) = 1;
    }
    if (egress_pkt->group2->ipv4->_PRESENT == 1) {
        egress_pkt->_match_id(1, 1) = 1;
    }
    if (egress_pkt->group2->udp->_PRESENT == 1) {
        egress_pkt->_match_id(2, 2) = 1;
    }
}

void _BModel::update_mid__egress_pkt__group2__ipv4() {
    if (egress_pkt->group2->ipv4->_PRESENT == 1) {
        egress_pkt->_match_id(1, 1) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__group2__udp() {
    if (ingress_pkt->group2->udp->_PRESENT == 1) {
        ingress_pkt->_match_id(2, 2) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__group3() {
    if (ingress_pkt->group3->l2->_PRESENT == 1) {
        ingress_pkt->_match_id(4, 4) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__group4__vxlan() {
    if (ingress_pkt->group4->vxlan->_PRESENT == 1) {
        ingress_pkt->_match_id(7, 7) = 1;
    }
}

void _BModel::update_mid__egress_pkt__group4__udp() {
    if (egress_pkt->group4->udp->_PRESENT == 1) {
        egress_pkt->_match_id(6, 6) = 1;
    }
}

void _BModel::update_mid__egress_pkt__group4__vxlan() {
    if (egress_pkt->group4->vxlan->_PRESENT == 1) {
        egress_pkt->_match_id(7, 7) = 1;
    }
}

void _BModel::update_mid__egress_pkt__group1() {
    if (egress_pkt->group1->l2->_PRESENT == 1) {
        egress_pkt->_match_id(0, 0) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__group2__vxlan() {
    if (ingress_pkt->group2->vxlan->_PRESENT == 1) {
        ingress_pkt->_match_id(3, 3) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__group4__udp() {
    if (ingress_pkt->group4->udp->_PRESENT == 1) {
        ingress_pkt->_match_id(6, 6) = 1;
    }
}

void _BModel::update_mid__egress_pkt__group4__ipv4() {
    if (egress_pkt->group4->ipv4->_PRESENT == 1) {
        egress_pkt->_match_id(5, 5) = 1;
    }
}

