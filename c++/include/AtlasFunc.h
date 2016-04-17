/* *****************************************************************************
 * 
 * Name:    AtlasFunc.h
 * Type:    <AtlasFunc>
 * Author:  Gabriel Gonzalez
 * Email:   gabeg@bu.edu
 * License: The MIT License (MIT)
 * 
 * Description: The Atlas Function type.
 * 
 * Notes: None.
 * 
 * *****************************************************************************
 */

/* Header guard */
#ifndef ATLAS_FUNC_H
#define ATLAS_FUNC_H

/* Includes */
#include <stdint.h>
#include <string>

/* Structure */
struct AtlasFunc
{
    std::string (*info)(void);
    int         (*event)(void*);
    int         (*signal)(uint8_t);
};

/* Namespace extension */
namespace atlas
{
    typedef AtlasFunc func;
};

#endif /* ATLAS_FUNC_H */
