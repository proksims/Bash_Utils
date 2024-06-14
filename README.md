# Simple Bash Utils

Development of Bash text utilities: cat, grep.
Bash utilities for working with C programming language texts. These utilities (cat and grep) are often used in the Linux terminal. As part of the project you’ll learn the organization of the Bash utilities and solidify knowledge of structured programming.

## Part 1. Working with the cat utility

need to develop a cat utility:

- Support of all flags (including GNU versions) specified
- The source, header, and build files must be placed in the src/cat/ directory

| No. | Options                                                        | Description                                  |
| --- | -------------------------------------------------------------- | -------------------------------------------- |
| 1   | -b (GNU: --number-nonblank)                                    | numbers only non-empty lines                 |
| 2   | -e implies -v (GNU only: -E the same, but without implying -v) | but also display end-of-line characters as $ |
| 3   | -n (GNU: --number)                                             | number all output lines                      |
| 4   | -s (GNU: --squeeze-blank)                                      | squeeze multiple adjacent blank lines        |
| 5   | -t implies -v (GNU: -T the same, but without implying -v)      | but also display tabs as ^I                  |

## Part 2. Working with grep utility

need to develop the grep utility:

- Support of the following flags: `-e`, `-i`, `-v`, `-c`, `-l`, ` -n``-h `, `-s`, `-f`, `-o`
- The source, header and make files must be placed in the src/grep/ directory

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
