# JPEG Recovery Tool

A command-line program that recovers JPEG images from a forensic image of a memory card. This tool can recover JPEG files even after they've been deleted from a memory card or storage device.

## Description

This program scans through raw memory data to find and recover JPEG images based on their file signatures. It works by:
- Identifying JPEG signatures in raw binary data
- Creating new image files for each JPEG found
- Sequentially naming recovered files (000.jpg, 001.jpg, etc.)
- Handling consecutive reads of 512-byte blocks

## Features

- Recovers deleted JPEG files
- Handles corrupted memory cards
- Processes raw forensic images
- Sequential file naming
- Reports total number of recovered files

## Prerequisites

- GCC or Clang compiler
- Make (optional, for using Makefile)
- Standard C libraries

## Usage

1. Compile the program:
```
make recover
```
2. Run the program:
```
./recover card.raw
```

This will process the forensic image `card.raw` and recover all JPEG files found within it. The recovered files will be named sequentially (000.jpg, 001.jpg, etc.) and saved in the current working directory.

## Notes

- Ensure the forensic image file is in the same directory as the program or provide the correct path to the image file.
- The program assumes the memory card is formatted in FAT32.
- The program will report the total number of JPEG files recovered.
- The program will handle errors such as file corruption or incomplete reads.

Happy recovering!