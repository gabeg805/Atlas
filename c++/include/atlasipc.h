/* *****************************************************************************
 * 
 * Name:    atlasipc.h
 * Author:  Gabriel Gonzalez
 * Email:   gabeg@bu.edu
 * License: The MIT License (MIT)
 * 
 * Description: The interprocess communication method between Atlas and the
 *              system window manager.
 * 
 * Notes: None.
 * 
 * *****************************************************************************
 */

/* Header guard */
#ifndef ATLAS_IPC_H
#define ATLAS_IPC_H

/* C++ to C guard */
#ifdef __cplusplus
extern "C" {
#endif

/* Includes */
#include <stdint.h>

/* Public functions */
int          setupipc(void);
int          openipc(void);
int32_t      readipc(int fd);
int32_t      writeipc(int fd, uint32_t buf);
const char * getipcfile(void);

#ifdef __cplusplus
}
#endif

#endif /* ATLAS_IPC_H */
