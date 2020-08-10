#include "_POLHAL.h"

/*
	WARNING: Ever pin in datasheet has a different offset and there is no apparent pattern
	for now at least unless an algorithm is found it is easier to hardcode the
	offset in an array like this.
	
	Description: This array returns the first bit of the MODE offset for given pin number.
*/
uint32_t PINPOS[16] = {
	(0x00),
	(0x04),
	(0x08),
	(0x0C),
	(0x10),
	(0x14),
	(0x18),
	(0x1C),
	(0x00),
	(0x04),
	(0x08),
	(0x0C),
	(0x10),
	(0x14),
	(0x18),
	(0x1C)
};