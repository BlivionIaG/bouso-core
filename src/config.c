#include "config.h"

static int handler(void *user, const char *section, const char *name,
                   const char *value) {
  config_t *config = (config_t *)user;

  if (!strcmp(section, "git")) {
    if (!strcmp(name, "repo")) {
      config->git_repo = strdup(value);
    } else if (!strcmp(name, "branch")) {
      if (config->git_branch)
        free(config->git_branch);

      config->git_branch = strdup(value);
    }
  } else if (!strcmp(section, "notes")) {
    if (!strcmp(name, "directory")) {
      config->notes_dir = strdup(value);
    } else if (!strcmp(name, "auto_sync")) {
      config->auto_sync = !strcmp(value, "true");
    }
  }

  return 1;
}

void config_init(config_t *config) {
  memset(config, 0, sizeof(config_t));
  config->git_branch = strdup(DEFAULT_MAIN_BRANCH);
  config->auto_sync = 0;
}

bool config_load(config_t *config, const char *filename) {
  if (ini_parse(filename, handler, config) < 0) {
    fprintf(stderr, "Error: Can't load config file '%s'\n", filename);
    return 0;
  }
  config->config_file = strdup(filename);
  return 1;
}

void config_free(config_t *config) {
  if (config->config_file)
    free(config->config_file);
  if (config->git_repo)
    free(config->git_repo);
  if (config->git_branch)
    free(config->git_branch);
  if (config->notes_dir)
    free(config->notes_dir);
}
