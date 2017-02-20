#include "vns.h"
#include <algorithm>

void VNS::insert(const HostName& host, const IPAddress& ip) {
  database.push_back(make_pair(host, ip));
}

bool VNS::remove(const HostName& host) {
  auto it = find_if(database.begin(), database.end(), [host](const std::pair<HostName, IPAddress>& pair) {
    return pair.first == host;
  });

  if(it != database.end()) {
    database.erase(it);
    return true;
  } else {
    return false;
  }
}

IPAddress VNS::lookup(const HostName& host) const {
  auto it = find_if(database.begin(), database.end(), [host](const std::pair<HostName, IPAddress>& pair) {
    return pair.first == host;
  });

  if(it != database.end()) {
    return it->second;
  } else {
    return NON_EXISTING_ADDRESS;
  }
}
