# ROMEO

---

![text](romeo.webp)

---

## PRESENTATION

Simple utility to create empty binary files with a specified size and fill.

---

## PREREQUISITES

* C11 compiler

---

## SUPPORTED PLATFORMS

- [X] Windows
- [X] Linux
- [X] macOS

---

## HOW TO USE

```sh
make

# print usage
./romeo -h
USAGE:
./romeo -<OPTION>
-o --output <FILENAME>   : specifies the output file name (defaults to rom.bin)
-s --size <SIZE IN BYTES>: specifies the desired rom size (defaults to 32kb)
-f --fill <VALUE IN HEX> : fills the  rom with a specific value from 00 to FF (defaults to 0xEA)

# create file
./romeo -s 131072 -f 0x68 -o my_rom.bin

# can also specify size in k, m or g
./romeo -s 128k -f 0x68 -o my_rom.bin
```

---

## REFERENCES

* [Ben eater's 6502 "hello, world" series](https://www.youtube.com/playlist?list=PLowKtXNTBypFbtuVMUVXNR0z1mu7dp7eH)

---

