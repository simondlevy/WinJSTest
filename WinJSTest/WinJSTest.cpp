/*
WinJSTest.cpp source code for WinJSTest console app

Copyright (C) Simon D. Levy 2017

This file is part of WinJSTest.

WinJSTest is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
WinJSTest is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with WinJSTest.  If not, see <http://www.gnu.org/licenses/>.

*/

#include "stdafx.h"

#include <Windows.h>

#include <shlwapi.h>
#pragma comment(lib, "Shlwapi.lib")


int main()
{
	JOYCAPS joycaps;

	// Grab the first available joystick
	UINT_PTR  uJoyID = 0;
	for (uJoyID=0; uJoyID<16; uJoyID++)
		if (joyGetDevCaps(uJoyID, &joycaps, sizeof(joycaps)) == JOYERR_NOERROR)
			break;

	if (uJoyID < 16) {

		while (true) {

			printf("%04x:%04x \"%S\"", joycaps.wMid, joycaps.wPid, joycaps.szPname);

			JOYINFOEX joyState;
			joyState.dwSize = sizeof(joyState);
			joyState.dwFlags = JOY_RETURNALL;
			joyGetPosEx(uJoyID, &joyState);

			printf("  X:%05d Y:%05d Z:%05d   R:%05d U:%05d V:%05d  b:%02d\r",
				joyState.dwXpos, joyState.dwYpos, joyState.dwZpos,
				joyState.dwRpos, joyState.dwUpos, joyState.dwVpos,
				joyState.dwButtons);
		}
	}

	else {
		printf("*** No device found ***\n");
		while (true)
			;
	}

    return 0;
}

