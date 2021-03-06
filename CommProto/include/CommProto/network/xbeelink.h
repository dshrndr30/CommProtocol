/*
  XBee Link that handles all xbee connections.

  Copyright (C) 2016  Mario Garcia.

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (At your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef __XBEE_LINK_H
#define __XBEE_LINK_H

#include <CommProto/network/commslink.h>
#include <CommProto/architecture/macros.h>
#include <unordered_map>
#include <memory>

namespace comnet {
namespace network {
namespace experimental {


class XBee;


class COMM_EXPORT XBeeLink : public CommsLink {
public:
  XBeeLink();

  ~XBeeLink() {
    free_pointer(xbees);
  }
  /**
     Initialize a connection for this node. Address is not required.
   */
  bool InitConnection(const char* port = NULL, const char* = NULL, uint32_t baudrate = 0);
  /**
     Adds an address to the link.
    TODO(Garcia, Wallace): Cluster communications required here!
   */
  bool AddAddress(uint8_t dest_id, const char* address = NULL, uint16_t port = 0);
  /**
     Remove an address from the link.
   */
  bool RemoveAddress(uint8_t dest_id);
  /**
     Send a message to the specified id of which an address is associated with.
   */
  bool Send(uint8_t dest_id, uint8_t* tx_data, uint32_t tx_length);
  /**
     Receive a message from a protocol id.
   */
  bool Recv(uint8_t* rx_data, uint32_t* rx_length);

  void DigestCommand(const char* cmd) { }

private:
  struct XBeeInfo {
    char addr[17];
    uint16_t id;
  };
  // Home address xbee.
  XBee* home;
  std::unordered_map<uint16_t, std::unique_ptr<XBeeInfo> >* xbees;
};
} // namespace Experimental
} // namespace Network
} // namespace Comnet
#endif // __XBEE_HANDLER_H
