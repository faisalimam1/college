#!/usr/bin/awk-f
BEGIN{
	cbrPkt=0;
	tcpPkt=0;
}
{
	if(($1=="d") && ($5=="cbr"))
	{
		cbrPkt=cbrPkt+1;
	}
	if(($1=="d") && ($5=="tcp"))
	{
		tcpPkt=tcpPkt+1;
	}
}
END{
	printf "\n No. of CBR packets dropped %d", cbrPkt;
	printf "\n No. of TCP Packets dropped %d", tcpPkt;
}
# awk -f lab1.awk out.tr
