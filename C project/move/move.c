#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <libplayerc/playerc.h>
//#include <playerc.h>
// Random numbers generated for random walk movement by robots
/*double
randomInt(int low, int high)
{
return low + (high - low) * (rand()/(RAND_MAX * 1.0 ));
}
// Main function for the program*/
int main(int argc, const char **argv)
{
playerc_client_t *client;
playerc_position2d_t *position2d;
int cycle, index=0;
double dist,angle,fidAngle = 0,lineAngle=0, fidDist=0, prevYaw=0,posAngle=0;
// Create a client and connect it to the server.
client = playerc_client_create(NULL, "localhost", 6665);
if (0 != playerc_client_connect(client))
return -1;
// Create and subscribe to a position2d device.
position2d = playerc_position2d_create(client, 0);
if (playerc_position2d_subscribe(position2d, PLAYER_OPEN_MODE))
return -1;
// Initiating random walk movement
/*if (0 != playerc_position2d_set_cmd_vel(position2d, randomInt(0.1,1)
,randomInt(0.1,1),DTOR(randomInt(-20,20)) ,1))
return -1;
fprintf(stdout, "robot random positions \n");*/
//looping in random positions
int diagonals;
printf("enter the number of diagonals:");
scanf("%d",&diagonals);
if(diagonals==1)
{
	int i;
	for (i = 0; i<=10; i++)
	{
		// Wait for new data from server
		playerc_client_read(client);
		fprintf(stdout, "X: %3.2f, Y: %3.2f, Yaw: %3.2f \n",position2d->px, position2d->py, position2d->pa);
		// Random walk is continued till finding first marker
		if (0 != playerc_position2d_set_cmd_vel(position2d, 0,0 ,0.62,1))
		return -1;
		usleep(1000);
	}
	for (i = 0; i<=10; i++)	
	{
		// Wait for new data from server
		playerc_client_read(client);
		fprintf(stdout, "X: %3.2f, Y: %3.2f, Yaw: %f \n",position2d->px, position2d->py, position2d->pa);
		// Random walk is continued till finding first marker
		if (0 != playerc_position2d_set_cmd_vel(position2d, 1,0 , 0,1))
		return -1;
		usleep(1000);
	}
	for (i = 0; i<=10; i++)
	{
		// Wait for new data from server
		playerc_client_read(client);
		fprintf(stdout, "X: %3.2f, Y: %3.2f, Yaw: %3.2f \n",position2d->px, position2d->py, position2d->pa);
		// Random walk is continued till finding first marker
		if (0 != playerc_position2d_set_cmd_vel(position2d, 0,0 ,0.66,1))
		return -1;
		usleep(1000);
	}
	for (i = 0; i<=10; i++)
	{
		// Wait for new data from server
		playerc_client_read(client);
		fprintf(stdout, "X: %3.2f, Y: %3.2f, Yaw: %3.2f \n",position2d->px, position2d->py, position2d->pa);
		// Random walk is continued till finding first marker
		if (0 != playerc_position2d_set_cmd_vel(position2d, 1,0 , 0,1))
		return -1;
		usleep(1000);
	}
	for (i = 0; i<=11; i++)
	{
		// Wait for new data from server
		playerc_client_read(client);
		fprintf(stdout, "X: %3.2f, Y: %3.2f, Yaw: %3.2f \n",position2d->px, position2d->py, position2d->pa);
		// Random walk is continued till finding first marker
		if (0 != playerc_position2d_set_cmd_vel(position2d, 0,0 ,-1.155,1))
		return -1;
		usleep(1000);
	}

	for (i = 0; i<=10; i++)
	{
		// Wait for new data from server
		playerc_client_read(client);
		fprintf(stdout, "X: %3.2f, Y: %3.2f, Yaw: %3.2f \n",position2d->px, position2d->py, position2d->pa);
		// Random walk is continued till finding first marker
		if (0 != playerc_position2d_set_cmd_vel(position2d, 1,0 , 0,1))
		return -1;
		usleep(1000);
	}
	for (i = 0; i<=10; i++)	
	{
		// Wait for new data from server
		playerc_client_read(client);
		fprintf(stdout, "X: %3.2f, Y: %3.2f, Yaw: %f \n",position2d->px, position2d->py, position2d->pa);
		// Random walk is continued till finding first marker
		if (0 != playerc_position2d_set_cmd_vel(position2d, 0,0 , 0.62,1))
		return -1;
		usleep(1000);
	}
	for (i = 0; i<=10; i++)
	{
		// Wait for new data from server
		playerc_client_read(client);
		fprintf(stdout, "X: %3.2f, Y: %3.2f, Yaw: %3.2f \n",position2d->px, position2d->py, position2d->pa);
		// Random walk is continued till finding first marker
		if (0 != playerc_position2d_set_cmd_vel(position2d, 1,0 , 0,1))
		return -1;
		usleep(1000);
	}
	for (i = 0; i<=10; i++)
	{
		// Wait for new data from server
		playerc_client_read(client);
		fprintf(stdout, "X: %3.2f, Y: %3.2f, Yaw: %3.2f \n",position2d->px, position2d->py, position2d->pa);
		// Random walk is continued till finding first marker
		if (0 != playerc_position2d_set_cmd_vel(position2d, 0,0 , -1.2,1))
		return -1;
		usleep(1000);
	}
	for (i = 0; i<=10; i++)
	{
		// Wait for new data from server
		playerc_client_read(client);
		fprintf(stdout, "X: %3.2f, Y: %3.2f, Yaw: %3.2f \n",position2d->px, position2d->py, position2d->pa);
		// Random walk is continued till finding first marker
		if (0 != playerc_position2d_set_cmd_vel(position2d, 1,0 , 0,1))
		return -1;
		usleep(1000);
	}
	for (i = 0; i<=10; i++)
	{
		// Wait for new data from server
		playerc_client_read(client);
		fprintf(stdout, "X: %3.2f, Y: %3.2f, Yaw: %3.2f \n",position2d->px, position2d->py, position2d->pa);
		// Random walk is continued till finding first marker
		if (0 != playerc_position2d_set_cmd_vel(position2d, 0,0 , 0.53,1))
		return -1;
		usleep(1000);
	}
	for (i = 0; i<=10; i++)
	{
		// Wait for new data from server
		playerc_client_read(client);
		fprintf(stdout, "X: %3.2f, Y: %3.2f, Yaw: %3.2f \n",position2d->px, position2d->py, position2d->pa);
		// Random walk is continued till finding first marker
		if (0 != playerc_position2d_set_cmd_vel(position2d, 1,0 , 0,1))
		return -1;
		usleep(1000);
	}
        for (i = 0; i<=10; i++)
        {
                // Wait for new data from server
                playerc_client_read(client);
                fprintf(stdout, "X: %3.2f, Y: %3.2f, Yaw: %3.2f \n",position2d->
px, position2d->py, position2d->pa);
                // Random walk is continued till finding first marker
                if (0 != playerc_position2d_set_cmd_vel(position2d, 0,0 , -1.35,1
))
                return -1;
                usleep(1000);
        }
        for (i = 0; i<=10; i++)
        {
                // Wait for new data from server
                playerc_client_read(client);
                fprintf(stdout, "X: %3.2f, Y: %3.2f, Yaw: %3.2f \n",position2d->
px, position2d->py, position2d->pa);
                // Random walk is continued till finding first marker
                if (0 != playerc_position2d_set_cmd_vel(position2d, 1,0 , 0,1))
                return -1;
                usleep(1000);
        }
        for (i = 0; i<=10; i++)
        {
                // Wait for new data from server
                playerc_client_read(client);
                fprintf(stdout, "X: %3.2f, Y: %3.2f, Yaw: %3.2f \n",position2d->
px, position2d->py, position2d->pa);
                // Random walk is continued till finding first marker
                if (0 != playerc_position2d_set_cmd_vel(position2d, 0,0 , 0.74,1
))
                return -1;
                usleep(1000);
        }
        for (i = 0; i<=15; i++)
        {
                // Wait for new data from server
                playerc_client_read(client);
                fprintf(stdout, "X: %3.2f, Y: %3.2f, Yaw: %3.2f \n",position2d->
px, position2d->py, position2d->pa);
                // Random walk is continued till finding first marker
                if (0 != playerc_position2d_set_cmd_vel(position2d, 1,0 , 0,1))
                return -1;
                usleep(1000);
        }
        for (i = 0; i<=10; i++)
        {
                // Wait for new data from server
                playerc_client_read(client);
                fprintf(stdout, "X: %3.2f, Y: %3.2f, Yaw: %3.2f \n",position2d->
px, position2d->py, position2d->pa);
                // Random walk is continued till finding first marker
                if (0 != playerc_position2d_set_cmd_vel(position2d, 0,0 , -1.65,1
))
                return -1;
                usleep(1000);
        }
        for (i = 0; i<=15; i++)
        {
                // Wait for new data from server
                playerc_client_read(client);
                fprintf(stdout, "X: %3.2f, Y: %3.2f, Yaw: %3.2f \n",position2d->
px, position2d->py, position2d->pa);
                // Random walk is continued till finding first marker
                if (0 != playerc_position2d_set_cmd_vel(position2d, 1,0 , 0,1))
                return -1;
                usleep(1000);
        }

        for (i = 0; i<=10; i++)
        {
                // Wait for new data from server
                playerc_client_read(client);
                fprintf(stdout, "X: %3.2f, Y: %3.2f, Yaw: %3.2f \n",position2d->
px, position2d->py, position2d->pa);
                // Random walk is continued till finding first marker
                if (0 != playerc_position2d_set_cmd_vel(position2d, 0,0 , 0.68,1
))
                return -1;
                usleep(1000);
        }
        for (i = 0; i<=14; i++)
        {
                // Wait for new data from server
                playerc_client_read(client);
                fprintf(stdout, "X: %3.2f, Y: %3.2f, Yaw: %3.2f \n",position2d->
px, position2d->py, position2d->pa);
                // Random walk is continued till finding first marker
                if (0 != playerc_position2d_set_cmd_vel(position2d, 1,0 , 0,1))
                return -1;
                usleep(1000);
        }/*

/*
	
}
else if(diagonals==5)
{
	int i;
	for (i = 0; i<=3; i++)
	{
		// Wait for new data from server
		playerc_client_read(client);
		fprintf(stdout, "X: %3.2f, Y: %3.2f, Yaw: %3.2f \n",position2d->px, position2d->py, position2d->pa);
		// Random walk is continued till finding first marker
		if (0 != playerc_position2d_set_cmd_vel(position2d, 1,0 , 0,1))
		return -1;
		usleep(1000);
	}
	for (i = 0; i<=10; i++)	
	{
		// Wait for new data from server
		playerc_client_read(client);
		fprintf(stdout, "X: %3.2f, Y: %3.2f, Yaw: %f \n",position2d->px, position2d->py, position2d->pa);
		// Random walk is continued till finding first marker
		if (0 != playerc_position2d_set_cmd_vel(position2d, 0,0 , 0.290,1))
		return -1;
		usleep(1000);
	}
	for (i = 0; i<=3; i++)
	{
		// Wait for new data from server
		playerc_client_read(client);
		fprintf(stdout, "X: %3.2f, Y: %3.2f, Yaw: %3.2f \n",position2d->px, position2d->py, position2d->pa);
		// Random walk is continued till finding first marker
		if (0 != playerc_position2d_set_cmd_vel(position2d, 1,0 , 0,1))
		return -1;
		usleep(1000);
	}
	for (i = 0; i<=10; i++)
	{
		// Wait for new data from server
		playerc_client_read(client);
		fprintf(stdout, "X: %3.2f, Y: %3.2f, Yaw: %3.2f \n",position2d->px, position2d->py, position2d->pa);
		// Random walk is continued till finding first marker
		if (0 != playerc_position2d_set_cmd_vel(position2d, 0,0 , 0.290,1))
		return -1;
		usleep(1000);
	}
	for (i = 0; i<=3; i++)
	{
		// Wait for new data from server
		playerc_client_read(client);
		fprintf(stdout, "X: %3.2f, Y: %3.2f, Yaw: %3.2f \n",position2d->px, position2d->py, position2d->pa);
		// Random walk is continued till finding first marker
		if (0 != playerc_position2d_set_cmd_vel(position2d, 1,0 , 0,1))
		return -1;
		usleep(1000);
	}
	for (i = 0; i<=10; i++)
	{
		// Wait for new data from server
		playerc_client_read(client);
		fprintf(stdout, "X: %3.2f, Y: %3.2f, Yaw: %3.2f \n",position2d->px, position2d->py, position2d->pa);
		// Random walk is continued till finding first marker
		if (0 != playerc_position2d_set_cmd_vel(position2d, 0,0 , 0.290,1))
		return -1;
		usleep(1000);
	}
	for (i = 0; i<=3; i++)
	{
		// Wait for new data from server
		playerc_client_read(client);
		fprintf(stdout, "X: %3.2f, Y: %3.2f, Yaw: %3.2f \n",position2d->px, position2d->py, position2d->pa);
		// Random walk is continued till finding first marker
		if (0 != playerc_position2d_set_cmd_vel(position2d, 1,0 , 0,1))
		return -1;
		usleep(1000);
	}
	for (i = 0; i<=10; i++)
	{
		// Wait for new data from server
		playerc_client_read(client);
		fprintf(stdout, "X: %3.2f, Y: %3.2f, Yaw: %3.2f \n",position2d->px, position2d->py, position2d->pa);
		// Random walk is continued till finding first marker
		if (0 != playerc_position2d_set_cmd_vel(position2d, 0,0 , 0.290,1))
		return -1;
		usleep(1000);
	}
	for (i = 0; i<=4; i++)
	{
		// Wait for new data from server
		playerc_client_read(client);
		fprintf(stdout, "X: %3.2f, Y: %3.2f, Yaw: %3.2f \n",position2d->px, position2d->py, position2d->pa);
		// Random walk is continued till finding first marker
		if (0 != playerc_position2d_set_cmd_vel(position2d, 1,0 , 0,1))
		return -1;
		usleep(1000);
	}*/
}
while(1)
{
	if (0 != playerc_position2d_set_cmd_vel(position2d, 0,0 , 0,1))
	return -1;
}

playerc_position2d_unsubscribe(position2d);
playerc_position2d_destroy(position2d);
playerc_client_disconnect(client);
playerc_client_destroy(client);
return 0;
}
