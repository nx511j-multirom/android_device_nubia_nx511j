/*
 * Copyright (C) 2008 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


// #define LOG_NDEBUG 0
#define LOG_TAG "verify"

#include <cutils/log.h>

#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>

#include <sys/ioctl.h>
#include <sys/types.h>

#define BUILD_PROP_PATH "/system/build.prop"

int main(int argc, char *argv[])
{
    FILE *fp;
    char buffer[PAGE_SIZE] = {0};
    char *src_version = NULL;

    if ((argc != 2) || (argv[1] == NULL) )
        return -1;
    else
        src_version = argv[1];

    fp = fopen(BUILD_PROP_PATH, "r");
    if (fp == NULL) {
        ALOGE("cannot open %s", BUILD_PROP_PATH);
        //printf("cannot open %s\n", BUILD_PROP_PATH);
        return -1;
    }

    while (feof(fp) == 0) {
        fgets(buffer, PAGE_SIZE, fp);
        if (strstr(buffer, src_version))
            goto match;
    }
    fclose(fp);
    /*not match*/
    //printf("Not match\n");
    return -1;
match:
    //printf("Match\n");
    fclose(fp);
    return 0;
}
