
#####################################################################
#
# Purpose:
#   To generate traffic for 'data_types and parser' construct example.
#
# Steps:
# (a). Send double-tagged packet(outer TPID(0x88A8), outer VLAN 10,
#      inner TPID(0x8100), inner vlan 20)  to port-0 of BM.
#      Print hexdump of the transmitted packet.
# (b). Send single-outer-tagged packet(outer TPID(0x88A8), outer VLAN 10)
#      to port-0 of BM. Print hexdump of the transmitted packet.
# (c). Send single-inner-tagged packet(inner TPID(0x8100), inner VLAN 20)
#      to port-0 of BM. Print hexdump of the transmitted packet.
# (d). Send un-tagged packet to port-0 of BM.
#      Print hexdump of the transmitted packet.
# (e). Send a IP packet with options to port-0 of BM.
#      Print hexdump of the transmitted packet.
#
#####################################################################
from scapy.all import *
import os
bm_rpc_lib = os.path.join(os.environ['NCS_ROOT'], 'bmi/cli')
sys.path.append(bm_rpc_lib)
from bm_rpc_intf import *

from datetime import datetime

#Pkt config
dst_mac = "00:00:00:00:01:10"
src_mac = "00:00:00:00:02:00"
dip = "1.1.1.1"
sip = "2.2.2.2"
ihl = 5
ip_len = 108
dataofs = 5
vlan_id = 10

def get_tx_double_tagged_packet(test_num):
    pkt = Ether(type=0x88A8)/Dot1Q(vlan=10)/Dot1Q(vlan=20)/IP()/TCP()/Raw()
    pkt[Ether].dst = dst_mac
    pkt[Ether].src = src_mac
    pkt[IP].dst = dip
    pkt[IP].src = sip
    pkt[IP].ihl = ihl
    pkt[TCP].dataofs = dataofs
    pkt[Raw].load = "This packet is being sent by test {} from CLI to BM".format(test_num)
    return pkt

def get_tx_single_outer_tagged_packet(test_num):
    pkt = Ether(type=0x88A8)/Dot1Q(vlan=10)/IP()/TCP()/Raw()
    pkt[Ether].dst = dst_mac
    pkt[Ether].src = src_mac
    pkt[IP].dst = dip
    pkt[IP].src = sip
    pkt[IP].ihl = ihl
    pkt[TCP].dataofs = dataofs
    pkt[Raw].load = "This packet is being sent by test {} from CLI to BM".format(test_num)
    return pkt

def get_tx_single_inner_tagged_packet(test_num):
    pkt = Ether()/Dot1Q(vlan=10)/IP()/TCP()/Raw()
    pkt[Ether].dst = dst_mac
    pkt[Ether].src = src_mac
    pkt[IP].dst = dip
    pkt[IP].src = sip
    pkt[IP].ihl = ihl
    pkt[TCP].dataofs = dataofs
    pkt[Raw].load = "This packet is being sent by test {} from CLI to BM".format(test_num)
    return pkt

def get_tx_un_tagged_packet(test_num):
    pkt = Ether()/IP()/TCP()/Raw()
    pkt[Ether].dst = dst_mac
    pkt[Ether].src = src_mac
    pkt[IP].dst = dip
    pkt[IP].src = sip
    pkt[IP].ihl = ihl
    pkt[TCP].dataofs = dataofs
    pkt[Raw].load = "This packet is being sent by test {} from CLI to BM".format(test_num)
    return pkt
def get_tx_ip_options_packet(test_num):
    pkt = Ether()/IP()/TCP()/Raw()
    pkt[Ether].dst = dst_mac
    pkt[Ether].src = src_mac
    pkt[IP].dst = dip
    pkt[IP].src = sip
    pkt[IP].options = IPOption('\x83\x03\x10')
    pkt[TCP].dataofs = dataofs
    pkt[Raw].load = "This packet is being sent by test {} from CLI to BM".format(test_num)
    return pkt

if __name__ == '__main__':
    bmintf = BMRpcIntf()
    port = [0]

    numpkts = 5
    for count  in range(numpkts):
        for i in port:
            if (count == 0):
                pkt = get_tx_double_tagged_packet(i+1)
            elif (count == 1):
                pkt = get_tx_single_outer_tagged_packet(i+1)
            elif (count == 2):
                pkt = get_tx_single_inner_tagged_packet(i+1)
            elif (count == 3):
                pkt = get_tx_un_tagged_packet(i+1)
            elif (count == 4):
                pkt = get_tx_ip_options_packet(i+1)

            recv_pkt = bmintf.tx_pkt(i, pkt, len(str(pkt)))
            print "##################################"
            print "TX PKT on port {}:".format(i)
            hexdump(pkt)
            if (recv_pkt['STATUS']):
                print "Packet is Dropped!"
            else:
                print "RX PKT on port {}:".format(recv_pkt['PORT'])
                #hexdump(recv_pkt['PACKET'])
