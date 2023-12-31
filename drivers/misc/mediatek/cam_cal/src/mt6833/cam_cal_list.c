/*
 * Copyright (C) 2018 MediaTek Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See http://www.gnu.org/licenses/gpl-2.0.html for more details.
 */
#include <linux/kernel.h>
#include "cam_cal_list.h"
#include "eeprom_i2c_common_driver.h"
#include "eeprom_i2c_custom_driver.h"
#include "kd_imgsensor.h"

#define MAX_EEPROM_SIZE_16K 0x4000

struct stCAM_CAL_LIST_STRUCT g_camCalList[] = {
	{CARR_OV13B10_SENSOR_ID, 0xA0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{CARR_S5K3L6_SENSOR_ID, 0xA0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{CARR_IMX355_SENSOR_ID, 0xA8, Common_read_region},
	{CARR_OV02B10_SENSOR_ID, 0xA4, Common_read_region},
	{CARR_GC02M1_SENSOR_ID, 0xA4, Common_read_region},
	{S5K3P9SP_SENSOR_ID_APOLLOW, 0xA8, Common_read_region},
	{S5KGM1ST_SENSOR_ID_ODINA, 0xA0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{IMX355_SENSOR_ID_ODINA, 0xA8, Common_read_region},
	{OV02B10_SENSOR_ID_ODINA, 0xA4, Common_read_region},
	{OV02B10_SENSOR_ID_APOLLOW, 0xA4, Common_read_region},
	{OV64B_SENSOR_ID_APOLLOW,0xA0,Common_read_region,MAX_EEPROM_SIZE_16K},
	/*Below is commom sensor */
	{IMX586_SENSOR_ID, 0xA0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{IMX576_SENSOR_ID, 0xA2, Common_read_region},
	{IMX519_SENSOR_ID, 0xA0, Common_read_region},
	{IMX319_SENSOR_ID, 0xA2, Common_read_region, MAX_EEPROM_SIZE_16K},
	{S5K3M5SX_SENSOR_ID, 0xA0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{IMX686_SENSOR_ID, 0xA0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{HI846_SENSOR_ID, 0xA0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{S5KGD1SP_SENSOR_ID, 0xA8, Common_read_region, MAX_EEPROM_SIZE_16K},
	{S5K2T7SP_SENSOR_ID, 0xA4, Common_read_region},
	{IMX386_SENSOR_ID, 0xA0, Common_read_region},
	{S5K2L7_SENSOR_ID, 0xA0, Common_read_region},
	{IMX398_SENSOR_ID, 0xA0, Common_read_region},
	{IMX350_SENSOR_ID, 0xA0, Common_read_region},
	{IMX386_MONO_SENSOR_ID, 0xA0, Common_read_region},
	{IMX499_SENSOR_ID, 0xA0, Common_read_region},
	{S5KGM1ST_SENSOR_ID, 0xA0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{S5KJN103_SENSOR_ID, 0xA0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{S5K3L6_SENSOR_ID, 0xA0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{IMX355_SENSOR_ID, 0xA8, Common_read_region, MAX_EEPROM_SIZE_16K},
	{GC02M1B_SENSOR_ID, 0xA4, Common_read_region, MAX_EEPROM_SIZE_16K},

    /*Add for Apollp-f*/
	{S5K3P9SP_SENSOR_ID_APOLLOF,0xA8, Common_read_region},//The default value is 8k.
	{S5KGM1ST_SENSOR_ID_APOLLOF,0xA0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{OV02B10_SENSOR_ID_APOLLOF, 0xA4, Common_read_region},
	{OV64B_SENSOR_ID_APOLLOF,0xA0,Common_read_region,MAX_EEPROM_SIZE_16K},

	{S5KGM1ST_SENSOR_ID_APOLLOB, 0xA0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{IMX355_SENSOR_ID_APOLLOB, 0xA8, Common_read_region, MAX_EEPROM_SIZE_16K},
	{OV02B10_SENSOR_ID_APOLLOB, 0xA4, Common_read_region, MAX_EEPROM_SIZE_16K},
	{GC02M1B_SENSOR_ID_APOLLOB, 0xA4, Common_read_region, MAX_EEPROM_SIZE_16K},
	{S5K3P9SP_SENSOR_ID_APOLLOB, 0xA8, Common_read_region},
	{OV13B10_SENSOR_ID_APOLLOB, 0xA0, Common_read_region, MAX_EEPROM_SIZE_16K},

	{S5K3L6_SENSOR_ID_ALICERT, 0xA0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{IMX355_SENSOR_ID_ALICERT, 0xA8, Common_read_region, MAX_EEPROM_SIZE_16K},
	{S5KJN103_SENSOR_ID_ALICER, 0xA0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{IMX355_SENSOR_ID_ALICER, 0xA8, Common_read_region, MAX_EEPROM_SIZE_16K},
	{S5KGM1ST_SENSOR_ID_ALICER, 0xA0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{HI5021SQT_SENSOR_ID_BLADE, 0xA0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{HI1336_SENSOR_ID_BLADE, 0xA0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{SC800CS_SENSOR_ID_BLADE, 0xA0, Common_read_region},
	{HI556_SENSOR_ID_BLADE, 0x40, Hi556_read_region, MAX_EEPROM_SIZE_16K},
	{SC201CS1_SENSOR_ID_BLADE, 0xA4, Common_read_region, MAX_EEPROM_SIZE_16K},
	{GC02M1_SENSOR_ID_APOLLOT, 0xA4, Common_read_region},
	/*  ADD before this line */
	{0, 0, 0}       /*end of list */
};

unsigned int cam_cal_get_sensor_list(
	struct stCAM_CAL_LIST_STRUCT **ppCamcalList)
{
	if (ppCamcalList == NULL)
		return 1;

	*ppCamcalList = &g_camCalList[0];
	return 0;
}


