#ifndef FLUID_PORT_H_
#define FLUID_PORT_H_

#include <cstdint>







  
    
      
        

class FluidPortLogical
{
public:
  FluidPortLogical(bool *d, bool *v,  bool *r) : data(d), vlid(v), rtry(r) { }
  FluidPortLogical() : data(NULL), vlid(NULL), rtry(NULL) { }

  bool read() const { return *data; }
  bool get_valid() const { return *vlid; }
  bool get_retry() const { return *rtry; }

  void invalid() { *vlid = false; }
  void write(bool d) { *data = d; *vlid = true; }

  bool *data;
  bool *vlid, *rtry;
};
      

    
  
    
      
        
class FluidPortU64
{
public:
  FluidPortU64(uint64_t *d, bool *v,  bool *r) : data(d), vlid(v), rtry(r) { }
  FluidPortU64() : data(NULL), vlid(NULL), rtry(NULL) { }

  uint64_t read() const { return *data; }
  bool get_valid() const { return *vlid; }
  bool get_retry() const { return *rtry; }

  void invalid() { *vlid = false; }
  void write(uint64_t d) { *data = d; *vlid = true; }

  uint64_t *data;
  bool *vlid, *rtry;
};

      
    
  
    

      
        

class FluidPortU32
{
public:
  FluidPortU32(uint32_t *d, bool *v,  bool *r) : data(d), vlid(v), rtry(r) { }
  FluidPortU32() : data(NULL), vlid(NULL), rtry(NULL) { }

  uint32_t read() const { return *data; }
  bool get_valid() const { return *vlid; }
  bool get_retry() const { return *rtry; }

  void invalid() { *vlid = false; }
  void write(uint32_t d) { *data = d; *vlid = true; }

  uint32_t *data;
  bool *vlid, *rtry;
};
      
      

    
  
    
      
    
  
    
      
    
  
    

      

    
  

  
    
      
    
  
    
      
    
  
    

      

    
  
    
      
    
  
    

      

    
  
    

      

    
  
    
      
    
  
    
      
    
  

  
    
      
    
  
    
      
    
  
    
      
    
  
    

      

    
  
    

      

    
  
    
      
    
  
    
      
    
  
    
      
    
  

  
    
      
    
  
    
      
    
  
    
      
    
  
    
      
    
  
    

      

    
  
    

      

    
  
    
      
    
  
    
      
    
  
    
      
    
  
    
      
    
  


#endif
