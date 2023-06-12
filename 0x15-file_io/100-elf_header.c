#include "main.h"
#include <stdio.h>
#include <elf.h>
#include <fcntl.h>

/**
* checkm_elf -function that  Checks if file is an ELF file
* @e_ident: A pointer
*/
void checkm_elf(unsigned char *e_ident)
{
int j;

for (j = 0; j < 4; j++)
{
if (e_ident[j] != 127 &&
e_ident[j] != 'E' &&
e_ident[j] != 'L' &&
e_ident[j] != 'F')
{
dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
exit(98);
}
}
}

/**
* print_magics - Prints the magics
* @e_ident: A pointer
*
*/
void print_magics(unsigned char *e_ident)
{
int i;

printf("  Magic:   ");

for (i = 0; i < EI_NIDENT; i++)
{
printf("%02x", e_ident[i]);

if (i == EI_NIDENT - 1)
printf("\n");
else
printf(" ");
}
}

/**
* print_classe - Prints the classe
* @e_ident: A pointer
*/
void print_classe(unsigned char *e_ident)
{
printf("  Class:                             ");

switch (e_ident[EI_CLASS])
{
case ELFCLASSNONE:
printf("none\n");
break;
case ELFCLASS32:
printf("ELF32\n");
break;
case ELFCLASS64:
printf("ELF64\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}
}

/**
* print_data1 - Prints the data
* @e_ident: A pointer
*/
void print_data1(unsigned char *e_ident)
{
printf("  Data:                              ");

switch (e_ident[EI_DATA])
{
case ELFDATANONE:
printf("none\n");
break;
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}
}

/**
* print_versions - Prints the version
* @e_ident: A pointer
*/
void print_versions(unsigned char *e_ident)
{
printf("  Version:                           %d",
e_ident[EI_VERSION]);

switch (e_ident[EI_VERSION])
{
case EV_CURRENT:
printf(" (current)\n");
break;
default:
printf("\n");
break;
}
}

/**
* print_osabie - Prints the OS/ABI
* @e_ident: A pointer
*/
void print_osabie(unsigned char *e_ident)
{
printf("  OS/ABI:                            ");

switch (e_ident[EI_OSABI])
{
case ELFOSABI_NONE:
printf("UNIX - System V\n");
break;
case ELFOSABI_HPUX:
printf("UNIX - HP-UX\n");
break;
case ELFOSABI_NETBSD:
printf("UNIX - NetBSD\n");
break;
case ELFOSABI_LINUX:
printf("UNIX - Linux\n");
break;
case ELFOSABI_SOLARIS:
printf("UNIX - Solaris\n");
break;
case ELFOSABI_IRIX:
printf("UNIX - IRIX\n");
break;
case ELFOSABI_FREEBSD:
printf("UNIX - FreeBSD\n");
break;
case ELFOSABI_TRU64:
printf("UNIX - TRU64\n");
break;
case ELFOSABI_ARM:
printf("ARM\n");
break;
case ELFOSABI_STANDALONE:
printf("Standalone App\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_OSABI]);
}
}

/**
* print_abie - Prints the ABI
* @e_ident: A pointer
*/
void print_abie(unsigned char *e_ident)
{
printf("  ABI Version:                       %d\n",
e_ident[EI_ABIVERSION]);
}

/**
* print_types - Prints the type of an ELF header.
* @e_type: The ELF type.
* @e_ident: A pointer to an array containing the ELF class.
*/
void print_types(unsigned int e_type, unsigned char *e_ident)
{
if (e_ident[EI_DATA] == ELFDATA2MSB)
e_type >>= 8;

printf("  Type:                              ");

switch (e_type)
{
case ET_NONE:
printf("NONE (None)\n");
break;
case ET_REL:
printf("REL (Relocatable file)\n");
break;
case ET_EXEC:
printf("EXEC (Executable file)\n");
break;
case ET_DYN:
printf("DYN (Shared object file)\n");
break;
case ET_CORE:
printf("CORE (Core file)\n");
break;
default:
printf("<unknown: %x>\n", e_type);
}
}

/**
* print_entry1 - Prints the elf class
* @e_entry: The entry
* @e_ident: pointer
*/
void print_entry1(unsigned long int e_entry, unsigned char *e_ident)
{
printf("  Entry point address:               ");

if (e_ident[EI_DATA] == ELFDATA2MSB)
{
e_entry = ((e_entry << 8) & 0xFF00FF00) |
((e_entry >> 8) & 0xFF00FF);
e_entry = (e_entry << 16) | (e_entry >> 16);
}

if (e_ident[EI_CLASS] == ELFCLASS32)
printf("%#x\n", (unsigned int)e_entry);

else
printf("%#lx\n", e_entry);
}

/**
* close_elf1 - Closes an ELf
* @el1f: The fie
*/
void close_elf1(int el1f)
{
if (close(el1f) == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't close fd %d\n", el1f);
exit(98);
}
}

/**
* main - Displays the information
* @argc: number of arguments
* @argv: pointer
* Return: 0 on success
*/
int main(int __attribute__((__unused__)) argc, char *argv[])
{
Elf64_Ehdr *header;
int f1, f;

f1 = open(argv[1], O_RDONLY);
if (f1 == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}
header = malloc(sizeof(Elf64_Ehdr));
if (header == NULL)
{
close_elf1(f1);
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}
f = read(f1, header, sizeof(Elf64_Ehdr));
if (f == -1)
{
free(header);
close_elf1(f1);
dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
exit(98);
}

checkm_elf(header->e_ident);
printf("ELF Header:\n");
print_magics(header->e_ident);
print_classe(header->e_ident);
print_data1(header->e_ident);
print_versions(header->e_ident);
print_osabie(header->e_ident);
print_abie(header->e_ident);
print_types(header->e_type, header->e_ident);
print_entry1(header->e_entry, header->e_ident);

free(header);
close_elf1(f1);
return (0);
}
