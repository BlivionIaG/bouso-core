/*
 * bouso-core
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
#include "config.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {
  s_program_options_t opts;

  if (!parse_args(argc, argv, &opts)) {
    return EXIT_FAILURE;
  }

  if (opts.verbose) {
    printf("Verbose mode enabled\n");
    if (opts.config_file) {
      printf("Using config file: %s\n", opts.config_file);
      s_config_t config;
      config_init(&config);
      config_load(&config, opts.config_file);
      printf("Config loaded successfully\n");
      printf("Config file: %s\n", config.config_file);
      printf("Git repo: %s\n", config.git_repo);
      printf("Git branch: %s\n", config.git_branch);
      printf("Notes directory: %s\n", config.notes_dir);
      printf("Auto sync: %s\n", config.auto_sync ? "true" : "false");
      config_free(&config);
    }
  }

  // TODO: Implement main program functionality
  printf("bouso-core: Tool to synchronise notes files with git repositories\n");

  return EXIT_SUCCESS;
}
