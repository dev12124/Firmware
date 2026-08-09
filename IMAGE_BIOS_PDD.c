typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;                                
// ===================
// VARIABLES
// ===================
#define ARCH_X86_64 0x8664
// ===================
// HEADERS
// ===================
typedef struct {
    uint8 signature[10];
    uint64 version_major;
    uint64 version_minor;
    uint32 header_size;
    uint64 image_size;
    uint64 entry_point;
    uint32 architecture;
    uint32 flags;
} IMAGE_BIOS_PDD_HEADER;
IMAGE_BIOS_PDD_HEADER bios_header = {
    .signature = {
        'B', 'I', 'O', 'S', '_', 'P', 'D', 'D', '\0'
    },
    .version_major = 0x3DDCFEE,
    .version_minor = 0x100155599,
    .header_size = sizeof(IMAGE_BIOS_PDD_HEADER),
    .image_size = 0,
    .entry_point = 0x1000,
    .architecture = ARCH_X86_64,
    .flags = 0
};
// =====================
// DISPOSITIVOS BÁSICOS
// =====================
typedef struct {
    const char* Screen;
    uint64 Touchpad;
    uint64 MouseUSB;
    uint64 KeyboardUSB;
} Dispositives;
void ConfDisp(Dispositives* Disp) {
    // 1. Configurations of Dispositives
    Disp->Screen = "Pantalla 1920x720";  // Resolution
    Disp->Touchpad = 540;  // Sensibility 
    Disp->MouseUSB = 570;  // DPI (Sensibility of Mouse)
    Disp->KeyboardUSB = 1; // True (1)
}
// =======
// POST
// =======
void InitPOST(IMAGE_BIOS_PDD_HEADER* Header, Dispositives* Disp) {
    // 1. Validation of Architecture
    if (Header->architecture == ARCH_X86_64) {
        // Valide
    } else {
        while(1);
    }
    // 2. Size of Header: Check
    if (Header->header_size == sizeof(IMAGE_BIOS_PDD_HEADER)) {
        //  Valide
    } else {
        while(1);
    }
    // 3. Configurations of Dispositives
    ConfDisp(Disp);
    // 4. Header Flags: POST Concluided
    Header->flags |= 0x1;
}
// =====================
// START FIRMWARE
// =====================
Dispositives dispositives;
 void FirmwareStart() {
    // 1. POST: Initializate
    InitPOST(&bios_header, &dispositives);
    while(1);
 }