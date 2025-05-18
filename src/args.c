/*
 * args.c - Command line argument handling
 * Copyright (C) 2025 BlivionIaG
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "args.h"

void print_version(void) {
  printf("bouso-core version %s\n", VERSION);
  printf("Copyright (C) 2025 BlivionIaG\n");
  printf("License GPLv3+: GNU GPL version 3 or later "
         "<https://gnu.org/licenses/gpl.html>\n");
  printf(
      "This is free software: you are free to change and redistribute it.\n");
  printf("There is NO WARRANTY, to the extent permitted by law.\n");
}

void print_usage(const char *program_name) {
  printf("Usage: %s [OPTIONS]\n", program_name);
  printf("Options:\n");
  printf("  -v, --verbose       Enable verbose output\n");
  printf("  -c, --config=FILE   Specify configuration file\n");
  printf("  -V, --version       Display version information\n");
  printf("  -h, --help          Display this help message\n");
}

bool parse_args(int argc, char *argv[], ProgramOptions *opts) {
  static const struct option long_options[] = {
      {"verbose", no_argument, NULL, 'v'},
      {"config", required_argument, NULL, 'c'},
      {"version", no_argument, NULL, 'V'},
      {"help", no_argument, NULL, 'h'},
      {NULL, 0, NULL, 0}};

  opts->verbose = 0;
  opts->config_file = NULL;

  int opt;
  while ((opt = getopt_long(argc, argv, "vc:Vh", long_options, NULL)) != -1) {
    switch (opt) {
    case 'v':
      opts->verbose = 1;
      break;
    case 'c':
      opts->config_file = optarg;
      break;
    case 'V':
      print_version();
      return 0;
    case 'h':
      print_usage(argv[0]);
      return 0;
    default:
      print_usage(argv[0]);
      return 0;
    }
  }

  return 1;
}