
#####################################################################
#
# Purpose:
#   To generate traffic for 'editor' construct example.
#
# Steps:
#   (a). Send a untagged packet from port-0 of BM
#        Receive packet from BM and print hexdump, it's a SOT pkt
#   (b). Send a single outer tagged packet to port-0 of BM
#        Receive packet from BM and print hexdump, it's a unttaged pkt
#   (c). Send a signle inner tagged packet from port-0 of BM
#        Receive packet from BM and print hexdump, it's a DT pkt
#   (d). Send a double tagged packet from port-0 of BM
#        Receive packet from BM and print hexdump, it's a SIT pkt
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
dip = "10.10.10.1"
sip = "11.11.11.2"
ihl = 5
ip_len = 108
dataofs = 5
vlan_id = 1


# Setup test packets
def get_tx_packet(test_num, tag_status):
    if (tag_status == 0) :
        # Untagged
        pkt = Ether()/IP()/TCP()/Raw()

    elif (tag_status == 1) :
        # Outer tagged TPID=0x8100
        pkt = Ether()/Dot1Q()/IP()/TCP()/Raw()
        pkt[Ether].type = 0x8100
        pkt[Dot1Q].vlan = vlan_id

    elif (tag_status == 2) :
        # Inner tagged TPID=0x9100
        pkt = Ether()/Dot1Q()/IP()/TCP()/Raw()
        pkt[Ether].type = 0x9100
        pkt[Dot1Q].vlan = vlan_id

    elif (tag_status == 3) :
        # Double tagged
        pkt = Ether()/Dot1Q(vlan=1,type=0x9100)/Dot1Q(vlan=2)/IP()/TCP()/Raw()
        pkt[Ether].type = 0x8100

    pkt[Ether].dst = dst_mac
    pkt[Ether].src = src_mac

    pkt[IP].dst = dip
    pkt[IP].src = sip
    pkt[IP].ihl = ihl
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
            #Sending untagged packet
            pkt = get_tx_packet(i+1,0)
            recv_pkt = bmintf.tx_pkt(i, pkt, len(str(pkt)))
            print "##################################"
            print "TX untagged PKT on port {}:".format(i)
            #hexdump(pkt)
            if (recv_pkt['STATUS']):
                print "Packet is Dropped!"
            else:
                print "RX PKT on port {}:".format(recv_pkt['PORT'])
                hexdump(recv_pkt['PACKET'])

            #Sending outer tagged packet
            time.sleep(1)
            pkt = get_tx_packet(i+2, 1)
            recv_pkt = bmintf.tx_pkt(i, pkt, len(str(pkt)))
            print "##################################"
            print "TX Outer tagged PKT on port {}:".format(i)
            #hexdump(pkt)
            if (recv_pkt['STATUS']):
                print "Packet is Dropped!"
            else:
                print "RX PKT on port {}:".format(recv_pkt['PORT'])
                hexdump(recv_pkt['PACKET'])

            #Sending inner tagged packet
            time.sleep(1)
            pkt = get_tx_packet(i+3, 2)
            recv_pkt = bmintf.tx_pkt(i, pkt, len(str(pkt)))
            print "##################################"
            print "TX Inner tagged PKT on port {}:".format(i)
            #hexdump(pkt)
            if (recv_pkt['STATUS']):
                print "Packet is Dropped!"
            else:
                print "RX PKT on port {}:".format(recv_pkt['PORT'])
                hexdump(recv_pkt['PACKET'])

            #Sending double tagged packet
            time.sleep(1)
            pkt = get_tx_packet(i+4, 3)
            recv_pkt = bmintf.tx_pkt(i, pkt, len(str(pkt)))
            print "##################################"
            print "TX Double tagged PKT on port {}:".format(i)
            #hexdump(pkt)
            if (recv_pkt['STATUS']):
                print "Packet is Dropped!"
            else:
                print "RX PKT on port {}:".format(recv_pkt['PORT'])
                hexdump(recv_pkt['PACKET'])

###########################################################################
# Example output with above test.
#
#{editor/editor_l2_tag}$: python bm_tests/corp_net/testPkt.py
#WARNING: No route found for IPv6 destination :: (no default route?)
#'Connected to Switch'
###################################
#TX untagged PKT on port 0:
#RX PKT on port 1:
#0000   00 0A 08 00 00 00 00 00  01 10 00 00 00 00 02 00   ................
#0010   81 00 45 00 00 5A 00 01  00 00 40 06 50 86 0B 0B   ..E..Z....@.P...
#0020   0B 02 0A 0A 0A 01 00 14  00 50 00 00 00 00 00 00   .........P......
#0030   00 00 50 02 20 00 4C 68  00 00 54 68 69 73 20 70   ..P. .Lh..This p
#0040   61 63 6B 65 74 20 69 73  20 62 65 69 6E 67 20 73   acket is being s
#0050   65 6E 74 20 62 79 20 74  65 73 74 20 31 20 66 72   ent by test 1 fr
#0060   6F 6D 20 43 4C 49 20 74  80 DE D5 12               om CLI t....
###################################
#TX Outer tagged PKT on port 0:
#RX PKT on port 1:
#0000   00 00 00 00 01 10 00 00  00 00 02 00 08 00 45 00   ..............E.
#0010   00 5A 00 01 00 00 40 06  50 86 0B 0B 0B 02 0A 0A   .Z....@.P.......
#0020   0A 01 00 14 00 50 00 00  00 00 00 00 00 00 50 02   .....P........P.
#0030   20 00 4B 68 00 00 54 68  69 73 20 70 61 63 6B 65    .Kh..This packe
#0040   74 20 69 73 20 62 65 69  6E 67 20 73 65 6E 74 20   t is being sent
#0050   62 79 20 74 65 73 74 20  32 20 66 72 6F 6D 20 43   by test 2 from C
#0060   4C 49 20 74 89 31 52 33                            LI t.1R3
###################################
#TX Inner tagged PKT on port 0:
#RX PKT on port 1:
#0000   00 00 00 00 01 10 00 00  00 00 02 00 81 00 00 0A   ................
#0010   91 00 00 01 08 00 45 00  00 5A 00 01 00 00 40 06   ......E..Z....@.
#0020   50 86 0B 0B 0B 02 0A 0A  0A 01 00 14 00 50 00 00   P............P..
#0030   00 00 00 00 00 00 50 02  20 00 4A 68 00 00 54 68   ......P. .Jh..Th
#0040   69 73 20 70 61 63 6B 65  74 20 69 73 20 62 65 69   is packet is bei
#0050   6E 67 20 73 65 6E 74 20  62 79 20 74 65 73 74 20   ng sent by test
#0060   33 20 66 72 6F 6D 20 43  4C 49 20 74 2D A4 C7 9E   3 from CLI t-...
###################################
#TX Double tagged PKT on port 0:
#RX PKT on port 1:
#0000   00 00 00 00 01 10 00 00  00 00 02 00 91 00 00 02   ................
#0010   08 00 45 00 00 5A 00 01  00 00 40 06 50 86 0B 0B   ..E..Z....@.P...
#0020   0B 02 0A 0A 0A 01 00 14  00 50 00 00 00 00 00 00   .........P......
#0030   00 00 50 02 20 00 49 68  00 00 54 68 69 73 20 70   ..P. .Ih..This p
#0040   61 63 6B 65 74 20 69 73  20 62 65 69 6E 67 20 73   acket is being s
#0050   65 6E 74 20 62 79 20 74  65 73 74 20 34 20 66 72   ent by test 4 fr
#0060   6F 6D 20 43 4C 49 20 74  2A DE D8 DA               om CLI t*...

