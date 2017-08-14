# Summary
Basic PROS code from the Squires team for Startstruck. This is basically a place where my partner and I will upload our code we are working on in robotics and access it later.
It currently has a functional drivetrain with a timer-based autonomous in progress.

This is open source and can possibly help you in creating your own code in PROS once completed.

## How to open the code

1. Have a copy of Microsoft Visual Studio 15 or 17

2. Install this as a zip file and run the solution called Escuderos.sln

## Installing PROS for Visual Studio

1. Install PROS by going to the PROS website underneath 

*If you don't want Atom do a custom install

2. In Visual Studio Installer, under workloads you need Desktop developmentwith C++

	In individual componentsm select C++/CLI support
	
3. Create folder for PROS projects

4. Open cmd.exe in the folder execute pros conduct new One "One is the name of folder you created"

5. If asked Y/N select Y, delete newly created folder and start over at step 3

6. Open Visual Studio, file, new existing project and select the folder you just created and name the project

7. Select use external build system

8. In build command line, rebuild command line pros mu

9.  In Clean command line, pros make clean

10. In output(for debugging) pros terminal and then click finish

11. Open Tools then open External Tools

12. Add an external tool and title it PROS upload

13. Write the file location of your pros.exe, in cli folder of PROS

14. In arguments write mu

15. For Initial directory, have it be for your Project Directory

16. Check Use Output window, now you can upload your PROS code to the cortex

## Logs

3/10/17

Cleaned up the code so its actually readable and could work with the robot,
will update this code with slew rate control in the future before end of break.

3/31/17

Making code for new robot in class which as of right now only has a drivetrain and autonomous

5/9/17

New robot, will be detailed in future. New functions for drive control and how to win.
Slew Rate Control implemented so motors will not ptc.
Robot will go around the field once with rope trailing behind it to each corner,
when it arrives to the last corner, gear with ziptie will turn at square and score a lap every 5 seconds.

8/13/17

Updated nstructions, the start of a new year with the Knights

### References 

Official PROS Website http://pros.cs.purdue.edu/

VEX Forums https://www.vexforum.com/index.php/

Visual Studio Download https://www.visualstudio.com/