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
    uint64 rsdp_pointer;
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
    .flags = 0,
    .rsdp_pointer = 0x000E0000
};
// ====================================================================
// ACPI
// ====================================================================
// Base Structure (RSDP)
typedef struct __attribute__((packed)) {
    uint8 signature[8];
    uint8 checksum;
    uint8 oem_id[6];
    uint8 revision;
    uint32 rsdt_address;
    uint32 length;
    uint64 xsdt_address;
    uint8 extended_checksum;
    uint8 reserved[3];
} ACPI_RSDP;
// Function to Calculate Checksum 
uint8 CalculateChecksum(const void* address, uint32 size) {
    const uint8* bytes = (const uint8*)address;
    uint8 sum = 0;
    for (uint32 i = 0; i < size; i++) {
        sum += bytes[i];
    }
    return sum;
}
// ========================================================================
// MEMORY MAP 
// ========================================================================
// Base Structure 
typedef struct __attribute__((packed)) {
    uint32 base_low;
    uint32 base_high;
    uint32 length_low;
    uint32 length_high;
    uint32 type;
} MemoryRegion;
// =====================
// BASIC DEVICES
// =====================
typedef struct {
    const char* Screen;
    uint64 Touchpad;
    uint64 MouseUSB;
    uint64 KeyboardUSB;
} Devices;
void ConfIgDisp(Devices* Disp) {
    // 1. Configurations of Dispositives
    Disp->Screen = "Display 1920x720";  // Resolution
    Disp->Touchpad = 540;  // Sensibility 
    Disp->MouseUSB = 570;  // DPI (Sensibility of Mouse)
    Disp->KeyboardUSB = 1; // True (1)
}
// =======
// POST
// =======
void InitPOST(IMAGE_BIOS_PDD_HEADER* Header, Devices* Disp) {
    // 1. Validation of Architecture
    if (Header->architecture == ARCH_X86_64) {
        // Valide
    } else {
        while (1) {
            __asm__ __volatile__("cli; hlt");
        }
    }
    // 2. Size of Header: Check
    if (Header->header_size == sizeof(IMAGE_BIOS_PDD_HEADER)) {
        //  Valide
    } else {
        while (1) {
            __asm__ __volatile__("cli; hlt");
        }
    }
    // 3. ACPI Validation 
    ACPI_RSDP* rsdp = (ACPI_RSDP8)Header->rsdp_pointer;
    // --- RSDP Calculation ---
    if (CalculateChecksum(rsdp, sizeof(ACPI_RSDP)) != 0) {
        Header->flags = 0x0000000000000E;
        __asm__ __volatile__ (
            "mov %0, %%cr3\n\t"
            :
            : "r" (Header->flags)
            : "memory"
        );
    } else {
        // Valide
    }
    // 4. Configurations of Dispositives
    ConfigDisp(Disp);
    // 5. Header flags: POST Concluded
    Header->flags |= 0x1;
}