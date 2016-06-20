/* 
  C++ Socket configuration.

  Copyright (C) 2016  Michael Wallace, Mario Garcia.

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef __COMMSOCKET_H
#define __COMMSOCKET_H

#include <CommProto/architecture/os/include_defines.h>

#define INTERFACE class

namespace Comnet {
namespace Network {

/**
  Basic Socket Interface to handle TCP and UDP sockets.
*/
INTERFACE TcpSocket {
public:
  virtual ~TcpSocket() 
  { }

  virtual uint32_t sockSend(const char* buffer, uint32_t len, const char* address = "", uint16_t port = 0) = 0;

  virtual uint32_t sockReceive(const char* buffer, uint32_t len, const char* address = "", uint16_t port = 0) = 0;
  
  virtual uint32_t sockConnect(const char* address, uint16_t port) = 0;
  
  virtual uint32_t sockAsyncConnect(const char* address, uint16_t port) = 0;

  virtual uint32_t sockListen(const char* address, uint16_t port) = 0;

  virtual uint32_t sockListen(uint16_t port) = 0;

  virtual TcpSocket* sockAccept() = 0;
};

} // Network namespace
} // Comnet namespace
#endif // __COMMSOCKET_H