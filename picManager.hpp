/*

Defines the interface for the directory walker. 
Depends on boost::filesystem.

Basic idea is to provide a starting point and the walker
will construct a list

*/

#ifndef _PICMANAGER_HPP_
#define _PICMANAGER_HPP_

#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>

#include <iostream>
#include <vector>

class PicManager {

public:
  PicManager();
  ~PicManager();

private:


};

#endif

