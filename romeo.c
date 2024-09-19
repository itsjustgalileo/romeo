/*
 * \file romeo.c
 * \brief used to make empty binary disk file
 * \author galileo
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char *output_rom_name = "rom.bin";
unsigned long long rom_size = 32 * 1024;
char fill_value = 0xEA;

// helper function
void print_help(char *prog_name);
int hex_to_int(char *hexdecnumber);

int main(int argc, char **argv) {
    // print usage in case user wants help
    if(argc == 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)) {
        print_help(argv[0]);
        // returning 0 because technically this is not an error
        // program is supposed to quit after printing help
        return 0;
    }

    // parsing through argument lines
    for(int i = 0; i < argc; ++i) {
        if(strcmp(argv[i], "-s") == 0 || strcmp(argv[i], "--size") == 0) {
            for(unsigned int c = 0; c < strlen(argv[i + 1]); c++) {
                if(argv[i + 1][c] == 'k' || argv[i + 1][c] == 'K') {
                    char *fill_size = argv[i + 1];
                    fill_size[strlen(argv[i + 1])] = '\0';
                    rom_size = atoi(fill_size) * 1024;
                } else if(argv[i + 1][c] == 'm' || argv[i + 1][c] == 'M') {
                    char *fill_size = argv[i + 1];
                    fill_size[strlen(argv[i + 1])] = '\0';
                    rom_size = atoi(fill_size) * 1024 * 1024;
                } else if(argv[i + 1][c] == 'g' || argv[i + 1][c] == 'G') {
                    char *fill_size = argv[i + 1];
                    fill_size[strlen(argv[i + 1])] = '\0';
                    rom_size = atoi(fill_size) * 1024 * 1024 * 1024;
                } else {
                    rom_size = atoi(argv[i + 1]);
                }
                if(rom_size == 0) {
                    puts("invalid operation: can't create a 0bytes file");
                    print_help(argv[0]);
                    return 1;
                }
            }
        } else if(strcmp(argv[i], "-f") == 0 || strcmp(argv[i], "--fill") == 0) {
            fill_value = hex_to_int(argv[i + 1]) & 0xFF;
            if((unsigned int)fill_value < 0x00 || (unsigned int)fill_value > 0xFF) {
                puts("fill value can't go below 00 or above FF");
                print_help(argv[0]);
                return 2;
            }
        } else if(strcmp(argv[i], "-o") == 0 || strcmp(argv[i], "--output") == 0) {
            output_rom_name = argv[i + 1];
        }
    }
    
    FILE *rom = fopen(output_rom_name, "wb");
    if(rom == NULL) {
        fprintf(stderr, "failed to open file: %s", output_rom_name);
        return 2;
    }

    for(unsigned long long i = 0; i < rom_size; i++) {
        fputc(fill_value, rom);
    }

    printf("rom file %s created successfully:\nsize: %llu bytes\nfill: 0x%X\n", output_rom_name, rom_size, (unsigned char)fill_value);
    fclose(rom);
    return 0;
}

void print_help(char *prog_name) {
    fprintf(stderr, "USAGE:\n%s -<OPTION>\n", prog_name);
	fprintf(stderr, "-o --output <FILENAME>   : specifies the output file name (defaults to rom.bin)\n");
	fprintf(stderr, "-s --size <SIZE IN BYTES>: specifies the desired rom size (defaults to 32kb)\n");
	fprintf(stderr, "-f --fill <VALUE IN HEX> : fills the  rom with a specific value from 00 to FF (defaults to 0xEA)\n");
}

/**
 * params:
 * \char *hexdecnumber: the number in hexadecimal format
 * takes not prefixes or suffixes (CORRECT: A9; INCORRECT: 0xA9, A9h)
 * \return: return the hex number in a decimal integer
 * */
int hex_to_int(char *hexdecnumber) {
    int decimalnumber, i; 
    
    // used to store the power index 
    int cnt; 
    
    // used to store the digit 
    int digit; 
  
    cnt = 0; 
    decimalnumber = 0; 
    
    // iterating the loop using length of hexadecnumber 
    for (i = (strlen(hexdecnumber) - 1); i >= 0; i--) { 
        
        // using switch case finding the equivalent decimal 
        // digit for each hexa digit 
        switch (hexdecnumber[i]) { 
        case 'A': 
            digit = 10; 
            break; 
        case 'B': 
            digit = 11; 
            break; 
        case 'C': 
            digit = 12; 
            break; 
        case 'D': 
            digit = 13; 
            break; 
        case 'E': 
            digit = 14; 
            break; 
        case 'F': 
            digit = 15; 
            break; 
        default: 
            digit = hexdecnumber[i] - 0x30; 
        } 
        
        // obtaining the decimal number 
        decimalnumber = decimalnumber + (digit)*pow((double)16, (double)cnt); 
        cnt++; 
    }
    return decimalnumber;
}
