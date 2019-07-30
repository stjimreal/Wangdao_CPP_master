#ifndef _HEAD_H
#define _HEAD_H

#define _GNU_SOURCE
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <map>
using std::map;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::istringstream;
using std::ifstream;

#define ARGS_CHECK(argc, num) {if(argc != num) {printf("Error args!\n"); return -1;}}
#endif