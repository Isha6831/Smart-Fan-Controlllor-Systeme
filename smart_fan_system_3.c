#include <stdio.h>

int main() 
{
	// Declare variables for switch state, fan speed, duration, swing state, and energy
	int switch_state, fan_state, swing_state;
    float duration;
    float power, total_energy; // power in watts, total_energy in watt-hours
	
    printf("\n Turn Fan ON or OFF");
    
    // State control for turning the fan ON or OFF
    state:
	printf("\n Enter 0 to Turn OFF the Fan.");
	printf("\n Enter 1 to Turn ON the Fan.");
    printf("\n Please Enter your Choice: ");
	scanf("%d", &switch_state);

    // If the switch state is OFF (0), display that the fan is turned off
    if (switch_state == 0)
    {
        printf("\n\n The Fan is now Turned OFF");
    }
    // If the switch state is ON (1), proceed with fan speed, duration, and swing control
    else if (switch_state == 1)
    {
        printf("\n The Fan is now Turned ON.");
        printf("\n\n Fan Speed Control Regulator " );

        // Fan speed input section with error checking for invalid inputs
        speed:
        printf("\n Enter the Fan Speed from the Speed Regulator as shown below:");
        printf("\n 1: Fan Speed BREEZE (Lowest) - 10 Watts/Hour");
        printf("\n 2: Fan Speed GENTLE (Low) - 20 Watts/Hour");
        printf("\n 3: Fan Speed MODERATE (Medium) - 35 Watts/Hour");
        printf("\n 4: Fan Speed TURBO (Highest) - 50 Watts/Hour");
        printf("\n Please Enter your Choice: ");
        scanf("%d", &fan_state);
	
	    // Cases for each fan speed setting, printing appropriate messages and setting power consumption
	    if (fan_state == 1)
	    {
	    	printf("\n The Fan Speed is set to Slight BREEZE (Lowest) \n");
            power = 10; // 10 watts/hour at lowest speed
	    }
	    else if (fan_state == 2)
	    {
		    printf("\n The Fan Speed is set to GENTLE Flow (Low) \n");
            power = 20; // 20 watts/hour at low speed
	    }
	    else if (fan_state == 3)
	    {
		    printf("\n The Fan Speed is set to MODERATE Wind (Medium) \n");
            power = 35; // 35 watts/hour at medium speed
	    }
	    else if (fan_state == 4)
	    {
	    	printf("\n The Fan Speed is set to TURBO Blast (Highest) \n");
            power = 50; // 50 watts/hour at highest speed
	    }
    	else
	    {
            // If the input is not between 1-4, ask the user to enter a valid speed again
	    	printf("\n Error: Invalid Input! Please enter a valid choice (1-4)");
            	goto speed;
	    }

        printf("\n\n For this Smart Fan, we intend to save Energy & be efficient");

        // Input for duration with validation for hours (0-24)
        time_input:
        printf("\n Please Enter Number of Hours to keep this Fan Turned ON (min 0 & max 24 hours): ");
        scanf("%f", &duration);
        if (duration >= 0 && duration <= 24)
        {
            printf("\n The Fan will be turned on for %f hours.", duration);
        }
        else
        {
            // If the duration input is out of range, prompt the user again
            printf("\n Invalid Input! Please Enter a Valid Duration (0-24)");
            goto time_input;
        }

        // Adding Swing Option (Oscillation control)
        printf("\n\n Fan Swing Control");

        // Swing input validation to allow the fan to either swing or remain stationary
        swing_input:
        printf("\n Enter 1 to enable Swing (oscillation) mode.");
        printf("\n Enter 0 to keep the Fan stationary.");
        printf("\n Please Enter your Choice: ");
        scanf("%d", &swing_state);

        // Cases for swing mode, either oscillating (1) or stationary (0)
        if (swing_state == 1)
        {
            printf("\n The Fan is now in Swing Mode (oscillating).");
        }
        else if (swing_state == 0)
        {
            printf("\n The Fan is stationary.");
        }
        else
        {
            // If the swing input is invalid, prompt the user again
            printf("\n Error: Invalid Input! Please enter a valid choice (0 for Stationary or 1 for Swing)");
            goto swing_input;
        }

        // Calculate the total energy consumed
        total_energy = power * duration * 0.001; // Energy in watt-hours (Wh)

        // Display the total energy consumed in this cycle
        printf("\n\n Total Energy Consumed by the Fan: %f kilowatt-hours (kWh).", total_energy);
    }
    else
    {
        // If the user enters anything other than 0 or 1 for the switch state, prompt again
        printf("\n Error: Invalid Input! Please enter a valid choice (0 for OFF or 1 for ON)");
        goto state;
    }

	return 0;
}
