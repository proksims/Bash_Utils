#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <string.h>

int f_parser_flag(int argc, char **argv, int *flags, char *pat);
void f_printf(int argc, char **argv, int *flags, char *pat);
void f_flagf(int *flags, char *pat, char *optarg);

int main(int argc, char **argv) {
  int numerror = 0;

  if (argc > 2) {
    // ищем флаги    0  1  2  3  4  5  6  7  8  9  10
    // ищем флаги   -e -i -v -c -l -n -h -s -f -o  Npat
    int flags[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    char pat[1024] = {0};
    numerror = f_parser_flag(argc, argv, flags, pat);
    // если флаги корректные или их нет находим файлы и печатаем их
    if (numerror == 0) {
      f_printf(argc, argv, flags, pat);
    }
  } else {
    numerror = 1;
  }
  // errors
  if (numerror == 1) {
    printf("usage: grep [-eivclnhsfo] [pattern] [file ...]\n");
  } else if (numerror == 2) {
    printf("usage: grep [-eivclnhsfo] [file ...]\n");
  }
  // else if (numerror == 3) // нет файла, вывод ошибки в функции f_printf
  return 0;
}

int f_parser_flag(int argc, char **argv, int *flags, char *pat) {
  int rez;
  int numerror = 0;
  const char *short_options = "e:ivclnhsf:o";
  // находим флаги
  while ((rez = getopt_long(argc, argv, short_options, NULL, NULL)) != -1) {
    switch (rez) {
      case 'e': {
        flags[0] = 1;
        if (flags[10] > 0) {
          strcat(pat, "|");
        }
        if (*optarg == '\0') {
          strcat(pat, ".");
        } else {
          strcat(pat, optarg);
        }
        flags[10]++;
        break;
      };
      case 'i': {
        flags[1] = 1;

        break;
      };
      case 'v': {
        flags[2] = 1;
        break;
      };
      case 'c': {
        flags[3] = 1;
        break;
      };
      case 'l': {
        flags[4] = 1;
        break;
      };
      case 'n': {
        flags[5] = 1;
        break;
      };
      case 'h': {
        flags[6] = 1;
        break;
      };
      case 's': {
        flags[7] = 1;
        break;
      };
      case 'f': {
        flags[8] = 1;
        f_flagf(flags, pat, optarg);
        flags[10]++;
        break;
      };
      case 'o': {
        flags[9] = 1;
        break;
      };
      // ошибочный флаг
      case '?': {
        numerror = 2;
        break;
      };
    }
  }
  // если нет -е и -f, то первый opting является паттерном
  if (!flags[0] && !flags[8]) {
    strcat(pat, argv[optind]);
    optind++;
  }
  // при -v не работает -o
  if (flags[2]) {
    flags[9] = 0;
  }
  // при -l не работает -o
  if (flags[4]) {
    flags[9] = 0;
  }
  // при -c не работает -o
  if (flags[3]) {
    flags[9] = 0;
  }
  // printf("flags = %d %d %d %d %d %d %d %d %d %d %d\n", flags[0], flags[1],
  //        flags[2], flags[3], flags[4], flags[5], flags[6], flags[7],
  //        flags[8], flags[9], flags[10]);
  return numerror;
}

void f_flagf(int *flags, char *pat, char *optarg) {
  FILE *file = NULL;
  file = fopen(optarg, "r");
  // нет файла, есть -s
  if (file == NULL && flags[7]) {
  } else if (file == NULL) {
    fprintf(stderr, "grep: %s: No such file or derectory\n", optarg);
  } else {
    // есть файл
    char str_f[1024] = {0};
    while (fgets(str_f, sizeof str_f, file) != NULL) {
      if (str_f[strlen(str_f) - 1] == '\n') {
        str_f[strlen(str_f) - 1] = '\0';
      }
      if (*pat != '\0') {
        strcat(pat, "|");
      }
      // no patt in str
      if (*str_f == '\0') {
        strcat(pat, ".");
      } else {
        strcat(pat, str_f);
      }
      // printf("optarg = %s\n", pat);
    }
  }
  fclose(file);
}

void f_printf(int argc, char **argv, int *flags, char *pat) {
  regex_t regex;  // область хранения скомпил рег выражения
  int cflags = REG_EXTENDED;  // тип компиляции
  if (flags[1] == 1) {
    cflags = REG_ICASE;
  }
  regcomp(&regex, pat, cflags);
  size_t nmatch = 1;
  regmatch_t pmatch[1];
  int N_str = 1;         // номер строки
  int N_str_find = 0;    // номер строки совпадения
  int N_str_nofind = 0;  // номер строки не совпадения
  int success;
  int N_optind = argc - optind;

  while (optind < argc) {
    // printf("optarg = %s\n", pat);
    // printf("optind = %s\n\n", argv[optind]);
    char str_file[10000] = {0};  //  целевая текстовая строка
    FILE *file = NULL;
    file = fopen(argv[optind], "r");

    // нет файла, есть -s
    if (file == NULL && flags[7] == 1) {
    } else if (file == NULL) {
      fprintf(stderr, "grep: %s: No such file or derectory\n", argv[optind]);
    } else {
      // есть файл пробегаем по каждой строке файла
      while (fgets(str_file, sizeof str_file, file) != NULL) {
        success = regexec(&regex, str_file, nmatch, pmatch, 0);
        // добавим в конце файла перенос строки
        if (strchr(str_file, '\n') == 0) {
          strcat(str_file, "\n");
        }
        // имя файла
        if (N_optind > 1 && success == 0 && !flags[2] && !flags[3] &&
            !flags[4] && !flags[6]) {
          printf("%s:", argv[optind]);
        }
        // имя файла при -v инверт
        if (N_optind > 1 && success != 0 && flags[2] && !flags[3] &&
            !flags[4] && !flags[6]) {
          printf("%s:", argv[optind]);
        }
        // -n
        if (flags[5] && !flags[9] && !flags[3] && !flags[4] &&
            ((success == 0 && !flags[2]) || (success != 0 && flags[2]))) {
          printf("%d:", N_str);
        }
        // -o
        if (success == 0 && flags[9] && !flags[5]) {
          char *p_str_file = str_file;
          while (success == 0) {
            if (pmatch->rm_so == pmatch->rm_eo) break;
            printf("%.*s\n", (int)(pmatch->rm_eo - pmatch->rm_so),
                   &p_str_file[pmatch->rm_so]);
            p_str_file = &p_str_file[pmatch->rm_eo];
            success = regexec(&regex, p_str_file, nmatch, pmatch, 0);
          }
        }
        // -o -n
        if (success == 0 && flags[9] &&
            (flags[5] && !flags[3] && !flags[4] &&
             ((success == 0 && !flags[2]) || (success != 0 && flags[2])))) {
          char *p_str_file = str_file;
          printf("%d:", N_str);
          while (success == 0) {
            if (pmatch->rm_so == pmatch->rm_eo) break;
            printf("%.*s\n", (int)(pmatch->rm_eo - pmatch->rm_so),
                   &p_str_file[pmatch->rm_so]);
            p_str_file = &p_str_file[pmatch->rm_eo];
            success = regexec(&regex, p_str_file, nmatch, pmatch, 0);
          }
        }
        // печатаем совпадение
        if (success == 0 && !flags[3] && !flags[4] && !flags[2] && !flags[9]) {
          printf("%s", str_file);
        }
        // -v печатаем инверт
        if (success != 0 && !flags[3] && !flags[4] && flags[2] && !flags[9]) {
          printf("%s", str_file);
        }
        // подсчет совпавших и нет строк для -с
        if (success == 0) {
          N_str_find++;
        }
        if (success != 0) {
          N_str_nofind++;
        }
        N_str++;
      }
      // -с
      if (flags[3] && !flags[2] && !flags[4]) {
        // при -h не печатаем файлы
        if (N_optind > 1 && !flags[6]) {
          printf("%s:", argv[optind]);
        }
        printf("%d\n", N_str_find);
      }
      // -c -l
      if (flags[3] && !flags[2] && flags[4]) {
        if (N_optind > 1 && !flags[6]) {
          printf("%s:", argv[optind]);
        }
        // при -h если есть совпадающие строки = 1 если нет =0
        if (N_str_find > 0) {
          printf("1\n");
        } else {
          printf("0\n");
        }
      }
      // -c -l -v
      if (flags[3] && flags[2] && flags[4]) {
        if (N_optind > 1 && !flags[6]) {
          printf("%s:", argv[optind]);
        }
        if (N_str_find > 0) {
          printf("1\n");
        } else {
          printf("1\n");
        }
      }
      // -c -v без -l
      if (flags[3] && flags[2] && !flags[4]) {
        if (N_optind > 1 && !flags[6]) {
          printf("%s:", argv[optind]);
        }
        printf("%d\n", N_str_nofind);
      }
      // -l
      if (flags[4] && flags[2]) {
        printf("%s\n", argv[optind]);
      }
      if (flags[4] && !flags[2] && N_str_find > 0) {
        printf("%s\n", argv[optind]);
      }
      fclose(file);
      N_str = 1;
      N_str_find = 0;
      N_str_nofind = 0;
    }
    optind++;
  }
  regfree(&regex);
}
