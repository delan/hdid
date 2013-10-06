#ifndef HDID_INTERFACE_H
#define HDID_INTERFACE_H

enum hdid_interface_t {
	HDID_INTERFACE_UNKNOWN,
	HDID_INTERFACE_ATA33,
	HDID_INTERFACE_ATA66,
	HDID_INTERFACE_ATA100,
	HDID_INTERFACE_ATA133,
	HDID_INTERFACE_SATA1,
	HDID_INTERFACE_SATA2,
	HDID_INTERFACE_SATA3,
	HDID_INTERFACE_FIREWIRE,
	HDID_INTERFACE_CFPLUS2,
};

extern const char *const hdid_interface_list[];

#endif