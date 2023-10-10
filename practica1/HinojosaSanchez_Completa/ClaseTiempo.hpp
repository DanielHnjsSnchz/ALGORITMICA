#ifndef CLASETIEMPO_HPP
#define CLASETIEMPO_HPP


#include <cassert>
#include <ctime>
#include <cstdio>
#include <cstring> //Para usar memset
#include <iostream>
#include <stdint.h> // Para usar uint64_t

class Clock {
    private:
    timespec _start;
    timespec _stop;
    bool _isStarted;
  public:
    inline Clock (){
        memset(&_start,0,sizeof(timespec));
        memset(&_stop,0,sizeof(timespec));
        _isStarted=false;}
    /*!\brief Starts the clock.
     * \pre not isStarted()
     * \post isStarted()
     */
    inline void start (){
        assert (!isStarted());
      clock_gettime (CLOCK_REALTIME, &_start);   
      _isStarted=true;
    }
    /*!\brief Re-starts the clock.
     * \post isStarted()
     */
    inline void restart (){
        clock_gettime (CLOCK_REALTIME, &_start);   
      _isStarted=true;
    }
   
    /*!\brief Stops the clock.
     * \pre isStarted()
     * \post not isStarted()
     */ 
    inline void stop (){
        assert (_isStarted);
      clock_gettime (CLOCK_REALTIME, &_stop);   
      _isStarted=false;
    }
    /*!\brief Is the clock started?
     * \return true if the clock is started currently.
     */
    inline bool isStarted() const{return _isStarted;}
    /*!\brief Return the elapsed time in mcs.*/
    inline uint64_t elapsed() const{
        assert (!_isStarted);
      uint64_t startT = (uint64_t)_start.tv_sec * 1000000LL + (uint64_t)_start.tv_nsec / 1000LL;
      uint64_t stopT = (uint64_t)_stop.tv_sec * 1000000LL + (uint64_t)_stop.tv_nsec / 1000LL;
      return stopT-startT;
    }
};

#endif