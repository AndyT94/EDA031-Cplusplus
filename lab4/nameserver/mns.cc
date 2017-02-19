#include "mns.h"
#include <algorithm>

void MNS::insert(const HostName& host, const IPAddress& ip) {
  database.insert(make_pair(host, ip));
}

bool MNS::remove(const HostName& host) {
  auto it = database.find(host);

  if (it != database.end()) {
    database.erase(it);
    return true;
  } else {
    return false;
  }
}

IPAddress MNS::lookup(const HostName& host) const {
  auto it = database.find(host);

  if (it != database.end()) {
    return it->second;
  } else {
    return NON_EXISTING_ADDRESS;
  }
}
