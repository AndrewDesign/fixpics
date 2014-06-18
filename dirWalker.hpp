/*

Defines the interface for the directory walker. 
Depends on boost::filesystem.

Basic idea is to provide a starting point and the walker
will construct a list

*/

#ifndef _DIRWALKER_HPP_
#define _DIRWALKER_HPP_

#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>

#include <iostream>
#include <vector>
#include <map>

class DirWalker {

public:
  DirWalker();
  DirWalker(boost::filesystem::path path, std::string ext);
  ~DirWalker();

  void createList(boost::filesystem::path p);
  void printList();
  bool addExtension();
  bool setPath(boost::filesystem::path p);

private:

  std::string m_extension;
  boost::filesystem::path m_path;
  std::vector<std::string> m_vAcceptedExtensions;

  static std::map<boost::filesystem::path, boost::filesystem::path> m_picMap;
  static std::vector<std::string> m_vPixList;
	static std::string m_prevWriteTime;

  void initAcceptedExtensions();
  bool isPic(boost::filesystem::path p);

};

#endif

