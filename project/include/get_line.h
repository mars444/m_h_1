#pragma once

#include <fcntl.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>

char* get_line (const char *path_to_file);
