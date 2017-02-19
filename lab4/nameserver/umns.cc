#include "umns.h"
#include <algorithm>

void UMNS::insert(const HostName& host, const IPAddress& ip) {
  database.insert(make_pair(host, ip));
}

bool UMNS::remove(const HostName& host) {
  auto it = database.find(host);

  if (it != database.end()) {
    database.erase(it);
    return true;
  } else {
    return false;
  }
}

IPAddress UMNS::lookup(const HostName& host) const {
  auto it = database.find(host);

  if (it != database.end()) {
    return it->second;
  } else {
    return NON_EXISTING_ADDRESS;
  }
}
