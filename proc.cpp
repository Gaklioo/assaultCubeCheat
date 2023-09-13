#include "pch.h"
#include "proc.h"
uintptr_t FindDMAAddy(uintptr_t ptr, std::vector<unsigned int> offsets) {
	// Dynamic Memory Allocation
	uintptr_t addr = ptr;
	for (unsigned int i = 0; i < offsets.size(); ++i) {
		addr = *(uintptr_t*)addr; // Handle to the process memory, pointer to the base adddress in specified proceess, (ae Local Plater Address), Store pointer to buffer, size of bytes to read from process, last is good for important debugging
		addr += offsets[i];								        	   // cast to byte ptr because it takes in a LPCVOID, long pointer to a const void, data type is not important, act as read by bytes
	}
	return addr;
}