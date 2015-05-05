// 
// CREATED BY: Gabriel Gonzalez (contact me at gabeg@bu.edu) 
// 
// 
// NAME:
// 
//     atlas.cpp
// 
// 
// SYNTAX: 
// 
//     $ g++ -o atlas *DEPENDENCIES.c `pkg-config gtk+-3.0 --cflags --libs`
// 
// 
// PURPOSE:
// 
//     Creates a taskbar at the top of the screen that contains:
//         
//         - Workspace tags
//         - Date and time
//         - Screen brightness
//         - Volume level
//         - Wifi strength
//         - Battery charge level
// 
// 
// KEYWORDS:
// 
//     N/A
// 
// 
// MODIFICATION HISTORY:
// 	
//     gabeg Sep 16 2014 <> created
// 
//     gabeg Sep 16 2014 <> Moved functions to update the statusbar over to "util.c"
//                          and added comments to each function
// 
// **********************************************************************************



// /////////////////////////////////
// ///// INCLUDES AND DECLARES /////
// /////////////////////////////////

// Includes
// #include "../hdr/Statusbar.h"
// #include "../hdr/bat.h"
// #include "../hdr/bright.h"
// #include "../hdr/date.h"
// #include "../hdr/vol.h"
// #include "../hdr/tags.h"
// #include "../hdr/wifi.h"

// #include <gtk/gtk.h>
// #include <signal.h>



// ///////////////////////////////////
// ///// DISPLAY ATLAS STATUSBAR /////
// ///////////////////////////////////

// LOOK AT GTKMM ONLINE
// Statusbar Atlas;

// Display the atlas statusbar
int main(int argc, char **argv) {
    
    // // Initialize gtk toolkit
    // gtk_init(&argc, &argv);
    
    // // Setup widgets
    // Atlas.init();
    
    // // Display widgets
    // display_tags(1);
    // display_date();
    // display_battery();
    // display_volume(); // Switch this and below
    // display_wifi();
    // display_brightness();
    
    // gtk_widget_show(Atlas.bar);
    // gtk_widget_show(Atlas.win);
    
    // // signal(SIGUSR1, widget_updater);
    
    // // Run the gtk loop
    // gtk_main();
    
    return 0;    
}
