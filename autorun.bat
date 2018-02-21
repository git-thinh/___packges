# I had the same issue in Win7 regarding running a script (.bat) at startup (When the computer boots vs when someone  logs in) that would modify the network parameters using netsh. What ended up working for me was the following:

#	1. Log in with an Administrator account
#	2. Click on start and type “Task Scheduler” and hit return
#	3. Click on “Task Scheduler Library”
#	4. Click on “Create New Task” on the right hand side of the screen and set the parameters as follows:

#		a. Set the user account to SYSTEM
#		b. Choose "Run with highest privileges"
#		c. Choose the OS for Windows7

#	5. Click on “Triggers” tab and then click on “New…” Choose “At Startup” from the drop down menu, click Enabled and hit OK
#	6. Click on the “Actions tab” and then click on “New…” If you are running a .bat file use cmd as the program the put /c .bat In the Add arguments field
#	7. Click on “OK” then on “OK” on the create task panel and it will now be scheduled.
#	8. Add the .bat script to the place specified in your task event.


@ECHO OFF

cd C:\nginx

nginx -s stop
start nginx

taskkill /IM sshd.exe /F
start C:\msys2\App\msys32\usr\bin\sshd.exe

