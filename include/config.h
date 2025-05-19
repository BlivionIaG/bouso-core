#ifndef CONFIG_H
#define CONFIG_H

#include "inih/ini.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_MAIN_BRANCH "master"

typedef struct {
  char *config_file;
  char *git_repo;
  char *git_branch;
  char *notes_dir;
  bool auto_sync;
} config_t;

void config_init(config_t *config);

bool config_load(config_t *config, const char *filename);

void config_free(config_t *config);

#endif // CONFIG_H