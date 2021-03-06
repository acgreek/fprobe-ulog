/*
	Copyright (C) Slava Astashonok <sla@0n.ru>

	This program is free software; you can redistribute it and/or
	modify it under the terms of the GNU General Public License.

	$Id: fprobe-ulog.h,v 1.1.2.3 2005/01/29 19:30:41 sla Exp $
*/

#ifndef _FPROBE_ULOG_H_
#define _FPROBE_ULOG_H_

#include <my_inttypes.h>

#ifndef IP_OFFMASK
#define IP_OFFMASK 0x1fff
#endif

#define SCHED SCHED_FIFO
#define EMIT_TIMEOUT 5
#define UNPENDING_TIMEOUT 5
#define CAPTURE_SIZE 131072
#define THREADS 5
#define COPY_INTO 0
#define MOVE_INTO 1

struct Time {
	time_t sec;
	long usec;
};

struct Flow {
	/* input interface */
	uint16_t iif;
	/* output interface */
	uint16_t oif;
	/* ip src address */
	struct in_addr sip;
	/* ip dst address */
	struct in_addr dip;
	/* ip protocol */
	uint8_t proto;
	/* ip fragment id */
	uint16_t id;
	/* tcp/udp src port or icmp message type */
	uint16_t sp;
	/* tcp/udp dst port or icmp type sub-code */
	uint16_t dp;
	/* ip ToS */
	uint8_t tos;
	/* tcp flags */
	uint8_t tcp_flags;
	/* number of packets */
	unsigned long pkts;
	/* sum of packets sizes */
	unsigned long size;
	/* fragment data size (for fragmented packets) */
	unsigned long sizeF;
	/* whole packet data size (for fragmented packets) */
	unsigned long sizeP;
	/* time of creation/flushing this flow */
	struct Time ctime;
	/* time of last modification this flow */
	struct Time mtime;
#define FLOW_FRAG	0x0001
#define FLOW_FRAGMASK	0x0003
#define FLOW_TL		0x0004
#define FLOW_LASTFRAG	0x0008
#define FLOW_PENDING	0x8000
	int flags;
	struct Flow *next;
};

struct Flow_F {
	/* input interface */
	uint16_t iif;
	/* output interface */
	uint16_t oif;
	/* ip src address */
	struct in_addr sip;
	/* ip dst address */
	struct in_addr dip;
	/* ip protocol */
	uint8_t proto;
	/* ip fragment id */
	uint16_t id;
};

struct Flow_TL {
	/* input interface */
	uint16_t iif;
	/* output interface */
	uint16_t oif;
	/* ip src address */
	struct in_addr sip;
	/* ip dst address */
	struct in_addr dip;
	/* ip protocol */
	uint8_t proto;
	/* ip fragment id */
	uint16_t id;
	/* tcp/udp src port or icmp message type */
	uint16_t sp;
	/* tcp/udp dst port or icmp type sub-code */
	uint16_t dp;
};

#define SIGALRM_MASK 1
#define SIGTERM_MASK 2
#define SIGUSR1_MASK 4

struct peer {
	int sock;
	struct sockaddr_in addr;
	struct sockaddr_in laddr;
	int type;
	uint32_t seq;
};

struct snmp_rule {
	char basename[IFNAMSIZ];
	int len;
	int base;
} snmp_rule_t;

#define PEER_MIRROR 0
#define PEER_ROTATE 1

#endif
