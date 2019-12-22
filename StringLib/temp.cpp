#include <iostream>
#include <vector>
#include <sstream>

int main() {
  srand (time(NULL)); /*ignore this line*/
  
  std::vector<int> vec{0,1,0,3,0,5,6,0,8,2};
  size_t index = 0;//rand()%15;

  try
  {
    if(index < vec.size())
    {
      std::cout << "Index: " << index << " is in range" << std::endl;

      if(vec[index] == 0)
      {
        throw std::overflow_error("Divide by zero exception occured.");
      }
      else
      {
        std::cout << "Answer: " << 69/vec[index] << std::endl;

        try
        {
          if(vec[index] < (rand() % 5))
            throw std::string("random string exception");
          else
          {
            std::cout << "Random integer exception" << std::endl;
            throw 6; //will be caught by catch(...)
          }
        }
        catch(const std::string& error)
        {
          std::cout << "Caught: " << error << std::endl;
        }
      }
    }
    else
    {
      std::stringstream s;
      s << "Index " << index << " out of bounds";
      throw std::out_of_range(s.str());
    }
  }
  catch(const std::out_of_range& error)
  {
      std::cout << error.what() << std::endl;
      std::cout << "Out of range was thrown because index > size." << std::endl;
      std::cout << "We can use .at() which throws out_of_range by default if index > size." << std::endl;
      try
      {
        vec.at(index); //this will throw out_of_range again
      }
      catch(const std::out_of_range& error)
      {
        std::cout << "Caught out_of_range again" << std::endl;
      }

  }
  catch(std::exception& e)
  {
    std::cout << e.what() << std::endl;
    std::cout << "Caught an std::exception or an exception derived from std::exception class" << std::endl;
  }
  catch(...)
  {
    std::cout << "Caught an exception (whether they are derived by std::exception or not.)" << std::endl;
  }
}