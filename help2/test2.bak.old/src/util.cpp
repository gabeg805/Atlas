// 
// CREATED BY: Gabriel Gonzalez (contact me at gabeg@bu.edu) 
// 
// 
// NAME:
// 
//     util.c
// 
// 
// SYNTAX: 
// 
//     #include "/PATH/TO/HEADER/util.h"
// 
// 
// PURPOSE:
// 
//     Contains utility functions that each widget needs, this saves the trouble
//     of each widget source file having the same utility function, and 
//     centralizes it in one source file.
// 
// 
// KEYWORDS:
// 
//     N/A
// 
// 
// MODIFICATION HISTORY:
// 	
//     gabeg Sep 25 2014 <> created
// 
//     gabeg Oct 05 2014 <> Added a header to the source file and moved functions to 
//                          update the statusbar into this source file
// 
// **********************************************************************************



// /////////////////////////////////
// ///// INCLUDES AND DECLARES /////
// /////////////////////////////////

// Includes
#include "../hdr/Statusbar.h"
#include "../hdr/util.h"
#include "../hdr/vol.h"
#include "../hdr/bright.h"
#include "../hdr/tags.h"
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <assert.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>



// /////////////////////////////////
// ///// ADD EVENTS TO WIDGETS /////
// /////////////////////////////////

// Add events to widgets that are triggered with signals
void widget_mouse_enter(GtkWidget *win, GtkWidget *widget, int timer, gboolean (*func)(gpointer)) {
    
    // Initialize widgets
    GtkWidget *event = gtk_event_box_new();
    
    // Handle widget signals
    gtk_widget_add_events(event, GDK_ENTER_NOTIFY_MASK);
    g_signal_connect(G_OBJECT(event), "enter-notify-event", G_CALLBACK(func), NULL);
    
    if ( timer > 0 ) 
        g_timeout_add_seconds(timer, (GSourceFunc)*func, event);
        
    // Display the widget
    gtk_container_add(GTK_CONTAINER(event), widget);
    if ( win != NULL ) {
        // gtk_container_add(GTK_CONTAINER(win), event);
        gtk_box_pack_end(GTK_BOX(Atlas.bar), event, 0, 0, 5);
    }
    
    gtk_widget_show(event);
}

// Add events to widgets that are triggered with signals
void widget_mouse_entera(GtkWidget *event, GtkWidget *widget, int timer, gboolean (*func)(gpointer)) {
    
    // Handle widget signals
    gtk_widget_add_events(event, GDK_ENTER_NOTIFY_MASK);
    g_signal_connect(G_OBJECT(event), "enter-notify-event", G_CALLBACK(func), NULL);
    
    if ( timer > 0 ) 
        g_timeout_add_seconds(timer, (GSourceFunc)*func, event);
        
    // Display the widget
    gtk_container_add(GTK_CONTAINER(event), widget);
    if ( Atlas.win != NULL ) {
        // gtk_container_add(GTK_CONTAINER(win), event);
        gtk_box_pack_end(GTK_BOX(Atlas.bar), event, 0, 0, 5);
    }
    
    gtk_widget_show(event);
}


// ///////////////////////////////////
// ///// SETUP STATUSBAR WIDGETS /////
// ///////////////////////////////////


void widget_updater(int sig) {
    
    int key, type, val;
    sem_t *sem = sem_open("/semi", O_RDONLY, 0644, key);
    
    if ( sem == NULL )
        return;
    
    sem_getvalue(sem, &key);
    
    type = (key >> 8);
    val  = (key & 0xFF);
    
    switch ( type ) {
    case 'B':
        if ( val == 0 )
            system("xbacklight -inc 10");
        else if ( val == 1 )
            system("xbacklight -dec 10");
        
        // set_brightness_icon(NULL);
        break;
    case 'P':
        if ( val == 0 )
            system("mocp -G");
        else if ( val == 1 )
            system("mocp -r");
        else if ( val == 2 )
            system("mocp -f");
        
        set_volume_icon(NULL);
        break;
    case 'T':
        val = (key & 0xFF);
        set_tag(val);
        break;
    case 'V':
        if ( val == 0 )
            system("amixer -q set Master 5%+");
        else if ( val == 1 )
            system("amixer -q set Master 5%-");
        else if ( val == 2 )
            system("amixer -q set Master toggle");
        
        set_volume_icon(NULL);
        break;
    default:
        break;
    }
}
