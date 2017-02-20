#include "hns.h"
#include <algorithm>

HNS::HNS(int size) {
  database.resize(size);
}

void HNS::insert(const HostName& host, const IPAddress& ip) {
  database[str_hash(host) % database.size()].push_back(make_pair(host, ip));
}

bool HNS::remove(const HostName& host) {
  unsigned int index = str_hash(host) % database.size();

  auto it = find_if(database[index].begin(), database[index].end(), [host](const std::pair<HostName, IPAddress> &pair) {
    return pair.first == host;
  });

  if(it != database[index].end()) {
    database[index].erase(it);
    return true;
  } else {
    return false;
  }
}

IPAddress HNS::lookup(const HostName& host) const {
  unsigned int index = str_hash(host) % database.size();

  auto it = find_if(database[index].begin(), database[index].end(), [host](const std::pair<HostName, IPAddress> &pair) {
    return pair.first == host;
  });

  if(it != database[index].end()) {
    return it->second;
  } else {
    return NON_EXISTING_ADDRESS;
  }
}