###########################################################################
# Example output with above test.
###########################################################################

#xl-sj1-30{sm925758}192: python bm_tests/corp_net/testPkt.py
#WARNING: No route found for IPv6 destination :: (no default route?)
#'Connected to Switch'
###################################
#TX PKT on port 0:
#0000   00 00 00 00 01 10 00 00  00 00 02 00 88 A8 00 0A   ................
#0010   81 00 00 14 08 00 45 00  00 5A 00 01 00 00 40 06   ......E..Z....@.
#0020   74 98 02 02 02 02 01 01  01 01 00 14 00 50 00 00   t............P..
#0030   00 00 00 00 00 00 50 02  20 00 70 7A 00 00 54 68   ......P. .pz..Th
#0040   69 73 20 70 61 63 6B 65  74 20 69 73 20 62 65 69   is packet is bei
#0050   6E 67 20 73 65 6E 74 20  62 79 20 74 65 73 74 20   ng sent by test
#0060   31 20 66 72 6F 6D 20 43  4C 49 20 74 6F 20 42 4D   1 from CLI to BM
#RX PKT on port 0:
###################################
#TX PKT on port 0:
#0000   00 00 00 00 01 10 00 00  00 00 02 00 88 A8 00 0A   ................
#0010   08 00 45 00 00 5A 00 01  00 00 40 06 74 98 02 02   ..E..Z....@.t...
#0020   02 02 01 01 01 01 00 14  00 50 00 00 00 00 00 00   .........P......
#0030   00 00 50 02 20 00 70 7A  00 00 54 68 69 73 20 70   ..P. .pz..This p
#0040   61 63 6B 65 74 20 69 73  20 62 65 69 6E 67 20 73   acket is being s
#0050   65 6E 74 20 62 79 20 74  65 73 74 20 31 20 66 72   ent by test 1 fr
#0060   6F 6D 20 43 4C 49 20 74  6F 20 42 4D               om CLI to BM
#RX PKT on port 0:
###################################
#TX PKT on port 0:
#0000   00 00 00 00 01 10 00 00  00 00 02 00 81 00 00 0A   ................
#0010   08 00 45 00 00 5A 00 01  00 00 40 06 74 98 02 02   ..E..Z....@.t...
#0020   02 02 01 01 01 01 00 14  00 50 00 00 00 00 00 00   .........P......
#0030   00 00 50 02 20 00 70 7A  00 00 54 68 69 73 20 70   ..P. .pz..This p
#0040   61 63 6B 65 74 20 69 73  20 62 65 69 6E 67 20 73   acket is being s
#0050   65 6E 74 20 62 79 20 74  65 73 74 20 31 20 66 72   ent by test 1 fr
#0060   6F 6D 20 43 4C 49 20 74  6F 20 42 4D               om CLI to BM
#RX PKT on port 0:
###################################
#TX PKT on port 0:
#0000   00 00 00 00 01 10 00 00  00 00 02 00 08 00 45 00   ..............E.
#0010   00 5A 00 01 00 00 40 06  74 98 02 02 02 02 01 01   .Z....@.t.......
#0020   01 01 00 14 00 50 00 00  00 00 00 00 00 00 50 02   .....P........P.
#0030   20 00 70 7A 00 00 54 68  69 73 20 70 61 63 6B 65    .pz..This packe
#0040   74 20 69 73 20 62 65 69  6E 67 20 73 65 6E 74 20   t is being sent
#0050   62 79 20 74 65 73 74 20  31 20 66 72 6F 6D 20 43   by test 1 from C
#0060   4C 49 20 74 6F 20 42 4D                            LI to BM
#RX PKT on port 0:
###################################
#TX PKT on port 0:
#0000   00 00 00 00 01 10 00 00  00 00 02 00 08 00 46 00   ..............F.
#0010   00 5E 00 01 00 00 40 06  E0 90 02 02 02 02 01 01   .^....@.........
#0020   01 01 83 03 10 00 00 14  00 50 00 00 00 00 00 00   .........P......
#0030   00 00 50 02 20 00 70 7A  00 00 54 68 69 73 20 70   ..P. .pz..This p
#0040   61 63 6B 65 74 20 69 73  20 62 65 69 6E 67 20 73   acket is being s
#0050   65 6E 74 20 62 79 20 74  65 73 74 20 31 20 66 72   ent by test 1 fr
#0060   6F 6D 20 43 4C 49 20 74  6F 20 42 4D               om CLI to BM
#RX PKT on port 0:
#xl-sj1-30{sm925758}193:
