#ifndef _MCCS_H

#define _MCCS_H

 //==============================================================================//

//                     Continuous Control Code Values                           //

//==============================================================================//


#define VCP_TYPE_CODE_MOMENTARY   0x01
#define VCP_TYPE_CODE_SET_PATAMETER  0x00
#define VCP_RESULT_CODE_NOERROR  0x00
#define VCP_RESULT_CODE_UNSUPPORT  0x01
//==============================================================================//

//                     Continuous Control Code Values                           //

//==============================================================================//

#define DDCCI_MCCS_SEC_DEGARSS                            0x02
#define DDCCI_MCCS_RESTORE_FACTORY                    0x04
#define DDCCI_MCCS_RESTORE_FACTORY_RESERVE                    0x05
#define DDCCI_MCCS_RESTORE_FACTORY_GEORMETRY                    0x06
#define DDCCI_MCCS_RESTORE_FACTORY_COLOR                    0x08
#define DDCCI_MCCS_BRIGHTNESS                            0x10
#define DDCCI_MCCS_CONTRAST                                0x12
#define DDCCI_MCCS_SELECT_COLOR_PRESET                                0x14

#define DDCCI_MCCS_INPUT_SOURCE_SECECT                            0x60





// The level of maximum luminance of RGB pixels

#define DDCCI_MCCS_RED_VIDEO_GAIN                        0x16

#define DDCCI_MCCS_GREEN_VIDEO_GAIN                        0x18

#define DDCCI_MCCS_BLUE_VIDEO_GAIN                        0x1A

 

// The level of minimum luminance of RGB pixels

#define DDCCI_MCCS_RED_VIDEO_BLACK_LEVEL                0x6C

#define DDCCI_MCCS_GREEN_VIDEO_BLACK_LEVEL                0x6E

#define DDCCI_MCCS_BLUE_VIDEO_BLACK_LEVEL                0x70

 

// Adjusts the apparent spot size

#define DDCCI_MCCS_FOCUS                                0x1C

 

#define DDCCI_MCCS_HORIZONTAL_POSITION                    0x20

#define DDCCI_MCCS_HORIZONTAL_SIZE                        0x22

 

// Cause the right and left sides of the image to become more or less convex

#define DDCCI_MCCS_HORIZONTAL_PINCUSHION                0x24

 

// Moves the center section of the image toward the right or left side of display

#define DDCCI_MCCS_HORIZONTAL_BALANCE                    0x26

 

// Increasing(decreasing) this value will shift the red pixels to the right(left)

// accros the image and the blude pixels lef(right) across the image with respect

// to green pixels.

#define DDCCI_MCCS_HORIZONTAL_MISCONVERGENCE            0x28

 

// Shifts the density of pixels from the left and right ends to the center of the image

#define DDCCI_MCCS_HORIZONTAL_LINEARITY                    0x2A

 

// Increasing(decreasing) this value shifts the density of pixels from the left(right)

// side to the right(left) side fo the image

#define DDCCI_MCCS_HORIZONTAL_LINEARITY_BALANCE            0x2C

 

#define DDCCI_MCCS_VERTICAL_POSITION                    0x30

#define DDCCI_MCCS_VERTICAL_SIZE                        0x32

 

// Increasing(decreasing) this value causes the top and bottom sides of the image to

// become more(less) convex

#define DDCCI_MCCS_VERTICAL_PINCUSHION                    0x34

 

// Increasing(decreasing) this value moves the center section of the image toward the

// top(bottom) of the display

#define DDCCI_MCCS_VERTICAL_PINCUSHION_BALANCE            0x36

 

// Increase(decreasing) this value shifts the red pixels up(down) across the image

// and the blue pixels down(up) across the image with respect to the green pixels

#define DDCCI_MCCS_VERTICAL_MISCONVERGENCE                0x38

 

// Increasing(decreasing) this value shifts the density of scan lines from the ends

// (center) to the center(ends) of the image

#define DDCCI_MCCS_VERTICAL_LINEARITY                    0x3A

 

// Increasing(decreasing) this value shifts the density of scan lines from the top

// (bottom) end to the bottom(top) end of the image

#define DDCCI_MCCS_VERTICAL_LINEARITY_BALANCE            0x3C

 

// Increasing(decreasing) this value shifts the top section of the image to the

// right(left) with respect to the bottom section of image

#define DDCCI_MCCS_PARALLELOGRAM_DISTORTION                0x40

 

// The ratio between the horizontal size at the top of the image relative to the

// horizontal size at the bottom of the image

#define DDCCI_MCCS_TRAPEZOIDAL_DISTORTION                0x42

 

// Increasing(decreasing) this value rotatels the image(counter) clockwise about

// the center point of the image

#define DDCCI_MCCS_TILT                                    0x44

 

#define DDCCI_MCCS_TOP_CORNER_DISTORTION_CONTROL        0x46

