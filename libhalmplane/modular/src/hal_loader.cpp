#include "hal_loader.h"
#include <cstddef>
#include <iostream> 
#include "wrapper.h"

Hal_Loader::Hal_Loader(const char* _libname)
{
    libname = _libname;
  if(libname)
    {
      dlhandle = dlopen(libname, RTLD_NOW | RTLD_GLOBAL);
    
      if (!dlhandle) 
      {
          std::cerr << dlerror() << std::endl;
      }
      void* (*rf)() = reinterpret_cast<void* (*)()>(dlsym(dlhandle, "function_map"));
      if(rf)
      {
        registered_functions = (std::map<std::string, void*>*) rf();
      }
      else
      {
        registered_functions = new std::map<std::string, void*>();
      }
    }
  else
    {
      registered_functions = new std::map<std::string, void*>();
    }
}

void* Hal_Loader::get_function(const char* ftag)
{
  if(registered_functions)
    {
      return (*registered_functions)[ftag];
    }
  return NULL;
}

void Hal_Loader::Hal_close()
{
  if(dlclose(dlhandle) == 0)
  {
    std::cout << "Library has closed" << std::endl;
  }
  else 
  {
    std::cout << "Library has not closed" << std::endl;
  }
}