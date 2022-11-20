#include "main.h"

template <typename T>
inline void write_memory(std::uintptr_t address, T value, bool protect = true) {
    unsigned long oldProt;
    if (protect) VirtualProtect(reinterpret_cast<void*>(address), sizeof(T), PAGE_READWRITE, &oldProt);
    *reinterpret_cast<T*>(address) = value;
    if (protect) VirtualProtect(reinterpret_cast<void*>(address), sizeof(T), oldProt, &oldProt);
}

AsiPlugin::AsiPlugin() {
    write_memory(0x5892AB, char(0), true);
}

AsiPlugin::~AsiPlugin() {
    write_memory(0x5892AB, char(10), true);
}