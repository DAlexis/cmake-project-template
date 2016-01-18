#include "libheader.hpp"

#include <boost/program_options.hpp>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    namespace po = boost::program_options;
    po::options_description generalOptions("Genral options");
    generalOptions.add_options()
        ("help,h", "Print help message")
        ("func,f", "Call func from library");
    
    po::options_description specialOptions("Special options");
    specialOptions.add_options()
        ("square,s", po::value<double>(), "Number to be squared");
    
    po::options_description allOptions("Allowed options");
    allOptions
        .add(generalOptions)
        .add(specialOptions);
    
    po::variables_map vmOptions;
    try
    {
        po::store(po::parse_command_line(argc, argv, allOptions), vmOptions);
        po::notify(vmOptions);
    }
    catch (po::error& e)
    {
        cerr << "Command line parsing error: " << e.what() << endl;
        return -1;
    }
    
    if (argc == 1 || vmOptions.count("help"))
    {
        cout << allOptions << endl;
        return 0;
    }
    if (vmOptions.count("func"))
    {
        func();
        
    }
    if (vmOptions.count("square"))
    {
        cout << "Square is " << sqr(vmOptions["square"].as<double>()) << endl;
        return 0;
    }
    
    return 0;
}