#define DDCCI_MCCS_TOP_CORNER_DISTORTION_BALANCE        0x48

#define DDCCI_MCCS_BOTTOM_CORNER_DISTORTION_CONTROL        0x4A

#define DDCCI_MCCS_BOTTOM_CORNER_DISTORTION_BALANCE        0x4C

 

// Adjusting this value controls the horizontal/vertical piciture moire cancellation

#define DDCCI_MCCS_HORIZONTAL_MORIE                        0x56

#define DDCCI_MCCS_VERTICAL_MORIE                        0x58

 

// Addressable horinzontal/vertical screen

#define DDCCI_MCCS_HORADD                                0x72

#define DDCCI_MCCS_VERADD                                0x74

 

// Addressable buffer

#define DDCCI_MCCS_BUFFERADD                            0X76

 

// update rate of the screen in 0.01HZ

#define DDCCI_MCCS_UPDATE                                0x78

 

// Changing this value will change the focal plane of the optics

#define DDCCI_MCCS_ADJUST_FOCAL_PLANE                    0x7A

 

// Changing this value will change the zoom of the optics

#define DDCCI_MCCS_ADJUST_ZOOM                            0x7C

 

// Changing this value will change the trapezoid adjustment of the optics

#define DDCCI_MCCS_TRAPEZOID                            0x7E

 

// Changing this value will change the keystone adjustment of the optics

#define DDCCI_MCCS_KEYSTONE                                0x80

 

// Changing this value will cause the picutre to flip horizontally by means of

// the optics of the device

#define DDCCI_MCCS_HORFLIP                                0x82

 

// Changing this value will cause the picutre to flip vertically by means of

// the optics of the device

#define DDCCI_MCCS_VERFLIP                                0x84

 

// Changing this value will affect the scaling(input versus output) function of display

#define DDCCI_MCCS_DISPLAY_SCALING                        0x86

 

// Increasing(decreasing) this value will increase(decrease) the velocity modulation of

// the horizontal scan as a function of the luminance level

#define DDCCI_MCCS_VELOCITY_SCAN_MODULATION                0x88

 

// Increasing the control increases the amplitude of the color difference components of

// the video signal. The result is an increase in the amount of pure color relative to

// white in the video. This control does not effect the RGB input, only the TV video

// input.

#define DDCCI_MCCS_TV_COLOR_SATURATION                    0x8A

 

// Increasing this control increases the amplitude of the hight frequency components of

// the video signal. The result is accentuation of fine details. This control deos not

// effect the RGB input, only the TV video inputs.

#define DDCCI_MCCS_TV_SHARPNESS                            0x8C

 

// Increasing this control increases the ratio between whites and blacks in the video.

// The control does not effect RGB input, only the TV video inputs.

#define DDCCI_MCCS_TV_CONTRAST                            0x8E

 

// (a.k.a. Tint)Increase this control increase the wavelength of the color component

// of the video signal. The result is a shift towards red in the hue of all colors.

// This control does not effect the RGB input, only the TV video inputs.

#define DDCCI_MCCS_TV_HUE                                0x90

 

// Increasing this control increases the black level of the video. The result is an

// increase of the lumen level of the video. A value of zero represents the darkest

// level possible. This control deos not effect the RGB input, only the TV video inputs.

#define DDCCI_MCCS_TV_BRIGHTNESS                        0x92

 

//==============================================================================//

//                     Non-Continuous Control Code Values                       //

//==============================================================================//

 

//==============================================================================//

//                     Non-Continuous Control Code Values                       //

//                     ( Read and Write controls )                              //

//==============================================================================//

 

// Changing this value chooses a different video input voltage for the display on input

// source select1. Format is reference white above blank, level of sync, below blank.

// 0 none selected

// 1 0.700, 0.300 (1.00 Vpp)

// 2 0.714, 0.286 (1.00 Vpp)

// 3 1.000, 0.400 (1.40 Vpp)

// 4 0.700, 0.000 (0.700 Vpp)

#define DDCCI_MCCS_INPUT_LEVEL_SELECT1                    0x5E

 

// 0 None selected

// 1 OSD is disabled to appear

// 2 OSD is enabled to appear

#define DDCCI_MCCS_ON_SCREEN_DISPLAY                    0xCA

 

// Changing this value chooses a different video input voltage for the display on input

// source select2. Format is reference white above blank, level of sync, below blank.

// 0 none selected

// 1 0.700, 0.300 (1.00 vpp)

// 2 0.714, 0.286 (1.00 vpp)

// 3 1.000, 0.400 (1.40 Vpp)

// 4 0.700, 0.000 (0.800 Vpp)

#define DDCCI_MCCS_INPUT_LEVEL_SELECT2                    0xCC

 

// Changing this value selects a different video input source.

// 0 None selected

// 1 DB-15HD/VGA1

// 2 DB-15HD/VGA2

// 3 DB-15HD/VGA3

