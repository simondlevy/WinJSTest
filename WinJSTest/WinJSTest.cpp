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

	if (joyGetDevCaps(JOYSTICKID1, &joycaps, sizeof(joycaps)) == JOYERR_NOERROR) {

		while (true) {

			printf("%d:%d \"%S\"", joycaps.wMid, joycaps.wPid, joycaps.szPname);

			JOYINFOEX joyState;
			joyState.dwSize = sizeof(joyState);
			joyState.dwFlags = JOY_RETURNALL | JOY_RETURNPOVCTS | JOY_RETURNCENTERED | JOY_USEDEADZONE;
			joyGetPosEx(JOYSTICKID1, &joyState);

			printf("  X:%d Y:%d Z:%d   R:%d U:%d V:%d  b:%d\r",
				joyState.dwXpos, joyState.dwYpos, joyState.dwZpos,
				joyState.dwRpos, joyState.dwUpos, joyState.dwVpos,
				joyState.dwButtons);
		}
	}

	else {
		while (true)
			printf("*** No device found ***\n");
	}

    return 0;
}
