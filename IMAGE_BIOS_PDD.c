#include "IMAGE_BIOS_PDD.h"
// =====================
// START FIRMWARE
// =====================
Devices devices;
void FirmwareStart() {
    // 1. POST: Initializate
    InitPOST(&bios_header, &devices);
    while (1) {
        __asm__ __volatile__("cli; hlt");
    }
 }