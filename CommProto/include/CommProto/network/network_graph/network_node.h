/*
  Network node.

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
#ifndef __NETWORKNODE_H
#define __NETWORKNODE_H


#include <CommProto/architecture/os/include_defines.h>
#include <CommProto/network/commslink.h>
#include <CommProto/network/network_graph/network_edge.h>
#include <memory>


namespace comnet {
namespace network {

class NetworkGraph;


// Network node definitions.
class Node {
public:
  Node(CommsLink* link);
  Node();

  ~Node();

  
private:
  EdgeContainer outgoing;
  EdgeContainer incoming;
  // CommsLink cluster.
  const CommsLink* cluster;

  // friendly neighborhood NetworkGraph...
  friend class NetworkGraph;
};
} // network
} // comnet 
#endif // __NETWORKNODE_H