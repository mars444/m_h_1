#pragma once
#define _GNU_SOURCE  
#include "../include/parser.h"      
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


#define FROM    "\nFrom:"
#define TO      "\nTo:"
#define DATE    "\nDate:"

#define CONTENT_TYPE        "\nContent-Type:"
#define BOUNDARY            "boundary="


typedef struct {
    char *mail_target;
} eml_t;


