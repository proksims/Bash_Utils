// Copyright 2022 nomacold
#include <getopt.h>
#include <stdio.h>

/*
0 -b  --number-nonblank
1 -e
2 -n  --number
3 -s  --squeeze-blank
4 -t
5 -v
*/

int f_parser_flag(int argc, char **argv, int *flags);
void f_printf(int argc, char **argv, int *flags);

int main(int argc, char **argv) {
  int numerror = 0;
  if (argc > 1) {
    // ищем флаги -b -e -n -s -t -v
    int flags[6] = {0, 0, 0, 0, 0, 0};
    numerror = f_parser_flag(argc, argv, flags);
    // если флаги корректные или их нет находим файлы и печатаем их
    if (numerror == 0) {
      f_printf(argc, argv, flags);
    }
  } else {
    numerror = 1;
  }
  // errors
  if (numerror == 1) {
    printf("not arguments");
  } else if (numerror == 2) {
    printf("usage: cat [-benstvTE] [file ...]\n");
  }
  // else if (numerror == 3) // нет файла, вывод ошибки в функции f_printf
  return 0;
}

int f_parser_flag(int argc, char **argv, int *flags) {
  int rez;
  int numerror = 0;
  const char *short_options = "+benstvTE";
  const struct option long_options[] = {{"number-nonblank", 0, 0, 'b'},
                                        {"number", 0, 0, 'n'},
                                        {"squeeze-blank", 0, 0, 's'},
                                        {NULL, 0, NULL, 0}};
  // находим флаги
  while ((rez = getopt_long(argc, argv, short_options, long_options, NULL)) !=
         -1) {
    switch (rez) {
      case 'b': {
        flags[0] = 1;
        break;
      };
      case 'e': {
        flags[1] = 1;
        flags[5] = 1;
        break;
      };
      case 'n': {
        flags[2] = 1;
        break;
      };
      case 's': {
        flags[3] = 1;
        break;
      };
      case 't': {
        flags[4] = 1;
        flags[5] = 1;
        break;
      };
      case 'v': {
        flags[5] = 1;
        break;
      };
      case 'E': {
        flags[1] = 1;
        flags[5] = 0;
        break;
      };
      case 'T': {
        flags[4] = 1;
        flags[5] = 0;
        break;
      };
      // ошибочный флаг
      case '?': {
        numerror = 2;
        break;
      };
    }
  }
  // если есть -b и -n применяем только -b
  if (flags[0] == 1) {
    flags[2] = 0;
  }
  return numerror;
}

void f_printf(int argc, char **argv, int *flags) {
  FILE *file = NULL;
  while (optind < argc) {
    file = fopen(argv[optind], "r");
    // нет файла
    if (file == NULL) {
      fprintf(stderr, "cat: %s: No such file or derectory\n", argv[optind]);
    } else {
      // есть файл
      int ch;
      int last_ch = '\n';
      int str = 1;
      int empty_str = 0;
      while ((ch = fgetc(file)) != EOF) {
        // -s удаление пустых строк
        // если больше 1 пустой строки берем сразу следующий символ
        // если это символ, то у нас нет больше пустых строк
        if (flags[3] && ch == '\n' && last_ch == '\n') {
          empty_str++;
          if (empty_str > 1) {
            continue;
          }
        } else {
          empty_str = 0;
        }
        // -b нумерует не пустые строки
        if (flags[0] && ch != '\n' && last_ch == '\n') {
          printf("%6d\t", str);
          str++;
        }
        // -n нумерует все строки
        if (flags[2] && last_ch == '\n') {
          printf("%6d\t", str);
          str++;
        }
        // -e в конце $
        if (flags[1] && ch == '\n') {
          printf("$");
        }
        // -t показывает табуляцию
        if (flags[4] && ch == '\t') {
          printf("^");
          ch = 'I';
        }
        // -v
        if (flags[5]) {
          if (ch < 9 || (ch > 10 && ch < 32)) {
            printf("^");
            ch = ch + 64;
          }
          if (ch == 127) {
            printf("^");
            ch = '?';
          }
        }
        // печатаем символ и обновляем
        printf("%c", ch);
        last_ch = ch;
      }
      fclose(file);
    }
    optind++;
  }
}
