/* *****************************************************************************
 * 
 * Name:    atlasio.h
 * Class:   None
 * Author:  Gabriel Gonzalez
 * Email:   gabeg@bu.edu
 * License: The MIT License (MIT)
 * 
 * Description: The Atlas input/output utility. Handles printing messages to
 *              stdout/stderr, as well as to a log file.
 * 
 * Notes: None.
 * 
 * *****************************************************************************
 */

/* Header guard */
#ifndef ATLASIO_H
#define ATLASIO_H

/* Includes */
#include <string>
#include <vector>

/* Defines */
#define ATLAS_DEBUG 1

/* Namespace */
namespace atlasio
{
    std::string              cut(std::string str, int field, char delim);
    std::string              trim(std::string str);
    std::string              trim_lead(std::string str);
    std::string              trim_trail(std::string str);
    bool                     is_space(std::string str);
    std::vector<std::string> split(std::string str, char delim);
    void                     print(std::string str);
    void                     printerr(std::string str);
    void                     lprint(std::string str);
    void                     debug(std::string str);
};

#endif /* ATLASIO_H */
