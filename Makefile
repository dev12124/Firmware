SHELL := cmd.exe
.PHONY: all build clean
all: build

build:
	call C:\Firmware\build.bat

clean:
	@rm -f * .o * .exe * .bin