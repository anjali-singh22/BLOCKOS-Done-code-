
# BLOCK-OS 

BLOCK-OS is a teaching-based open-source operating system with 
32-bit system architecture. It is a simple and small os built-in 
C and assembly language that teaches one how to implement basic 
concepts of operating systems from scratch providing one with 
experience of in-depth understanding of concepts of operating 
systems.

![](https://github.com/anjali-singh22/BLOCKOS-Done-code-/blob/main/images/OSmain.png)



## Features

- Set up BIOS and our kernel at initial level.
- Boot Sector and Boot Loader for booting process.
- Implementation of GDT(Global descriptor table).
- Switch to 32-bit protected mode from 16-bit mode.
- Added support for C.
- Implemented a Graphic Driver that displays graphics on screen.
- Added functions like : COLORA (for changing screen monitor color) , VITBHOPAL(to display messages on the screen) etc.
- Implemented ISR (Interrupt Descriptor Table).
- Set up a Keyboard driver using ISR and PIC.
- Hard disk writing and reading function using ATA.
- Set up audio support using the PLAY() command.
- Global constructor.
- Programmable Interval Timer.






## Tech Stack

**Main:** ASM Assembly Language , C.









## Deployment

To deploy this project install following tools:
**Tools needed to be installed:** 

NASM, SASM: The Netwide Assembler (NASM) is an assembler and disassembler 
for the Intel x86 architecture.

https://www.nasm.us/

QEMU: A generic and open source machine emulator and virtualizer to run our BLOCK-OS.

https://www.qemu.org/download/

Hex Editor: https://www.hhdsoftware.com/free-hex-editor
VS Code: https://code.visualstudio.com/download

- After installing all the tools follow these steps:

1. Clone the BLOCK-OS repository into your system
2. Create a folder named : "bin"

3. Go to compile.bat file and run.
3. In case it shows error: Inside bin folder create two files: 
   "bootsect.bin" and "kernel.bin" 

   Again after doing this, run compile.bat

The BLOCK-OS will start running on QEMU emulator.
Now you can test various functions implemented given below.
```bash
  
```


## FUNCTIONS IMPLEMENTED

-	**CLS**: clear screen
-	**COLORA**: set monitor color turquoise
-	**COLORB**: set monitor color purple
-	**COLORC**: set monitor color green
-	**COLORD**: set monitor color light green
-	**VID**: Shows video (scrooling video screen)
-	**HI**: Prints message on screen: "HELLO, GLAD YOU SELECTED BLOCK OS"
-	**PUT**: Write array of "J" in memory
-	**GET**: Read array of "J" from memory
-	**VITBHOPAL**:  Prints message on screen: "A place to learn, a chance to grow"
-	**PLAY**: Plays audio
-   **SLEEP**: Timer of 5 seconds
## Screenshots

![](https://github.com/anjali-singh22/BLOCKOS-Done-code-/blob/main/images/RESULT1.png)
![](https://github.com/anjali-singh22/BLOCKOS-Done-code-/blob/main/images/RESULT2.png)
