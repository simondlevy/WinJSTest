# WinJSTest
A little Windows console program for testing joysticks , game controllers, and similar devices

As a Linux user I appreciate the convenience of the <b>jstest</b> utility, which allows you to see the raw 
numerical outputs of the control axes on a joysticks, game controller, or
similar input devicd.  Unable to find anything similar for Windows, I created
this little Visual Studio C++ console application.  It reports the manufactuer
and product id of the first such device, as well as the axis values and button state, extracted from the
[JOYCAPS](https://msdn.microsoft.com/en-us/library/windows/desktop/dd757103(v=vs.85).aspx) data structure.
