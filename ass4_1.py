from scapy.all import sniff
from scapy import packet

def packet_analysis(pkt):
    if pkt.haslayer("TCP"):
        print("TCP: sport={}, dport={}, sip={}, dip={}".format(pkt["TCP"].sport, pkt["TCP"].dport, pkt["IP"].src, pkt["IP"].dst))
    elif pkt.haslayer("UDP"):
        print("UDP: sport={}, dport={}, sip={}, dip={}".format(pkt["UDP"].sport, pkt["UDP"].dport, pkt["IP"].src, pkt["IP"].dst))
    elif pkt.haslayer("ICMP"):
        print("ICMP: sip={}, dip={}".format(pkt["IP"].src, pkt["IP"].dst))

pkts=sniff(filter="tcp or udp or icmp", prn=packet_analysis, count=5)