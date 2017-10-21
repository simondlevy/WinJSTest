# WinJSTest
A little Windows console program for testing joysticks , game controllers, and similar devices

As a Linux user I appreciate the convenience of the <b>jstest</b> utility, which allows you to see the raw 
numerical outputs of the control axes on a joystick, game controller, or
similar input device.  Unable to find anything similar for Windows, I created
this little Visual Studio C++ console application.  It reports the manufactuer
and product id of the first such device detected, as well as the axis values
and button state, extracted from the
[JOYCAPS](https://msdn.microsoft.com/en-us/library/windows/desktop/dd757103(v=vs.85).aspx)
data structure.

To run WinJSTest you'll need Visual Studio (I'm using Visual Studio Community 2017).  Double-clicking on 
<b>WinJSTest.sln</b> should launch Visual Studio, after which you can hit the <b>F5</b> key to build and run
the program.
