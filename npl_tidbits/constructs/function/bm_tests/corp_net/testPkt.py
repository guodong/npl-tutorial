
#####################################################################
#
# Purpose:
#   To generate traffic for function construct example.
#
# Steps:
#   (a). Send a TCP packet with src_port=dst_port=0
#        Receive a packet from BM and do Hexdump
#   (b). Send a UDP packet with src_port = 0x1234 and dst_port=0x5678
#        Receive a packet from BM and do Hexdump
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
dip = "10.10.10.4"
sip = "192.192.192.2"
ihl = 5
ip_len = 108
dataofs = 5
vlan_id = 1


# TCP packets, with src_port/dst_port = 0
def get_tx_packet_tcp(test_num):
    pkt = Ether()/IP()/TCP()/Raw()
    pkt[Ether].dst = dst_mac
    pkt[Ether].src = src_mac
    pkt[IP].dst = dip
    pkt[IP].src = sip
    pkt[IP].ihl = ihl
    pkt[TCP].dataofs = dataofs
    pkt[Raw].load = "This packet is being sent by test {} from CLI to BM".format(test_num)
    return pkt

# UDP packets, src_port = 0x1234 and dst_port = 0x5678
def get_tx_packet_udp(test_num):
    pkt = Ether()/IP()/UDP()/Raw()
    pkt[Ether].dst = dst_mac
    pkt[Ether].src = src_mac
    pkt[IP].dst = dip
    pkt[IP].src = sip
    pkt[IP].ihl = ihl
    pkt[UDP].sport= 0x1234
    pkt[UDP].dport= 0x5678
    pkt[Raw].load = "This packet is being sent by test {} from CLI to BM".format(test_num)
    return pkt

if __name__ == '__main__':
    bmintf = BMRpcIntf()
    #sending the first Packet
    port = [0]

    numpkts = 1
    for count  in range(numpkts):
        for i in port:
            #Sending tcp packet
            pkt = get_tx_packet_tcp(i+1)
            recv_pkt = bmintf.tx_pkt(i, pkt, len(str(pkt)))
            print "##################################"
            print "TX TCP PKT on port {}:".format(i)
            #hexdump(pkt)
            if (recv_pkt['STATUS']):
                print "Packet is Dropped!"
            else:
                print "RX PKT on port {}:".format(recv_pkt['PORT'])
                hexdump(recv_pkt['PACKET'])

            time.sleep(1)
            #Sending udp packet
            pkt = get_tx_packet_udp(i+2)
            recv_pkt = bmintf.tx_pkt(i, pkt, len(str(pkt)))
            print "##################################"
            print "TX UDP PKT on port {}:".format(i)
            #hexdump(pkt)
            if (recv_pkt['STATUS']):
                print "Packet is Dropped!"
            else:
                print "RX PKT on port {}:".format(recv_pkt['PORT'])
                hexdump(recv_pkt['PACKET'])

###########################################################################
# Example output with above test.
#
#{function}$: python bm_tests/corp_net/testPkt.py
#WARNING: No route found for IPv6 destination :: (no default route?)
#'Connected to Switch'
###################################
#TX TCP PKT on port 0:
#RX PKT on port 1:
#0000   00 00 00 00 01 10 00 00  00 00 02 00 08 00 45 00   ..............E.
#0010   00 5A 00 01 00 00 40 06  E5 CC C0 C0 C0 02 0A 0A   .Z....@.........
#0020   0A 04 00 14 00 50 00 00  00 00 00 00 00 00 50 02   .....P........P.
#0030   20 00 E1 AE 00 00 54 68  69 73 20 70 61 63 6B 65    .....This packe
#0040   74 20 69 73 20 62 65 69  6E 67 20 73 65 6E 74 20   t is being sent
#0050   62 79 20 74 65 73 74 20  31 20 66 72 6F 6D 20 43   by test 1 from C
#0060   4C 49 20 74 A9 A3 61 AD                            LI t..a.
###################################
#TX UDP PKT on port 0:
#RX PKT on port 1:
#0000   00 00 00 00 01 10 00 00  00 00 02 00 08 00 45 00   ..............E.
#0010   00 4E 00 01 00 00 40 11  E5 CD C0 C0 C0 02 0A 0A   .N....@.........
#0020   0A 04 12 34 56 78 00 3A  E8 2F 54 68 69 73 20 70   ...4Vx.:./This p
#0030   61 63 6B 65 74 20 69 73  20 62 65 69 6E 67 20 73   acket is being s
#0040   65 6E 74 20 62 79 20 74  65 73 74 20 32 20 66 72   ent by test 2 fr
#0050   6F 6D 20 43 4C 49 20 74  2D F0 82 3C               om CLI t-..<

