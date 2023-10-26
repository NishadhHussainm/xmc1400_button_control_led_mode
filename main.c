#include <DAVE.h>

//#define LED_PIN P1_0
//#define BUTTON_PIN P1_1

uint8_t ledMode = 0; // Variable to store the current LED mode
uint8_t buttonState = 0; // Variable to store the previous state of the pushbutton


void changeLEDMode(void)
{
  // Increment the LED mode
  ledMode++;

  // Wrap around the LED mode if it exceeds the maximum value
  if (ledMode > 2)
  {
    ledMode = 0;
  }

  // Update the LED based on the new mode
  switch (ledMode) {
    case 0:
    	DIGITAL_IO_SetOutputLow(&DIGITAL_IO_4); // LED OFF
      break;
    case 1:
    	DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_4); // LED ON
      break;
    case 2:
    	DIGITAL_IO_ToggleOutput(&DIGITAL_IO_4); // LED TOGGLE

      break;
  }
}

int main(void) {
  DAVE_STATUS_t status;

  // Initialization of DAVE apps
  status = DAVE_Init();

  // Check if DAVE initialization is successful
  if (status != DAVE_STATUS_SUCCESS) {
    // Handle error
    while(1);
  }

  // Infinite loop
  while(1) {
    // Read the current state of the pushbutton
    buttonState = DIGITAL_IO_GetInput(&DIGITAL_IO_0);

    // Check if the pushbutton is pressed (active low)
    if (buttonState == 0)
    {
      changeLEDMode();
      // Add any additional logic if needed
    }

    // Add a small delay to avoid rapid button state changes
  //  for (volatile uint32_t i = 0; i < 10000; i++);
  }
}
