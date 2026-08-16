#include "IMAGE_BIOS_PDD.h"
// =====================
// START FIRMWARE
// =====================
Dispositives dispositives;
 void FirmwareStart() {
    // 1. POST: Initializate
    InitPOST(&bios_header, &dispositives);
    while (1) {
        __asm__ __volatile__("cli; hlt");
    }
 }