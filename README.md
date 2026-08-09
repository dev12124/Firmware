### ⚙️ IMAGE_BIOS_PDD Firmware
 > A custom bare-metal BIOS/PDD initialization firmware header and POST runner writen low-level C for x86_64 architecture.

### About the Project
**IMAGE_BIOS_PDD is an experimental low-level firmware module designed to handle initial POST (Power-On Self-Test) sequence, architecture validation, header integrity checking, and basic input/output device configuration (Screen, Touchpad, USB Mouse, USB Keyboard) prior to handoff.**

### Key Features
**Custom Boot Header: Integrated IMAGE_BIOS_PDD containing signature verification, architecture, flags and entry point mapping.**

**POST (Power-On Self Test): Built-in hardware checks ensuring target system matches ARCH_X86_64 (0x8664) and checking header memory layout before boot continuation.**

**Basic Configurations: Configure Display parameters and input device responsiveness (Sensibility, DPI, and status flags).**

**Freestanding Runtime Environment: Zero dependencies on standard C libraries (nostdlib).**

### 🛠️ Toolchain & Environment
**Compiler & Linker: Clang / LLD (x86_64-elf / freestanding target)**

**Build System: Makefile calling build.bat**

**Host OS: Windows 11 Home 24H2**

**Editor: Visual Studio Code**

**Version Control: Git & GitHub Desktop & Github.com**

**ENTRY: Discord Server. Name of Server: Programming.**

**Server-Discord: https://discord.gg/88hUjybuY5**

**Limit-Collaborators-In-Server: 5-10 Collaborators**

### 🚀 Getting Started
## Prerequisites:

**Clang Compiler / LLD Linker**

**GNU Make (make)**

**Windows Command Line environment (build.bat execution support)**

### Building
'''bash
# Clone the repository
git clone https://github.com/dev12124/Firmware.git

cd Firmware
# Git workflow examples
git branch feature/novo-recurso

git checkout feature/novo-recurso

git commit -m "feat: add basic POST checks"

git request-pull

# To compile using Makefile (Make calls build.bat, which invokes Clang and LLD Linker)
make