// 4 BNC/RGB1

// 5 BNC/RGB2

// 6 BNC/RGB3

// 7 EVC1

// 8 EVC2

// 9 EVC3

// 10 MAC1

// 11 MAC2

// 12 MAC3

// 13 RCA/ Composite Video1

// 14 RCA/ Composite Video2

// 15 RCA/ Composite Video3

// 16 S-Video1

// 17 S-Video2

// 18 S-Video3

// 19 SCART-Composite1

// 20 SCART-Composite2

// 21 SCART-RGB

// 22 SCART-S-video

// 23 Tuner1

// 24 Tuner2

// 25 Tuner3

// 26 YUV1

// 27 YUV2

// 28 YUV3

#define DDCCI_MCCS_INPUT_SOURCE_SELECT1                    0x60

 

// Changing this value selects a different video input source.

// Coding of the different sources to select are the same as

// Input Source Select 1

#define DDCCI_MCCS_INPUT_SOURCE_SELECT2                    0xCE

 

// Changing this value selects a different video input source.

// Coding of the different sources to select are the same as

// Input Source Select 1

#define DDCCI_MCCS_OUTPUT_SOURCE_SELECT1                0xD0

 

// Changing this value selects a different video input source.

// Coding of the different sources to select are the same as

// Input Source Select 1

#define DDCCI_MCCS_OUTPUT_SOURCE_SELECT2                0xD2

 

// Changing this value selects the video mode with respect to 2D or 3D.

// 0 None selected

// 1 Mono Mode

// 2 Enable Field-Sequential Right Eye First

// 3 Enable Field-Sequential Left Eye First

// 4 Enable 2-Way Interleaved Right Eye First

// 5 Enable 2-Way Interleaved Left Eye First

// 6 Enable 4-Way Interleaved, Display Stereo Buffer 0 (even scan lines)

// 7 Enable 4-Way Interleaved, Display Stereo Buffer 1 (odd scan lines)

// 8 Enable Side-by-Side Interleaved

#define DDCCI_MCCS_STEREO_MODE                            0xD4

 

// DPMS Power Status

// 0 none selected

// 1 On

// 2 Standby

// 3 Suspend

// 4 Off

#define DDCCI_MCCS_DISPLAY_POWER_MODE                    0xD6

 

#define DDCCI_MCCS_PRESET_COLOT_TEMP                    0xD8

 

// 0: none selected

// 1: underscan

// 2: overscan

// 3: 16 x 9 letterbox

#define DDCCI_MCCS_SCAN_FORMAT                            0xDA

 

// 0: None selected

// 1: Productivity

// 2: Games

// 3: Movies

#define DDCCI_MCCS_DISPLAY_MODE                            0xDC

 

// 0: None selected

// 1: Stand alone

// 2: Slave (full PC control)

#define DDCCI_MCCS_OPERATION_MODE                        0xDE

 

//==============================================================================//

//                     Non-Continuous Control Code Values                       //

//                     ( Read Only controls )                                   //

//==============================================================================//

 

// 0. None selected

// 1. Disabled

// 2. Enabled

#define DDCCI_MCCS_AUTO_SIZE_CENTER                        0xA2

 

// 3. None selected

// 4. Negative

// 5. Positive

#define DDCCI_MCCS_POLARITY_HORIZONTAL_SYNCHRONIZATION    0xA4

 

// 6. None selected

// 7. Negative

// 8. Positive

#define DDCCI_MCCS_POLARITY_VERTICAL_SYNCHRONIZATION    0xA6

 

// 9. None selected

// 10. Separate

// 11. Digital Composite

// 12. Composite on Green

#define DDCCI_MCCS_SYNCHRONIZATION_TYPE                    0xA8

 

// 13. none selected

// 14. Landscape

// 15. Portrait

#define DDCCI_MCCS_SCREEN_ORIENTATION                    0xAA

 

// Horizontal frequency in Hz.

// The value to indicate the displays information is: FFh FFh FFh

#define DDCCI_MCCS_HORFREQUENCY                            0xAC

 

// Vertical frequency in 0.01Hz

// The value to indicate the displays information is: FFh FFh

#define DDCCI_MCCS_VERTFREQUENCY                        0xAE

 

//==============================================================================//

//                     Non-Continuous Control Code Values                       //

//                     ( Write Only controls )                                  //

//==============================================================================//

 

// This request causes the display to Degauss and does not alter any of its control

// or status values. By any number not equal to zero will make the monitor to degauss.

// The value zero will nullify the degauss request.

#define DDCCI_MCCS_DEGAUSS                                0x01

 

// 0. None selected

// 1. Store Current settings in the monitor

// 2. Restore Factory default belonging to the particular video mode the monitor is in.

// 3. Restore the user saved values belonging to the particular video mode the monitor

//    is in

#define DDCCI_MCCS_SETTINGS                                0xB0 

#endif
