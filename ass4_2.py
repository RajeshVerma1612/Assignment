import scapy.all as sc
ip_pairs = set() # Set to store distinct IP pairs
def analyzer(packet):
    global ip_pairs

    if sc.IP in packet:
        src_ip = packet[sc.IP].src
        dst_ip = packet[sc.IP].dst
        ip_pair = (src_ip, dst_ip)
        ip_pairs.add(ip_pair)
try:
    sc.sniff(prn=analyzer, count=100)
except Exception as e:
    pass 
print("Distinct IP pairs:")
for pair in ip_pairs:
    src_ip, dst_ip = pair
    print("Source:", src_ip, "| Destination:", dst_ip)
print("Total distinct IP pairs:", len(ip_pairs))