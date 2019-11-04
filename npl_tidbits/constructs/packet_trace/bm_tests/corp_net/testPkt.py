
#####################################################################
#
# Purpose:
#   To generate traffic for 'packet trace' construct example.
#
# Steps:
#   (a). Send a packet w/o ip options to port-0 of BM.
#        Receive packet from BM and print hexdump
#   (b). Send a packet with ip options to port-0 of BM
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
vlan_id = 1



def get_tx_packet(test_num, ip_option):
    pkt = Ether()/IP()/TCP()/Raw()
    pkt[Ether].dst = dst_mac
    pkt[Ether].src = src_mac
    pkt[IP].dst = dip
    pkt[IP].src = sip
    if ip_option == 1:
        # ip option setup
        pkt[IP].ihl = ihl+1
        pkt[IP].options = '\x02\x00\x00\x00'
    pkt[TCP].dataofs = dataofs
    pkt[Raw].load = "This packet is being sent by test {} from CLI to BM".format(test_num)
    return pkt

if __name__ == '__main__':
    bmintf = BMRpcIntf()
    #sending the first Packet
    port = [0]

    numpkts = 1
    for count  in range(numpkts):
        for i in port:
            # Sending packet without ip options
            pkt = get_tx_packet(i+1, 1)
            recv_pkt = bmintf.tx_pkt(i, pkt, len(str(pkt)))
            print "##################################"
            print "TX PKT without IP options on port {}:".format(i)
            #hexdump(pkt)
            if (recv_pkt['STATUS']):
                print "Packet is Dropped!"
            else:
                print "RX PKT on port {}:".format(recv_pkt['PORT'])
                hexdump(recv_pkt['PACKET'])

            time.sleep(1)
            # Sending packet with ip option
            pkt = get_tx_packet(i+2, 0)
            recv_pkt = bmintf.tx_pkt(i, pkt, len(str(pkt)))
            print "##################################"
            print "TX PKT with IP on port {}:".format(i)
            #hexdump(pkt)
            if (recv_pkt['STATUS']):
                print "Packet is Dropped!"
            else:
                print "RX PKT on port {}:".format(recv_pkt['PORT'])
                hexdump(recv_pkt['PACKET'])

###########################################################################
# Example output with above test.
#
#{packet_trace}$: python bm_tests/corp_net/testPkt.py
#WARNING: No route found for IPv6 destination :: (no default route?)
#'Connected to Switch'
###################################
#TX PKT without IP options on port 0:
#RX PKT on port 1:
#0000   00 00 00 00 01 10 00 00  00 00 02 00 08 00 46 00   ..............F.
#0010   00 5E 00 01 00 00 40 06  77 94 00 00 00 02 00 00   .^....@.w.......
#0020   00 04 02 00 00 00 00 14  00 50 00 00 00 00 00 00   .........P......
#0030   00 00 50 02 20 00 76 7A  00 00 54 68 69 73 20 70   ..P. .vz..This p
#0040   61 63 6B 65 74 20 69 73  20 62 65 69 6E 67 20 73   acket is being s
#0050   65 6E 74 20 62 79 20 74  65 73 74 20 31 20 66 72   ent by test 1 fr
#0060   6F 6D 20 43 4C 49 20 74  D3 FF 9D 4E               om CLI t...N
###################################
#TX PKT with IP on port 0:
#RX PKT on port 1:
#0000   00 00 00 00 01 10 00 00  00 00 02 00 08 00 45 00   ..............E.
#0010   00 5A 00 01 00 00 40 06  7A 98 00 00 00 02 00 00   .Z....@.z.......
#0020   00 04 00 14 00 50 00 00  00 00 00 00 00 00 50 02   .....P........P.
#0030   20 00 75 7A 00 00 54 68  69 73 20 70 61 63 6B 65    .uz..This packe
#0040   74 20 69 73 20 62 65 69  6E 67 20 73 65 6E 74 20   t is being sent
#0050   62 79 20 74 65 73 74 20  32 20 66 72 6F 6D 20 43   by test 2 from C
#0060   4C 49 20 74 C7 F8 88 D6                            LI t....

