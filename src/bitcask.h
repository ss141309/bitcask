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

#include <stdio.h>

#include "ht.h"
#include "utils.h"

typedef struct {
  i64 timestamp;
  isize key_len;
  isize val_len;
} Header;

typedef struct {
  Header header;
  char *key;
  char *val;
  u64 crc;

  char *buffer;
  isize buffer_len;
} BcEntry;

typedef struct {
  bool read_write;
  bool sync_on_put;
  isize max_file_size;
} Options;

typedef struct {
  isize cursor;
  isize num_files;

  char *parent_dir_path;
  char *data_dir_path;
  char *hint_dir_path;
  char *merged_dir_path;
  char *active_file_path;

  FILE *active_fp;
  HashTable key_dir;
  Options options;
  Arena arena;
} BcHandle;

typedef struct {
  BcHandle bc;
  bool is_ok;
} BcHandleResult;

BcHandleResult bc_open(Arena arena, s8 dir_path, Options options);
void bc_close(BcHandle *bc);
s8 bc_get(BcHandle *bc, s8 key);
bool bc_put(BcHandle *bc, s8 key, s8 val);
bool bc_delete(BcHandle *bc, s8 key);
bool bc_merge(BcHandle *bc);
bool bc_sync(BcHandle *bc);
