# Alien Abduction Unit Virtual Pinball Controller

This is a virtual pinball table USB microcontroller-based controller device used on the Xero Pinball and Reload Bar Pinball tables.

See https://alienabductionunit.com/pinball for an overview of the tables.

The project utilises a PIC16F1455 microcontroller (earlier PCBs used a variety of other Microchip microcontrollers) on a custom PCB which supports six buttons:

 * Left flipper
 * Right flipper
 * Launch button
 * Play button
 * Admin function button

Also two LED outputs are supported:

 * Launch LED
 * Player LED

The game software running on the Mini PC is written using Orx. The USB interface portion of the game uses the hidapi library to communicate with the USB controller.

To access more information about the Virtual Pinball project, schematics, frame construction, game software and PCB gerbers;, these will be available at: https://alienabductionunit.com/pinball.

This project has a lot of templated code and could do with being fully cleaned up. The microcontroller code is long tested and pragmatically won't be changed in the near future.