
The CRYPTO module runs as a client/server model.
The server can only runs on the CM0+.
The client can run both the CM4 and the CM0+.

"ClientRunsOnCM0+" folder contains the examples that the client runs on the CM0+.
(CM0+ client <-> IPC <-> CM0+ server)
Just copy the files (main_cm0plus.c and a header if exists) and re-build project
then run the CM0+ project. 
Run_XXX function (XXX is operation dependent) does CRYPTO client operations.
Plese refer the function in each main_cm0plus.c.

"ClientRunsOnCM4" folder contains examples that the client runs on the CM4.
(CM4 client <-> IPC <-> CM0+ server)
Just copy the files (main_cm4, main_cm0plus.c and a header if exists) and re-build project
then run the both CM4 and CM0+ project. Keep CM0+ freely run.
The CM4 is the client, you can get the result and debug on the CM4.
Run_XXX function (XXX is operation dependent) does CRYPTO client operations.
Plese refer the function in each main_cm4.c.
And also please refer main_cm0plus.c for how to start the server.
Note that main_cm0plus.c are same in each folder. So you need one re-build and
run the CM0+ only once if using "ClientRunsOnCM4" examples continuously.

