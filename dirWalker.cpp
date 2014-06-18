#include "dirWalker.hpp"

#include <string>
#include <ctime>
#include <sstream>

#include <boost/regex.hpp>

namespace fs = boost::filesystem;

std::vector<std::string> DirWalker::m_vPixList;
std::string DirWalker::m_prevWriteTime = "";

DirWalker::DirWalker()
:
  m_extension(".txt"),
  m_path("/"),
  m_vAcceptedExtensions()
{
  initAcceptedExtensions();
}

DirWalker::DirWalker(boost::filesystem::path path, std::string extension)
:
  m_extension(extension),
  m_path(path),
  m_vAcceptedExtensions()
{
  initAcceptedExtensions();
}

DirWalker::~DirWalker()
{
}

void DirWalker::initAcceptedExtensions()
{
  m_vAcceptedExtensions.push_back(".png");
  m_vAcceptedExtensions.push_back(".jpg");
  m_vAcceptedExtensions.push_back(".jpeg");
}

void DirWalker::createList(fs::path p)
{
  if(!exists(p))
  {
    std::cerr << p.string() << " doesn't exist..." << std::endl;
    return;
  }

  // first case: m_path is a path to a file.  
  if(fs::is_regular_file(p))
  {
	  if(isPic(p)) {
      m_vPixList.push_back(p.string());
      return;
		}
  }
  // otherwise we've got a directory
  else
  {
    fs::directory_iterator end;
    for(fs::directory_iterator i(p); i != end; ++i)
    {
      if(fs::is_directory(i->path()))
        createList(i->path());
      if(isPic(i->path()))
        m_vPixList.push_back(i->path().string()); 


      // todo: here's where we left off:
			// right now the code below should be moved to another method which creates a map
			// out of the list of pics from m_vPixList.  m_vPixList needs to just be the list
			// of all pics in the directory and subdirectories initially provided.

			// when that list is compiled, then we can go and figure out which destination
			// folders they'll be in.  so this createList method should end on line 68.
			// also need to do some housekeeping on init lists with the map private member variable
			std::time_t lastWriteTime = fs::last_write_time(i->path());
			std::string ctime = std::ctime(&lastWriteTime);
			std::string monthDay, year;
			std::stringstream ss;
		  ss << ctime;
				
			monthDay = ctime.substr(0, 10);
			year = ctime.substr(20, 4);

			std::string prevFolderName = monthDay + " " + year;

			if(prevFolderName != m_prevWriteTime)
			{
				std::cout << prevFolderName << std::endl;
				m_prevWriteTime = prevFolderName;
			}
    }
  }
}

bool DirWalker::setPath(fs::path p)
{
  m_path = p;
  return true;
}

bool DirWalker::isPic(fs::path p)
{
  for(auto iter = m_vAcceptedExtensions.begin(); iter != m_vAcceptedExtensions.end(); ++iter)
  {
    //std::cout<< "currently checking " << p.string() << " against " <<
    //   *iter << " to see if it's a pic..." << std::endl;

    if(p.string().find(*iter) != std::string::npos)
      return true;
  }  

  return false;
}

void DirWalker::printList()
{
  //std::cout << m_vPixList.size() << std::endl;

  for(auto iter = m_vPixList.begin(); iter != m_vPixList.end(); ++iter)
		std::cout << *iter << std::endl;
}

