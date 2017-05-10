# Summary
Basic PROS code from the Squires team for Startstruck. This is basically a place where my partner and I will upload our code we are working on in robotics and access it later.
It currently has a functional drivetrain with a timer-based autonomous in progress.

This is open source and can possibly help you in creating your own code in PROS once completed.

## How to open the code

1. Have a copy of Microsoft Visual Studio 15 or 17

2. Install this as a zip file and run the solution called Escuderos.sln

## Installing PROS for Visual Studio

1. Install PROS by going to the PROS website underneath

2. Once installed, open Visual Studio

3. Open Tools then open External Tools

4. Add an external tool and title it PROS upload

5. Write the file location of your pros.exe, in cli folder of PROS

6. In arguments write mu

7. For Initial directory, have it be for your Project Directory

8. Check Use Output window, now you can upload your PROS code to the cortex

### Logs

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

### References 

Official PROS Website http://pros.cs.purdue.edu/

VEX Forums https://www.vexforum.com/index.php/

Visual Studio Download https://www.visualstudio.com/