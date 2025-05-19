/*
 * args.h - Command line argument handling
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

#ifndef BOUSO_ARGS_H
#define BOUSO_ARGS_H

#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>

#define VERSION "0.0.1"

typedef struct {
  bool verbose;
  const char *config_file;
} s_program_options_t;

void print_version(void);

void print_usage(const char *program_name);

bool parse_args(int argc, char *argv[], s_program_options_t *opts);

#endif // BOUSO_ARGS_H