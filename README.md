# Simple Bash Utils

Development of Bash text utilities: cat, grep.
In this project you will learn and develop basic Bash utilities for working with C programming language texts. These utilities (cat and grep) are often used in the Linux terminal. As part of the project you’ll learn the organization of the Bash utilities and solidify knowledge of structured programming.

## Part 1. Working with the cat utility

need to develop a cat utility:

- Support of all flags (including GNU versions) specified [above](#cat-options)
- The source, header, and build files must be placed in the src/cat/ directory

## Part 2. Working with grep utility

need to develop the grep utility:

- Support of the following flags: `-e`, `-i`, `-v`, `-c`, `-l`, ` -n``-h `, `-s`, `-f`, `-o`
- The source, header and make files must be placed in the src/grep/ directory

## Information

### cat History

> cat was part of the early versions of Unix, e.g., Version 1, and replaced pr, a PDP-7 and Multics utility for copying a single file to the screen.

### cat Usage

Cat is one of the most frequently used commands on Unix-like operating systems. It has three related functions with regard to text files: displaying them, combining copies of them and creating new ones.

`cat [OPTION] [FILE]...`

### cat Options

| No. | Options                                                        | Description                                  |
| --- | -------------------------------------------------------------- | -------------------------------------------- |
| 1   | -b (GNU: --number-nonblank)                                    | numbers only non-empty lines                 |
| 2   | -e implies -v (GNU only: -E the same, but without implying -v) | but also display end-of-line characters as $ |
| 3   | -n (GNU: --number)                                             | number all output lines                      |
| 4   | -s (GNU: --squeeze-blank)                                      | squeeze multiple adjacent blank lines        |
| 5   | -t implies -v (GNU: -T the same, but without implying -v)      | but also display tabs as ^I                  |

### grep History

> Thompson wrote the first version in PDP-11 assembly language to help Lee E. McMahon analyze the text of the Federalist Papers to determine authorship of the individual papers. The ed text editor (also authored by Thompson) had regular expression support but could not be used on such a large amount of text, so Thompson excerpted that code into a standalone tool. He chose the name because in ed, the command g/re/p would print all lines matching a specified pattern. grep was first included in Version 4 Unix. Stating that it is "generally cited as the prototypical software tool", McIlroy credited grep with "irrevocably ingraining" Thompson's tools philosophy in Unix.

### grep Usage

`grep [options] template [file_name]`

### grep Options

| No. | Options | Description                                                    |
| --- | ------- | -------------------------------------------------------------- |
| 1   | -e      | pattern                                                        |
| 2   | -i      | Ignore uppercase vs. lowercase.                                |
| 3   | -v      | Invert match.                                                  |
| 4   | -c      | Output count of matching lines only.                           |
| 5   | -l      | Output matching files only.                                    |
| 6   | -n      | Precede each matching line with a line number.                 |
| 7   | -h      | Output matching lines without preceding them by file names.    |
| 8   | -s      | Suppress error messages about nonexistent or unreadable files. |
| 9   | -f file | Take regexes from a file.                                      |
| 10  | -o      | Output the matched parts of a matching line.                   |
