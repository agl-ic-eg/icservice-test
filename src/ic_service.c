/*
 * Copyright (c) 2021, Nippon Seiki Co., Ltd.
 * SPDX-License-Identifier: Apache-2.0
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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#include <cluster_ipc.h>

#include "ipc_common.h"

static void helpPrint(void);
static void helpWritePrint(void);
static void listPrint(void);
static void writeData(void);
static void writeDataToStruct(int id, long value);

IPC_DATA_IC_SERVICE_S g_dataIcService;

int main(void)
{
    IPC_RET_E ret;
    char command[10];
    char dummy[10];
    bool isRunning = true;
    char *pRetStr;

    memset(&g_dataIcService, 0, sizeof(g_dataIcService));

    ret = ipcServerStart(IPC_USAGE_TYPE_IC_SERVICE);
    if (ret != IPC_RET_OK) {
        printf("ipcServerStart Error:%d\n", ret);
        goto end;
    }

    while(isRunning) {
    	(void)ipcSendMessage(IPC_USAGE_TYPE_IC_SERVICE, (const void*)&g_dataIcService, sizeof(g_dataIcService));
		
    	usleep(20*1000);	//100 * 1000 usec
    	g_dataIcService.spAnalogVal = g_dataIcService.spAnalogVal + 20;
    	g_dataIcService.spAnalogVal = g_dataIcService.spAnalogVal % 10000;
    }

end:
    ipcServerStop(IPC_USAGE_TYPE_IC_SERVICE);

    return 0;
}

static void writeDataToStruct(int id, long value)
{
    void *pValue;

    if (id < 0 || IC_SERVICE_LIST_NUM < id) {
        return;
    }

    pValue = (void *)&g_dataIcService + IcServiceList[id].offset;
    memcpy(pValue, (void *)&value, IcServiceList[id].size);
}

