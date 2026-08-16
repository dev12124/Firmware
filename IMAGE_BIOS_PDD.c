#include "IMAGE_BIOS_PDD.h"
// =====================
// START FIRMWARE
// =====================
Devices devices;
void FirmwareStart(void) {
    // 1. POST: Initialize
    InitPOST(&bios_header, &devices);
    while (1) {
        __asm__ __volatile__("cli; hlt");
    }
 }