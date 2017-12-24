#pragma once

#include "BinTree.h"
#include <fstream>

BinTree Database(const string file_name, BinTree f);
void Print(BinTree f);
void Print(BinTree f, int f_id);
void Print(BinTree f, string f_author);