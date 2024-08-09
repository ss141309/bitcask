/*
Copyright 2024 समीर सिंह Sameer Singh

This file is part of bitcask.

bitcask is free software: you can redistribute it and/or modify it under the terms of the GNU
General Public License as published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

bitcask is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
Public License for more details.

You should have received a copy of the GNU General Public License along with bitcask. If not, see
<https://www.gnu.org/licenses/>. */

#pragma once

#include <stddef.h>
#include <stdint.h>

#include <linux/limits.h>

#include "utils.h"

typedef struct {
  char file_id[PATH_MAX];
  isize val_len;
  isize val_pos;
  i64 timestamp;
} KeyDirEntry;
