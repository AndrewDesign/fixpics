#include <iostream>
#include <boost/program_options.hpp>
#include "dirWalker.hpp"

namespace po = boost::program_options;

int main (int argc, char* argv[]) {

  /* Setup program options
   *
  po::options_description desc("Allowed options");
	desc.add_options()
		("initial_path", po::value<std::string>(),
			"Where to point the app to begin looking for pictures (root node)");

	po::variables_map vm;
	po::store(po::parse_command_line(argc, argv, vm);
	po::store(po::command_line_parser(argc, argv).options(desc).po
	po::notify(vm);

  if(vm.count("initial_path"))
	{
	  std::cout << "blah blah" << std::endl;
	//  std::cout << "Starting to fix pictures in " << vm["initial_path"].as<std::string> << std::endl;
	}

 std::string initPath = vm["initial_path"].as<std::string>;
*/

  DirWalker dw;

  dw.setPath("/home/chris/");

  std::string initPath = "/home/chris/Wallpapers";
  boost::filesystem::path p(initPath);
  dw.createList(p);
//  dw.printList();

  return 0;
}

