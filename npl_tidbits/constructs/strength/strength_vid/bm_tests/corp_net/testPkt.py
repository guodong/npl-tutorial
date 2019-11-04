
#####################################################################
#
# Purpose:
#   To generate traffic for 'strength' construct example.
#
# Steps:
#   (a). Send a tagged packet from port-0 to BM
#        Receive packet from BM and print hexdump
#   (b). Send an untagged EtherII packet from port-0 to BM
#        Receive packet from BM and print hexdump
#   (c). Send an untagged LLC packet from port-0 to BM
#        Receive packet from BM and print hexdump
#   (d). Send an untagged SNAP packet from port-0 to BM
#        Receive packet from BM and print hexdump
#
#####################################################################


from scapy.all import *
import os
import time
bm_rpc_lib = os.path.join(os.environ['NCS_ROOT'], 'bmi/cli')
sys.path.append(bm_rpc_lib)
from bm_rpc_intf import *

from datetime import datetime

#Pkt config
dst_mac = "00:00:00:00:01:10"
src_mac = "00:00:00:00:02:00"
dip = "0.0.0.4"
sip = "0.0.0.2"
ihl = 5
ip_len = 108
dataofs = 5
vlan_id = 10


# Setup tagged IP packet
def get_tx_tagged_packet(test_num):
    pkt = Ether()/Dot1Q()/IP()/TCP()/Raw()
    pkt[Ether].dst = dst_mac
    pkt[Ether].src = src_mac
    pkt[Dot1Q].vlan = vlan_id
    pkt[IP].dst = dip
    pkt[IP].src = sip
    pkt[IP].ihl = ihl
    pkt[TCP].dataofs = dataofs
    pkt[Raw].load = "This packet is being sent by test {} from CLI to BM".format(test_num)
    return pkt

# Setup untagged EtherII packet
def get_tx_ethII_packet(test_num):
    pkt = Ether()/IP()/TCP()/Raw()
    pkt[Ether].dst = dst_mac
    pkt[Ether].src = src_mac
    pkt[IP].dst = dip
    pkt[IP].src = sip
    pkt[IP].ihl = ihl
    pkt[TCP].dataofs = dataofs
    pkt[Raw].load = "This packet is being sent by test {} from CLI to BM".format(test_num)
    return pkt

# Setup LLC packet
def get_tx_llc_packet(test_num):
    pkt=Dot3()/LLC()/Raw()
    pkt[Dot3].dst = dst_mac
    pkt[Dot3].src = src_mac
    pkt[Raw].load = "This packet is being sent by test {} from CLI to BM".format(test_num)
    return pkt

# Setup SNAP packet
def get_tx_snap_packet(test_num):
    pkt=Dot3()/LLC()/SNAP()/Raw()
    pkt[Dot3].dst = dst_mac
    pkt[Dot3].src = src_mac
    pkt[Raw].load = "This packet is being sent by test {} from CLI to BM".format(test_num)
    return pkt

if __name__ == '__main__':
    bmintf = BMRpcIntf()
    pkt = ""
    port = [0]

    numpkts = 4
    for count  in range(numpkts):
        for i in port:
            if (count == 0):
                # Sending VLAN tagged packet
                pkt = get_tx_tagged_packet(count)
                print "##################################"
                print "TX tagged PKT on port {}:".format(i)
            elif (count == 1):
                # Sending etherII packet
                pkt = get_tx_ethII_packet(count)
                print "##################################"
                print "TX EtherII PKT on port {}:".format(i)
            elif (count == 2):
                # Sending LLC packet
                pkt = get_tx_llc_packet(count)
                print "##################################"
                print "TX LLC PKT on port {}:".format(i)
            elif (count == 3):
                # Sending SNAP packet
                pkt = get_tx_snap_packet(count)
                print "##################################"
                print "TX SNAP PKT on port {}:".format(i)
            #hexdump(pkt)
            recv_pkt = bmintf.tx_pkt(i, pkt, len(str(pkt)))
            #hexdump(pkt)
            if (recv_pkt['STATUS']):
                print "Packet is Dropped!"
            else:
                print "RX PKT on port {}:".format(recv_pkt['PORT'])
                hexdump(recv_pkt['PACKET'])
            time.sleep(1)

###########################################################################
# Example output with above test.
#
#{strength/strength_vid}$: python bm_tests/corp_net/testPkt.py
#WARNING: No route found for IPv6 destination :: (no default route?)
#'Connected to Switch'
###################################
#TX tagged PKT on port 0:
#RX PKT on port 1:
#0000   00 00 00 00 01 10 00 00  00 00 02 00 81 00 00 0A   ................
#0010   08 00 45 00 00 5A 00 01  00 00 40 06 7A 98 00 00   ..E..Z....@.z...
#0020   00 02 00 00 00 04 00 14  00 50 00 00 00 00 00 00   .........P......
#0030   00 00 50 02 20 00 77 7A  00 00 54 68 69 73 20 70   ..P. .wz..This p
#0040   61 63 6B 65 74 20 69 73  20 62 65 69 6E 67 20 73   acket is being s
#0050   65 6E 74 20 62 79 20 74  65 73 74 20 30 20 66 72   ent by test 0 fr
#0060   6F 6D 20 43 4C 49 20 74  88 79 D6 71               om CLI t.y.q
###################################
#TX EtherII PKT on port 0:
#RX PKT on port 1:
#0000   00 00 00 00 01 10 00 00  00 00 02 00 08 00 45 00   ..............E.
#0010   00 5A 00 01 00 00 40 06  7A 98 00 00 00 02 00 00   .Z....@.z.......
#0020   00 04 00 14 00 50 00 00  00 00 00 00 00 00 50 02   .....P........P.
#0030   20 00 76 7A 00 00 54 68  69 73 20 70 61 63 6B 65    .vz..This packe
#0040   74 20 69 73 20 62 65 69  6E 67 20 73 65 6E 74 20   t is being sent
#0050   62 79 20 74 65 73 74 20  31 20 66 72 6F 6D 20 43   by test 1 from C
#0060   4C 49 20 74 65 06 34 F6                            LI te.4.
###################################
#TX LLC PKT on port 0:
#RX PKT on port 1:
#0000   00 00 00 00 01 10 00 00  00 00 02 00 00 35 00 00   .............5..
#0010   00 54 68 69 73 20 70 61  63 6B 65 74 20 69 73 20   .This packet is
#0020   62 65 69 6E 67 20 73 65  6E 74 20 62 79 20 74 65   being sent by te
#0030   73 74 20 32 20 66 72 6F  6D 20 43 4C 49 20 74 D0   st 2 from CLI t.
#0040   99 84 FD                                           ...
###################################
#TX SNAP PKT on port 0:
#RX PKT on port 1:
#0000   00 00 00 00 01 10 00 00  00 00 02 00 00 3A AA AA   .............:..
#0010   03 00 00 00 00 00 54 68  69 73 20 70 61 63 6B 65   ......This packe
#0020   74 20 69 73 20 62 65 69  6E 67 20 73 65 6E 74 20   t is being sent
#0030   62 79 20 74 65 73 74 20  33 20 66 72 6F 6D 20 43   by test 3 from C
#0040   4C 49 20 74 7E AA D8 53                            LI t~..S
