# bouso-core

Tool to synchronise notes files with git repositories.

## Building

### Prerequisites
- C compiler (clang or gcc)
- make
- git

### Build Steps

1. Clone the repository with submodules:
```bash
git clone --recursive https://github.com/yourusername/bouso-core.git
cd bouso-core
```

If you've already cloned without submodules, initialize them:
```bash
git submodule update --init --recursive
```

2. Build the project:
```bash
make
```

3. Clean build artifacts:
```bash
make clean
```

4. Rebuild from scratch:
```bash
make rebuild
```

## Project Structure

- `src/` - Source files
- `include/` - Header files
- `lib/` - Third-party libraries (inih)
- `obj/` - Build artifacts (generated)

## Configuration

The application uses INI files for configuration. Create a `config.ini` file in your working directory with the following structure:

```ini
[git]
repo = https://github.com/username/repo.git
branch = main

[notes]
directory = /path/to/notes
auto_sync = true
```

## TODO
- cli mode to manage update and sync
- deamon mode to automatically pull
- http api call