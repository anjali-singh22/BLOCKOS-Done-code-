void setMonitorColor(char);
void cls();
void printString(char*);
void vid();
void put();
void get();

extern void read();
extern void write();


int blockAddr;
char At[1024];

char* TM_START;

void blink() {
	setMonitorColor(0x59);
	int TIME_OUT = 0x10fffff;
	while(--TIME_OUT);
	setMonitorColor(0xa5);
}

char strcmp(char* sou , char* dest) {
	int i = 0;
	while(*(sou + i) == *(dest + i)) {
		if(*(sou + i) == 0 && *(dest + i) == 0)
			return 1;
		i++;
	}
	return 0;
}


// *evaluates the commands and performs necessary operation.
void strEval(char* CMD) {
	char cmd1[] = "CLS";
	char cmd2[] = "COLORA";
	char cmd3[] = "COLORB";
	char cmd4[] = "COLORC";
	char cmd5[] = "COLORD";
	char cmd6[] = "VID";
	char cmd7[] = "HI";
	char cmd8[] = "PUT";
	char cmd9[] = "GET";
	char cmd10[] = "VITBHOPAL";

	char msg1[] = "\nHELLO , GLAD YOU SELECTED BLOCKS OS\n";
	char msg2[] = "\nA place to learn, an chance to grow.\n";

	if(strcmp(CMD , cmd1))
		cls();

	else if(strcmp(CMD , cmd2))
		setMonitorColor(0x3c);

	else if(strcmp(CMD , cmd3))
		setMonitorColor(0x5a);

	else if(strcmp(CMD , cmd4))
		setMonitorColor(0x2a);

	else if(strcmp(CMD , cmd5))
		setMonitorColor(0xa5);	

	else if(strcmp(CMD , cmd6))
		vid();

	else if(strcmp(CMD , cmd7))
		printString(msg1);

	else if(strcmp(CMD , cmd8)) {
		blockAddr = 0;
		int i = 0;
		
		while(i < 511) {
			At[i] = 'J'; // Fill with J
			i++;
		}
		At[i] = 0; // Null character

		put(); // Writes to Hard disk by calling write function
		
		i = 0;
		while(i < 511) {
			At[i] = 0;  // Clears the content
			i++;
		}
	}		
	
	else if(strcmp(CMD , cmd9)) {
		blockAddr = 0;
		get();
		printString(At);
	}

	// Additional Functions
	else if(strcmp(CMD , cmd10))
		printString(msg2);
}

void vid() {
	char clr = 'A';
	while(1) {
		int i = 0;
		while(i < 2 * 80 * 25) {
			*(TM_START + i) = clr;
			clr++;
			i++;
		}
	}
}


void put() {
	write();
}

void get() {
	read();
}